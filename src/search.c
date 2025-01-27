/*
** EPITECH PROJECT, 2025
** B-CPE-110-BAR-1-1-secured-mark.charadnik
** File description:
** search
*/

#include "../include/hashtable.h"
#include <stddef.h>

char *ht_search(hashtable_t *ht, char *key)
{
    int index;
    node_t *current;

    if (!ht || !key)
        return NULL;
    index = ht->hash(key, ht->len) % ht->len;
    current = ht->buckets[index];
    while (current) {
        if (my_strcmp(current->key, key) == 0)
            return current->value;
        current = current->next;
    }
    return NULL;
}
