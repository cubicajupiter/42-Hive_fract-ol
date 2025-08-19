/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:53:03 by jvalkama          #+#    #+#             */
/*   Updated: 2025/05/04 11:57:28 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	powers_of_ten(int n, int power)
{
	int		count;

	count = 0;
	while (n > 0)
	{
		n /= power;
		count++;
	}
	return (count);
}

static char	*ascifier(int n, int len, int sign, int int_min)
{
	char	digit;
	char	*string;
	int		i;

	string = malloc(len + 1);
	if (sign)
		string[0] = '-';
	if (n == 0)
		string[0] = '0';
	else
	{
		i = 1;
		while (n > 0)
		{
			digit = (n % 10) + '0';
			if (int_min && i == 1)
				digit += 1;
			string[len - i] = digit;
			n /= 10;
			i++;
		}
	}
	string[len] = '\0';
	return (string);
}

char	*ft_itoa(int n)
{
	int		len;
	int		sign;
	int		int_min;

	len = 0;
	sign = 0;
	int_min = 0;
	if (n == INT_MIN)
	{
		int_min = 1;
		n += 1;
	}
	if (n < 0)
	{
		len += 1;
		n *= -1;
		sign = 1;
	}
	if (n == 0)
		len = 1;
	else
		len += powers_of_ten(n, 10);
	return (ascifier(n, len, sign, int_min));
}
