/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 15:25:37 by alsanche          #+#    #+#             */
/*   Updated: 2023/01/25 10:33:55 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	ft_exe(char *gps, t_comand *com)
{
	if (com->fd_out != STDOUT_FILENO)
		dup2(com->fd_out, STDOUT_FILENO);
	if (com->close != 0)
		close (com->close);
	execve(gps, com->comand, g_mini->envs);
}

void	ft_run(t_comand *com)
{
	char	*gps;
	int		i;

	if (com->fd_in != STDIN_FILENO)
		dup2(com->fd_in, STDIN_FILENO);
	if (!access(com->comand[0], X_OK))
		ft_exe(com->comand[0], com);
	i = -1;
	while (g_mini->path != NULL && g_mini->path[++i])
	{
		gps = ft_strjoin(g_mini->path[i], com->comand[0]);
		if (!access(gps, X_OK))
			ft_exe(gps, com);
		free(gps);
	}
	send_error(1, com->comand[0]);
	close(com->close);
	close(com->fd_in);
	close(com->fd_out);
	exit (127);
}

static void	init_childs(t_comand *com, int i)
{	
	pid_t	pid;
	int		fd[2];

	pipe(fd);
	manage_pipe(fd, com);
	pid = fork();
	g_mini->state = pid;
	if (pid > 0)
		g_mini->childs[i] = pid;
	else if (pid < 0)
		send_error(2, "fork");
	else
	{
		signal(SIGINT, sig_redir);
		if (com->builtin == 1)
			exit(run_builtin(com));
		else
			ft_run(com);
	}
	if (com->wait == 1)
		waitpid(g_mini->childs[i], NULL, 0);
	if (com->pipe == 0)
		close(fd[0]);
	close(fd[1]);
}

static int	built_or_exec(void)
{
	int			i;
	int			status;
	t_comand	*aux;

	aux = g_mini->comands;
	i = -1;
	while (++i < g_mini->n_com)
	{
		init_childs(aux, i);
		close_fd_child(aux);
		aux = aux->next;
	}
	ft_reset_main_fd();
	i = -1;
	while (++i < g_mini->n_com && g_mini->childs[i])
	{
		g_mini->state = g_mini->childs[i];
		waitpid(g_mini->childs[i], &status, 0);
	}
	g_mini->state = 0;
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (0);
}

int	ft_execv(void)
{
	int	status;

	g_mini->envs = env_2_str();
	g_mini->path = find_path(g_mini->envs);
	status = 0;
	if (g_mini->n_com == 1 && g_mini->comands->builtin == 1)
		run_builtin(g_mini->comands);
	else
	{
		g_mini->childs = ft_calloc(g_mini->n_com - 1, sizeof(pid_t *));
		if (!g_mini->childs)
			printf("children not found");
		status = built_or_exec();
		free(g_mini->childs);
	}
	if (g_mini->envs != NULL)
		free_split(g_mini->envs);
	if (g_mini->path != NULL)
		free_split(g_mini->path);
	return (status);
}
