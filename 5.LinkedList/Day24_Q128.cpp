// detectLoop
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

bool detectLoop(struct Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return false;
    }
    Node *p, *q;
    p = head;
    q = head->next;
    while (p != q)
    {
        if (q == NULL || q->next == NULL)
        {
            return false;
        }
        p = p->next;
        q = q->next->next;
    }
    return true;
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
    cout << detectLoop(a) << endl;

    return 0;
}