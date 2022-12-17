/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:27:38 by alaparic          #+#    #+#             */
/*   Updated: 2022/12/16 20:37:45 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<signal.h>
#include "libft/libft.h"

static void	ft_handler(int signum, siginfo_t *info, void *context)
{
	static int	len = 0;
	static int	character = 0;

	(void)context;
	if (signum == SIGUSR1)
		character |= (1 << len);
	len++;
	if (len == 8)
	{
		ft_printf("%c", character);
		kill(info->si_pid, SIGUSR1);
		character = 0;
		len = 0;
	}
}

int	main(void)
{
	struct sigaction	sa1;
	
	ft_printf("Server Started.\nPID: %d\nWating for messages...\n", getpid());
	sa1.sa_flags = SA_SIGINFO;
	sa1.sa_sigaction = ft_handler;
	sigaction(SIGUSR1, &sa1, 0);
	while (1)
		pause();
}
