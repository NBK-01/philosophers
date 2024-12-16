#include "../../includes/main.h"
#include <stdint.h>

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

void	print_action(int time, uint8_t id, t_action action)
{
	if (action == SLEEP)
		printf("%s[%d] ---- %s%sphilo [%d] is sleeping 💤 %s\n",
				CYAN, time, RESET, YELLOW, id, RESET);
	if (action == THINK)
		printf("%s[%d] ---- %s%sphilo [%d] is thinking 🤔 %s\n",
				CYAN, time, RESET, YELLOW, id, RESET);
	if (action == EAT)
		printf("%s[%d] ---- %s%sphilo [%d] is eating 🍝 %s\n",
				CYAN, time, RESET, GREEN, id, RESET);
	if (action == EAT)
		printf("%s[%d] ---- %s%sphilo [%d] is taking a fork 🍽️ %s\n",
				CYAN, time, RESET, BLUE , id, RESET);
	if (action == DIE)
		printf("%s[%d] ---- %s%sphilo [%d] is dead ☠️  %s\n",
				CYAN, time, RESET, RED, id, RESET);
}

void	print_final(t_routine *routine)
{
	int column_width = 18;

	printf("\n");
	printf("%-*s | %-*s | %-*s\n", column_width, "Philo 1", column_width, "Philo 2", column_width, "Philo 3");
	printf("%-*c | %-*c | %-*c\n", column_width, '-', column_width, '-', column_width, '-');
	printf("%-*u | %-*u | %.*s\n", column_width, routine->philos->times_ate, column_width, routine->philos->times_ate, column_width, "Died");
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

