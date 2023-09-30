    #include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};

void peek();
void enqueue();
void dequeue();
void display();
struct node *front = NULL, *rear = NULL;

int main()
{
    int op;
    do
    {
    printf("\n--------------------------------\n");
    printf("\n1.Insert\n2.Delete\n3.Peek\n4.Display\n0.Exit\n");
    printf("\nOP: ");
    scanf("%d", &op);
    switch(op)
    {
        case 1 :
            enqueue();
            break;
        case 2 :
            dequeue();
            break;
        case 3 :
            peek();
            break;
        case 4 :
            display();
            break;
        }
    }
    while(op != 0);
    return(0);
}
void peek()
{
    if(front != NULL)
    {
        printf("\nThe peek element is : %d \n", rear->data);
    }
}

void enqueue()
{
    struct node *tmp;
    tmp = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data to insert : ");
    scanf("%d", &tmp->data);
    if(front == NULL)
    {
        rear = front = tmp;
        tmp->link = tmp;
    }
    else
    {
        rear->link = tmp;
        tmp->link = front;
        rear = tmp;
    }
 }
void dequeue()
{
    struct node *tmp;
    if(front != NULL)
    {
        if(front->link == front)
        {
            tmp = front;
            front = NULL;
            free(tmp);
        }
        else
        {
            tmp = front;
            front = front->link;
            rear->link = front;
            free(tmp);
        }
    }
    else 
    {
     printf("\nUNDERFLOW\n");
    }

    display();
 }
void display()
{
    struct node *p;
    if(front == NULL)
    {
        printf("EMPTY LIST\n");
    }
    else
    {
            p = front;
            printf("\nQUEUE IS :");
        do
        {
            printf(" %d ", p->data);
            p = p->link;
        }while(p != front);
        
        printf("\n");
    }
}