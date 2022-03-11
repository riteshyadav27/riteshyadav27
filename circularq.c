#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL, *newnode, *temp, *tail = NULL;

int main()
{
    int choice, data;
    printf("\nQUEUE using Linked list");
    do
    {
        printf("\nPress 1 to Enqueue");
        printf("\nPress 2 to Dequeue");
    //    printf("\nPress 3 to Display");
        printf("\nPress 0 to Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter Data to insert in Queue : ");
            scanf("%d", &data);
            enqueue(data);
            break;
        case 2:
            dequeue();
            break;
       /* case 3:
            display();
            break;
        */
        case 0:
            printf("\nEXIT!!!");
            break;
        default:
            printf("ERROR !!! Enter correct choice ");
            break;
        }
    } while (choice);
}
void enqueue(int data)
{

    newnode = (struct node *)malloc(sizeof(struct node *));
    newnode->data = data;
    newnode->next = NULL;
    if (head == NULL && tail == NULL)
    {
        head = tail = newnode;
    }
    else
    {
        tail->next = newnode;
        tail = newnode;
    }
    tail->next = head;
}

void dequeue()
{
    temp = head;
    if (head == NULL && tail == NULL)
    {
        printf("\nQueue is empty");
    }

    else if (head == tail)
    {
        printf("\nThe Dequeue element is : %d ", temp->data);
        head = tail = NULL;
        free(temp);
    }
    else
    {
        printf("\nThe Dequeue element is : %d ", head->data);
        head = head->next;
        tail->next=head;
        free(temp);
    }
}

/*
void display()
{
    temp = head;
    if (head == NULL && tail == NULL)
    {
        printf("\nQueue is empty");
    }
    else
    {
        printf("\nElement present in the Queue :");
        do
        {
            printf(" %d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
}
*/
