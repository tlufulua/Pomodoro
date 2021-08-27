#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"

int	cronom(int minutes)
{
	int	time;
	int min;
	int sec;

	time = minutes * 60;
	min = minutes;
	sec = 0;
	while (time > 0)
	{
		ft_printf("\r%.2d:%.2d", min--, sec);
		sec = 59;
		time--;
		sleep(1);
		while (sec > 0)
		{
			ft_printf("\r%.2d:%.2d", min, sec--);
			sleep(1);
			time--;
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	repeats;

	system("clear");
	repeats = argc == 4 ? ft_atoi(argv[3]) : 10;
	if (argc <= 1)
	{
		ft_printf("\x1b[31mWrong arguments\x1b[0m\n");
		return (0);
	}
	while (repeats)
	{
		ft_printf("\n\x1b[33mWork time\x1b[0m\n");
		repeats -= cronom(ft_atoi(argv[1]));
		system("clear");
		ft_printf("\n\x1b[34mRest time\x1b[0m\n");
		cronom(ft_atoi(argv[2]));
	}
	system("clear");
	ft_printf("\n\x1b[32mYou complete %i repeats\x1b[0m\n", repeats);
	return (0);
}
