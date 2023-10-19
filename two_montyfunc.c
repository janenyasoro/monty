#include "montymain.h"
/**
 * liner - Frees lineptr buffer malloc'd by getline
 *@lineptr: Pointer to the buffer containing the string
 *
 * Return: length of token
 */
void liner(char **lineptr)
{
	if (*lineptr && **lineptr == 0)
	{
		fre(lineptr);
	}

	free(*lineptr);
}


/**
 *tok_len - Finds the length the token
 *
 * Return: length of token
 */
unsigned int tok_len(void)
{
	unsigned int len = 0;

	while (tok[len])
		len++;

	return(len);
}


/**
 *find_opcodeFX - Finds the function associated with the opcode
 *@opcode: A token containing the opcode
 *
 * Return: Void
 */
void (*find_opcodeFX(char *opcode))(stack_t**, unsigned int)
{
	int i = 0;
	int is_opcode;
	instruction_t opcodeFXs[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{NULL, NULL}
	};

	while (opcodeFXs[i].opcode != NULL)
	{
		is_opcode = strcmp(opcode, opcodeFXs[i].opcode);

		if(is_opcode == 0)
			return (opcodeFXs[i].f);
		i++;
	}

	return (NULL);
}

/**
 *tok_free - Frees Tokens
 *
 * Return: Void
 */
void tok_free(void)
{
	int i = 0;

	if (tok != NULL)
	{
		while (tok[i])
		{
			free(tok[i]);
			i++;
		}

		free(tok);

	}
}

/**
 * _strtok - seperates words
 *
 * @str: pointer to string
 * @delims: pointer ot delimitors
 *
 * Return: pointers to each word
 */
char **_strtok(char *str, char *delims)
{
	char **strings = NULL;
	int word_c, len_s, n, i = 0;

	if(str == NULL || !*str)
		return (NULL);
	word_c = get_wc(str, delims);


	if (word_c == 0)
		return (NULL);


	while (i < word_c)
	{
		len_s = get_wl(str, delims);
		if (_isDelim(*str, delims))
		{
			str = get_nw(str,delims);
		}


		strings[i] = malloc((len_s + 1) * sizeof(char));
		if (strings[i] == NULL)
		{
			while (i >= 0)
			{
				i--;
				free(strings[i]);
			}
			free(strings);
			return (NULL);
		}

		n = 0;
		while (n < len_s)
		{
			strings[i][n] = *(str + n);
			n++;
		}
		strings[i][n] = '\0';
		str = get_nw(str, delims);
		i++;

	}
	strings[i] = NULL;
	return (strings);
}



