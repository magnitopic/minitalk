/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:59:51 by alaparic          #+#    #+#             */
/*   Updated: 2022/11/30 17:40:19 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	send_binary(char c)
{
	
}

int	main(int argc, char **argv)
{
	char	*message;

	message = argv[2];
	while (*message)
	{
		send_binary(*message++);
	}
	//kill(ft_atoi(argv[1]), SIGUSR1);
	return (0);
}
