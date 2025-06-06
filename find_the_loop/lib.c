#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * add_nodeint - adds a new node at the beginning of a listint_t list
 * @head: pointer to a pointer to the start of the list
 * @n: value to add
 * Return: address of the new element, or NULL if failed
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
    listint_t *new = malloc(sizeof(listint_t));
    if (!new)
        return (NULL);
    new->n = n;
    new->next = *head;
    *head = new;
    return (new);
}

/**
 * print_listint_safe - prints a listint_t list, safely handling loops
 * @head: pointer to head
 * Return: number of nodes printed
 */
size_t print_listint_safe(const listint_t *head)
{
    const listint_t *slow = head, *fast = head;
    size_t count = 0;
    int loop = 0;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            loop = 1;
            break;
        }
    }

    slow = head;
    while (head)
    {
        printf("[%p] %d\n", (void *)head, head->n);
        count++;
        if (loop && head == fast)
        {
            printf("-> [%p] %d\n", (void *)head, head->n);
            break;
        }
        head = head->next;
    }
    return (count);
}

/**
 * free_listint_safe - frees a listint_t list even if it has a loop
 * @h: pointer to pointer to head
 * Return: number of nodes freed
 */
size_t free_listint_safe(listint_t **h)
{
    size_t count = 0;
    listint_t *temp;
    listint_t *slow = *h, *fast = *h;

    if (!h || !*h)
        return (0);

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }

    if (slow == fast)
    {
        slow = *h;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        listint_t *loop_start = slow;
        do {
            temp = (*h)->next;
            free(*h);
            *h = temp;
            count++;
        } while (*h != loop_start);

        *h = NULL;
        return (count);
    }

    while (*h)
    {
        temp = (*h)->next;
        free(*h);
        *h = temp;
        count++;
    }

    return (count);
}

/**
 * free_listint - frees a regular list
 * @head: pointer to head
 */
void free_listint(listint_t *head)
{
    listint_t *tmp;

    while (head)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}
