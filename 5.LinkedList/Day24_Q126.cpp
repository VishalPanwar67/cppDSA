// Reverse a Linked List
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
void createLL(){
    int num, i{1};
    cout << "Enter the no. of node you want to create: " << endl;
    cin >> num;
    while (i <= num){
        int ele;
        cout << "Enter the no. for " << i << " node :";
        cin >> ele;
        createInsLL(ele);
        i++;
    }
}
void Display(){
    struct Node *p = first;
    if (p == NULL){
        cout << "LL is Empty";
        return;
    }
    cout << "The Linklist is: " << endl;
    while (p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void *reverseList(struct Node *head)
{
    struct Node *p, *q, *r;
    p = head;
    q = r = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
}
int main()
{
    createLL();
    Display();
    reverseList(first);
    Display();

    return 0;
}