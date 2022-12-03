/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:59:51 by alaparic          #+#    #+#             */
/*   Updated: 2022/12/03 23:25:35 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "libft/libft.h"

void	send_binary(char c, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & (1 << i++))
		{
			kill(pid, SIGUSR1);
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
		send_binary(*message++, ft_atoi(argv[1]));
	}
	return (0);
}
