/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:22:04 by alaparic          #+#    #+#             */
/*   Updated: 2023/01/09 16:51:17 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include "libft/libft.h"

static void	ft_handler(int signum)
{
	if (signum == SIGUSR2)
	{
		ft_printf("\033[32mFull message recived ✅\n");
		exit(0);
	}
}

static void	send_binary(int pid, char character)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (character & (1 << i++))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(250);
	}
	usleep(250);
}

int	main(int argc, char **argv)
{
	char	*str;
	int		pid;

	if (argc != 3)
		return (1);
	str = argv[2];
	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, ft_handler);
	signal(SIGUSR2, ft_handler);
	while (*str)
		send_binary(pid, *str++);
	send_binary(pid, '\0');
	sleep(10);
	ft_printf("\033[31mNo response from server ❌\n");
	return (0);
}
