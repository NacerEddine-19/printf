#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = print("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    print("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    print("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    print("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    print("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    print("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    print("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    print("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    print("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = print("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    print("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    print("Unknown:[%r]\n");
    printf("Unknown:[%r]\n");
    return (0);
}