// Day 26
//  Q137: Intersection Point in Y Shaped Linked Lists

int intersectPoint(Node *head1, Node *head2)
{
    // Your Code Here
    Node *p = head1, *q = head2;

    while (1)
    {
        if (p == q)
        {
            return p->data;
        }
        p = p->next;
        q = q->next;

        if (p == NULL and q == NULL)
        {
            return -1;
        }

        if (p == NULL)
        {
            p = head2;
        }
        if (q == NULL)
        {
            q = head1;
        }
    }
    return -1;
}

// Q136: Intersection of two sorted Linked lists
Node *findIntersection(Node *head1, Node *head2)
{
    // code goes here.
    Node *result = new Node(-1);
    Node *ans = result;
    Node *p = head1;
    Node *q = head2;
    while (p && q)
    {
        if (p->data == q->data)
        {
            ans->next = new Node(p->data);
            ans = ans->next;
            p = p->next;
            q = q->next;
        }
        else if (p->data > q->data)
        {
            q = q->next;
        }
        else if (q->data > p->data)
        {
            p = p->next;
        }
    }
    return result->next;
}

// Q135: Add two numbers represented by linked lists
Node *reverse(Node *head)
{
    if (!head || !head->next)
        return head;

    Node *prev = NULL, *curr = head;

    while (curr)
    {
        Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    return prev;
}
struct Node *addTwoLists(struct Node *first, struct Node *second)
{
    // code here
    Node *dummy = new Node(0);
    Node *ans = dummy;
    first = reverse(first);
    second = reverse(second);
    int carry = 0;
    while (first != NULL || second != NULL || carry != 0)
    {
        int newval = 0;
        int sum = 0;
        if (first != NULL)
        {
            newval += first->data;
            first = first->next;
        }
        if (second != NULL)
        {
            newval += second->data;
            second = second->next;
        }
        newval += carry;
        sum = newval % 10;
        carry = newval / 10;
        Node *newnode = new Node(sum);
        ans->next = newnode;
        ans = ans->next;
    }
    Node *temp = dummy;
    dummy = dummy->next;
    delete (temp);

    return reverse(dummy);
}
