/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 22:29:27 by qthierry          #+#    #+#             */
/*   Updated: 2022/12/30 16:39:42 by qthierry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

int	equals(char	*s1, char *s2)
{
	size_t	i;

	i = 0;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (!ft_isdigit(*nptr))
	{
		if (*nptr == '-')
			sign = -1;
		else if (*nptr != '+')
			return (-2147483648);
		nptr++;
	}
	while (ft_isdigit(*nptr))
		res = res * 10 + *nptr++ - '0';
	if (*nptr)
		return (-2147483648);
	return (res * sign);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

size_t	ft_strlen(const char *s)
{
	const char	*cpy;

	cpy = s;
	while (*s)
		s++;
	return (s - cpy);
}

int	has_duplicated_elem(char **string)
{
	int	i;
	int	j;

	i = 0;
	while (string[i])
	{
		j = i + 1;
		while (string[j])
		{
			if (equals(string[j], string[i]))
			{
				write(1, "Error\n", 6);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
