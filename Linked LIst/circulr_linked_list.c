#include<stdio.h>
#include<stdlib.h>

struct node *last = NULL;

struct node
{
    int data;
    struct node *link;
};

//Adds at the beginning (first node)
struct node* addBeg(struct node* last, int element)
{
    if(last == NULL)
    {
        struct node* tmp;
        tmp = (struct node*)malloc(sizeof(struct node*));
        tmp->data = element;
        last = tmp;
        last->link= last;
        return last;
    }
    else
    {
        struct node *temp;
        temp = (struct node*)malloc(sizeof(struct node));
        temp -> data = element;
        temp -> link = last->link;
        last->link = temp;
        return last;
    }
}

//Adds at the end
struct node* addEnd(struct node* last, int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    struct node* p = last;
    while(p->link!=last->link)
    {
        p = p->link;
    }
    temp -> data = data;
    p -> link = temp;
    temp -> link = p -> link;
    return last;
}

//Insertion at a given position
struct node* addBetween(struct node* last, int pos, int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    int i;
    //inserts at the beginning (can you call addBeg() function here?)
    if(pos == 1)
    {
        temp -> data = data;
        temp -> link = last;
        last = temp;
        return last;
    }
    else{
        struct node* p = last;
        for(i=1; i<pos-1; i++) //if i<pos, then it goes one element too far [solve if confused]
            p = p->link;
        temp -> data = data;
        //inserting new node in between
        temp -> link = p -> link;
        p -> link = temp;
        return last;
    }
}

//Insertion after a given value
struct node* addAfterNode(struct node* last, int item, int data)
{
    int i;
    struct node* temp, *p;
    temp = (struct node*)malloc(sizeof(struct node));
    temp -> data = data;
    p = last;
    while(p->link != last->link)
    {
        if(p->data == item)
        {
            temp -> link = p -> link;
            p -> link = temp;
            return last;
        }
        else
            p = p->link;
    }
    if(p->data != item)
        printf("Item not present in linked list\n");
    return last;
}

//Insertion before a given value
struct node* addBeforeNode(struct node* last, int item, int data)
{
    int i;
    struct node* temp, *p;
    temp = (struct node*)malloc(sizeof(struct node));
    temp -> data = data;
    p = last;
    while(p->link != last->link)
    {
        if(p->link->data == item)
        {
            temp -> link = p -> link;
            p -> link = temp;
            return last;
        }
        else
            p = p->link;
    }
    if(p->data != item)
        printf("Item not present in linked list\n");
    return last;
}

//Display
void display(struct node *last)
{
    struct node *p = last->link;
    if(last == NULL)
    {
        printf("\n**********EMPTY**********\n");
    }
    printf("LINKED LIST: ");
    do
    {
        printf("%d ", p->data);
        p = p->link;
    }while(p!=last->link);
}

//Delete first node
struct node* deleteFirst(struct node* last)
{
    struct node *temp;
    temp = last;
    //List is empty
    if(last == NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        printf("%d was deleted from the list\n",temp->data);
        last = last -> link;
        free(temp);
        return last;
    }
}

//Delete last node
struct node* deleteLast(struct node* last)
{
    struct node *p;
    if(last == NULL)
    {
        printf("List is empty\n");
    }
    else if(last -> link == last)
    {
        p = last;
        printf("%d was deleted from the list\n",p->data);
        free(p);
        last = NULL;
    }
    else
    {
        p = last;
        while(p->link->link!=last->link)
        {
            p = p -> link;
        }
        printf("%d was deleted from the list\n",p->link->data);
        free(p->link);
        p -> link = NULL;
        return last;
    }
    return last;
}

//Delete at a given position
struct node* deleteAtPos(struct node* last, int pos)
{
    int i;
    struct node *p = last;
    struct node *temp;
    if(last == NULL)
        printf("List is empty\n");
    else if(pos == 1)
    {
        printf("%d was deleted from the list\n", last->data);
        last = NULL;
        free(p);
    }
    else
    {
        for(i=1; i<pos-1 && p!=last->link; i++)
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
    return last;
}

//Searching
void search(struct node* last, int item)
{
    int pos = 1, flag = 0;
    struct node *p = last;
    if(last == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while(p!=last->link)
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
int count(struct node *last)
{
    int n=0;
    struct node *p = last;
    if(last == NULL)
        return 0;
    while(p!=last->link)
    {
        p = p -> link;
        n++;
    }
    return n;
}

int main()
{
    int ch, ch1, ch2, pos, val, nodeVal, num;
    do
    {
        printf("\n\n*************************************\n");
        printf("\n1. Insertion\n2. Deletion\n3. Display\n4. Count\n5. Search\n0. Exit\n");
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
                    last = addBeg(last, val);
                    break;

                    case 2:
                    printf("Enter value : ");
                    scanf("%d", &val);
                    last = addEnd(last, val);
                    break;

                    case 3:
                    printf("Enter value : ");
                    scanf("%d", &val);
                    printf("Enter position : ");
                    scanf("%d", &pos);
                    last = addBetween(last, pos, val);
                    break;

                    case 4:
                    printf("Enter value : ");
                    scanf("%d", &val);
                    printf("Enter node value : ");
                    scanf("%d", &nodeVal);
                    last = addAfterNode(last, nodeVal, val);
                    break;

                    case 5:
                    printf("Enter value : ");
                    scanf("%d", &val);
                    printf("Enter node value : ");
                    scanf("%d", &nodeVal);
                    last = addBeforeNode(last, nodeVal, val);
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
                    last = deleteFirst(last);
                    break;

                    case 2:
                    last = deleteLast(last);
                    break;

                    case 3:
                    printf("Enter position : ");
                    scanf("%d",&pos);
                    last = deleteAtPos(last, pos);
                    break;
                }
                break;

                case 3:
                display(last);
                break;

                case 4:
                num = count(last);
                printf("\nTotal number of nodes : %d\n",num);
                break;

                case 5:
                printf("Enter value : ");
                scanf("%d",&nodeVal);
                search(last, nodeVal);
                break;

            }

        }while(ch!=0);
        return 0;
}