// Remove duplicate element from sorted Linked List
#include <iostream>
#include <bits/stdc++.h>
#include "BaseLL.cpp"
using namespace std;

void removeDuplicates(struct Node *first)
{
    // your code goes here
    Node *p, *q;
    p = first;
    q = p->next;
    while (q != NULL)
    {
        if (p->data == q->data)
        {
            p->next = q->next;
            delete (q);
            q = p->next;
        }
        else
        {
            p = q;
            q = q->next;
        }
    }
}

int main()
{
    createLL();
    Display();
    removeDuplicates(first);
    cout << "Panwar" << endl;
    Display();
    return 0;
}