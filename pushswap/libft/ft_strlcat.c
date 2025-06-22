/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 13:48:46 by amile-ge          #+#    #+#             */
/*   Updated: 2023/09/16 13:52:28 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	x;
	size_t	j;

	i = 0;
	j = 0;
	while (dest[i] && i < size)
		i++;
	while (src[j])
		j++;
	if (i >= size)
		return (i + j);
	x = i;
	while (src[x - i] && x < size - 1)
	{
		dest[x] = src[x - i];
		x++;
	}
	dest[x] = '\0';
	return (i + j);
}
/*
int main()
{
    char dest [] = "Ara";
    const char src[] = "celly";
    size_t size = 2;
    
    size_t j = ft_strlcat(dest, src, size);
    printf("%zu", j);
    printf("%s", dest);
    return(0);
}
*/
