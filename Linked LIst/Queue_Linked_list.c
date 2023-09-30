#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int data;
    struct queue *link;
};

struct queue *front = NULL;

struct queue* add_queue(struct queue *front, int elem)
{
    struct queue *tmp;
    tmp = (struct queue* )malloc(sizeof(struct queue));
    if(front == NULL)
    {
        tmp -> data = elem;
        tmp->link = NULL;
        front = tmp;
        return front;
    }
    else
    {
        struct queue *p;
        p = front;
        while(p->link!=NULL)
        {
            p=p->link;
        }
        tmp -> data = elem;
        tmp->link = NULL;
        p->link = tmp;
        return front;
    }
}

struct queue* del_queue(struct queue* front)
{
    struct queue *tmp;
    tmp = (struct queue*)malloc(sizeof(struct queue));
    if(front == NULL)
    {
        printf("*****QUEUE IS EMPTY*****");
    }
    else
    {
        tmp = front;
        front = front->link;
        free(tmp);
        printf("\n");
        display(front);
    }
    return front;
}

void display(struct queue *front)
{
    if(front == NULL)
    {
        printf("*****QUEUE IS EMPTY*****");
    }
    else
    {
        struct queue *p;
        p = front;
        printf("QUEUE: ");
        while(p!=NULL)
        {
            printf("%d ", p->data);
            p = p->link;
        }
    }
}
int main()
{
    int OP;
    do
    {
        printf("\n-----------------------------\n");
        printf("1.ADD AN ELEMENT\n2.DELETE AN ELEMENT\n3.DISPLAY\n0.EXIT\n\nOperation: ");
        scanf("%d", &OP);
        switch(OP)
        {
            case 1:
            {
                int element;
                printf("enter the elemen to enter: ");
                scanf("%d", &element);
                front = add_queue(front, element);
            }
            break;

            case 2:
            {
                front = del_queue(front);
            }
            break;

            case 3:
            {
                display(front);
            }
            break;
        }
    }while(OP!=0);
    return 0;
}
