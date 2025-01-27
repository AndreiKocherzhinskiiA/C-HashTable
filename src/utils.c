/*
** EPITECH PROJECT, 2025
** B-CPE-110-BAR-1-1-secured-mark.charadnik
** File description:
** utils
*/

#include <unistd.h>
#include <stdlib.h>

void my_putchar(int error, char c)
{
    write(error, &c, 1);
}

void my_putstr(int error, char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        my_putchar(error, str[i]);
    }
}

int my_strlen(const char *str)
{
    int len = 0;

    for (int i = 0; str[i] != '\0'; i++)
        len++;
    return len;
}

static char *my_strcpy(char *dest, char const *src)
{
    int i;

    for (i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = src[i];
    return dest;
}

char *my_strdup(const char *src)
{
    int len = my_strlen(src);
    char *dest = malloc(len + 1);

    if (!dest)
        return NULL;
    my_strcpy(dest, src);
    return dest;
}

void my_putnum(int error, int c)
{
    int divisor = 1;

    while (c / divisor > 9) {
        divisor *= 10;
    }
    while (divisor > 0) {
        my_putchar(error, (c / divisor) % 10 + '0');
        c %= divisor;
        divisor /= 10;
    }
}
