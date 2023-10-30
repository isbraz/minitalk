/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:57:09 by isbraz-d          #+#    #+#             */
/*   Updated: 2023/08/30 16:07:24 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_convert_bin_to_number(char *str)
{
	int		i;
	int		j;
	int		n;
	char	*aux;

	n = 0;
	j = 0;
	aux = str;
	i = ft_strlen(aux);
	while (j < i)
	{
		n = (n * 2) + (aux[j] - '0');
		j++;
	}
	return (n);
}

void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static char	str[9];
	static int	i;
	int			b;
	char		c;
	int			sp;

	(void)context;
	sp = info->si_pid;
	if (!str[0])
		i = 0;
	if (sig == 10)
		str[i++] = '1';
	else
		str[i++] = '0';
	if (i == 8)
	{
		str[i] = '\0';
		b = ft_convert_bin_to_number(str);
		c = (char)b;
		i = 0;
		write(1, &c, 1);
		kill(sp, SIGUSR1);
	}
}

int	main(void)
{
	struct sigaction	sa;
	int					p;
	char				*sp;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	p = getpid();
	sp = ft_itoa(p);
	write(1, "pid:", 4);
	write(1, sp, ft_strlen(sp));
	write(1, "\n waiting for message...\n", 25);
	while (1)
	{
		sleep(1);
	}
	return (0);
}
