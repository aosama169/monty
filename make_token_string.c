#include <stdlib.h>

char **strtow(char *str, char *delims);
int is_delim(char ch, char *delims);
int get_word_length(char *str, char *delims);
int get_word_count(char *str, char *delims);
char *get_next_word(char *str, char *delims);

/**
 * strtow - takes string and seperates its words
 *
 * @str: string to seperate into words
 * @delims: delimiters to use to delimite words
 *
 * Return: 2D array of pointers of each word
 */

char **strtow(char *str, char *delims)
{
	char **temp = NULL;
	int wc, wordLen, n, i = 0;

	if (str == NULL || !*str)
		return (NULL);
	wc = get_word_count(str, delims);


	if (wc == 0)
		return (NULL);
	temp = malloc((wc + 1) * sizeof(char *));
	if (temp == NULL)
		return (NULL);
	while (i < wc)
	{
		wordLen = get_word_length(str, delims);
		if (is_delim(*str, delims))
		{
			str = get_next_word(str, delims);
		}
		temp[i] = malloc((wordLen + 1) * sizeof(char));
		if (temp[i] == NULL)
		{
			while (i >= 0)
			{
				i--;
				free(temp[i]);
			}
			free(temp);
			return (NULL);
		}
		n = 0;
		while (n < wordLen)
		{
			temp[i][n] = *(str + n);
			n++;
		}
		temp[i][n] = '\0';
		str = get_next_word(str, delims);
		i++;
	}
	temp[i] = NULL;
	return (temp);
}

/**
 * is_delim - checks if stream has delimitor char
 *
 * @ch: chars in stream
 *
 * @delims: Pointer to null terminated array of delimiters
 *
 * Return: 1 or zero
 */

int is_delim(char ch, char *delims)
{
	int i = 0;

	while (delims[i])
	{
		if (delims[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

/**
 * get_word_length - gets the word length of cur word in str
 *
 * @str: string to get word length from current word
 * @delims: delimitors to use to delimit words
 *
 * Return: word length of current word
 */

int get_word_length(char *str, char *delims)
{
	int wLen = 0, pending = 1, i = 0;

	while (*(str + i))
	{
		if (is_delim(str[i], delims))
			pending = 1;
		else if (pending)
		{
			wLen++;
		}
		if (wLen > 0 && is_delim(str[i], delims))
			break;
		i++;
	}
	return (wLen);
}

/**
 * get_word_count - gets word count of a string
 *
 * @str: string to get word count
 * @delims: delimitors to use to delimit words
 *
 * Return: word count of string
 */

int get_word_count(char *str, char *delims)
{
	int wc = 0, pending = 1, i = 0;

	while (*(str + i))
	{
		if (is_delim(str[i], delims))
			pending = 1;
		else if (pending)
		{
			pending = 0;
			wc++;
		}
		i++;
	}
	return (wc);
}

/**
 * get_next_word - gets next word in a string
 *
 * @str: string to get next word from
 * @delims: delimiter to use to delimit words
 *
 * Return: pointer to first char of next word
 */

char *get_next_word(char *str, char *delims)
{
	int pending = 0;
	int i = 0;

	while (*(str + i))
	{
		if (is_delim(str[i], delims))
			pending = 1;
		else if (pending)
			break;
		i++;
	}
	return (str + i);
}
