#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

struct list
{
    int id;
    list *next;
};

void build(list *head);

void push(list **head, int id);
void print(list *head);
void push_before(list **head, int marker, int id);
void push_after(list *head, int marker, int id);
void push_tail(list *head, int id);
int pop(list **head);
int pop_last(list *head);
void pop_marker(list **head, int marker);
void pop_after(list *head, int marker);
void individual(list *head);


#endif // LIST_H_INCLUDED
