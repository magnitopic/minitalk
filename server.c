/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:18:37 by alaparic          #+#    #+#             */
/*   Updated: 2022/12/05 16:38:23 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "libft/libft.h"

int	g_message = 0;

void	sig_handler(int signum)
{
	g_message = (g_message * 10) + 1;
	ft_printf("%d", 1);
}

void	sig_handler2(int signum)
{
	g_message *= 10;
	ft_printf("%d", 0);
}

int	main(void)
{
	ft_printf("%d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, sig_handler);
		signal(SIGUSR2, sig_handler2);
	}
	return (0);
}
