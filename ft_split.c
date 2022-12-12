/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:28:16 by qthierry          #+#    #+#             */
/*   Updated: 2022/12/12 14:47:42 by qthierry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	free_all(char **string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		free(string[i]);
		i++;
	}
	free(string);
}

static int	count_words(const char *string, char c)
{
	int res;

	res = 0;
	while (*string)
	{
		while (*string == c)
			string++;
		if (!*string)
			break;
		while (*string && *string != c)
			string++;
		res++;
	}
	return (res);
}

static char	*get_word(const char **string, char c, int index)
{
	char	*res;
	int		size;
	int		i;

	size = 0;
	while (**string && **string == c)
		(*string)++;
	while ((*string)[size] && (*string)[size] != c)
		size++;
	res = malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < size)
	{
		res[i] = **string;
		(*string)++;
		i++;
	}
	res[i] = 0;
	return (res);
}

char	**ft_split(const char *string, char c)
{
	int		nb_words;
	int		i;
	char	**res;

	if (!string)
		return (NULL);
	nb_words = count_words(string, c);
	res = malloc(sizeof(char *) * (nb_words + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < nb_words)
	{
		res[i] = get_word(&string, c, i);
		if (!res[i])
			return (free_all(res), NULL);
		i++;
	}
	res[i] = NULL;
	return (res);
}
