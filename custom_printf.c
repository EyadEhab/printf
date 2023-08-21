#include "main.h"
#include <stdarg.h>
#include <stdio.h> /* For putchar function */

int _printf(const char *format, ...)
{
    int printed_chars = 0;
    va_list args;
    va_start(args, format);

    int i;
    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            putchar(format[i]);
            printed_chars++;
        }
        else
        {
            i++; /* Move past the*/ '%'
            switch (format[i])
            {
                case 'c':
                {
                    int c = va_arg(args, int);
                    putchar(c);
                    printed_chars++;
                }
                break;
                case 's':
                {
                    char *s = va_arg(args, char *);
                    int j;
                    for (j = 0; s[j] != '\0'; j++)
                    {
                        putchar(s[j]);
                        printed_chars++;
                    }
                }
                break;
                case '%':
                    putchar('%');
                    printed_chars++;
                    break;
                default:
                    break;
            }
        }
    }

    va_end(args);
    return printed_chars;
}
