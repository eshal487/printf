#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/**
 *  * _printf - Produces output according to a format
 *   * @format: Format string containing directives
 *    * Return: Number of characters printed
 *     */
int _printf(const char *format, ...)
{
	    va_list args;
	    int i = 0, count = 0;
	    char c, *s;

	    if (!format)
		    return (-1);

	    va_start(args, format);

	    while (format && format[i])
	    {
		    if (format[i] == '%' && format[i + 1])
		    {
			    i++;
			    switch (format[i])
			    {
				    case 'c':
					    c = va_arg(args, int);
					    write(1, &c, 1);
					    count++;
					    break;
				    case 's':
					    s = va_arg(args, char *);
					    if (!s)
						    s = "(null)";
					    while (*s)
					    {
						    write(1, s++, 1);
						    count++;
					    }
					    break;
					case '%':
						write(1, "%", 1);
						count++;
						break;
					case 'd':
					case 'i':
					    {
						    int n = va_arg(args, int);
						    char buffer[12];
						    int len = sprintf(buffer, "%d", n);
						    write(1, buffer, len);
						    count += len;
						    break;
					    }
					default:
					    write(1, "%", 1);
					    write(1, &format[i], 1);
					    count += 2;
			    }
		    }
		    else
		    {
			    write(1, &format[i], 1);
			    count++;
		    }
		    i++;

	    }
	    va_end(args);
	    return (count);
}

