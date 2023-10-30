/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:57:01 by isbraz-d          #+#    #+#             */
/*   Updated: 2023/07/16 14:03:40 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_check;

void	signal_handler(int sig)
{
	g_check = sig;
}

int	ft_send_message(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		i--;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int	i;

	i = 0;
	g_check = 0;
	if (argc != 3)
		write(1, "error", 5);
	signal(SIGUSR1, signal_handler);
	while (argv[2][i])
	{
		ft_send_message((ft_atoi(argv[1])), argv[2][i]);
		i++;
	}
	if (g_check)
		write(1, "Message sent to server successfully!\n", 37);
	return (0);
}

// SIGUSR1 == 10  SIGUSR2 == 12