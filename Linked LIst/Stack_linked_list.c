#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int data;
    struct stack *link;
};

struct stack *top=NULL;

struct stack* add_stack(struct stack *top, int elem)
{
    struct stack *tmp;
    tmp = (struct stack* )malloc(sizeof(struct stack));
    if(top == NULL)
    {
        tmp -> data = elem;
        tmp->link = NULL;
        top = tmp;
        return top;
    }
    else
    {
        tmp->data = elem;
        tmp->link = top;
        top = tmp;
        return top;
    }
}

struct stack* del_stack(struct stack* top)
{
    if(top == NULL)
    {
        printf("*****STACK IS EMPTY*****");
        return top;
    }

    else
    {
        struct stack *tmp;
        tmp = (struct stack* )malloc(sizeof(struct stack));
        tmp->data = top->data;
        top = top->link;
        free(tmp);
        return top;
    }
}

void display(struct stack *top)
{
    if(top == NULL)
    {
        printf("*****STACK IS EMPTY*****");
    }
    else
    {
        struct stack *p;
        p = top;
        printf("STACK: ");
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
                int elem;
                printf("\nenter the element to enter: ");
                scanf("%d", &elem);
                top = add_stack(top, elem);
            }
            break;

            case 2:
            {
                top = del_stack(top);
            }
            break;

            case 3:
            {
                display(top);
            }
            break;
        }
    }while(OP!=0);
    return 0;
}
