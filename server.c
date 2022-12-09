/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:18:37 by alaparic          #+#    #+#             */
/*   Updated: 2022/12/09 17:34:41 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "libft/libft.h"

int	g_message = 0;

static void	one(int signum)
{
	g_message = (g_message * 10) + 1;
	ft_printf("%d", 1);
}

static void	zero(int signum)
{
	g_message *= 10;
	ft_printf("%d", 0);
}

int	main(void)
{
	ft_printf("%d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, one);
		signal(SIGUSR2, zero);
	}
	return (0);
}
