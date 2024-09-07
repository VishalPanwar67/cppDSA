#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
} *root = NULL;

void InsertBST(int key)
{
    struct Node *t = root;
    struct Node *r, *p;
    if (root == NULL)
    {
        p = new Node;
        p->lchild = NULL;
        p->rchild = NULL;
        p->data = key;
        root = p;
        return;
    }
    while (t != NULL)
    {
        r = t;
        if (key < t->data)
        {
            t = t->lchild;
        }
        else if (key > t->data)
        {
            t = t->rchild;
        }
        else
        {
            return;
        }
    }
    p = new Node;
    p->data = key;
    p->lchild = NULL;
    p->rchild = NULL;
    if (key < r->data)
    {
        r->lchild = p;
    }
    else
    {
        r->rchild = p;
    }
}

void inoredBST(struct Node *p)
{

    if (p != NULL)
    {
        inoredBST(p->lchild);
        cout << p->data << " ";
        inoredBST(p->rchild);
    }
}

struct Node *searchBST(int key)
{
    struct Node *p = root;
    while (p != NULL)
    {
        if (key == p->data)
        {
            return p;
        }
        else if (key < p->data)
        {
            p = p->lchild;
        }
        else
        {
            p = p->rchild;
        }
    }
    return NULL;
}

int main()
{
    int times, num;
    struct Node *temp;
    cout << "Enter the no. of the Nodes; ";
    cin >> times;
    while (times > 0)
    {
        cout << "Enter the no. you want to insert in BST: ";
        cin >> num;
        InsertBST(num);
        times--;
    }
    cout << "\tThe InOrder of BST is: " << endl;
    inoredBST(root);
    cout << endl;
    temp = searchBST(5);
    if (temp != NULL)
    {
        cout << "Element is found" << endl;
    }
    else
    {
        cout << "Element is not found" << endl;
    }

    return 0;
}