/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove_main.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 10:26:24 by jmurovec      #+#    #+#                 */
/*   Updated: 2022/10/17 13:36:55 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
// #include "../srcs_eval/libft.h"
// #include "../libft_mains.h"
/*
void *memmove(void *dst, const void *src, size_t len);

DESCRIPTION
The memmove() function copies len bytes from string src to string dst.

The two strings may overlap;
								???
The copy is always done in a non-destructive manner.

// Src len ne sme bit vecja od destlen !!! segfault, ali kopira cudne znake
//      Sicer vcasih dela, ce ni razlika prevelika ?
// Len ne sme bit vecja od srclen !!! Segfault

RETURN VALUES
     The memmove() function returns the original value of dst.


// ERRORS
// THERE NEEDS TO BE HANDLED THE CASES WHERE dest and src CAN BE COPIED INTO EACH OTHER:
// 			memmove(dest, src, 8)
//          memmove(src, dest, 8)

// IN THE TEST THERE IS THIS TRICK: dest = source = 1;    THIS CAUSES THE FOLLOWING ERROR:
cat test03.output
	lorem ipum dolor sit a
cat user_output_test03
	llllllllum dolor sit aj    // REPEATING THE SAME LETTER, INSTAD OF MOVING ON

*/



void		*ft_memmove(void *dest, const void *src, size_t len)
{
	char *s;
	char *d;

	// char s[20];	// error, can not be later:  s = (char*)src
	// char d[20];

	if (!dest && !src)
		return (NULL);
	s = (char*)src;
	d = (char*)dest;
	if (s < d)  // THIS IS NEEDED IN CASE SRC IS LOCATED IN MEMORY BEFORE DEST 
	{			//   TO HANDLE OVERLAPPING
				//  IT NEEDS TO START COPYING AT THE END, TO PREVENT REPETITION
				// THE STR IS COPIED INTO ITSELF, WITH OFFSET, is: dest + 3, src
		s = s + len - 1;
		d = d + len - 1;  	// HERE SETS BOTH D AND S TO THE END OF len - 1 
		while (len-- > 0)	// COPIES FROM END TO START
		{
			//printf("   -------- %c\n", *s);
			*d-- = *s--;
			// d-- = s--;
		}
	}
	else
		while (len-- > 0)
			*d++ = *s++;
	return (dest);
}



// ALSO WORKS, without backwards copying - HOW TO TEST OVERLAPING ???
void		*ft_memmove_forwards(void *dest, const void *src, size_t len)
{
	char *s;
	char *d;

	// char s[20];	// error, can not be later:  s = (char*)src
	// char d[20];

	if (!dest && !src)
		return (NULL);
	s = (char*)src;
	d = (char*)dest;
	if (s < d)  // THIS IS NEEDED IN CASE SRC IS LOCATED IN MEMORY BEFORE DEST 
	{			//   TO HANDLE OVERLAPPING
				//  IT NEEDS TO START COPYING AT THE END, TO PREVENT REPETITION
				// THE STR IS COPIED INTO ITSELF, WITH OFFSET, is: dest + 3, src
		//s = s + len - 1;
		//d = d + len - 1;  	// HERE SETS BOTH D AND S TO THE END OF len - 1 
		int i = 0;
		while (i < len)	// COPIES FROM END TO START
		{
			//printf("   -------- %c\n", *s);
			*d++ = *s++;
			// d-- = s--;
			i++;
		}
	}
	else
	{
		int i = 0;
		while (i < len)
		{
			*d++ = *s++;
			i++;
		}
	}
	return (dest);
}

//////////////////////////////////////////////////////////////////////////////////



#include "colors.h"

void print_elements(char *array, int size)
{
	int i;
	for (i = 0; i < size; i++) {
		printf ("%c ", array[i]);
	}
	printf (" ");
}

