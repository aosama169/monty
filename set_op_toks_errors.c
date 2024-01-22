#include "monty.h"

/**
 * set_op_tok_error - Set last element of op_toks
 * @error_code: Int to store as string
 */
void set_op_tok_error(int error_code)
{
	int toks_len = 0, i = 0;
	char *exitString = NULL;
	char **new_toks = NULL;

	toks_len = token_arr_len();
	new_toks = malloc(sizeof(char *) * (toks_len + 2));
	if (!op_toks)
	{
		malloc_error();
		return;
	}
	while (i < toks_len)
	{
		new_toks[i] = op_toks[i];
		i++;
	}
	exitString = get_int(error_code);
	if (!exitString)
	{
		free(new_toks);
		malloc_error();
		return;
	}
	new_toks[i++] = exitString;
	new_toks[i] = NULL;
	free(op_toks);
	op_toks = new_toks;
}
