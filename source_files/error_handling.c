
#include "error_handling.h"

int check_num_val(int val, int min, int max)
{
	return (val >= min && val <= max);
}

int check_str_if_int(char string[], char* error_msg)
{
	for (int i = 0; i < (int) strlen(string); i++)
		if (!isdigit(string[i]))
		{
			printf("%s\n\n", error_msg);
			exit(INPUT_IS_NOT_INTEGER);
		}
			
	return atoi(string);
}

int check_input_if_int(char* error_msg)
{
	char string[10];
	scanf("%s", string);
	getchar();
	return check_str_if_int(string, error_msg);
}
