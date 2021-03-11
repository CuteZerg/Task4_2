#include <iostream>
#include "List.h"

using namespace std;


void build(list *head)
{
    list *tmp = head;
    for(int i = 0;i < 5;i++)
    {
        list *el = new list;
        tmp->next = el;
        el->next = NULL;
        el->id = rand() % 20 + 1;
        tmp = tmp->next;
    }
}


void print(list *head)
{
    list *tmp = head;
    while (tmp->next != NULL)
    {
        cout << tmp->id << " ";
        tmp = tmp->next;
    }
    cout << tmp->id << endl;
}


void push(list **head,int id)
{
    list *tmp = new list;
    tmp->id = id;
    tmp->next = *head;
    *head = tmp;
}


void push_before(list **head,int marker, int id)
{
    list *ptr = *head;

    if ((*head)->id == marker)
    {
       push(&(*head), id);
       return;
    }

    while(true)
    {
        if (ptr->next->id != marker)
        {
            if (ptr->next->next == NULL)
            {
                cout << "ƒанного числа не было обнаружено в списке:(" << endl;
                return;
            }
            ptr = ptr->next;
        }
        else
            break;
    }
    list *tmp = ptr;
    ptr = ptr->next;
    list *el = new list;
    tmp->next = el;
    el->id = id;
    el->next = ptr;
}


void push_after(list *head,int marker, int id)
{
    while(true)
    {
        if (head->id != marker)
        {
            if (head->next == NULL)
            {
                cout << "ƒанного числа не было обнаружено в списке:(" << endl;
                return;
            }
            head = head->next;
        }
        else
            break;
    }
    list *el = new list;
    el->id = id;
    el->next = head->next;
    head->next = el;
}


void push_tail(list *head, int id)
{
    while(head->next != NULL)
        head = head->next;
    list *el = new list;
    head->next = el;
    el->id = id;
    el->next = NULL;
}


int pop(list **head)
{
    int res = (*head)->id;
    list *tmp = *head;
    *head = (*head)->next;
    delete tmp;

    return res;
}


int pop_last(list *head)
{
    while(head->next->next != NULL)
        head = head->next;
    list *tmp = head;
    tmp = tmp->next;
    delete tmp;
    head->next = NULL;
}


void pop_marker(list **head, int marker)
{
    list *tmp = *head;
    if ((*head)->id == marker)
    {
        pop(&(*head));
        return;
    }

    while(true)
    {
        if (tmp->next->id != marker)
        {
            if (tmp->next->next == NULL)
            {
                cout << "ƒанного числа не было обнаружено в списке:(" << endl;
                return;
            }
            tmp = tmp->next;
        }
        else
            break;
    }
    list *ptr = tmp;
    ptr = ptr->next;
    tmp->next = tmp->next->next;
    delete ptr;
}


void pop_after(list *head, int marker)
{
    while(true)
    {
        if (head->id != marker)
        {
            if (head->next->next == NULL)
            {
                cout << "ƒанного числа не было обнаружено в списке:(" << endl;
                return;
            }
            head = head->next;
        }
        else
            break;
    }

    list *tmp = head;
    tmp = tmp->next;
    head->next = head->next->next;
    delete tmp;
}



void individual(list *head)
{
    while (head->next != NULL)
    {
        if (head->id == head->next->id)
            pop_after(head, head->id);
        else
            head = head->next;
    }
}
