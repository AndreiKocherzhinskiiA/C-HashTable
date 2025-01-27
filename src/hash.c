/*
** EPITECH PROJECT, 2025
** B-CPE-110-BAR-1-1-secured-mark.charadnik
** File description:
** hash
*/

#include "../include/hashtable.h"
#include <stdlib.h>

int hash(char *key, int len)
{
    long hash = 5381;

    while (*key) {
        hash = (hash * 33) + *key;
        key++;
    }
    return (int)(hash % len);
}
