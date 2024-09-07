#include <iostream>
#include <bits/stdc++.h>
#include "BSTmain.cpp"
using namespace std;

void preOreder(struct Node *p)
{
    if (p != NULL)
    {
        cout << p->data << " ";
        preOreder(p->lchild);
        preOreder(p->rchild);
    }
}

void itpreOrder(struct Node *p)
{
    if (root == nullptr)
        return;
    stack<Node *> stack;
    stack.push(root);

    while (!stack.empty())
    {
        Node *temp = stack.top();
        stack.pop();

        cout << temp->data << " ";

        if (temp->rchild)
        {
            stack.push(temp->rchild);
        }

        if (temp->lchild)
        {
            stack.push(temp->lchild);
        }
    }
}

void inOrder(struct Node *p)
{
    if (p != NULL)
    {
        inOrder(p->lchild);
        cout << p->data << " ";
        inOrder(p->rchild);
    }
}
void itinOrder(struct Node *p)
{
    if (root == NULL)
    {
        return;
    }
    stack<Node *> stack;
    Node *curr = root;

    while (!stack.empty() || curr != nullptr)
    {
        if (curr != nullptr)
        {
            stack.push(curr);
            curr = curr->lchild;
        }
        else
        {
            curr = stack.top();
            stack.pop();
            cout << curr->data << " ";

            curr = curr->rchild;
        }
    }
}

void postOrder(struct Node *p)
{
    if (root == NULL)
    {
        return;
    }
    stack<int> out;
    stack<Node *> stack;
    stack.push(root);
    while (!stack.empty())
    {
        Node *temp = stack.top();
        stack.pop();
        out.push(temp->data);
        // cout << temp->data << " ";
        if (temp->lchild)
        {
            stack.push(temp->lchild);
        }
        if (temp->rchild)
        {
            stack.push(temp->rchild);
        }
    }
    while (!out.empty())
    {
        cout << out.top() << " ";
        out.pop();
    }
}
int main()
{

    createBST();
    // preOreder(root);
    cout << endl;
    itpreOrder(root);
    cout << endl;

    itinOrder(root);
    cout << endl;
    postOrder(root);
    return 0;
}