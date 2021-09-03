#include "pomodoro.h"

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

void	final_msg(int i)
{
	int	x;
	int	x2;

	x = 0;
	x2 = 0;
	if (i < 60)
		ft_printf("\n\x1b[32mYou've been concentrate %.2d minutes\x1b[0m\n\n", i);
	else
	{
		x = i / 60;
		x2 = x;
		while (x2--)
			i -= 60;
		ft_printf("\n\x1b[32mYou've been concentrate %.2d hours and %.2d minutes\x1b[0m\n\n", x, i);
	}
	system(BELL_PATH);
}

int	main(int argc, char **argv)
{
	int	repeats;
	int i;
	int	stdy_time;
	int	rest_time;

	system("clear");
	i = 0;
	if (argc < 3)
	{
		ft_printf("\7\n\x1b[31mWrong arguments\n");
		ft_printf("Programm needs almost 2 numberic arguments\n\x1b[0m\n");
		return (0);
	}
	stdy_time = ft_atoi(argv[1]);
	rest_time = ft_atoi(argv[2]);
	repeats = argc == 4 ? ft_atoi(argv[3]) : 3;
	while (repeats && (stdy_time > 0 || rest_time > 0))
	{
		ft_printf("\n\x1b[33mWork time\x1b[0m\n");
		if (i)
			system(BELL_PATH);
		repeats -= cronom(stdy_time);
		i += stdy_time;
		system("clear");
		ft_printf("\n\x1b[34mRest time\x1b[0m\n");
		system(BELL_PATH);
		cronom(rest_time);
	}
	system("clear");
	if (i)
		final_msg(i);
	return (0);
}
