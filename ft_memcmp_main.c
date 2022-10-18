#include <stdio.h>
#include <string.h>
// #include "../srcs_eval/libft.h"
// #include "../libft_mains.h"
/*			  
#include <string.h>

int   memcmp(const void *s1, const void *s2, size_t n);

DESCRIPTION
The memcmp() function compares byte string s1 against byte string s2.  
       Both strings are assumed to be n bytes long. ???????
   ??? Different source: n −> This is the number of bytes to be compared. ???


RETURN VALUES
The memcmp() function returns zero if the two strings are identical, 
otherwise returns the difference between the first two differing bytes (treated 
as unsigned char values, so that `\200' is greater than `\0', for example).  
Zero-length strings are always identical.  
This behavior is not required by C and portable code should only depend on the 
sign of the returned value.

ORIGINAL IS BEHAVING DIFFERENTLY THAN MINE AND CLONE AT FOLLOWING PARAMS:
  s1 = "aa", s2 = "ab", n = 2


*/

int ft_memcmp(const char *s1, const char *s2, int n)
{
	const unsigned char *str1;         // why is this necessary ???
	const unsigned char *str2;

    str1 = (const unsigned char *)s1;  // why is this necessary ???
	str2 = (const unsigned char *)s2;  

	if (n == 0)
		return (0);
	int i = 0;
	while (n > 0)
	{
		//printf("str1 - str2: %d\n", *str1 - *str2);
		//printf("%d compare: %c : %c\n", i, *str1, *str2);

		if (*str1 != *str2)
			return (*str1 - *str2);
		n--;
		str1++;
		str2++;
		i++;
	}
	return (0);
}

int		clone_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char		*str1;
	const unsigned char		*str2;

	if (s1 == s2 || n == 0)
		return (0);
	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	while (n--)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		if (n)
		{
			str1++;
			str2++;
		}
	}
	return (0);
}

int ft_memcmp04(const char *str1, const char *str2, size_t n)
{
	const unsigned char *s1;
	const unsigned char *s2;

	s1 = (const unsigned char*)str1;
	s2 = (const unsigned char*)str2;
	if (n == 0)
		return (0);
	while (n > 0)
	{
		printf("compare: %c : %c\n", *s1, *s2);
		if (*s1 != *s2)
			return (*s1 - *s2);
		n--;
		s1++;
		s2++;
		
	}
	return (0);
}

// SIMILAR FUNCTION STRNCMP VS MEMCMP
/*int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	const unsigned char *s1;
	const unsigned char *s2;

	s1 = (const unsigned char*)str1;
	s2 = (const unsigned char*)str2;
	if (n == 0)
		return (0);
	while (n > 0 && *s1 != '\0' && *s2 != '\0')
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
			n--;
		}
		else
			return (*s1 - *s2);
	}
	return (*s1 - *s2);
}
*/



#include "colors.h"
int main(void)
{
	printf(HYEL"\n------------------------------------------------------------");
	printf("\n--- FT_MEMCMP ---------------------------------------------\n\n"RES);

	{
		// char *str1 = "aaa";
		// char *str2 = "aaa";
		char str1[] = "";
		char str2[] = "";
		int n = 1;
		printf(MAG"Test 01:  [%s : %s]     n%d\n"RES, str1, str2, n);
		printf("   orig: %d\n",      memcmp(str1, str2, n));
		printf("   mine: %d\n\n", ft_memcmp(str1, str2, n));
	}

	{
		char str1[] = "aaa";
		char str2[] = "aaa";
		int n = 3;
		printf(MAG"Test 02:  [%s : %s]     n%d\n"RES, str1, str2, n);

		printf("   orig: %d\n",      memcmp(str1, str2, n));
		printf("   mine: %d\n\n", ft_memcmp(str1, str2, n));
	}

	{
		char str1[] = "aaa";
		char str2[] = "aaX";
		int n = 3;
		printf(MAG"Test 03:  [%s : %s]     n%d\n"RES, str1, str2, n);
		printf("   orig: %d\n",      memcmp(str1, str2, n));
		printf("   mine: %d\n\n", ft_memcmp(str1, str2, n));
	}


	{
		char str1[] = "aaa";
		char str2[] = "aaX";
		int n = 4;
		printf(MAG"Test 04:  [%s : %s]     n%d\n"RES, str1, str2, n);
		printf("   orig: %d\n",      memcmp(str1, str2, n));
		printf("   mine: %d\n\n", ft_memcmp(str1, str2, n));
	}

	{
		char str1[] = "a";
		char str2[] = "b";
		int n = 0;
		printf(MAG"Test 05:  [%s : %s]     n%d\n"RES, str1, str2, n);
		printf("   orig: %d\n",      memcmp(str1, str2, n));
		printf("   mine: %d\n\n", ft_memcmp(str1, str2, n));
	}

	{
		char str1[] = "a";
		char str2[] = "b";
		int n = 1;
		printf(MAG"Test 06:  [%s : %s]     n%d\n"RES, str1, str2, n);
		printf("   orig: %d\n",      memcmp(str1, str2, n));
		printf("   mine: %d\n\n", ft_memcmp(str1, str2, n));
	}

	{
		char str1[] = "test";
		char str2[] = "testX";
		int n = 5;
		printf(MAG"Test 07:  [%s : %s]     n%d\n"RES, str1, str2, n);
		printf("   orig: %d\n",      memcmp(str1, str2, n));
		printf("   mine: %d\n\n", ft_memcmp(str1, str2, n));
	}

	{
		char str1[] = "testX";
		char str2[] = "test";
		int n = 6;
		printf(MAG"Test 08:  [%s : %s]     n%d\n"RES, str1, str2, n);
		printf("   orig: %d\n",      memcmp(str1, str2, n));
		printf("   mine: %d\n\n", ft_memcmp(str1, str2, n));
	}

	{
		char str1[] = "test\175";
		char str2[] = "test\0";
		int n = 6;
		printf(MAG"Test 09:  [%s : %s]     n%d\n"RES, str1, str2, n);
		printf("   orig: %d\n",      memcmp(str1, str2, n));
		printf("   mine: %d\n\n", ft_memcmp(str1, str2, n));
	}

	{
		char str1[] = "test\175def";
		char str2[] = "test\0def";
		int n = 15;
		printf(MAG"Test 10:  [%s : %s]     n%d\n"RES, str1, str2, n);
		printf("   orig: %d\n",      memcmp(str1, str2, n));
		printf("   mine: %d\n\n", ft_memcmp(str1, str2, n));
	}


	{
		char str1[] = "test\\175";
		char str2[] = "test\\0";
		int n = 15;
		printf(MAG"Test 11:  [%s : %s]     n%d\n"RES, str1, str2, n);
		printf("   orig: %d\n",      memcmp(str1, str2, n));
		printf("   mine: %d\n\n", ft_memcmp(str1, str2, n));
	}

	{
		char str1[] = "abcde";
		char str2[] = "abcde";
		int n = 15;
		printf(MAG"Test 12, Check beyond n,  [%s : %s]     n%d\n"RES, str1, str2, n);
		printf("   orig: %d\n",      memcmp(str1, str2, n));
		printf("   mine: %d\n\n", ft_memcmp(str1, str2, n));
	}

  	return (0);
}


