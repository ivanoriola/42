/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 08:29:21 by ioriola           #+#    #+#             */
/*   Updated: 2021/10/14 17:46:09 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

#include <libft.h>

typedef struct s_args
{
	int		pid;
	char	*str;
}	t_args;

short	is_number(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

short	parse_args_ok(struct s_args *args, int argc, char **argv)
{
	if (!args || argc != 3 || !is_number(argv[1]))
		return (0);
	args->pid = ft_atoi(argv[1]);
	args->str = argv[2];
	return (1);
}

void	send_char(int pid, char character)
{
	int	current_bit;

	current_bit = 0;
	while (current_bit < 8)
	{
		if (character & (1 << current_bit))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(250);
		current_bit++;
	}
}

void	send_message(struct s_args *args)
{
	int	i;

	i = 0;
	while (args->str[i])
		send_char(args->pid, args->str[i++]);
}

int	main(int argc, char **argv)
{
	t_args	args;

	if (!parse_args_ok(&args, argc, argv))
	{
		ft_putstr("Invalid arguments\n");
		return (1);
	}
	send_message(&args);
	return (0);
}
