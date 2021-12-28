/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 10:07:45 by ioriola           #+#    #+#             */
/*   Updated: 2020/09/16 09:05:19 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

#define LBLUE		"\033[36m"
#define RED			"\033[31m"
#define GREEN		"\033[32m"
#define YELLOW		"\033[33m"
#define BLUE		"\033[34m"
#define WHITE		"\033[37m"
#define BG			"\033[40m"
#define RESET		"\033[0m"

void	check(int value1, int value2)
{
	(value1 == value2) ? printf(RESET GREEN "\n\n OK\t%i = %i\t (✔)", value1, value2) : printf(RESET RED "\n\n KO\t%i ≠ %i\t (𐄂)", value1, value2);
	printf("\n\t¯¯¯¯¯¯¯¯¯¯¯¯");
}

int		main(void)
{
	char			*block;
	int				value1, value2;

	char			c, *str;
	void			*pointer;
	int				a, b;
	unsigned int	u, v, uintmax;

	c = 'C';
	str = "Hello World";
	pointer = &str;
	a = 12345;
	b = -45678;
	u = 987654321;
	uintmax = 4294967295u;
	v = 123456789;

	printf(WHITE "\n  /██████   /██                              /██             /██      /██████ ");
	printf("\n /██__  ██ | ██                             |__/            | ██     /██__  ██");
	printf("\n| ██  \\__//██████         /██████   /██████  /██ /███████  /██████  | ██  \\__/");
	printf("\n| ████   |_  ██_/        /██__  ██ /██__  ██| ██| ██__  ██|_  ██_/  | ████    ");
	printf("\n| ██_/     | ██         | ██  \\ ██| ██  \\__/| ██| ██  \\ ██  | ██    | ██_/    ");
	printf("\n| ██       | ██ /██     | ██  | ██| ██      | ██| ██  | ██  | ██ /██| ██      ");
	printf("\n| ██       |  ████/     | ███████/| ██      | ██| ██  | ██  |  ████/| ██      ");
	printf("\n|__/        \\___//██████| ██____/ |__/      |__/|__/  |__/   \\___/  |__/      ");
	printf("\n                |______/| ██                                                  ");
	printf("\n                        | ██                             'Mandatory Part'");
	printf("\n                        |__/");

	printf(LBLUE "\n\n  __");
	printf ("\n /_ |   ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░");
	printf("\n  | |   ░░░░░░░░░░                                ░░░░░░░░░░");
	printf("\n  | |   ▒▒▒▒▒▒▒▒▒▒ " WHITE " SIMPLE CONVERSION MANAGEMENT " LBLUE " ▒▒▒▒▒▒▒▒▒▒");
	printf("\n  | |   ▓▓▓▓▓▓▓▓▓▓                                ▓▓▓▓▓▓▓▓▓▓");
	printf("\n  |_|   ████████████████████████████████████████████████████");
	printf(WHITE "\n\n\tSimply check each conversion without any flags 'cspdiuxX%%'");
	printf("\n\t¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯");

	block = "%c";
	printf(YELLOW "\n\n[%s] (No flags)", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, c);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, c);
	check(value1, value2);


	block = "%s";
	printf(YELLOW "\n\n[%s] (No flags)", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, str);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, str);
	check(value1, value2);

	block = "%p";
	printf(YELLOW "\n\n[%s](No flags)", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, pointer);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, pointer);
	check(value1, value2);

	block = "%d";
	printf(YELLOW "\n\n[%s] (No flags)", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, a);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, a);
	check(value1, value2);

	block = "%i";
	printf(YELLOW "\n\n[%s] (No flags)", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, b);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, b);
	check(value1, value2);

	block = "%u";
	printf(YELLOW "\n\n[%s] (No flags)", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, u);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, u);
	check(value1, value2);

	block = "%x";
	printf(YELLOW "\n\n[%s] (No flags)", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, v);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, v);
	check(value1, value2);

	block = "%X";
	printf(YELLOW "\n\n[%s] (No flags)", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, v);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, v);
	check(value1, value2);

	block = "%%";
	printf(YELLOW "\n\n[%s] (No flags)", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, v);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, v);
	check(value1, value2);

	printf(WHITE "\n\n\tTry special cases like 0 or smallest int or empty string or null pointer");
	printf("\n\t¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯");


	block = "%d";
	printf(YELLOW "\n\n[%s] (Zero)", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, 0);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, 0);
	check(value1, value2);

	block = "%i";
	printf(YELLOW "\n\n[%s] (Smallest int)", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, -2147483648);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, -2147483648);
	check(value1, value2);

	block = "%s";
	printf(YELLOW "\n\n[%s] (Empty string)", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, "");
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, "");
	check(value1, value2);

	block = "%p";
	printf(YELLOW "\n\n[%s] (Null pointer)", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, NULL);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, NULL);
	check(value1, value2);

	printf(WHITE "\n\n\tTry with multiple arguments/conversions");
	printf("\n\t¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯");

	block = "%c %s %p %i";
	printf(YELLOW "\n\n[%s]", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, c, str, pointer, a);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, c, str, pointer, a);
	check(value1, value2);

	printf(WHITE "\n\n\tTry the various conversions in the middle of a sentence (with other characters before and/or after)");
	printf("\n\t¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯");

	block = "'%c' is a character and \"%s\" is a string";
	printf(YELLOW "\n\n[%s]", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, c, str);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, c, str);
	check(value1, value2);

	block = "\"%s\" is a string and '%c' is a NULL character";
	printf(YELLOW "\n\n[%s]", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, str, NULL);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, str, NULL);
	check(value1, value2);

	printf(LBLUE "\n\n  ___");
	printf("\n |__ \\  ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░");
	printf("\n    ) | ░░░░░░░░░░                           ░░░░░░░░░░");
	printf("\n   / /  ▒▒▒▒▒▒▒▒▒▒ " WHITE " SIMPLE FLAGS MANAGEMENT " LBLUE " ▒▒▒▒▒▒▒▒▒▒");
	printf("\n  / /_  ▓▓▓▓▓▓▓▓▓▓                           ▓▓▓▓▓▓▓▓▓▓");
	printf("\n |____| ███████████████████████████████████████████████");
	printf("\n\n\tUse the 's' conversion for all the following test");
	printf(WHITE "\n\n\tCheck the 'minimum field width' with values bigger, equal and smaller than the string");
	printf("\n\t¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯");

	block = "%15s";
	printf(YELLOW "\n\n[%s] (Width bigger than string)", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, str);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, str);
	check(value1, value2);

	block = "%11s";
	printf(YELLOW "\n\n[%s] (Width equal than string)", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, str);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, str);
	check(value1, value2);

	block = "%5s";
	printf(YELLOW "\n\n[%s] (Width smaller than string)", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, str);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, str);
	check(value1, value2);

	printf(WHITE "\n\n\tCheck the 'minimum field width' with values bigger, equal and smaller than the string with '-'");
	printf("\n\t¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯");

	block = "%-15s";
	printf(YELLOW "\n\n[%s] (Width bigger than string, with -)", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, str);
	printf(BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, str);
	check(value1, value2);

	block = "%-11s";
	printf(YELLOW "\n\n[%s] (Width equal than string, with -)", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, str);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, str);
	check(value1, value2);

	block = "%-5s";
	printf(YELLOW "\n\n[%s] (Width smaller than string, with -)", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, str);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, str);
	check(value1, value2);

	printf(WHITE "\n\n\tCheck the 'minimum field width' with values bigger, equal and smaller than the string with '0'");
	printf("\n\t¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯");

	block = "%015s";
	printf(YELLOW "\n\n[%s] (Width bigger than string, with 0)", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, str);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, str);
	check(value1, value2);

	block = "%011s";
	printf(YELLOW "\n\n[%s] (Width equal than string, with 0)", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, str);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, str);
	check(value1, value2);

	block = "%05s";
	printf(YELLOW "\n\n[%s] (Width smaller than string, with 0)", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, str);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, str);
	check(value1, value2);

	printf(WHITE "\n\n\tCheck the '.' with multiple precisions");
	printf("\n\t¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯");

	block = "%.15s";
	printf(YELLOW "\n\n[%s] (Precision bigger than string)", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, str);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, str);
	check(value1, value2);

	block = "%.11s";
	printf(YELLOW "\n\n[%s] (Precision equal than string)", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, str);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, str);
	check(value1, value2);

	block = "%.5s";
	printf(YELLOW "\n\n[%s] (Precision smaller than string)", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, str);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, str);
	check(value1, value2);

	block = "%.0s";
	printf(YELLOW "\n\n[%s] (Precision zero)", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, str);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, str);
	check(value1, value2);

	printf(LBLUE "\n\n  ___");
	printf("\n |__ \\  ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░");
	printf("\n   _) | ░░░░░░░░░░                             ░░░░░░░░░░");
	printf("\n  |_ <  ▒▒▒▒▒▒▒▒▒▒ " WHITE " ADVANCED FLAGS MANAGEMENT " LBLUE " ▒▒▒▒▒▒▒▒▒▒");
	printf("\n  __) | ▓▓▓▓▓▓▓▓▓▓                             ▓▓▓▓▓▓▓▓▓▓");
	printf("\n |___/  █████████████████████████████████████████████████");
	printf("\n\n\tUse the 's' conversion for all the following test");
	printf(WHITE "\n\n\tCheck '*' as minimum field width (try values like negative one, zero etc.)");
	printf("\n\t¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯");

	block = "%*s";
	printf(YELLOW "\n\n[%s] ('*' Width bigger than string)", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, 15, str);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, 15, str);
	check(value1, value2);

	block = "%*s";
	printf(YELLOW "\n\n[%s] ('*' Width equal than string)", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, 11, str);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, 11, str);
	check(value1, value2);

	block = "%*s";
	printf(YELLOW "\n\n[%s] ('*' Width smaller than string)", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, 5, str);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, 5, str);
	check(value1, value2);

	block = "%*s";
	printf(YELLOW "\n\n[%s] ('*' Width negative one)", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, -1, str);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, -1, str);
	check(value1, value2);

	block = "%*s";
	printf(YELLOW "\n\n[%s] ('*' Width zero)<", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, 0, str);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, 0, str);
	check(value1, value2);

	printf(WHITE "\n\n\tCheck '*' as precision (try values like negative one, zero etc.)");
	printf("\n\t¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯");

	block = "%.*s";
	printf(YELLOW "\n\n[%s] ('*' Precision bigger than string)", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, 15, str);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, 15, str);
	check(value1, value2);

	block = "%.*s";
	printf(YELLOW "\n\n[%s] ('*' Precision equal than string)", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, 11, str);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, 11, str);
	check(value1, value2);

	block = "%.*s";
	printf(YELLOW "\n\n[%s] ('*' Precision smaller than string)", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, 5, str);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, 5, str);
	check(value1, value2);

	block = "%.*s";
	printf(YELLOW "\n\n[%s] ('*' Precision negative one)", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, -1, str);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, -1, str);
	check(value1, value2);

	block = "%.*s";
	printf(YELLOW "\n\n[%s] ('*' Precision zero)", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, 0, str);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, 0, str);
	check(value1, value2);

	printf(WHITE "\n\n\tCheck '*' as both with/without one other flag (try values like negative one, zero etc.)");
	printf("\n\t¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯");

	block = "%*.*s";
	printf(YELLOW "\n\n[%s] ('*' Precision and '*' Width)", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, 15, 15, str);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, 15, 15, str);
	check(value1, value2);

	block = "%*s";
	printf(YELLOW "\n\n[%s] ('*' Width)", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, 15, str);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, 15, str);
	check(value1, value2);

	block = "%.*s";
	printf(YELLOW "\n\n[%s] ('*' Precision)", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, 15, str);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, 15, str);
	check(value1, value2);

	block = "%*.*s";
	printf(YELLOW "\n\n[%s] ('*' Precision and '*' Width both negative one)", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, -1, -1, str);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, -1, -1, str);
	check(value1, value2);

	block = "%*.*s";
	printf(YELLOW "\n\n[%s] ('*' Precision and '*' Width both zero)", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, 0, 0, str);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, 0, 0, str);
	check(value1, value2);

	printf(LBLUE "\n\n _  _");
	printf("\n| || |  ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░");
	printf("\n| || |_ ░░░░░░░░░░             ░░░░░░░░░░");
	printf("\n|__   _|▒▒▒▒▒▒▒▒▒▒ " WHITE " GET CRAZY " LBLUE " ▒▒▒▒▒▒▒▒▒▒");
	printf("\n   | |  ▓▓▓▓▓▓▓▓▓▓             ▓▓▓▓▓▓▓▓▓▓");
	printf("\n   |_|  █████████████████████████████████");
	printf(WHITE "\n\n\tTry any combination of flags and conversions");
	printf("\n\t¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯");

	block = "%020-.7s";
	printf(YELLOW "\n\n[%s] ", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, str);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, str);
	check(value1, value2);

	block = "%09.5s %-07.9p";
	printf(YELLOW "\n\n[%s] ", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, str, pointer);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, str, pointer);
	check(value1, value2);

	block = "%-7s %3.3i %5s";
	printf(YELLOW "\n\n[%s] ", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, str, a, str);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, str, a, str);
	check(value1, value2);

	block = "%-7x %3.3i";
	printf(YELLOW "\n\n[%s] ", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, a, a);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, a, a);
	check(value1, value2);

	block = "%% %X %10.015i %07%";
	printf(YELLOW "\n\n[%s] ", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, a, a);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, a, a);
	check(value1, value2);

	block = "%% %5% %-5% %05% %-05%";
	printf(YELLOW "\n\n[%s] ", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf("%% %5% %-5% %05% %-05%");
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf("%% %5% %-5% %05% %-05%");
	check(value1, value2);

	block = "%s %32s %2s %-32s ";
	printf(YELLOW "\n\n[%s] (NULL strings)", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, NULL, NULL, NULL, NULL);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, NULL, NULL, NULL, NULL);
	check(value1, value2);

	block = "%.0i%.i%5.0i%5.i%-5.0i%-5.i";
	printf(YELLOW "\n\n[%s] (Zero precision and zero value)", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, 0, 0, 0, 0, 0, 0);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, 0, 0, 0, 0, 0, 0);
	check(value1, value2);

	block = "%u";
	printf(YELLOW "\n\n[%s] (Unsigned Int Maximun value))", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, uintmax);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, uintmax);
	check(value1, value2);

	block = "%x %X";
	printf(YELLOW "\n\n[%s] (Zero value)", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, 0, 0);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, 0, 0);
	check(value1, value2);

	block = "%.0x %.X %5.0x %5.X %-5.0x %-5.X";
	printf(YELLOW "\n\n[%s] (Zero precision and zero value)", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, 0, 0, 0, 0, 0, 0);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, 0, 0, 0, 0, 0, 0);
	check(value1, value2);

	block = "%.p %5.p %2.p %.0p";
	printf(YELLOW "\n\n[%s] (Zero precision and zero/NULL value)", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, NULL, NULL, NULL, 0);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, NULL, NULL, NULL, 0);
	check(value1, value2);

	block = "%0*i %0*i %*i";
	printf(YELLOW "\n\n[%s] (Different '*' combinations)", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, 7, -54, -7, -54, -14, 94827);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, 7, -54, -7, -54, -14, 94827);
	check(value1, value2);

	block = "%*s %-*s %-*.*s";
	printf(YELLOW "\n\n[%s] (Different '*' combinations)", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, -32, str, -32, str, -7, -3, str);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, -32, str, -32, str, -7, -3, str);
	check(value1, value2);

	block = "%% *.5i 42 == |%*.5i|";
	printf(YELLOW "\n\n[%s]", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, 4, 42);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, 4, 42);
	check(value1, value2);

	block = "%.*i %.*i %.*i";
	printf(YELLOW "\n\n[%s] (Negative precision '*')", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, -3, 123, -1, 123, -1, 0);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, -3, 123, -1, 123, -1, 0);
	check(value1, value2);

	printf(WHITE "\n\n\tCheck what happens with duplicate flags");
	printf("\n\t¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯");

	block = "%--5d";
	printf(YELLOW "\n\n[%s] ", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, b);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, b);
	check(value1, value2);

	block = "%10.15.5s";
	printf(YELLOW "\n\n[%s] ", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, str);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, str);
	check(value1, value2);

	block = "%015.005u";
	printf(YELLOW "\n\n[%s] ", block);
	printf(LBLUE "\nft_printf" WHITE BG "\n");
	value1  = ft_printf(block, u);
	printf(RESET BLUE "\nprintf" WHITE BG "\n");
	value2  = printf(block, u);
	check(value1, value2);

	// printf(RESET "\n");
	// system ("leaks a.out");

}
