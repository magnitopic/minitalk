/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:59:51 by alaparic          #+#    #+#             */
/*   Updated: 2022/12/02 16:15:40 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	send_binary(char c, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & (1 << i++))
		{
			kill(ft_atoi(), SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR1);
		}
	}
}

int	main(int argc, char **argv)
{
	char	*message;

	message = argv[2];
	while (*message)
	{
		send_binary(*message++, argv[1]);
	}
	return (0);
}
