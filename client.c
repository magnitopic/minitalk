/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:59:51 by alaparic          #+#    #+#             */
/*   Updated: 2022/12/10 14:25:59 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

static void	send_binary(int pid, char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		while (i < 8)
		{
			if (*str & (1 << i++))
			{
				kill(pid, SIGUSR1);
				ft_printf("1");
			}
			else
			{
				kill(pid, SIGUSR2);
				ft_printf("0");
			}
			usleep(50);
		}
		str++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (1);
	send_binary(ft_atoi(argv[1]), argv[2]);
	return (0);
}
