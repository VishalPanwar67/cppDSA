// Remove loop in Linked List

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

void removeLoop(Node *head)
{
    // code here
    // just remove the loop without losing any nodes
    Node *p = head;
    Node *q = head;
    Node *r = NULL;
    while (q != NULL && q->next != NULL)
    {
        p = p->next;
        r = q->next;
        q = q->next->next;
        if (p == q)
        {
            p = head;
            while (p != q)
            {
                p = p->next;
                r = q;
                q = q->next;
            }
            r->next = NULL;
            break;
        }
    }
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