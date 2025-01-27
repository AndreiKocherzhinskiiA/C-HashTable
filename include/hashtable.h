/*
** EPITECH PROJECT, 2025
** B-CPE-110-BAR-1-1-secured-mark.charadnik
** File description:
** hashtable
*/

#ifndef HASHTABLE_H_
    #define HASHTABLE_H_

typedef struct node_s {
    char *key;
    char *value;
    struct node_s *next;
} node_t;

typedef struct hashtable_s {
    node_t **buckets;
    int len;
    int (*hash)(char *, int);
} hashtable_t;

int my_strcmp(char const *s1, char const *s2);
void my_putchar(int error, char c);
int my_strlen(const char *str);
void my_putstr(int error, char *str);
void my_putnum(int error, int c);
char *my_strdup(const char *src);
hashtable_t *new_hashtable(int (*hash)(char *, int), int len);
int ht_insert(hashtable_t *ht, char *key, char *value);
void delete_hashtable(hashtable_t *ht);
void free_nodes(node_t *node);
void ht_dump(hashtable_t *ht);
char *ht_search(hashtable_t *ht, char *key);
int hash(char *key, int len);
int ht_delete(hashtable_t *ht, char *key);
void free_node(node_t *node);
node_t *find_node(node_t *head, char *key, node_t **prev);



#endif /* !HASHTABLE_H_ */
