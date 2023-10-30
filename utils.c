/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:58:22 by isbraz-d          #+#    #+#             */
/*   Updated: 2023/07/16 13:55:12 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_isspace(const char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

static int	ft_isnum(const char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

static int	ft_operator(const char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	n;
	int	n1;

	i = 0;
	n = 1;
	n1 = 0;
	while (nptr[i] && ((ft_isnum(nptr[i]) || ft_operator(nptr[i]))
			|| ft_isspace(nptr[i])))
	{
		if (ft_operator(nptr[i]) && !(ft_isnum(nptr[i + 1])))
			return (0);
		if (nptr[i] == '-')
			n *= -1;
		if (ft_isnum(nptr[i]))
		{
			n1 = (n1 * 10) + (nptr[i] - 48);
			if (!(ft_isnum(nptr[i + 1])))
				return (n1 * n);
		}
		i++;
	}
	return (0);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
