/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:18:37 by alaparic          #+#    #+#             */
/*   Updated: 2022/11/22 13:00:11 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void sig_handler_parent(int signum){
	printf("Parent : Received a response signal from child \n");
}

void sig_handler_child(int signum){
	printf("Child : Received a signal from parent \n");
	sleep(1);
	kill(getppid(),SIGUSR1);
}

int	main(void)
{
	pid_t	pid;

	if((pid=fork())<0)
	{
		printf("Fork Failed\n");
		exit(1);
	}
	printf("%i",pid);
	if(pid==0)
	{
		signal(SIGUSR1,sig_handler_child);
		printf("Child: waiting for signal\n");
		pause();
	}
	else
	{
		signal(SIGUSR1,sig_handler_parent);
		sleep(1);
		printf("Parent: sending signal to Child\n");
		kill(pid,SIGUSR1);
		printf("Parent: waiting for response\n");
		pause();
	}
	return (0);
}