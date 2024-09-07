#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first, *last = NULL;

void createInsLL(int x)
{
    struct Node *p;
    p = new Node;
    p->data = x;
    p->next = NULL;
    if (first == NULL)
    {
        first = p;
        last = p;
    }
    else
    {
        last->next = p;
        last = p;
    }
}
void createLL()
{
    int num, i{1};
    cout << "Enter the no. of node you want to create: " << endl;
    cin >> num;
    while (i <= num)
    {
        int ele;
        cout << "Enter the no. for " << i << " node :";
        cin >> ele;
        createInsLL(ele);
        i++;
    }
}

Node *insertionSort(struct Node *head)
{
    // code here
    Node *p = head, *q = head, *r = head;
    while (p != nullptr)
    {
        r = p;
        q = p;
        while (q != nullptr)
        {
            if (q->data < r->data)
            {
                r = q;
            }
            q = q->next;
        }
        swap(r->data, p->data);
        p = p->next;
    }
    return head;
}

void Display(struct Node *p)
{
    // struct Node *p = first;
    if (p == NULL)
    {
        cout << "LL is Empty";
        return;
    }
    cout << "The Linklist is: " << endl;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    createLL();
    Display(first);
    struct Node *disp = insertionSort(first);

    Display(disp);
    return 0;
}