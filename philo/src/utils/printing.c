#include "../../includes/main.h"

void	print_msg(char *msg, int type)
{
	if (type == ERROR)
		printf("%s------Error------\n%s\n\n%s", RED, msg, RESET);
	if (type == WARNING)
		printf("%s-----Warning-----\n%s\n\n%s", YELLOW, msg, RESET);
	if (type == SUCCESS)
		printf("%s-----------------\n%s\n%s", GREEN, msg, RESET);
	if (type == MSG)
		printf("%s-----Message-----\n%s\n\n%s", CYAN, msg, RESET);
}

void	print_final(t_philo *philo)
{
	(void)philo;
	int column_width = 18;

	printf("\n");
	printf("%-*s | %-*s | %-*s\n", column_width, "Philo 1", column_width, "Philo 2", column_width, "Philo 3");
	printf("%-*c | %-*c | %-*c\n", column_width, '-', column_width, '-', column_width, '-');
	printf("%-*s | %-*s | %.*s\n", column_width, "Ate 3 times", column_width, "Ate 3 times", column_width, "Died");
	printf("\n");
}

void print_art() 
{
	printf("%s.-------------------------------------------------", CYAN);
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
	printf("-----------------------------'\n%s", RESET);
}

