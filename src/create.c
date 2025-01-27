/*
** EPITECH PROJECT, 2025
** B-CPE-110-BAR-1-1
** File description:
** create
*/

#include "../include/hashtable.h"
#include <stdlib.h>
#include <stdio.h>

hashtable_t *new_hashtable(int (*hash)(char *, int), int len)
{
    hashtable_t *ht = malloc(sizeof(hashtable_t));

    if (!ht || !hash)
        return NULL;
    ht->len = len;
    ht->hash = hash;
    ht->buckets = malloc(len * sizeof(node_t *));
    if (!ht->buckets) {
        free(ht);
        return NULL;
    }
    for (int i = 0; i < len; i++) {
        ht->buckets[i] = NULL;
    }
    return ht;
}

int main(void)
{
    hashtable_t *ht = new_hashtable(&hash, 4);

    if (!ht) {
        printf("[ERROR] Failed to create hashtable, exiting\n");
        return 1;
    }
    ht_insert(ht, "Vision", "./Documents/Vision.txt");
    ht_insert(ht, "Kratos", "./Trash/Kratos.ai");
    ht_insert(ht, "<3", "+33 6 31 45 61 23 71");
    ht_insert(ht, "</3", "+33 7 51 49 01 38 11");
    ht_dump(ht);
    printf("Searching 'Kratos': %s\n", ht_search(ht, "Kratos"));
    printf("Deleting 'Vision'\n");
    ht_delete(ht, "Vision");
    ht_dump(ht);
    delete_hashtable(ht);
    return 0;
}
