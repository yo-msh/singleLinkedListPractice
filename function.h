
// for displaying linked list
void display(struct node *head)
{
    struct node *p;

    if (head == NULL)
    {
        cout << "no node to show, as the linked list is empty";
        return;
    }

    p = head;

    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

// for counting total number of nodes in a linked list and returning the cnt to the main funtion
/// commented out this fucntion because the fucntion cntNode() was calling it was calculting the the lenght each time which has time O(n), and not storing the reture value, thus with the introduction with the new global variable totalNodes keeping the he count in real time another function cntNode1() is begin used with has a avg-time of O(1)
/*
int cntNode(struct node * head)
{
    struct node * p;
    int cnt = 0;

    p = head;

    while(p != NULL)
    {
        cnt++;
        p = p->next;
    }

    return cnt;
}
*/

// for displaying total number of nodes
void cntNode1()
{
    cout << "total number of nodes with :" << totalNodes << endl;
}
