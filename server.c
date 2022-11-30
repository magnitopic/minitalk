/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:18:37 by alaparic          #+#    #+#             */
/*   Updated: 2022/11/30 17:37:28 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	sig_handler(int signum)
{
	printf("Do a thing\n");
}

int	main(void)
{
	printf("%d\n", getpid()); //TODO: change printf to ft_printf
	while (1)
		signal(SIGUSR1, sig_handler);
	return (0);
}
