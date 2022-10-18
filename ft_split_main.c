/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 12:44:38 by jmurovec      #+#    #+#                 */
/*   Updated: 2020/11/03 12:44:38 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <bsd/string.h>


static void		*free_arr(char **splitted, int i)
{
	int	n;

	n = 0;
	while (n <= i)
	{
		free(splitted[n]);
		n++;
	}
	free(splitted);
	return (NULL);
}

static int		count_words(char const *s, char c)
{
	int		i;
	int		words;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static int		words_len(char const *s, char c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static char		**fill(char const *s, int words, char c, char **splitted)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	while (i < words)
	{
		while (*s == c)
			s++;
		len = words_len(s, c);
		splitted[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!splitted[i])
			return (free_arr(splitted, i));
		j = 0;
		while (j < len)
		{
			splitted[i][j] = *s;
			j++;
			s++;
		}
		splitted[i][j] = '\0';
		i++;
	}
	splitted[i] = NULL;
	return (splitted);
}

char			**ft_split_orig(char	const *s, char c)
{
	char	**splitted;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	splitted = (char **)malloc(sizeof(char*) * (words + 1));
	if (!splitted)
		return (NULL);
	splitted = fill(s, words, c, splitted);
	return (splitted);
}


// //////////////////////////////////////////////////////////////////
char			**ft_split(char	const *s, char c)
{
	char	**splitted;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	splitted = (char **)malloc(sizeof(char*) * (words + 1));
	if (!splitted)
		return (NULL);
	splitted = fill(s, words, c, splitted);
	return (splitted);
}
// //////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////
// VAJA PONAVLJANJE



#include "colors.h"
int main(void)
{
	printf(HYEL"\n------------------------------------------------------------");
	printf("\n--- FT_SPLIT -----------------------------------------------\n\n"RES);

	int i = 0;
	char dl = '-';
{
	printf(MAG"TEST 01\n");

	char *str1 = "---asd---qwe---wer---ert---dfg---";
	char **arr1;
	printf("   String to split: %s\n   Delimiter: '%c'\n"RES, str1, dl);
	printf("\n      orig: ");
	arr1 = ft_split_orig(str1, dl);
	while (arr1[i] != NULL)
	{	printf("%s ", arr1[i]);  i++; }
	i = 0;
	while (arr1[i] != NULL)
	{	free(arr1[i]);	i++; }
	free(arr1[i]);
	free(arr1);

	printf("\n      mine: ");
	i = 0;
	dl = '-';
	char **arr2;
	char *str2 = "---asd---qwe---wer---ert---dfg---";
	arr2 = ft_split(str2, dl);
	while (arr2[i] != NULL)
	{	printf("%s ", arr2[i]); i++; }
	i = 0;
	while (arr2[i] != NULL)
	{	free(arr2[i]);	i++; }
	free(arr2[i]);
	free(arr2);

}
// TEST 02 /////////////////////////////////////////////////////////////////////////
{

	printf(MAG"\n\nTEST 02\n");
	i = 0;
	dl = '-';
	char **arr1;
	char *str1 = "---oneword---";
	printf("   String to split: %s\n   Delimiter: '%c'\n"RES, str1, dl);
	printf("\n      orig: ");
	arr1 = ft_split_orig(str1, dl);
	while (arr1[i] != NULL)
	{	printf("%s ", arr1[i]);  i++; }
	i = 0;
	while (i < 1)
	{	free(arr1[i]);	i++; }
	free(arr1);

	printf("\n      mine: ");
	i = 0;
	dl = '-';
	char **arr2;
	char *str2 = "---oneword---";
	arr2 = ft_split(str2, dl);
	while (arr2[i] != NULL)
	{	printf("%s ", arr2[i]); i++; }
	i = 0;
	while (i < 1)
	{   free(arr2[i]);  i++; }
	free(arr2);
}
	// TEST 03 /////////////////////////////////////////////////////////////////////////
{

	printf(MAG"\n\nTEST 03\n");
	i = 0;
	dl = '-';
	char **arr1;
	char *str1 = "----------";
	printf("   String to split: %s\n   Delimiter: '%c'\n"RES, str1, dl);
	printf("\n      orig: ");
	arr1 = ft_split_orig(str1, dl);
	while (arr1[i] != NULL)
	{	printf("%s ", arr1[i]);  i++; }
	i = 0;
	while (i < 1)
	{	free(arr1[i]);	i++; }
	free(arr1);

	printf("\n      mine: ");
	i = 0;
	dl = '-';
	char **arr2;
	char *str2 = "----------";
	arr2 = ft_split(str2, dl);
	while (arr2[i] != NULL)
	{	printf("%s ", arr2[i]); i++; }
	i = 0;
	while (i < 1)
	{   free(arr2[i]);  i++; }
	free(arr2);
}
	// TEST 04 /////////////////////////////////////////////////////////////////////////
{

	printf(MAG"\n\nTEST 04\n");
	i = 0;
	dl = '-';
	char **arr1;
	char *str1 = "abcd efgh ijkl mnop rstu";
	printf("   String to split: %s\n   Delimiter: '%c'\n"RES, str1, dl);
	printf("\n      orig: ");
	arr1 = ft_split_orig(str1, dl);
	while (arr1[i] != NULL)
	{	printf("%s ", arr1[i]);  i++; }
	i = 0;
	while (i < 1)
	{	free(arr1[i]);	i++; }
	free(arr1);

	printf("\n      mine: ");
	i = 0;
	dl = '-';
	char **arr2;
	char *str2 = "abcd efgh ijkl mnop rstu";
	arr2 = ft_split(str2, dl);
	while (arr2[i] != NULL)
	{	printf("%s ", arr2[i]); i++; }
	i = 0;
	while (i < 1)
	{   free(arr2[i]);  i++; }
	free(arr2);
}
	// TEST 05 /////////////////////////////////////////////////////////////////////////
{

	printf(MAG"\n\nTEST 05\n");
	i = 0;
	dl = '-';
	char **arr1;
	char *str1 = "abcd---efgh";
	printf("   String to split: %s\n   Delimiter: '%c'\n"RES, str1, dl);
	printf("\n      orig: ");
	arr1 = ft_split_orig(str1, dl);
	while (arr1[i] != NULL)
	{	printf("%s ", arr1[i]);  i++; }
	i = 0;
	while (i < 1)
	{	free(arr1[i]);	i++; }
	free(arr1);

	printf("\n      mine: ");
	i = 0;
	dl = '-';
	char **arr2;
	char *str2 = "abcd---efgh";
	arr2 = ft_split(str2, dl);
	while (arr2[i] != NULL)
	{	printf("%s ", arr2[i]); i++; }
	i = 0;
	while (i < 1)
	{   free(arr2[i]);  i++; }
	free(arr2);
}
	// TEST 06 /////////////////////////////////////////////////////////////////////////
{

	printf(MAG"\n\nTEST 06\n");
	i = 0;
	dl = ' ';
	char **arr1;
	char *str1 = "   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ";
	printf("   String to split: %s\n   Delimiter: '%c'\n"RES, str1, dl);
	printf("\n      orig: ");
	arr1 = ft_split_orig(str1, dl);
	while (arr1[i] != NULL)
	{	printf("%s ", arr1[i]);  i++; }
	i = 0;
	while (i < 1)
	{	free(arr1[i]);	i++; }
	free(arr1);

	printf("\n      mine: ");
	i = 0;
	dl = ' ';
	char **arr2;
	char *str2 = "   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ";
	arr2 = ft_split(str2, dl);
	while (arr2[i] != NULL)
	{	printf("%s ", arr2[i]); i++; }
	i = 0;
	while (i < 1)
	{   free(arr2[i]);  i++; }
	free(arr2);
}
	// TEST 06 /////////////////////////////////////////////////////////////////////////
{
	

	printf(MAG"\n\nTEST 07\n");
	i = 0;
	dl = '\n';
	char **arr1;
	char *str1 = "   lorem\nipsum\ndolor\nsit\namet,\nconsectetur\nadipiscing elit.\nSed\nnon\nrisus.\nSuspendisse";
	printf("   String to split: %s\n   Delimiter: 'new line'\n"RES, str1);
	printf("\n      orig: ");
	arr1 = ft_split_orig(str1, dl);
	while (arr1[i] != NULL)
	{	printf("%s ", arr1[i]);  i++; }
	i = 0;
	while (i < 1)
	{	free(arr1[i]);	i++; }
	free(arr1);

	printf("\n      mine: ");
	i = 0;
	dl = '\n';
	char **arr2;
	char *str2 = "   lorem\nipsum\ndolor\nsit\namet,\nconsectetur\nadipiscing elit.\nSed\nnon\nrisus.\nSuspendisse";
	arr2 = ft_split(str2, dl);
	while (arr2[i] != NULL)
	{	printf("%s ", arr2[i]); i++; }
	i = 0;
	while (i < 1)
	{   free(arr2[i]);  i++; }
	free(arr2);
}


	printf(HYEL"\n\n------------------------------------------------------------\n\n"RES);


	return (0);
}

/*
	if ((arg = atoi(argv[1])) == 1)
		check_split("          ", ' ');
	else if (arg == 2)
		check_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');
	else if (arg == 3)
		check_split("   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' ');
	else if (arg == 4)
		check_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'i');
	else if (arg == 5)
		check_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'z');
*/
