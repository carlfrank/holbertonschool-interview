#include "lists.h"

/**
 * reverse_list - Reverses a linked list
 * @head: Pointer to the head of the list
 * Return: Pointer to the new head
 */
listint_t *reverse_list(listint_t *head)
{
    listint_t *prev = NULL;
    listint_t *current = head;
    listint_t *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

/**
 * is_palindrome - Checks if a singly linked list is a palindrome
 * @head: Double pointer to the head of the list
 * Return: 1 if palindrome, 0 if not
 */
int is_palindrome(listint_t **head)
{
    listint_t *slow = *head;
    listint_t *fast = *head;
    listint_t *second_half, *prev_slow = *head;
    int is_palindrome = 1;

    /* Empty list or single node */
    if (*head == NULL || (*head)->next == NULL)
        return (1);

    /* Find the middle using slow/fast pointer technique */
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        prev_slow = slow;
        slow = slow->next;
    }

    /* If odd number of nodes, skip the middle node */
    if (fast != NULL)
    {
        slow = slow->next;
    }

    /* Reverse the second half */
    second_half = reverse_list(slow);
    
    /* Compare first half with second half */
    listint_t *temp = *head;
    listint_t *temp_second = second_half;
    
    while (temp_second != NULL)
    {
        if (temp->n != temp_second->n)
        {
            is_palindrome = 0;
            break;
        }
        temp = temp->next;
        temp_second = temp_second->next;
    }

    /* Restore the list (optional) */
    reverse_list(second_half);
    
    return is_palindrome;
}