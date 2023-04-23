#include <stdio.h>
#include <stdarg.h>

#define BUFF_SIZE 1024

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - produces output according to a format
 * @format: character string containing directives
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    char c;
    int buff_ind = 0;
    char buffer[BUFF_SIZE];

    va_start(args, format);

    while ((c = *format++) != '\0')
    {
        if (c != '%')
        {
            buffer[buff_ind++] = c;
            if (buff_ind == BUFF_SIZE)
            {
                print_buffer(buffer, &buff_ind);
            }
            count++;
        }
        else
        {
            switch (*format++)
            {
            case 'c':
            {
                char arg = (char)va_arg(args, int);
                buffer[buff_ind++] = arg;
                if (buff_ind == BUFF_SIZE)
                {
                    print_buffer(buffer, &buff_ind);
                }
                count++;
                break;
            }
            case 's':
            {
                char *arg = va_arg(args, char *);
                while (*arg != '\0')
                {
                    buffer[buff_ind++] = *arg++;
                    if (buff_ind == BUFF_SIZE)
                    {
                        print_buffer(buffer, &buff_ind);
                    }
                    count++;
                }
                break;
            }
            case 'd':
            case 'i':
            {
                int arg = va_arg(args, int);
                char temp_buff[12];
                int i = 0;

                if (arg < 0)
                {
                    buffer[buff_ind++] = '-';
                    if (buff_ind == BUFF_SIZE)
                    {
                        print_buffer(buffer, &buff_ind);
                    }
                    arg = -arg;
                    count++;
                }

                do
                {
                    temp_buff[i++] = arg % 10 + '0';
                    arg /= 10;
                } while (arg);

                while (--i >= 0)
                {
                    buffer[buff_ind++] = temp_buff[i];
                    if (buff_ind == BUFF_SIZE)
                    {
                        print_buffer(buffer, &buff_ind);
                    }
                    count++;
                }
                break;
            }
            case '%':
            {
                buffer[buff_ind++] = '%';
                if (buff_ind == BUFF_SIZE)
                {
                    print_buffer(buffer, &buff_ind);
                }
                count++;
                break;
            }
            default:
            {
                break;
            }
            }
        }
    }

    print_buffer(buffer, &buff_ind);

    va_end(args);
    free(buffer);

    return count;
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
    if (*buff_ind > 0)
    {
        write(buffer, 1, *buff_ind, stdout);
    }

    *buff_ind = 0;
}