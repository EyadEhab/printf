#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Custom printf function
 * @format: Format string with conversion specifiers
 * @...: Variable arguments corresponding to conversion specifiers
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
    int printed_chars = 0;
    va_list args;
    va_start(args, format);

    for (int i = 0; format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            putchar(format[i]);
            printed_chars++;
        }
        else
        {
            i++; // Move past the '%'
            switch (format[i])
            {
                case 'c':
                    // Handle character argument
                    {
                        int c = va_arg(args, int);
                        putchar(c);
                        printed_chars++;
                    }
                    break;
                case 's':
                    // Handle string argument
                    {
                        char *s = va_arg(args, char *);
                        for (int j = 0; s[j] != '\0'; j++)
                        {
                            putchar(s[j]);
                            printed_chars++;
                        }
                    }
                    break;
                case '%':
                    // Handle '%' character
                    putchar('%');
                    printed_chars++;
                    break;
                default:
                    // Invalid conversion specifier, ignore
                    break;
            }
        }
    }

    va_end(args);
    return printed_chars;
}
