#include "main.h"
int flag_handler(char *input)
{
	int flags = 0;
	char *ptr = input;
	char i = 0;

	for (i = 0; *ptr != '\0'; ++i)
	{
		if(*ptr == '%')
			ptr++;

		switch (*ptr++)
		{
			case ' ':
				flags |= SPACE;
				break;

			case '#': flags |= HASH;
				break;

			case '+': flags |= PLUS;
				break;
		}
	}
	return (flags);
}
