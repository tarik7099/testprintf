#include <stdarg.h>
#include "main.h"
#include <stdio.h>

int _printf(const char *format, ...)
{
if (format == "\0")
	return 0;
int i = 0;
int counter = 0;

va_list args;
va_start(args, format); 
while(*format){
	if(*format == '%')
	{
		format++;

		if (*format == 's')
	{
		print_string(va_arg(args, char*));
		counter++;
	}	
		else if(*format == 'c')
        {
                print_char(va_arg(args, char*));
		counter++;
        }
		else if(*format ==  '%')
	{
		putchar('%');
		counter++;

	}
		if (*format == '\0')
                break;
		else if (*format == 'b')
		{
			decimalTobinary(va_arg(args,unsigned int));
		}
}
	else
{
	putchar(*format);
	counter++;
}
format++;
}
va_end(args);
return counter;
}

void print_string(char *str)
{
for (int i = 0;str[i] != '\0';i++ )
	{
		putchar(str[i]);
	}
}
void print_char(char *c)
{
	for (int i = 0; c[i]; c++) {
        putchar(c[i]);

	}
}
void decimalTobinary(unsigned int d)
{
if (d == 0) {
        putchar('0');
        return;
    }
int quotient[32];
int i = 0;
while(d > 0)
{
  quotient[i] = d % 2;
  d = d / 2;

i++;
}
for (int j = i - 1; j >= 0; j--) {
        putchar( quotient[j] + '0');
}
}
int main()
{
_printf("%b\n", 99);


}
