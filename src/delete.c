/*
** EPITECH PROJECT, 2025
** B-CPE-110-BAR-1-1-secured-mark.charadnik
** File description:
** delete
*/

#include "../include/hashtable.h"
#include <stdlib.h>

void free_nodes(node_t *node)
{
    node_t *temp;

    while (node) {
        temp = node;
        node = node->next;
        if (temp->key){
            free(temp->key);
        }
        if (temp->value) {
            free(temp->value);
        }
        free(temp);
    }
}

void delete_hashtable(hashtable_t *ht)
{
    int i;

    if (!ht) {
        return;
    }
    for (i = 0; i < ht->len; i++) {
        if (ht->buckets[i]) {
            free_nodes(ht->buckets[i]);
            ht->buckets[i] = NULL;
        }
    }
    free(ht->buckets);
    ht->buckets = NULL;
    free(ht);
}
