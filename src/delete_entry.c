/*
** EPITECH PROJECT, 2025
** B-CPE-110-BAR-1-1-secured-mark.charadnik
** File description:
** delete_entry
*/

#include "../include/hashtable.h"
#include <stdlib.h>

node_t *find_node(node_t *head, char *key, node_t **prev)
{
    *prev = NULL;
    while (head) {
        if (my_strcmp(head->key, key) == 0)
            return head;
        *prev = head;
        head = head->next;
    }
    return NULL;
}

void free_node(node_t *node)
{
    if (node) {
        free(node->key);
        free(node->value);
        free(node);
    }
}

int ht_delete(hashtable_t *ht, char *key)
{
    int index;
    node_t *prev = NULL;
    node_t *current;

    if (!ht || !key)
        return -1;
    index = ht->hash((char *)key, ht->len) % ht->len;
    current = find_node(ht->buckets[index], (char *)key, &prev);
    if (!current)
        return -1;
    if (prev)
        prev->next = current->next;
    else
        ht->buckets[index] = current->next;
    free_node(current);
    return 0;
}
