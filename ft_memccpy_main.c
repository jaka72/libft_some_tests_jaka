/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy_main.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 13:39:41 by jmurovec      #+#    #+#                 */
/*   Updated: 2022/10/17 13:50:52 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
//#include <bsd/string.h> // not found on Mac
// #include "../srcs_eval/libft.h"
// #include "../libft_mains.h"


/*
The memccpy() function copies n bytes from string src to string dst.  
(c should be converted to an unsigned char).

If the character c occurs in the string src, the copy stops and a pointer 
to the byte after the copy of c in the string dst is returned. 

Otherwise, n  bytes are copied, and a NULL pointer is returned.


The source and destination strings should not overlap, as the behavior is undefined.

!!! n SHOULD NOT BE LARGER THAN sizeof(source), or it will abort.

#include <string.h>
  void *  memccpy(void *restrict dst, const void *restrict src, int c, size_t n);

*/
/*
 cat test03.output
	jjj
	zyxwvutsrqponmlkjihgfedcbajjja
 cat user_output_test03
	zyxwvutsrqponmlkjihgfedcbajjj
	zyxwvutsrqponmlkjihgfedcbajjjj
*/



void	*ft_memccpy(void *dest, const void *src, int c, size_t size)
{
	char		*d;
	const char	*s;
	size_t		i;

	d = (char *)dest;
	s = (const char *)src;  // SKOPIRA V NOTRANJE VARS
	i = 0;
	while (i < size && s[i] != '\0')
	{
		d[i] = s[i];
		if (s[i] == (const char)c)
			return ((char *)dest + 1);
		i++;
		dest++;
	}
	return (0);
}




#include "colors.h"

int main(void) 
{
	printf(HYEL"\n------------------------------------------------------------");
	printf("\n--- FT_MEMCCPY ---------------------------------------------\n\n"RES);

	{
		printf(MAG"Test 00\n"RES);
		char	dest1[20]	= "destination";
		char	dest2[20]	= "destination";
		char	*source     = "XYQ";
		char	c 			= 'Q';
		size_t	n			= 2;
		printf(" dest: %s, source: %s, c: %c, n: %lu\n", dest1, source, c, n);
		printf(HWHT"   orig: %s\n",        (char*)memccpy(dest1, source, c, n));
		printf("   mine: %s\n"RES,      (char*)ft_memccpy(dest2, source, c, n));
		printf("   orig dest after copy: %s\n"RES,   dest1);
		printf("   mine dest after copy: %s\n\n"RES, dest2);
	}

	{
		printf(MAG"Test 01\n"RES);
		char	dest1[20]	= "destination";
		char	dest2[20]	= "destination";
		char	*source     = "XYQ";
		char	c 			= 'X';
		size_t	n			= 6;
		printf(" dest: %s, source: %s, c: %c, n: %lu\n", dest1, source, c, n);
		printf(HWHT"   orig: %s\n",        (char*)memccpy(dest1, source, c, n));
		printf("   mine: %s\n"RES,      (char*)ft_memccpy(dest2, source, c, n));
		printf("   orig dest after copy: %s\n"RES,   dest1);
		printf("   mine dest after copy: %s\n\n"RES, dest2);
	}

	{
		printf(MAG"Test 02\n"RES);
		char	dest1[20]	= "destination";
		char	dest2[20]	= "destination";
		char	*source     = "XYQ";
		char	c 			= 'Z';
		size_t	n			= 8;
		printf(" dest: %s, source: %s, c: %c, n: %lu\n", dest1, source, c, n);
		printf(HWHT"   orig: %s\n",        (char*)memccpy(dest1, source, c, n));
		printf("   mine: %s\n"RES,      (char*)ft_memccpy(dest2, source, c, n));
		printf("   orig dest after copy: %s\n"RES,   dest1);
		printf("   mine dest after copy: %s\n\n"RES, dest2);
	}


	{
		printf(MAG"Test 03\n"RES);
		char	dest1[20]	= "";
		char	dest2[20]	= "";
		char	*source     = "XYQ";
		char	c 			= 'Z';
		size_t	n			= 8;
		printf(" dest: %s, source: %s, c: %c, n: %lu\n", dest1, source, c, n);
		printf(HWHT"   orig: %s\n",        (char*)memccpy(dest1, source, c, n));
		printf("   mine: %s\n"RES,      (char*)ft_memccpy(dest2, source, c, n));
		printf("   orig dest after copy: %s\n"RES,   dest1);
		printf("   mine dest after copy: %s\n\n"RES, dest2);
	}


	{
		printf(MAG"Test 04\n"RES);
		char	dest1[20]	= "destination";
		char	dest2[20]	= "destination";
		char	*source     = "XYQ";
		char	c 			= 'Y';
		size_t	n			= 5;
		printf(" dest: %s, source: %s, c: %c, n: %lu\n", dest1, source, c, n);
		printf(HWHT"   orig: %s\n",        (char*)memccpy(dest1, source, c, n));
		printf("   mine: %s\n"RES,      (char*)ft_memccpy(dest2, source, c, n));
		printf("   orig dest after copy: %s\n"RES,   dest1);
		printf("   mine dest after copy: %s\n\n"RES, dest2);
	}


	{
		printf(MAG"Test 05\n"RES);
		char	dest1[20]	= "destination";
		char	dest2[20]	= "destination";
		char	*source     = "XYQ";
		char	c 			= 's';
		size_t	n			= 5;
		printf(" dest: %s, source: %s, c: %c, n: %lu\n", dest1, source, c, n);
		printf(HWHT"   orig: %s\n",        (char*)memccpy(dest1, source, c, n));
		printf("   mine: %s\n"RES,      (char*)ft_memccpy(dest2, source, c, n));
		printf("   orig dest after copy: %s\n"RES,   dest1);
		printf("   mine dest after copy: %s\n\n"RES, dest2);
	}

	{
		printf(MAG"Test 05\n"RES);
		char	dest1[20]	= "destination";
		char	dest2[20]	= "destination";
		char	*source     = "abcdefghijklmnopr";
		char	c 			= 'g';
		size_t	n			= 15;
		printf(" dest: %s, source: %s, c: %c, n: %lu\n", dest1, source, c, n);
		printf(HWHT"   orig: %s\n",        (char*)memccpy(dest1, source, c, n));
		printf("   mine: %s\n"RES,      (char*)ft_memccpy(dest2, source, c, n));
		printf("   orig dest after copy: %s\n"RES,   dest1);
		printf("   mine dest after copy: %s\n\n"RES, dest2);
	}


  	return (0);
}
