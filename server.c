/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:18:37 by alaparic          #+#    #+#             */
/*   Updated: 2022/12/03 23:24:17 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "libft/libft.h"

int	g_message = 0;

void	recive_one(int signum)
{
	g_message = (g_message * 10) + 1;
}

void	recive_cero(int signum)
{
	g_message *= 10;
}

int	main(void)
{
	ft_printf("%d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, recive_one);
		signal(SIGUSR2, recive_cero);
	}
	return (0);
}
