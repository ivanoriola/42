/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 08:29:21 by ioriola           #+#    #+#             */
/*   Updated: 2021/10/19 07:19:21 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <libft.h>

typedef struct s_character
{
	char	character;
	int		current_bit;
}	t_character;

void	mini_printf_int(char *str, int nb)
{
	int	i;

	i = 0;
	while (str[i] != '%')
		ft_putchar(str[i++]);
	i++;
	if (str[i] == 'i')
		ft_putnbr(nb);
	i++;
	ft_putstr(str + i);
}

void	my_sig_handler(int sig)
{
	static struct s_character	character = {0, 0};

	if (sig == SIGUSR2)
		character.character |= (1 << character.current_bit);
	character.current_bit++;
	if (character.current_bit == 8)
	{
		ft_putchar(character.character);
		character.character = 0;
		character.current_bit = 0;
	}
}

int	main(void)
{
	mini_printf_int("Server PID: %i\n", getpid());
	signal(SIGUSR1, my_sig_handler);
	signal(SIGUSR2, my_sig_handler);
	while (1)
		pause();
	return (0);
}
