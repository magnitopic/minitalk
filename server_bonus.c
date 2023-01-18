/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:27:38 by alaparic          #+#    #+#             */
/*   Updated: 2023/01/18 17:22:55 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
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
		if (character == '\0')
			(kill(info->si_pid, SIGUSR2), ft_putchar('\n'));
		else
			kill(info->si_pid, SIGUSR1);
		ft_putchar(character);
		character = 0;
		len = 0;
	}
}

int	main(void)
{
	struct sigaction	sa1;
	struct sigaction	sa2;

	ft_printf("Server Started.\nPID: %d\nWaiting for messages...\n", getpid());
	sa1.sa_flags = SA_SIGINFO;
	sa1.sa_sigaction = ft_handler;
	sigaction(SIGUSR1, &sa1, NULL);
	sa2.sa_flags = SA_SIGINFO;
	sa2.sa_sigaction = ft_handler;
	sigaction(SIGUSR2, &sa2, NULL);
	while (1)
		pause();
}
