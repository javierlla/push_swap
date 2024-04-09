/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jllarena <jllarena@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:36:58 by jllarena          #+#    #+#             */
/*   Updated: 2024/04/08 16:37:00 by jllarena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	i;

	i = ft_strlen(s) + 1;
	str = (char *)malloc(sizeof(char) * i);
	if (!str)
		return (NULL);
	while (i--)
		str[i] = s[i];
	return (str);
}
/*
int	main(void)
{
	char	*s1;
	char	*s2;

	s1 = "test";
	s2 = ft_strdup(s1);
	printf("%s\n", s2);
	return (0);
}
*/
