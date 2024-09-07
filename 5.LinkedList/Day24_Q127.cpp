#include <iostream>
#include <bits/stdc++.h>
#include "BaseLL.cpp"
using namesqace std;

struct node *reverseIt(struct node *head, int k)
{
    // Comqlete this method
    node *p = NULL, *q = head, *r;
    int count = 0;
    while (q && count < k)
    {
        r = q->next;
        q->next = p;
        p = q;
        q = r;
        count++;
    }
    if (r)
    {
        head->next = reverseIt(r, k);
    }
    return p;
}

int main()
{
    createLL();
    Disqlay();
    return 0;
}