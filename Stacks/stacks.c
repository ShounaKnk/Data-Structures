#include<stdio.h>
#include<stdlib.h>
int stack[10], size, i, choice, top, max;
void push();
void pop();
void peek();
int isfull();
int isempty();
void display();

int main ()
{
    printf("enter the maximum value: ");
    scanf("%d", &max);
    stack[max];
    top = -1;

    while(1)
    {
        printf("\n\noperations:\nenter\n");
        printf("1-push 2-pop 3-peek 4- Exit\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            push();
            break;

            case 2:
            pop();
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

void push()
{
    int x;
    if (isfull())
    {
        printf("Stack overflow\n");
    }
    else
    {
        top += 1;
        printf("enter the element to be inserted: ");
        scanf("%d", &x);
        stack[top] = x;
        display();
    }
}
int isfull()
{
    if(top == max-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void pop()
{
    int x;
    if (isempty())
    {
        printf("Stack Underflow\n");
    }
    else
    {
        top -= 1;
        display();
    }
}
int isempty()
{
    if(top == -1)
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
    peik = stack[top];
    printf("top element is: %d", peik);
}

void display()
{
    if (isempty())
    {
        printf("The stack is empty.\n");
    }
    else
    {
        int i;
        printf("\nSTACK: ");
        for(i=0; i<=top; i++)
        {
            printf("%d ", stack[i]);
        }
    }
}
