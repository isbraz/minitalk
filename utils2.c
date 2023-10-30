/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:27:46 by isbraz-d          #+#    #+#             */
/*   Updated: 2023/07/12 14:32:44 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static long	ft_count_dig(long n)
{
	long	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	ft_reverse_string(char *s1, int size)
{
	int	i;
	int	f;
	int	aux;

	i = 0;
	f = size / 2;
	if (s1[0] == '-')
	{
		i = 1;
		f = (size / 2) + 1;
	}
	while (i < f)
	{
		aux = s1[i];
		s1[i] = s1[size - 1];
		s1[size - 1] = aux;
		i++;
		size--;
	}
}

static void	ft_is_neg(long n, char *str)
{
	long	i;
	long	digit;

	i = 1;
	n = n * -1;
	str[0] = '-';
	while (n > 0)
	{
		digit = n % 10;
		str[i] = digit + 48;
		n /= 10;
		i++;
	}
	str[i] = '\0';
	ft_reverse_string(str, i);
}

static void	ft_is_pos(long n, char *str)
{
	long	i;
	long	digit;

	i = 0;
	if (n == 0)
	{
		str[i] = 48;
		i++;
	}
	while (n > 0)
	{
		digit = n % 10;
		str[i] = digit + 48;
		n /= 10;
		i++;
	}
	str[i] = '\0';
	ft_reverse_string(str, i);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	number;
	long	i;

	number = n;
	i = ft_count_dig(number);
	str = (char *)malloc(sizeof(char) * i + 1);
	if (str == NULL)
		return (NULL);
	else if (n < 0)
		ft_is_neg(number, str);
	else if (n >= 0)
		ft_is_pos(number, str);
	return (str);
}
