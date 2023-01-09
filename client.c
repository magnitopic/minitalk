/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:59:51 by alaparic          #+#    #+#             */
/*   Updated: 2023/01/09 17:32:17 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "./libft/libft.h"

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
			usleep(250);
		}
		str++;
		i = 0;
		usleep(250);
	}
	ft_printf("\033[0;32mMessage Sent 📨\n");
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (1);
	send_binary(ft_atoi(argv[1]), argv[2]);
	return (0);
}
