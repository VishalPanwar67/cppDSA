// Find the first node of loop in linked list
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int x)
{
    struct Node *p;
    p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}

int findFirstNode(Node *head)
{
    // your code here
    Node *p = head;
    if (p == NULL)
    {
        return -1;
    }
    while (p != NULL)
    {
        if (p->data < 0)
        {
            return -(p->data);
        }
        p->data = -(p->data);
        p = p->next;
    }
    return -1;
}

void Display(struct Node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
int main()
{
    struct Node *a = createNode(1);
    struct Node *b = createNode(2);
    struct Node *c = createNode(3);
    struct Node *d = createNode(4);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = b;
    // Display(a);
    cout << findFirstNode(a) << endl;

    return 0;
}