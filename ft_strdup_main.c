#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <bsd/string.h>
// #include "../srcs_eval/libft.h"
// #include "../libft_mains.h"

/*
char *strdup(const char *s1);

DESCRIPTION
     The strdup() function allocates sufficient memory for a copy of the string s1, 
	 does the copy, and returns a pointer to it.  
	 The pointer may subsequently be used as an argument to the function
     free(3).

     If insufficient memory is available, NULL is returned and errno is set to ENOMEM.
*/

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

#include "colors.h"
char *ft_strdup(const char *s1)
{
	int i;
	char *pt;

	i = 0;
	pt = malloc(ft_strlen(s1) * (sizeof(pt) + 1));
	if (pt == NULL)
		return (NULL);

	while (s1[i])
	{
		pt[i] = s1[i];
		i++;
	}
	pt[i] = '\0';


	return (pt);
}

int main(void) 
{
	printf(HYEL"\n------------------------------------------------------------");
	printf("\n--- FT_STRDUP ----------------------------------------------\n\n"RES);
	char *source = "this is\0 a normal test";

	printf(MAG"TEST 01\n"RES);
	printf("Source: this is\\0 a normal test\n");
    printf(HWHT"   orig:  %s\n",     strdup(source));
    printf("   mine:  %s\n\n"RES, ft_strdup(source));
  	return (0);
}