int main(void) 
{
	printf(HYEL"\n------------------------------------------------------------");
	printf("\n--- FT_MEMMOVE ---------------------------------------------\n\n"RES);

	{
		printf(MAG"\nTEST 00 \n"RES);
		char source1[50] = "SOURCE";
		char source2[50] = "SOURCE";
		char dest1[50] = "destination";
		char dest2[50] = "destination";
		int n = 6;

		printf("dest: [%s]  src: [%s]   n: %d\n", dest1, source1, n);
		printf(HWHT"   orig: %s\n",       (char*)memmove(dest1, source1, n));
		printf("   mine: %s\n\n"RES,   (char*)ft_memmove(dest2, source2, n));
	}

	{
		printf(MAG"\nUNIT TEST 03:    DESTINATION = SOURCE \n"RES);
		char src1[] = "lorem ipsum dolor sit amet";
		char src2[] = "lorem ipsum dolor sit amet";
		char *dest1;
		char *dest2;
		int n = 1;
		
		dest1 = src1;
		dest2 = src2;
		printf("dest: [%s]  src: [%s]   n: %d\n", dest1, src1, n);
		printf(HWHT"   orig: %s\n",        (char*)memmove(dest1, src1, n));
		printf("   mine: %s\n\n"RES,    (char*)ft_memmove(dest2, src2, n));
	}

	{
		printf(MAG"\nUNIT TEST 03:     DESTINATION = SOURCE + 3\n"RES);
		char src1[] = "0123456789";
		char src2[] = "0123456789";
		char *dest1;
		char *dest2;
		int n = 3;
		
		dest1 = src1 + 3;
		dest2 = src2 + 3;
		printf("dest: [%s]  src: [%s]   n: %d\n", dest1, src1, n);
		printf(HWHT"   orig: %s\n",        (char*)memmove(dest1, src1, n));
		printf("   mine: %s\n\n"RES,    (char*)ft_memmove(dest2, src2, n));
	}

	{
		printf(MAG"\nUNIT TEST 05: dest into dest + 10\n"RES);
		char dest1[50];
		char dest2[50];
		char *src1 = "This string will be overlapped!";
		int n = 7;
	
		memcpy(dest1, src1, strlen(src1));
		memcpy(dest2, src1, strlen(src1));
		
		printf("dest: [%s]  src: [%s]   n: %d\n", dest1, src1, n);
		printf(HWHT"   orig: %s\n",        (char*)memmove(dest1 + 10, src1, n));
		printf("   mine: %s\n\n"RES,    (char*)ft_memmove(dest2 + 10, src1, n));

		char *src2 = "thiß ß\xde\xad\xbe\xeftriñg will be øvérlapéd !\r\n";
		printf(HWHT"   orig: %s\n",        (char*)memmove(dest1 + 10, src2, n));
		printf("   mine: %s\n\n"RES,    (char*)ft_memmove(dest2 + 10, src2, n));

	}

	{
		printf(MAG"\nUNIT TEST 06: src copied into dest + 3\n"RES);

		char dest1[80];
		char dest2[80];
		char *src2 = "thiß ß\xde\xad\xbe\xeftriñg will be øvérlapéd !";
		//char *src2 = "abcdefghijkl";
		int size = 50;

		memcpy(dest1, src2, strlen(src2));
		memcpy(dest2, src2, strlen(src2));
		printf("s1 [%s],    address %p\n", dest1, &dest1);
		printf("s2 [%s],    address %p\n", dest2, &dest2);
		printf(HWHT"   orig: %s\n",          (char*)memmove(dest1 + 3, src2, size));
		printf("   mine: %s\n\n"RES,    (char*)ft_memmove(dest2 + 3, src2, size));
	}



	// TEST OVERLAPING, SOURCE > DESTINATION
	{	
		printf("\n");
		char array[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'o', 'p', 'r'};
		char arrayB[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'o', 'p', 'r'};
		printf("array: "); print_elements(array, sizeof(array));
		
		printf("After memmove orig:\n");
		memmove((void *)&array[0], (void *)&array[1], 15);
		printf("orig:  "); print_elements(array, sizeof(array));
		
		printf("After memmove mine:\n");
		ft_memmove((void *)&arrayB[0], (void *)&arrayB[1], 15);
		printf("mine:  "); print_elements(arrayB, sizeof(arrayB));
		printf("\n");
	}

		// TEST OVERLAPING, SOURCE < DESTINATION
	{	
		printf("\n");
		char array[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'o', 'p', 'r'};
		char arrayB[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'o', 'p', 'r'};
		printf("array: "); print_elements(array, sizeof(array));
		
		printf("After memmove orig:\n");
		memmove((void *)&array[1], (void *)&array[2], 10);
		printf("orig:  "); print_elements(array, sizeof(array));
		
		printf("After memmove mine:\n");
		ft_memmove((void *)&arrayB[1], (void *)&arrayB[2], 10);
		printf("mine:  "); print_elements(arrayB, sizeof(arrayB));
		printf("\n");
	}


	

  	return (0);
}
