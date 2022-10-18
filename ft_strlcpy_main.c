/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy_main.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 11:29:19 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/17 10:06:49 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>

/*	STRLCPY

	Copies n size of source into buffer destination
	Buffer must be big enough
	Returns always the whole lenght of source

*/

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}


size_t ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t len;

	if (!src || !dest)
		return (0);
	len = ft_strlen(src);
	i = 0;
	if (size <= 0)
		return (len);
	while (*src != '\0' && i < size - 1)
	{
		*dest = *src;
		dest++;
		src++;
		i++;	
	}
	*dest = '\0';
	return (len);
}


#include "colors.h"
int main(void)
{

	printf(HYEL"\n------------------------------------------------------------");
	printf("\n--- FT_STRLCPY ---------------------------------------------\n\n"RES);
	
	{
		printf(MAG"Test 00\n"RES);
		char size       = 0;
		char *src       = "ACBDE";
		char destA[20]  = "abcd..efgh..ijkl";
		char destB[20]  = "abcd..efgh..ijkl";

		printf("dest: %s, src: %s, size: %d\n", destA, src, size);
		printf(HWHT"   orig: return %lu,   dest: [%s] \n"RES,        strlcpy(destA, src, size), destA);
		printf(HWHT"   mine: return %lu,   dest: [%s] \n\n\n"RES, ft_strlcpy(destB, src, size), destB);
	}

	{
		printf(MAG"Test 01\n"RES);
		char size       = 1;
		char *src       = "ACBDE";
		char destA[20]  = "abcd..efgh..ijkl";
		char destB[20]  = "abcd..efgh..ijkl";

		printf("dest: %s, src: %s, size: %d\n", destA, src, size);
		printf(HWHT"   orig: return %lu,   dest: [%s] \n"RES,        strlcpy(destA, src, size), destA);
		printf(HWHT"   mine: return %lu,   dest: [%s] \n\n\n"RES, ft_strlcpy(destB, src, size), destB);
	}

	{
		printf(MAG"Test 02\n"RES);
		char size       = 2;
		char *src       = "ACBDE";
		char destA[20]  = "abcd..efgh..ijkl";
		char destB[20]  = "abcd..efgh..ijkl";

		printf("dest: %s, src: %s, size: %d\n", destA, src, size);
		printf(HWHT"   orig: return %lu,   dest: [%s] \n"RES,        strlcpy(destA, src, size), destA);
		printf(HWHT"   mine: return %lu,   dest: [%s] \n\n\n"RES, ft_strlcpy(destB, src, size), destB);
	}

	{
		printf(MAG"Test 03\n"RES);
		char size       = 5;
		char *src       = "ACBDE";
		char destA[20]  = "abcd..efgh..ijkl";
		char destB[20]  = "abcd..efgh..ijkl";

		printf("dest: %s, src: %s, size: %d\n", destA, src, size);
		printf(HWHT"   orig: return %lu,   dest: [%s] \n"RES,        strlcpy(destA, src, size), destA);
		printf(HWHT"   mine: return %lu,   dest: [%s] \n\n\n"RES, ft_strlcpy(destB, src, size), destB);
	}

	{
		printf(MAG"Test 04\n"RES);
		char size       = 6;
		char  *src     = "ACBDE";
		char destA[20]  = "abcd..efgh..ijkl";
		char destB[20]  = "abcd..efgh..ijkl";

		printf("dest: %s, src: %s, size: %d\n", destA, src, size);
		printf(HWHT"   orig: return %lu,   dest: [%s] \n"RES,        strlcpy(destA, src, size), destA);
		printf(HWHT"   mine: return %lu,   dest: [%s] \n\n\n"RES, ft_strlcpy(destB, src, size), destB);
	}

}







/*	LITTLE TEST
void test(int size)
{
    char string[] = "abcd..efgh..ijkl"; // 16
    char buffer[20] = {};
    int ret;

    ret = ft_strlcpy(buffer, string, size);

    printf("Size %4d,   Copied [%s]    into buff: [%s]    length %d\n",
            size, string, buffer, ret );
}

int main()
{
    test(0);
    test(1);
    test(2);
    test(10);
    test(20);

    return(0);
}
*/