/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:18:37 by alaparic          #+#    #+#             */
/*   Updated: 2023/01/18 17:22:38 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

static void	ft_handler(int signum)
{
	static int	len = 0;
	static int	character = 0;

	if (signum == SIGUSR1)
		character |= (1 << len);
	len++;
	if (len == 8)
	{
		ft_putchar(character);
		character = 0;
		len = 0;
	}
}

int	main(void)
{
	ft_printf("Server Started.\nPID: %d\nWaiting for messages...\n", getpid());
	signal(SIGUSR1, ft_handler);
	signal(SIGUSR2, ft_handler);
	while (1)
		pause();
}
