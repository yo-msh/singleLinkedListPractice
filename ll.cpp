#include <iostream>
#include "global.h"
#include "function.h"
#include "insertFunction.h"
#include "deleteFunction.h"

int main()
{
    // using variable 'x' : for any kind of data input and 'y' for inputing index
    // using variable 'ch' : for inputting user choice to perfrom which operation

    int x, y, ch;
    bool loop = true;

    struct node *head = NULL;

    head = (struct node *)malloc(sizeof(struct node));

    cout << "enter the first node data :" << endl;
    cin >> x;

    head->data = x;
    head->next = NULL;
    totalNodes++;

    while (loop)
    {
        cout << endl << endl
             << "select what u want to do :" << endl
             << "1. Display" << endl
             << "2. Count Nodes" << endl
             << "3. insAtEnd" << endl
             << "4. insAtHead" << endl
             << "5. insAtInd" << endl
             << "6. delAtEnd" << endl
             << "7. delAtHead" << endl
             << "8. delAtInd" << endl
             << "9. delEntireLinkerList" << endl

             << "20. Exit" << endl
             << endl;

        cin >> ch;

        cout << "your choice is number :: " << ch << endl
             << endl;

        switch (ch)
        {
        case 1:
            cout << "displaying all the concent in the linked list" << endl;
            display(head);
            break;

        case 2:
            // x = cntNode(head);
            // cout << "number of nodes are :" << x;
            cntNode1();
            break;

        case 3:
            cout << "enter new node at the end data at :";
            cin >> x;
            insAtEnd(head, x);
            break;

        case 4:
            cout << "enter new node at the beginning data :";
            cin >> x;
            // insAtHead(&head, x);
            head = insAtHead1(head, x);
            break;

        case 5:
            cout << "enter index :";
            cin >> y;
            cout << "enter new node at index " << y << " data :";
            cin >> x;
            head = insAtInd(head, x, y);
            break;

        case 6:
            delAtEnd(head);
            break;

        case 7:
            head = delAtHead(head);
            break;

        case 8:
            cout << "enter the index of the node you want to delete :";
            cin >> y;
            head = delAtInd(head,y);
            break;
        case 9:
            head = delEntireLinkerList(head);
            break;


        case 20:
            loop = false;
            cout << "exiting";
            break;
        }
    }

    return 0;
}
