#include<stdio.h>
#include<stdlib.h>

struct node *start = NULL;

struct node
{
    int data;
    struct node *link;
};


struct node* add1st(struct node* start, int data)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp -> data = data;
    temp -> link = NULL;
    start = temp;
}
//Adds at the beginning (first node)
struct node* addBeg(struct node* start, int data)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp -> data = data;
    temp -> link = start;
    start = temp;
    return start;
}

//Adds at the end
struct node* addEnd(struct node* start, int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    struct node* p = start;
    while(p->link!=NULL)
        p = p->link;
    temp -> data = data;
    temp -> link = NULL;
    p -> link = temp;
    return start;
}

//Insertion at a given position
struct node* addBetween(struct node* start, int pos, int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    int i;
    //inserts at the beginning (can you call addBeg() function here?)
    if(pos == 1)
    {
        temp -> data = data;
        temp -> link = start;
        start = temp;
        return start;
    }
    else{
        struct node* p = start;
        for(i=1; i<pos-1; i++) //if i<pos, then it goes one element too far [solve if confused]
            p = p->link;
        temp -> data = data;
        //inserting new node in between
        temp -> link = p -> link;
        p -> link = temp;
        return start;
    }
}

//Insertion after a given value
struct node* addAfterNode(struct node* start, int item, int data)
{
    int i;
    struct node* temp, *p;
    temp = (struct node*)malloc(sizeof(struct node));
    temp -> data = data;
    p = start;
    while(p->link != NULL)
    {
        if(p->data == item)
        {
            temp -> link = p -> link;
            p -> link = temp;
            return start;
        }
        else
            p = p->link;
    }
    if(p->data != item)
        printf("Item not present in linked list\n");
    return start;
}

//Insertion before a given value
struct node* addBeforeNode(struct node* start, int item, int data)
{
    int i;
    struct node* temp, *p;
    temp = (struct node*)malloc(sizeof(struct node));
    temp -> data = data;
    p = start;
    while(p->link != NULL)
    {
        if(p->link->data == item)
        {
            temp -> link = p -> link;
            p -> link = temp;
            return start;
        }
        else
            p = p->link;
    }
    if(p->data != item)
        printf("Item not present in linked list\n");
    return start;
}

//Display
void display(struct node *p)
{
    printf("LINKED LIST: ");
    while(p!=NULL)
    {
        printf("%d ", p->data);
        p = p->link;
    };
}

//Delete first node
struct node* deleteFirst(struct node* start)
{
    struct node *temp;
    temp = start;
    //List is empty
    if(start == NULL) {
        printf("Empty list\n");
    }else{
        printf("%d was deleted from the list\n",temp->data);
        start = start -> link;

        free(temp);
        return start;
    }
}

//Delete last node
struct node* deleteLast(struct node* start)
{
    struct node *p;
    if(start == NULL){
        printf("List is empty\n");
    }
    else if(start -> link == NULL)
    {
        p = start;
        printf("%d was deleted from the list\n",p->data);
        free(p);
        start = NULL;
    }
    else
    {
        p = start;
        while(p->link->link!=NULL)
        {
            p = p -> link;
        }
        printf("%d was deleted from the list\n",p->link->data);
        free(p->link);
        p -> link = NULL;
        return start;
    }
    return start;
}

//Delete at a given position
struct node* deleteAtPos(struct node* start, int pos)
{
    int i;
    struct node *p = start;
    struct node *temp;
    if(start == NULL)
        printf("List is empty\n");
    else if(pos == 1)
    {
        printf("%d was deleted from the list\n", start->data);
        start = NULL;
        free(p);
    }
    else
    {
        for(i=1; i<pos-1 && p!=NULL; i++)
            p = p -> link;
        temp = p;
        if(p==NULL)
        printf("\nNo of elements is less than the position");
        else
        {
            printf("%d is deleted\n",p->link->data);
            temp=p->link;
            p->link=temp->link;
            free(temp);
        }

    }
    return start;
}

//Searching
void search(struct node* start, int item)
{
    int pos = 1, flag = 0;
    struct node *p = start;
    if(start == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while(p!=NULL)
    {
        if(p->data == item)
        {
            printf("%d was found at position %d", item, pos);
            flag = 10;
            break;
        }
        p = p -> link;
        pos++;
    }
    if(flag == 0)
        {
            printf("element doesnt exist");
        }
}

//traversal
int count(struct node *start)
{
    int n=0;
    struct node *p = start;
    if(start == NULL)
        return 0;
    while(p!=NULL)
    {
        p = p -> link;
        n++;
    }
    return n;
}

//Reversal
struct node *rev(struct node *start)
{
    struct node *p, *next, *prev;
    p = start;
    next = NULL;
    prev = NULL;
    while(p != NULL)
    {
        next = p->link;
        p->link = prev;
        prev = p;
        p = next;
    }
    start = prev;
    return start;
}


int main()
{
    int ch, ch1, ch2, pos, val, nodeVal, num;
    do
    {
        printf("\n*************************************\n");
        printf("\n1. Insertion\n2. Deletion\n3. Display\n4. Count\n5. Search\n6. Reversal\n0. Exit\n");
        printf("\n\nOperation: ");
        scanf("%d",&ch);
        //system("clear");
            switch(ch)
            {
                case 1:
                printf("\n1. Add at beginning\n2. Add at end\n3. Add at a given position\n4. Add after a given node\n5. Add before a given node\n");
                printf("\n\nOperation: ");
                scanf("%d",&ch1);
                switch(ch1)
                {
                    case 1:
                    printf("Enter value : ");
                    scanf("%d", &val);
                    start = addBeg(start, val);
                    break;

                    case 2:
                    printf("Enter value : ");
                    scanf("%d", &val);
                    start = addEnd(start, val);
                    break;

                    case 3:
                    printf("Enter value : ");
                    scanf("%d", &val);
                    printf("Enter position : ");
                    scanf("%d", &pos);
                    start = addBetween(start, pos, val);
                    break;

                    case 4:
                    printf("Enter value : ");
                    scanf("%d", &val);
                    printf("Enter node value : ");
                    scanf("%d", &nodeVal);
                    start = addAfterNode(start, nodeVal, val);
                    break;

                    case 5:
                    printf("Enter value : ");
                    scanf("%d", &val);
                    printf("Enter node value : ");
                    scanf("%d", &nodeVal);
                    start = addBeforeNode(start, nodeVal, val);
                    break;
                }
                break;

                case 2:
                printf("\n1. Delete at beginning\n2. Delete at end\n3. Delete at a given position\n");
                printf("\n\nOperation: ");
                scanf("%d",&ch2);
                switch(ch2)
                {
                    case 1:
                    start = deleteFirst(start);
                    break;

                    case 2:
                    start = deleteLast(start);
                    break;

                    case 3:
                    printf("Enter position : ");
                    scanf("%d",&pos);
                    start = deleteAtPos(start, pos);
                    break;
                }
                break;

                case 3:
                display(start);
                break;

                case 4:
                num = count(start);
                printf("\nTotal number of nodes : %d\n",num);
                break;

                case 5:
                printf("Enter value : ");
                scanf("%d",&nodeVal);
                search(start, nodeVal);
                break;

                case 6:
                start = rev(start);
                break;

            }

        }while(ch!=0);
        return 0;
}
