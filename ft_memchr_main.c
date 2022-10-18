#include <stdio.h>
#include <string.h>
// #include "../srcs_eval/libft.h"
// #include "../libft_mains.h"
/*			  
#include <string.h>

void *memchr(const void *s, int c, size_t n);

DESCRIPTION
The memchr() function locates the first occurrence of c (converted to 
an unsigned char) in string s.

RETURN VALUES
The memchr() function returns a pointer to the byte located, 
or NULL if no such byte exists within n bytes.
*/

/// CLONE LOOMANS /////////////////////////////////////////////
void	*clone_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*uc_s;
	unsigned char		uc_c;

	i = 0;
	uc_s = s;
	uc_c = c;
	while (i < n)
	{
		if (uc_s[i] == uc_c)
			return ((void *)(uc_s + i));
		i++;
	}
	return (NULL);
}
///////////////////////////////////////////////////////////////

void	*ft_memchr(const void *str, int ch, size_t n)
{
	const unsigned char *s;
	unsigned char 		c;
	size_t				i;

	s = str;
	c = ch;
	i = 0;
	while (i < n)  	//  IN THIS CASE BETTER USE i THAN *str
	{				//	BECAUSE IT NEEDS TO COMPARE ALSO THE \0
		if (s[i] == c)
			return ((char*)(s + i));
		i++;
	}
	return (NULL);
}



#include "colors.h"
int main(void) 
{
	printf(HYEL"\n------------------------------------------------------------");
	printf("\n--- FT_MEMCHR ---------------------------------------------\n\n"RES);

	int		n = 7;
	char	c = 'i';

	{
		char dest[50] = "destination";
		printf(MAG"TEST 01: %s, '%c',  n%d\n"RES, dest, c, n);
		printf("  orig: %s\n",         (char*)memchr(dest, c, n));
		printf("  mine: %s\n\n",   (char*)ft_memchr(dest, c, n));
	}
	{
		n = 3;
		c = 'i';
		char dest[50] = "destination";
		printf(MAG"TEST 02: %s, '%c',  n%d\n"RES, dest, c, n);
		printf("  orig: %s\n",         (char*)memchr(dest, c, n));
		printf("  mine: %s\n\n",   (char*)ft_memchr(dest, c, n));
	}
	{
		n = 10;
		c = 'n';
		char dest[50] = "destination";
		printf(MAG"TEST 03: %s, '%c',  n%d\n"RES, dest, c, n);
		printf("  orig: %s\n",         (char*)memchr(dest, c, n));
		printf("  mine: %s\n\n",   (char*)ft_memchr(dest, c, n));
	}

	{
		n = 10;
		c = 'n';
		char dest[50] = "";
		printf(MAG"TEST 04: %s, '%c',  n%d\n"RES, dest, c, n);
		printf("  orig: %s\n",        memchr(dest, c, n));
		printf("  mine: %s\n\n",   ft_memchr(dest, c, n));
	}
	{
		n = 20;
		c = 'x';
		char dest[50] = "destination";
		printf(MAG"TEST 05: %s, '%c',  n%d\n"RES, dest, c, n);
		printf("  orig: %s\n",        memchr(dest, c, n));
		printf("  mine: %s\n\n",   ft_memchr(dest, c, n));
	}


	return (0);
}
