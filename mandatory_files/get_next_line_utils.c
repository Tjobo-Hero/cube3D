/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: tim <tim@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/18 13:28:17 by tim           #+#    #+#                 */
/*   Updated: 2020/04/26 20:20:02 by vancitters    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

char			*ft_strdup(const char *src)
{
	int			i;
	char		*copy;
	int			len;

	len = 0;
	i = 0;
	if (!src)
		copy = (char*)src;
	while (src[i] != '\0')
	{
		i++;
		len++;
	}
	copy = (char *)malloc(sizeof(*src) * (len + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char			*ft_strchr(const char *str, int c)
{
	char *ptr;

	ptr = (char *)str;
	while (*ptr != c)
	{
		if (!*ptr)
			return (0);
		ptr++;
	}
	return (ptr);
}

static int		ft_len(char *s1, char *s2)
{
	int		len1;
	int		len2;
	int		res;

	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	res = len1 + len2 + 1;
	return (res);
}

char			*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*newstr;
	int		i;
	int		i2;

	if (!s1 || !s2 || (!s1 && !s2))
		return (0);
	newstr = (char *)malloc(sizeof(char *) * (ft_len((char *)s1, (char *)s2)));
	if (!newstr)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		newstr[i] = s1[i];
		i++;
	}
	i2 = 0;
	while (s2[i2] != '\0')
	{
		newstr[i] = s2[i2];
		i++;
		i2++;
	}
	newstr[i] = '\0';
	return (newstr);
}

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;

	if (!dst && !src)
		return (dst);
	if (src < dst)
	{
		i = len;
		while (i > 0)
		{
			i--;
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}
