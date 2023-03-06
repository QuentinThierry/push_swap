/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 22:29:27 by qthierry          #+#    #+#             */
/*   Updated: 2023/03/02 23:37:44 by qthierry         ###   ########.fr       */
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

int	ft_atoi_sec(const char *nptr, int *error)
{
	long	res;
	int		sign;
	size_t	i;

	res = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (!ft_isdigit(*nptr))
	{
		if (*nptr == '-')
			sign = -1;
		else if (*nptr != '+')
			return (*error = 1, -1);
		nptr++;
	}
	if (!*nptr)
		return (*error = 1, -1);
	i = 0;
	while (*nptr == '0')
		nptr++;
	while (ft_isdigit(*nptr) && ++i)
		res = res * 10 + *nptr++ - '0';
	return (*error = ((i > 10) || (res * sign > 2147483647) || 
			(res *sign  < -2147483648) || (*nptr)), res * sign);
}

// int	ft_atoi_sec(const char *nptr, int *error)
// {
// 	long	res;
// 	int		sign;
// 	size_t	i;

// 	res = 0;
// 	sign = 1;
// 	*error = 1;
// 	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
// 		nptr++;
// 	if (*nptr == '-' && nptr++)
// 		sign = -1;
// 	else if (*nptr == '+')
// 		nptr++;
// 	i = 0;
// 	while (*nptr == '0' && i++)
// 		nptr++;
// 	while (ft_isdigit(*nptr) && ++i)
// 	{
// 		res = res * 10 + *nptr++ - '0';
// 		error = 0;
// 	}
// 	if (*nptr)
// 		return (*error = 1, -1);
// 	printf("i : %ld\n", i);
// 	return (*error += (i > 10), res * sign);
// }

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

int	has_duplicated_elem(t_stack *head)
{
	t_stack *iter;
	t_stack *iter2;

	iter = head->next;
	while (iter != head)
	{
		iter2 = iter->prev;
		while (iter2 != head->prev)
		{
			if (iter2->value == iter->value)
				return (1);
			iter2 = iter2->prev;
		}
		iter = iter->next;
	}
	return (0);
}
