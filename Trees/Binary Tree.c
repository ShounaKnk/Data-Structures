#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *rchild;
    struct node *lchild;
};
struct node *root = NULL;

struct node* insert_nrec(struct node *root, int element)
{
    struct node *tmp, *par, *ptr;
    ptr = root;
    par = NULL;
    tmp = (struct node*)malloc(sizeof(struct node));
    tmp->data = element;
    tmp->lchild= NULL;
    tmp->rchild= NULL;

    while (ptr!= NULL)
    {
        par = ptr;

        if (element > ptr->data)
        {
            ptr = ptr->rchild;
        }
        else if (element < ptr->data)
        {
            ptr = ptr->lchild;
        }
        else
        {
            printf("\n**********DUPLICATE**********\n");
            return root;
        }
    }
    if (par == NULL)
    {
        root = tmp;
    }
    else if (element > par->data)
    {
        par->rchild = tmp;
        return root;
    }
    else
    {
        par->lchild = tmp;
        return root;
    }
}
struct node* case_a(struct node *root, struct node *par, struct node *ptr)
{
    if(par == NULL)
    {
        root = NULL;
    }
    else if(ptr == par->lchild)
    {
        par->lchild = NULL;
    }
    else
    {
        par->rchild = NULL;
    }
    free(ptr);
    return root;
}

struct node* case_b(struct node *root, struct node *par, struct node *ptr)
{
    struct node *child;
    if (ptr->lchild != NULL)
    {
        child = ptr->lchild;
    }
    else
    {
        child = ptr->rchild;
    }
    if(par == NULL)
    {
        root = child;
    }
    else if(ptr == par->lchild)
    {
        par->lchild = child;
    }
    else
    {
        par->rchild = child;
    }
    free(ptr);
    return root;
}

struct node* case_c(struct node *root, struct node *par, struct node *ptr)
{
    struct node *succ, *parsucc;
    parsucc = ptr;
    succ = ptr->rchild;
    while(succ->lchild != NULL)
    {
        parsucc = succ;
        succ = succ->lchild;
    }
    ptr->data = succ->data;
    if (succ->lchild == NULL && succ->rchild == NULL)
    {
        root = case_a(root, parsucc, succ);
    }
    else
    {
        root = case_b(root, parsucc, succ);
    }
    return root;
}

struct node* deletet_nrec(struct node *root, int element)
{
    struct node *ptr, *par;
    ptr = root;
    par = NULL;
    while(ptr!=NULL)
    {
        if(element == ptr->data)
        {
            break;
        }
        par = ptr;
        if(element < ptr->data)
        {
            ptr = ptr ->lchild;
        }
        if(element > ptr->data)
        {
            ptr = ptr ->rchild;
        }
    }
        if (ptr == NULL)
        {
            printf("element doesnt exist\n");
        }
        else if(ptr->lchild !=NULL && ptr->rchild != NULL)
        {
            root = case_c(root, par, ptr);
        }
        else if (ptr->lchild == NULL)
        {
            root = case_b(root, par, ptr);
        }
        else if (ptr->rchild == NULL)
        {
            root = case_b(root, par, ptr);
        }
        else
        {
            root = case_a(root, par, ptr);
        }
        return root;
}

struct node* search(struct node *ptr, int element)
{
    if (ptr == NULL)
    {
        printf("\nelement doesnt exist in the tree\n");
       return NULL;
    }
    else if(element > ptr->data)
    {
        return search(ptr->rchild, element);
    }
    else if(element < ptr->data)
    {
        return search(ptr->lchild, element);
    }
    else
    {
        return ptr;
    }
}

void minimum(struct node *ptr)
{
    while (ptr->lchild != NULL)
    {
        ptr = ptr->lchild;
    }
    printf("minimum: %d", ptr->data);
    printf("\n");
}

void inorder(struct node* root)
{
    if(root) 
    {
        inorder(root->lchild);
        printf("%d ",root->data);
        inorder(root->rchild);
    }
}

void preorder(struct node* root)
{
    if(root) 
    {
        printf("%d ",root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
    
}

void postorder(struct node* root)
{
    if(root) 
    {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d ",root->data);
    }
}

void maximum(struct node *ptr)
{
    while (ptr->rchild != NULL)
    {
        ptr = ptr->rchild;
    }
    printf("MAXIMUM: %d", ptr->data);
    printf("\n");
}

int main()
{
    int op;
    do
    {
        printf("\n\n--------------------------\n");
        printf("1.INSERT\n2.DELETE\n3.search\n4.DISPLAY\n5.minimun\n6.maximum\n0.exit\n");
        printf("\nenter operation: ");
        scanf("%d", &op);
        switch(op)
        {
            case 1:
            {
                int element;
                printf("\nenter the element to insert: ");
                scanf("%d", &element);
                root = insert_nrec(root, element);
            }
            break;

            case 2:
            {
                int element; 
                printf("enter the element to delete: ");
                scanf("%d", &element);
                root = deletet_nrec(root, element);
            }
            break;

            case 3:
            {
                struct node *ptr;
                int element;
                printf("Enter the element to search: ");
                scanf("%d", &element);
                ptr = search(root, element);
                if(ptr != NULL)
                {
                    printf("element was found in the tree\n");
                }
            }
            break;

            case 4:
            {
                int op1;
                printf("\n1.INORDER\n2.PREORDER\n3.POSTORDER\n\n");
                printf("enter operation: ");
                scanf("%d", &op1);
                switch(op1)
                {
                    case 1:
                        printf("\nINORDER: ");
                        inorder(root);
                    break;

                    case 2:
                        printf("\nPREORDER: ");
                        preorder(root);
                    break;

                    case 3:
                        printf("\nPOSTORDER: ");
                        postorder(root);
                    break;
                }
            }
            break;

            case 5:
            {
                minimum(root);
            }
            break;

            case 6:
            {
                maximum(root);
            }
            break;
        }
    } while (op !=0);
    
}
