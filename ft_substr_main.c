/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr_main.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 10:51:13 by jmurovec      #+#    #+#                 */
/*   Updated: 2022/10/18 10:51:54 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
//#include <bsd/string.h>
#include <stdlib.h>
#include <ctype.h>
// #include "../srcs_eval/libft.h"
// #include "../libft_mains.h"


// SUBSTR - THERE IS NO ORIGINAL ???

// Prototype
//char *ft_substr(char const *s, unsigned int start, size_t len);

/*

Returns a chunk (substring) of the original string

- Check if string exists
- put \0 at the end of returning string
- do we need to check that length does not go over the end of original string?
   - i discovered that in this case it's correct if i return pointer pt[0] = '\0'


ERRORS:
Test 05 gives error, it is weird, something with 400 bytes and a word Bullshit

*/


size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

// SIMILAR TO SUBSTR:
char	*ft_strnstr_comparison(const char *hay, const char *needle, size_t size)
{
	const char	*h;
	const char	*n;
	size_t		s;

	if (*needle == '\0')
		return (char*)(hay);
	while (*hay != '\0' && size > 0)
	{
		h = hay;
		n = needle;
		s = size;
		while (*n != '\0' && *h == *n && s > 0)
		{
			h++;
			n++;
			s--;
		}
		if (*n == '\0')
			return (char*)(hay);
		hay++;
		size--;
	}
	return (0);
}


/// CLONE /////
char	*ft_substr_orig(char const *s, unsigned int start, size_t n)
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





// VAJA PONAVLJANJE SUBSTR ////////////////////////////////



#include "colors.h"
int main(void) 
{	
	printf(HYEL"\n-----------------------------------------------------------");
	printf("\n--- FT_SUBSTR ---------------------------------------------\n\n"RES);

	char *str1 = "lorem ipsum dolor sit amet";

	printf(MAG"TEST STRING \"lorem ipsum dolor sit amet\"\n\n"RES);
	printf(MAG"                        start    len\n"RES);
	printf(MAG"Test 01    substr(str1,   0,     10)\n"RES);
	//printf("  orig: %s\n",         substr(str1, 0, 10));
   	printf("  clone: %s\n",    ft_substr_orig(str1, 0, 10));   
 	printf("   mine: %s\n\n",  ft_substr(str1, 0, 10));  

	printf(MAG"Test 02   substr(str1, 7, 10)\n"RES);
	//printf("  clone: %s\n", substr(str1, 7, 10));
   	printf("  clone: %s\n",     ft_substr_orig(str1, 7, 10));   
 	printf("   mine: %s\n\n",   ft_substr(str1, 7, 10)); 

	printf(MAG"Test 03   substr(str1, 7, 0)\n"RES);
	//printf("  clone: %s\n", substr(str1, 7, 0));
   	printf("  clone: %s\n",     ft_substr_orig(str1, 7, 0));   
 	printf("   mine: %s\n\n",   ft_substr(str1, 7, 0));

	printf(MAG"Test 04   substr(str1, 0, 0)\n"RES);
	//printf("  clone: %s\n", substr(str1, 0, 0));
   	printf("  clone: %s\n",     ft_substr_orig(str1, 0, 0));   
 	printf("   mine: %s\n\n",   ft_substr(str1, 0, 0)); 

	printf(MAG"Test 05   substr(str1, 400, 20)\n"RES);
	//printf("  clone: %s\n", substr(str1, 400, 20));
   	printf("  clone: %s\n",     ft_substr_orig(str1, 400, 20));   
 	printf("   mine: %s\n\n",   ft_substr(str1, 400, 20)); 

	printf(MAG"Test 06   substr(str1, 0, 0)\n"RES);
	//printf("  clone: %s\n", substr(str1, 0, 0));
   	printf("  clone: %s\n",     ft_substr_orig(str1, 17, 20));   
 	printf("   mine: %s\n\n",   ft_substr(str1, 17, 20)); 

	printf(MAG"Test 07   substr(str1, 24, 5) (length is longer than substring from start to end)\n"RES);
	//printf("  clone: %s\n", substr(str1, 0, 0));
   	printf("  clone: %s\n",     ft_substr_orig(str1, 24, 5));   
 	printf("   mine: %s\n\n",   ft_substr(str1, 24, 5)); 

    return(0);
}
