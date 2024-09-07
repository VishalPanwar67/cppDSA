// Move last element to front of a given Linked List
#include <iostream>
#include <bits/stdc++.h>
#include "BaseLL.cpp"
using namespace std;

void moveToFront(struct Node **first)
{
    struct Node *p, *q, *r;
    p = *first;
    q = r = NULL;
    while (p != NULL)
    {
        if (p->next == NULL)
        {

            r = p;
            q->next = NULL;
            r->next = *first;
            break;
        }
        else
        {
            q = p;
        }
        p = p->next;
    }
    *first = r;
}

int main()
{
    createLL();
    Display();
    moveToFront(&first);
    Display();
    return 0;
}