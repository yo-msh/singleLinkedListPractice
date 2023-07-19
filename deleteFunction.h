
// for deleting the last node from the linked list

void delAtEnd(struct node *head)
{
    struct node *p, *q;
    p = head;

    while (p->next != NULL)
    {
        q = p;
        p = p->next;
    }

    q->next = NULL;
    free(p);
    cout << "sucessfully deleted the last node from linked list";
    totalNodes--;
}

// for deleting the head or the beginning node from the linked list

struct node *delAtHead(struct node *head)
{
    struct node *p;
    p = head;

    head = head->next;

    free(p);

    cout << "sucessfully deleted the head/beginning node form linked list";
    totalNodes--;
    return head;
}

// for deleting the node from the inputted/given index from the user

struct node *delAtInd(struct node *head, int y)
{
    if (y == 0)
    {
        struct node *p;
        p = delAtHead(head);
        return p;
    }

    else if (y == totalNodes - 1)
    {
        delAtEnd(head);
        return head;
    }

    else if(y > totalNodes- 1)
    {
        cout << "this index is not available in the link list, please try again and enter a valid index: ";
        return head;
    }

    else
    {
        struct node *p, *q;
        p = head;

        for (int i = 0; i < y; i++)
        {
            q = p;
            p = p->next;
        }

        q->next = p->next;
        p->next = NULL;
        free(p);

        totalNodes--;

        return head;
    }
}

// function for deleting an entire linked list

struct node * delEntireLinkerList (struct node * head)
{
    struct node *p,*q;
    p = head;

    while(p != NULL)
    {   q = p;
        p = p->next;
        free(q);
    }
    head = NULL;

    cout << "deleted the entire linked list successfully ";
    totalNodes = 0;
    
    return head;
}