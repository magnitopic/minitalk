/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:59:51 by alaparic          #+#    #+#             */
/*   Updated: 2022/12/12 18:06:22 by alaparic         ###   ########.fr       */
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
			usleep(200);
		}
		str++;
		i = 0;
	}
	ft_printf("Message Sent");
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (1);
	send_binary(ft_atoi(argv[1]), argv[2]);
	return (0);
}
