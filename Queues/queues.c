#include<stdio.h>
int queue[10], size, i, choice, rear, front = -1, max;
void enqueue();
void dequeue();
void peek();
int IsFull();
int IsEmpty();
void display();

int main ()
{
    printf("enter the maximum value: ");
    scanf("%d", &max);
    queue[max];
    rear = -1;

    while(1)
    {
        printf("\n\noperations:\nenter\n");
        printf("1-enqueue 2-dequeue 3-peek 4- Exit\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            enqueue();
            break;

            case 2:
            dequeue();
            break;

            case 3:
            peek();
            break;

            case 4:
            exit(1);

            default:
            printf("error\n");
            break;
        }
    }

}

void enqueue()
{
    int x;
    if (IsFull())
    {
        printf("\nQueue overflow\n");
    }
    else
    {
        if(front == -1)
        {
            front = 0;
        }
        printf("enter the element to be inserted: ");
        scanf("%d", &x);
        rear = rear + 1;
        queue[rear] = x;
        display();
    }
}
int IsFull()
{
    if(rear == max-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void dequeue()
{
    if (IsEmpty())
    {
        printf("\nQueue Underflow\n");
    }
    else
    {
        front = front + 1;
        display();
    }
}
int IsEmpty()
{
    if(front == -1 || front>rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void peek()
{
    int peik;
    peik = queue[rear];
    printf("\nrear element is: %d", peik);
}

void display()
{
    if (IsEmpty())
    {
        printf("\nThe queue is empty.\n");
    }
    else
    {
        int i;
        printf("\nQUEUE: ");
        for(i=front; i<=rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
}
