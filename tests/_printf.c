#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

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
            case 'p':
            {
                void *arg = va_arg(args, void *);
                unsigned long long ptr_val = (unsigned long long)arg;
                char temp_buff[16];
                int i = 0;

                if (arg == NULL)
                {
                    buffer[buff_ind++] = '(';
                    buffer[buff_ind++] = 'n';
                    buffer[buff_ind++] = 'i';
                    buffer[buff_ind++] = 'l';
                    buffer[buff_ind++] = ')';
                    if (buff_ind == BUFF_SIZE)
                    {
                        print_buffer(buffer, &buff_ind);
                    }
                    count += 5;
                }
                else
                {
                    buffer[buff_ind++] = '0';
                    buffer[buff_ind++] = 'x';

                    do
                    {
                        temp_buff[i++] = "0123456789abcdef"[ptr_val % 16];
                        ptr_val /= 16;
                    } while (ptr_val > 0);

                    while (--i >= 0)
                    {
                        buffer[buff_ind++] = temp_buff[i];
                        if (buff_ind == BUFF_SIZE)
                        {
                            print_buffer(buffer, &buff_ind);
                        }
                        count++;
                    }
                    count += 2; /* for the '0x' prefix */
                }
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
        fwrite(buffer, 1, *buff_ind, stdout);
    }

    *buff_ind = 0;
}

int main()
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    // _printf("Unsigned:[%u]\n", ui);
    // printf("Unsigned:[%u]\n", ui);
    // _printf("Unsigned octal:[%o]\n", ui);
    // printf("Unsigned octal:[%o]\n", ui);
    // _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    // printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    // _printf("Address:[%p]\n", addr);
    // printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    // _printf("Unknown:[%r]\n");
    // printf("Unknown:[%r]\n");
    return 0;
}