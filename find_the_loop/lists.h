#ifndef LISTS_H
#define LISTS_H

#include <stddef.h>

/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 */
typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;

size_t print_listint_safe(const listint_t *head);
listint_t *add_nodeint(listint_t **head, const int n);
void free_listint(listint_t *head);
size_t free_listint_safe(listint_t **h);  /* ✅ Correct return type */
listint_t *find_listint_loop(listint_t *head);

#endif
