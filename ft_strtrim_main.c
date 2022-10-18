/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim_main.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 11:01:51 by jmurovec      #+#    #+#                 */
/*   Updated: 2022/10/18 11:06:40 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
//#include <bsd/string.h>
#include <stdlib.h>
// #include "../srcs_eval/libft.h"
// #include "../libft_mains.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}


char *ft_strchr(const char *s, int c)
{
	int i;
	char *str;

	str = (char*)s;  // TREBA CAST V POMOZNO VARIABLO
	i = 0;
	while (str[i] != '\0') // get length i
		i++;
	if (c == '\0')
		return (str + i);  // return the end of this string
	while (*str)
	{
		if (c == *str)
			return (str);
		str++;
	}
	return (NULL);
}


char	*ft_substr(char const *s, unsigned int start, size_t n)
{
	char	*pt;
	size_t	i;

	if (!s)
		return (NULL);
	if (n > ft_strlen(s))
		n = ft_strlen(s);
	pt = malloc((n + 1) * sizeof(char));
	if (!pt)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		pt[0] = '\0';
		return (pt);
	}
	i = 0;
	while (i < n && s[start] != '\0')
	{
		pt[i] = s[start];
		i++;
		start++;
	}
	pt[i] = '\0';
	return (pt);
}



char	*ft_strtrim_orig(char const *str, char const *set)
{
	int		len;
	char	*trimmedstr;

	if (!str)
		return (NULL);
	if (!set)
		return ((char*)str);
	while (*str && ft_strchr(set, *str))
		str++;
	len = ft_strlen(str);
	while (len && ft_strchr(set, str[len]))
		len--;
	trimmedstr = ft_substr(str, 0, len + 1);
	return (trimmedstr);
}


char	*ft_strtrim(char const *str, char const *set)
{
	int		len;
	char	*trimmedstr;

	if (!str)
		return (NULL);
	if (!set)
		return ((char*)str);
	while (*str && ft_strchr(set, *str))
		str++;
	len = ft_strlen(str);
	while (len && ft_strchr(set, str[len]))
		len--;
	trimmedstr = ft_substr(str, 0, len + 1);
	return (trimmedstr);
}


#include "colors.h"
int main(void)
{
	printf(HYEL"\n\n\n------------------------------------------------------------");
	printf("\n--- FT_STRTRIM -------------------------------------------------\n\n"RES);

{
	printf(MAG"TEST 01    str: ---+++abcdef---+++    set: +-\n"RES);
	char *str1 = "---+++abcdef---+++";
	char *set1 = "-+"; 
	printf("   clone: %s\n",      ft_strtrim_orig(str1, set1));
	printf("    mine: %s\n\n",    ft_strtrim(str1, set1));
}
{
	printf(MAG"TEST 02    str: ---+++abcdef---+++    set: -+\n"RES);
	char *str1 = "---+++abcdef---+++";
	char *set1 = "-+"; 
	printf("   clone: %s\n",      ft_strtrim_orig(str1, set1));
	printf("    mine: %s\n\n",    ft_strtrim(str1, set1));
}
{
	printf(MAG"TEST 03    str: ---+++abcdef---+++    set: \"\"\n"RES);
	char *str1 = "---+++abcdef---+++";
	char *set1 = ""; 
	printf("   clone: %s\n",      ft_strtrim_orig(str1, set1));
	printf("    mine: %s\n\n",    ft_strtrim(str1, set1));
}
{
	printf(MAG"TEST 04    str: ---+++abcdef---+++    set: NULL\n"RES);
	char *str1 = "---+++abcdef---+++";
	char *set1 = NULL; 
	printf("   clone: %s\n",      ft_strtrim_orig(str1, set1));
	printf("    mine: %s\n\n",    ft_strtrim(str1, set1));
}
{
	printf(MAG"TEST 05    str: \"\"    set: +-\n"RES);
	char *str1 = "";
	char *set1 = "+-"; 
	printf("   clone: %s\n",      ft_strtrim_orig(str1, set1));
	printf("    mine: %s\n\n",    ft_strtrim(str1, set1));
	return 0;
}
}