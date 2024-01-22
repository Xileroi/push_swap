#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"

/*
1 -> 5

5 -> 4

4 -> NULL

9

*/

void free_stack(t_pile **stack)
{
    t_pile *tmp = *stack;
    t_pile *tmp_del;
    while (tmp != NULL)
    {
        tmp_del = tmp;
        tmp = tmp->next;
        free(tmp_del);
    }
    *stack = NULL;
}


void dell_value(t_pile **stack, int value)
{
    t_pile *tmp = *stack;
    while (tmp != NULL && tmp->next != NULL && tmp->next->valeur != value)
    {
        tmp = tmp->next;
    }
    if (tmp->next == NULL)
    {
        if (tmp->valeur = value)
        {
            free(tmp);
            *stack = NULL;
        }
        else
        {
            //value existe pas 
            return ;
        }
    }
    t_pile *del = tmp->next;
    tmp->next = tmp->next->next;
    free(del);
}

void print_stack(t_pile **stack)
{
    t_pile *tmp = *stack;
    while (tmp != NULL)
    {
        printf("%d\n", tmp->valeur);
        tmp = tmp->next;
    }
}

int add_maillon(t_pile **stack, int value)
{
    t_pile *tmp = *stack;
    while (tmp != NULL && tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    t_pile *maillon = malloc(sizeof(t_pile));
    if (maillon == NULL)
    {
        return -1;
    }
    maillon->valeur = value;
    maillon->next = NULL;
    tmp->next = maillon;
}

int main()
{
    t_pile *stack = malloc(sizeof(t_pile));
    if (stack == NULL)
    {
        //error malloc (a free)
        return (0);
    }
    stack->valeur = 1;
    stack->next = NULL;
    if (add_maillon(&stack, 5) == -1)
    {
        //error malloc (a free)
        return (0);
    }
    if (add_maillon(&stack, 4) == -1)
    {
        //error malloc (a free)
        return (0);
    }
    if (add_maillon(&stack, 9) == -1)
    {
        //error malloc (a free)
        return (0);
    }
    print_stack(&stack);
    dell_value(&stack, 4);
    printf("\n\n");
    print_stack(&stack);
    free_stack(&stack);
}
