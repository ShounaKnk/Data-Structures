#include <stdio.h>
#include<stdlib.h>
struct node *start = NULL;

struct node
{
    struct node *prev;
    struct node *next;
    int data;
};

struct node* add_at_beg(struct node *start, int element)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    if(start==NULL)
    {
        temp->next = NULL;  
        temp->prev=NULL;  
        temp->data=element;  
        start = temp;
        printf("\n");
        printf("\n\n--------------------------\n\n");
        return start;
    }
    else
    {
        temp -> data= element;
        temp -> prev = NULL;
        temp -> next = start;
        start -> prev = temp;
        start = temp;
        printf("\n");
        printf("\n--------------------------\n\n");
        return start;
    }
}

struct node* add_at_end(struct node *start, int element)
{
    struct node *tmp, *p;
    tmp = (struct node*)malloc(sizeof(struct node));
    p = start;
    tmp->data= element;
    tmp->next=NULL;
    while(p->next!=NULL)
    {
        p = p->next;
    }
    tmp->prev=p;
    p->next= tmp;
    printf("\n");
    printf("\n--------------------------\n\n");
    return start;
}

struct node* add_aft_node(struct node* start, int element, int pos)
{
    struct node *tmp, *p;
    int f=0;
    tmp= (struct node*)malloc(sizeof(struct node));
    p = start;
    tmp->data=element;
    while(p!=NULL)
    {
        if(p->data == pos)
        {
            tmp->prev=p;
            tmp->next = p->next;
            if(p->next!=NULL)
            {
                p->next->prev=tmp;
            }
            p->next=tmp;
            f= 1;
        }
        p = p->next;
    }
    if(f==0)
    {
        printf("\n********\nELEMENT NOT FOUND\n\n*******\n\n");
    }
    printf("\n");
    printf("\n--------------------------\n\n");
    return start;
}

struct node* add_bfr_node(struct node* start, int element, int pos)
{
    struct node *tmp, *p;
    int f=0;
    tmp= (struct node*)malloc(sizeof(struct node));
    p = start;
    tmp->data=element;
    while(p!=NULL)
    {
        if(p->data == pos)
        {
            tmp->data=element;
            tmp->prev=p->prev;
            tmp->next=p;
            p->prev->next=tmp;
            p->prev=tmp;
            f=1;
        }
        p = p->next;
    }
    if(f==0)printf("\n********\nELEMENT NOT FOUND\n\n*******\n\n");
    printf("\n");
    printf("\n--------------------------\n\n");
    return start;
}

struct node* del_at_beg(struct node* start)
{                 
    struct node *tmp;

    if(start == NULL)
    {
        printf("list is empty\n");
        printf("\n\n--------------------------\n\n");
        return start;
    }

    else if(start->next == NULL)
    {
        tmp = start;
        start = NULL;
        free(tmp);
        printf("\n\n--------------------------\n\n");
        return start;
    }

    else
    {
        tmp =start;
        start = start->next;
        start->prev==NULL;
        free(tmp);
        return start;
        printf("\n\n--------------------------\n\n");
    }
}

struct node* del_at_end(struct node* start)
{
    struct node* tmp;
    tmp = start;
    while(tmp->next!=NULL)
    {
        tmp = tmp->next;
    }
    tmp->prev->next = NULL;
    free(tmp);
    printf("\n\n--------------------------\n");
    return start;
}

struct node* del_aft_node(struct node* start, int pos)
{
    struct node* tmp;
    tmp = start;
    int f = 0, count = 0;
    while(tmp->next!=NULL)
    {
        
        if(count == pos)
        {
            tmp->prev->next=tmp->next;
            tmp->next->prev=tmp->prev;
            free(tmp);
            f = 1;
            printf("\n\n--------------------------\n\n");
            return start;
        }
        count++;
        tmp = tmp->next;
    }
    if (f == 0)
    {
        printf("element not found\n");
    }

    printf("\n\n--------------------------\n\n");
    return start;
}

