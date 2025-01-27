/*
** EPITECH PROJECT, 2025
** B-CPE-110-BAR-1-1-secured-mark.charadnik
** File description:
** insert
*/

#include "../include/hashtable.h"
#include <stdlib.h>

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    int index;
    node_t *new_node;

    if (!ht)
        return -1;
    index = ht->hash(key, ht->len) % ht->len;
    new_node = (node_t *)malloc(sizeof(node_t));
    if (!new_node)
        return -1;
    new_node->key = my_strdup(key);
    new_node->value = my_strdup(value);
    if (!new_node->key || !new_node->value) {
        free(new_node->key);
        free(new_node->value);
        free(new_node);
        return -1;
    }
    new_node->next = ht->buckets[index];
    ht->buckets[index] = new_node;
    return 0;
}

void ht_dump(hashtable_t *ht)
{
    node_t *current;

    if (!ht)
        return;
    for (int i = 0; i < ht->len; i++) {
        my_putchar(1, '[');
        my_putnum(1, i);
        my_putstr(1, "]: ");
        current = ht->buckets[i];
        while (current) {
            my_putstr(1, "> ");
            my_putstr(1, current->key);
            my_putstr(1, " - ");
            my_putstr(1, current->value);
            my_putchar(1, ' ');
            current = current->next;
        }
        my_putchar(1, '\n');
    }
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] && s2[i]) {
        if (s1[i] != s2[i]) {
            return s1[i] - s2[i];
        }
        i++;
    }
    if (s1[i] == '\0' && s2[i] == '\0') {
        return 0;
    }
    return s1[i] - s2[i];
}
