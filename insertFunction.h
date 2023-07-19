// for inserting a new node at the end of the linked list
void insAtEnd(struct node *head, int x)
{
    struct node *p, *temp;

    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;

    p = head;

    while (p->next != NULL)
        p = p->next;

    p->next = temp;

    totalNodes++;
}

// for inserting a new node at the beginning or at head 
// IGNORE THIS COMMENT FOR NOW : but the funtion insAtHead1() reture a pointer value to the main function, so the new function inAtHead() uses double pointer in one the arguments, thus allowing us not to reture any value

struct node * insAtHead1(struct node *head, int x)
{
    struct node *p, *temp;

    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;

    temp->next = head;
    head = temp;

    totalNodes++;

    return head;
}


/*

// for inserting a new node at the beginning or at head
// this function was working good, but for the function insAtPos() condition (y == 0 ), this function creates a problem which is solved  by the fucntion insAtHead1()
void insAtHead(struct node **head, int x)
{
    struct node *p, *temp;

    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;

    temp->next = *head;
    *head = temp;

    totalNodes++;
}
*/



// for inserting a new node at any index provided by the user
// im using return in the function because, for the condition of y == 0 and calling the functino inAtHead(&head,x) in the case requires triple pointer instead of double pointer being used in insAtHead(), so for this test case its better to use the function insAtHead1() which reture the head address but because of this now i need to reture an address of each condition, even when there are no changes in the head pointer, and this is working fine for now, as i wasnt able to come up with any other solution for calling insAtHead1() inside insAtPos()
struct node * insAtInd(struct node *head, int x, int y)
{
    // totalNodes++;

    if (y == 0)
    {
        struct node *p;
        cout << "yes its working:";
        // insAtHead(&head, x);

        p = insAtHead1(head,x);
        return p;
    }

    // cout << "outside if";

    else if (y == totalNodes - 1)
    {
        insAtEnd(head, x);
        return head;
    }

    else if(y > totalNodes- 1)
    {
        cout << "this index is not available in the link list, please try again and enter a valid index: ";
        return head;
    }

    else
    {

        struct node *p, *temp;
        int i;
        y--;

        temp = (struct node *)malloc(sizeof(struct node));

        temp->data = x;
        temp->next = NULL;

        p = head;

        // cout << "yes:";

        for (i = 0; i < y; i++)
        {
            if (p->next != NULL)
                p = p->next;
        }
        temp->next = p->next;
        p->next = temp;

        totalNodes++;

        return head;
    }


}


// cout << "no";
