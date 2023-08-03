/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:37:03 by switt             #+#    #+#             */
/*   Updated: 2023/08/03 22:29:33 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**ft_free(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static int	countwords(char const *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] != '\0' && str[i] != c)
				i++;
		}
		else
		{
			i++;
		}
	}
	return (count);
}

static char	*word(char const *str, int index, char c)
{
	char	*w;
	int		i;
	int		len;
	int		j;

	i = index;
	len = 0;
	j = 0;
	while (str[i] != c && str[i] != '\0')
	{
		len++;
		i++;
	}
	w = (char *)malloc((len + 1) * sizeof(char));
	if (!w)
		return (NULL);
	while (str[index] != c && str[index] != '\0')
	{
		w[j] = str[index];
		j++;
		index++;
	}
	w[j] = '\0';
	return (w);
}

char	**ft_split(char const *str, char c)
{
	char	**split;
	int		i;
	int		j;

	i = 0;
	j = 0;
	split = (char **)malloc((countwords(str, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			split[j] = word(str, i, c);
			if (!split[j])
				return (ft_free(split));
			j ++;
			while (str[i] != '\0' && str[i] != c)
				i++;
		}
		else
			i++;
	}
	split[j] = NULL;
	return (split);
}
