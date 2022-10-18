/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat_main.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 11:08:30 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/17 09:59:23 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

#define HYEL "\e[0;93m"
#define MAG   "\x1B[35m"
#define RES "\x1B[0m"

/*
Prilepi source na konec dest[10] in doda \0. 
Obe skupaj sta dolgi najvec (odvisno):
	srclen + size   ALI   srclen + dstlen

	if  size < dest  => return: size + src
	if  size > dest  => return: src + dest
*/


size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t destlen;
	size_t i;

	destlen = ft_strlen(dest);
	//printf(" --- destlen: %ld,   last[%d]\n", destlen, dest[2]);
	if (size < ft_strlen(dest))
		destlen = size;
	i = 0;												// If size is smaller then dest, this will not happen
	while (src[i] != '\0' && size > destlen + i + 1)	// stop if \0 in source is found
	{													// stop if destlen + i becomes bigger than size 
		dest[destlen + i] = src[i];
		i++;
	}
	if (size > destlen + i)				// in this size is bigger than dest + source
		dest[destlen + i] = '\0';		// so needs to terminate after source
	return (destlen + ft_strlen(src));
}




#include "colors.h"
int main(void)
{
	printf("- Buffer (destination must be at lest 1 bigger than its string \n\n");

	printf(HYEL"\n------------------------------------------------------------");
	printf("\n--- FT_STRLCAT ---------------------------------------------\n\n"RES);

	{
		printf(MAG"Test 00:   size < destination			(returns length: size + source)\n"RES);
		int  size      = 0;
		char *str      = "ABCDE";
		char destA[20] = "abcd..efgh";
		char destB[20] = "abcd..efgh";

		printf("dest: \"%s\",   src: \"%s\",   size: %d \n", destA, str, size);
		printf("     orig:   returns %lu,    [%s] \n"RES,          strlcat(destB, str, size), destB);
		printf("     mine:   returns %lu,    [%s] \n\n\n"RES,   ft_strlcat(destB, str, size), destB);
	}

	{
		printf(MAG"Test 01:   size < destination			(returns length: size + source)\n"RES);
		int  size      = 3;
		char *str      = "ABCDE";
		char destA[20] = "abcd..efgh";
		char destB[20] = "abcd..efgh";

		printf("dest: \"%s\",   src: \"%s\",   size: %d \n", destA, str, size);
		printf("     mine:   returns %lu,    [%s] \n\n\n"RES,   ft_strlcat(destB, str, size), destB);
	}

	{
		printf(MAG"Test 02:   size == destination			(returns length: size + source)\n"RES);
		int  size      = 10;
		char *str      = "ABCDE";
		char destA[20] = "abcd..efgh";
		char destB[20] = "abcd..efgh";

		printf("dest: \"%s\",   src: \"%s\",   size: %d \n", destA, str, size);
		printf("     orig:   returns %lu,    [%s] \n"RES,          strlcat(destB, str, size), destB);
		printf("     mine:   returns %lu,    [%s] \n\n\n"RES,   ft_strlcat(destB, str, size), destB);
	}

	{
		printf(MAG"Test 03:   size > destination			(returns destLen + sourceLen)\n"RES);
		int  size      = 11;
		char *str      = "ABCDE";
		char destA[20] = "abcd..efgh";
		char destB[20] = "abcd..efgh";

		printf("dest: \"%s\",   src: \"%s\",   size: %d \n", destA, str, size);
		printf("     orig:   returns %lu,    [%s] \n"RES,          strlcat(destB, str, size), destB);
		printf("     mine:   returns %lu,    [%s] \n\n\n"RES,   ft_strlcat(destB, str, size), destB);
	}

	{
		printf(MAG"Test 04:   size > destination			(returns destLen + sourceLen)\n"RES);
		int  size      = 12;
		char *str      = "ABCDE";
		char destA[20] = "abcd..efgh";
		char destB[20] = "abcd..efgh";

		printf("dest: \"%s\",   src: \"%s\",   size: %d \n", destA, str, size);
		printf("     orig:   returns %lu,    [%s] \n"RES,          strlcat(destB, str, size), destB);
		printf("     mine:   returns %lu,    [%s] \n\n\n"RES,   ft_strlcat(destB, str, size), destB);
	}

	{
		printf(MAG"Test 04:   size > destination			(returns destLen + sourceLen)\n"RES);
		int  size       = 16;
		char *str      = "ABCDE";
		char destA[20] = "abcd..efgh";
		char destB[20] = "abcd..efgh";

		printf("dest: \"%s\",   src: \"%s\",   size: %d \n", destA, str, size);
		printf("     orig:   returns %lu,    [%s] \n"RES,          strlcat(destB, str, size), destB);
		printf("     mine:   returns %lu,    [%s] \n\n\n"RES,   ft_strlcat(destB, str, size), destB);
	}

	{
		printf(MAG"Test 05:   size > destination			(returns destLen + sourceLen)\n"RES);
		int  size       = 20;
		char *str      = "ABCDE";
		char destA[20] = "abcd..efgh";
		char destB[20] = "abcd..efgh";

		printf("dest: \"%s\",   src: \"%s\",   size: %d \n", destA, str, size);
		printf("     orig:   returns %lu,    [%s] \n"RES,          strlcat(destB, str, size), destB);
		printf("     mine:   returns %lu,    [%s] \n\n\n"RES,   ft_strlcat(destB, str, size), destB);
	}

	{
		printf(MAG"Test 06:   size < destLen + srcLen			(returns destLen + sourceLen)\n"RES);
		int  size       = 20;
		char *str      = "ABCDEFGHIJKLMNOPRSTUVZ";
		char destA[20] = "abcd..efgh";
		char destB[20] = "abcd..efgh";

		printf("dest: \"%s\",   src: \"%s\",   size: %d \n", destA, str, size);
		printf("     orig:   returns %lu,    [%s] \n"RES,          strlcat(destB, str, size), destB);
		printf("     mine:   returns %lu,    [%s] \n\n\n"RES,   ft_strlcat(destB, str, size), destB);
	}
}	
