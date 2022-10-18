#include <stdio.h>
#include <string.h>
//#include <bsd/string.h>
#include <stdlib.h>
#include <ctype.h>
// #include "../srcs_eval/libft.h"
// #include "../libft_mains.h"

// Prototype
//char *ft_strjoin(char const *s1, char const *s2);
/*

*/

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin4(char const *s1, char const *s2)
{
	char	*pt;
	int		len;

	if (!s1)
		return ((char*)s2);
	if (!s2)
		return ((char*)s1);
	len = ft_strlen(s1) + ft_strlen(s2);
	pt = malloc((len + 1) * sizeof(char));
	if (!pt)
		return (NULL);
	while (*s1)
	{
		*pt = *s1;
		pt++;
		s1++;
	}
	while (*s2)
	{
		*pt = *s2;
		pt++;
		s2++;
	}
	*pt = '\0';
	return (pt - len);
}

char *ft_strjoin(char const *s1, char const *s2)
{
	char *pt;
	int len;

	if (!s1)
		return ((char*)s2);
	if (!s2)
		return ((char*)s1);
	len = ft_strlen(s1) + ft_strlen(s2);
	pt = malloc((len + 1) * sizeof(char));
	if (!pt)
		return (NULL);
	while (*s1)
		*pt++ = *s1++;
	while (*s2)
		*pt++ = *s2++;
	*pt = '\0';
	return (pt - len);
}

char *ft_strjoin_orig(char const *s1, char const *s2)
{
	char *pt;
	int len;

	if (!s1)
		return ((char*)s2);
	if (!s2)
		return ((char*)s1);
	len = ft_strlen(s1) + ft_strlen(s2);
	pt = malloc((len + 1) * sizeof(char));
	if (!pt)
		return (NULL);
	while (*s1)
		*pt++ = *s1++;
	while (*s2)
		*pt++ = *s2++;
	*pt = '\0';
	return (pt - len);
}


#include "colors.h"
int main(void) 
{
	printf(HYEL"\n------------------------------------------------------------");
	printf("\n--- FT_STRJOIN ---------------------------------------------\n\n"RES);

	char *str1a = "abcd";
	char *str1b = "EFGH";
	printf(MAG"TEST 01    \"%s\"  +  \"%s\"\n"RES, str1a, str1b);
   	printf("  orig: %s\n", 	   ft_strjoin_orig(str1a, str1b));   
	printf("  mine: %s\n\n",   ft_strjoin(str1a, str1b));      
    
	char *str2a = "";
	char *str2b = "EFGH";
	printf(MAG"TEST 02    \"%s\"  +  \"%s\"\n"RES, str2a, str2b);
   	printf("  orig: %s\n", 	  ft_strjoin_orig(str2a, str2b));   
	printf("  mine: %s\n\n",   ft_strjoin(str2a, str2b));

	char *str3a = "abcd";
	char *str3b = "";
	printf(MAG"TEST 03    \"%s\"  +  \"%s\"\n"RES, str3a, str3b);
   	printf("  orig: %s\n", 	  ft_strjoin_orig(str3a, str3b));   
	printf("  mine: %s\n\n",   ft_strjoin(str3a, str3b));

	char *str4a = "abcd";
	char *str4b = NULL;
	printf(MAG"TEST 04    \"%s\"  +  \"%s\"\n"RES, str4a, str4b);
   	printf("  orig: %s\n", 	  ft_strjoin_orig(str4a, str4b));   
	printf("  mine: %s\n\n",   ft_strjoin(str4a, str4b));

	char *str5a = NULL;
	char *str5b = "EFGH";
	printf(MAG"TEST 05    \"%s\"  +  \"%s\"\n"RES, str5a, str5b);
   	printf("  orig: %s\n", 	  ft_strjoin_orig(str5a, str5b));   
	printf("  mine: %s\n\n",   ft_strjoin(str5a, str5b));

    return(0);
}

