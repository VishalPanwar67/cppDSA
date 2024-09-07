#include <iostream>
#include <bits/stdc++.h>
#include "BaseLL.cpp"
using namespace std;

void removeDuplicates(Node *head)
{
    unordered_set<int> store;
    Node *p, *q;
    p = head;
    q = NULL;
    while (p != NULL)
    {
        if (store.find(p->data) != store.end())
        {
            q->next = p->next;
            delete (p);
            // p = q->next;
        }
        else
        {
            store.insert(p->data);
            q = p;
        }
        p = p->next;
    }
}

int main()
{
    createLL();
    Display();
    removeDuplicates(first);
    Display();
    return 0;
}