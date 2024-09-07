// Add 1 to a number represented as linked list gfg
#include <iostream>
#include <bits/stdc++.h>
#include "BaseLL.cpp"
using namespace std;

int f(Node *head)
{
    if (head->next == NULL)
    {
        int carry = (head->data + 1) / 10;
        head->data = (head->data + 1) % 10;
        return carry;
    }
    int carry = f(head->next);
    int newCarry = (head->data + carry) / 10;
    head->data = (head->data + carry) % 10;
    return newCarry;
}
Node *addOne(Node *head)
{
    // Your Code here
    // return head of list after adding one
    int carry = f(head);
    if (carry != 0)
    {
        Node *newNode = new Node(carry);
        newNode->next = head;
        head = newNode;
    }
    return head;
}

void reverseLL(struct Node **head)
{
    struct Node *p, *q, *r;
    p = *head;
    q = r = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    *head = q;
}

void addOne(Node **head)
{
    // Your Code here
    // return head of list after adding one
    reverseLL(head);
    // Display();
    Node *p = *head;
    Node *q = NULL;
    int carry{0};

    while (p != NULL)
    {
        if (p->data == 9)
        {
            p->data = 0;
            carry++;
        }
        else
        {
            p->data += 1;
            carry--;
            break;
        }
        q = p;
        p = p->next;
    }
    reverseLL(head);
    cout << carry << " carry" << endl;
    if (carry >= 1)
    {
        struct Node *t;
        t = new Node;
        t->data = 1;
        t->next = *head;
        *head = t;
    }
}

int main()
{
    createLL();
    Display();
    // reverseLL(&first);
    // addOne(&first);
    addOne2(first);
    Display();
    return 0;
}