/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:22:04 by alaparic          #+#    #+#             */
/*   Updated: 2022/12/24 18:35:00 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

static void	ft_handler(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("Message recived by server👍\n");
	exit(0);
}

static void	send_binary(int pid, char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		while (i < 8)
		{
			if (*str & (1 << i++))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
		}
		str++;
		i = 0;
	}
	ft_printf("Message Sent 📨\n");
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (1);
	signal(SIGUSR1, ft_handler);
	send_binary(ft_atoi(argv[1]), argv[2]);
	sleep(10);
	ft_printf("No response from server ❌\n");
	return (0);
}
