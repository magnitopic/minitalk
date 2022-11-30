/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:59:51 by alaparic          #+#    #+#             */
/*   Updated: 2022/11/30 13:26:55 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	sendBinary(int c)
{
	if (c == 0 || c == 1)
		return (c);
	else
	{
		return ((c % 2) + 10 * sendBinary(c / 2));
	}
}

int	main(int argc, char **argv)
{
	char	*message;
	char	*binary;

	message = argv[2];
	while (*message)
	{
		binary = ft_itoa(sendBinary(*message++));
		printf("%s", binary);
	}
	//kill(ft_atoi(argv[1]), SIGUSR1);
	return (0);
}