struct node* count(struct node* start)
{
    int n = 0;
    struct node *p;
    p = start;
    while(p!=NULL)
    {
        p = p->next;
        n++;
    }
    printf("\nNo. OF ELEMENTS: %d\n\n", n);
    printf("\n--------------------------\n\n");
    return start;
}

struct node* search(struct node* start, int element)
{
    int n = 0;
    struct node *p;
    p = start;
    while(p!=NULL)
    {
        if(p->data == element)
        {
            printf("\n%d WAS FOUND AT POSITION %d\n\n", element, n);
        }
        p = p->next;
        n++;
    }
    printf("\n--------------------------\n\n");
    return start;
}

struct node* rev(struct node* start)
{
    struct node *ptr1, *ptr2;
    ptr1 = start;
    ptr2 = ptr1->next;

    ptr1->prev = ptr2;
    ptr1->next = NULL;

    while(ptr2 != NULL)
    {
        ptr2->prev = ptr2->next;
        ptr2->next = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr2->prev;
    }
    start = ptr1;
    printf("\n--------------------------\n\n");
    return start;
}

void display(struct node *start)
{
    if(start==NULL)
    {
        printf("List is EMPTY\n\n");
    }
    else
    {
        struct node *p;
        p = start;
        printf("\nLIST: ");
        while(p!=NULL)
        {
            printf("%d ", p->data);
            p = p->next;
        }
        printf("\n");
    }
    printf("\n--------------------------\n\n");
}

int main()
{
    int OP;
    
    do
    {
        printf("--------------------------");
        printf("\n1. Insertion\n2. Deletion\n3. Display\n4. Count\n5. Search\n6. Reverse\n0. Exit\n");
        printf("\n\nOperation: ");
        scanf("%d", &OP);
        
        switch(OP)
        {
            case 1:
            {
                int OP1;
                printf("\n1. Add at beginning\n2. Add at end\n3. Add after a given node\n4. Add before a given node\n");
                printf("\n\nOperation: ");
                scanf("%d",&OP1);
                switch (OP1)
                {
                    case 1:
                    {
                        int element;
                        printf("Enter the element to add: ");
                        scanf("%d", &element);
                        start = add_at_beg(start, element);
                    }
                    break;

                    case 2:
                    {
                        int elem;
                        printf("Enter the element to add: ");
                        scanf("%d", &elem);
                        start = add_at_end(start, elem);
                    }
                    break;

                    case 3:
                    {
                        int elem, pos;
                        printf("Enter the element to add: ");
                        scanf("%d", &elem);
                        printf("enter the element to add after: ");
                        scanf("%d", &pos);
                        start = add_aft_node(start, elem, pos);
                    }
                    break;

                    case 4:
                    {
                        int elem, pos;
                        printf("Enter the element to add: ");
                        scanf("%d", &elem);
                        printf("enter the element to add before: ");
                        scanf("%d", &pos);
                        start = add_bfr_node(start, elem, pos);
                    }
                    break;
                }
            }
            break;

            case 2:
            {
                int OP2;
                printf("\n1. Delete at beginning\n2. Delete at end\n3. Delete at a given position\n");
                printf("\n\nOperation: ");
                scanf("%d",&OP2);
                switch(OP2)
                {
                    case 1:
                    {
                        start = del_at_beg(start);
                    }
                    break;

                    case 2:
                    {
                        start = del_at_end(start);
                    }
                    break;

                    case 3:
                    {
                        int elem, pos;
                        printf("Enter the position to delete: ");
                        scanf("%d", &pos);
                        start = del_aft_node(start, pos);
                    }
                    break;
                }
            }
            break;

            case 3:
            {
                display(start);
            }
            break;

            case 4:
            {
                start = count(start);
            }
            break;

            case 5:
            {
                int elem;
                printf("Enter the element to search: ");
                scanf("%d", &elem);
                start = search(start, elem);
            }
            break;

            case 6:
            {
                start = rev(start);
            }
        }
    }while (OP != 0);
    return 0;
}