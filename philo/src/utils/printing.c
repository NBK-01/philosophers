/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkanaan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:47:19 by nkanaan           #+#    #+#             */
/*   Updated: 2024/07/24 16:47:23 by nkanaan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"


/*fun ascii printing funcs*/
int	print_error(char *str)
{
	print_red();
	printf("------Error------\n%s\n\n", str);
	return (0);
}

int	print_warning(char *str)
{
	print_yellow();
	printf("-----Warning-----\n%s\n\n", str);
	return (0);
}

int	print_random(char *str)
{
	print_cyan();
	printf("-----Message-----\n%s\n\n", str);
	return (0);
}

int	print_success(char *str)
{
	print_green();
	printf("-----------------\n%s\n", str);
	return (0);
}

void print_art() 
{
	print_cyan();
	printf(".-------------------------------------------------");
	printf("---------------.\n");
	printf("|                                            ");
	printf("			 |\n");
	printf("|    /$$$$$$$  /$$   /$$ /$$$$$$ /$$        ");
	printf("/$$$$$$   /$$$$$$    |\n");
	printf("|   | $$__  $$| $$  | $$|_  $$_/| $$       ");
	printf("/$$__  $$ /$$__  $$   |\n");
	printf("|   | $$  \\ $$| $$  | $$  | $$  | $$      ");
	printf("| $$  \\ $$| $$  \\__/   |\n");
	printf("|   | $$$$$$$/| $$$$$$$$  | $$  | $$      ");
	printf("| $$  | $$|  $$$$$$    |\n");
	printf("|   | $$____/ | $$__  $$  | $$  | $$      ");
	printf("| $$  | $$ \\____  $$   |\n");
	printf("|   | $$      | $$  | $$  | $$  | $$      ");
	printf("| $$  | $$ /$$  \\ $$   |\n");
	printf("|   | $$      | $$  | $$ /$$$$$$| $$$$$$");
	printf("$$|  $$$$$$/|  $$$$$$/   |\n");
	printf("|   |__/      |__/  |__/|______/|");
	printf("________/ \\______/  \\______/    |\n");
	printf("|                                                                |\n");
	printf("'-----------------------------------");
	printf("-----------------------------'\n");
}

