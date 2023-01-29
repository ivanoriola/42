/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_2_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 11:18:06 by alsanche          #+#    #+#             */
/*   Updated: 2023/01/25 10:33:24 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*str_path(char **enpv)
{
	int	i;

	i = 0;
	if (!enpv || *enpv == NULL)
		return (NULL);
	while (enpv[i])
	{
		if (enpv[i][0] == 'P' && enpv[i][1] == 'A'
			&& enpv[i][2] == 'T' && enpv[i][3] == 'H' && enpv[i][4] == '=')
			return (&enpv[i][5]);
		i++;
	}
	return (NULL);
}

char	**find_path(char **enpv)
{
	char	**gps;
	char	*path;
	char	*aux;
	int		i;

	path = str_path(enpv);
	if (!path)
		return (NULL);
	i = -1;
	gps = ft_split(path, ':');
	while (gps[++i])
	{
		aux = gps[i];
		gps[i] = ft_strjoin(aux, "/");
		free(aux);
	}
	return (gps);
}

char	**env_2_str(void)
{
	int		i;
	t_env	*aux;
	char	**str;

	i = -1;
	aux = g_mini->env;
	str = malloc(sizeof(char *) * g_mini->n_env + 1);
	if (!str)
		return (NULL);
	while (aux)
	{
		str[++i] = ft_strdup(aux->value);
		aux = aux->next;
	}
	str[++i] = NULL;
	return (str);
}
