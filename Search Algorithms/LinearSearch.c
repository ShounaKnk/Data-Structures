#include <stdio.h>
int main()
{
    int s, x, i, pos, f=0;
    
    printf("enter the size of array: ");
    scanf("%d", &s);
    int a[s];
    
    printf("enter the elements of the array: ");
    for(i=0; i<s; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("enter the element to be searched: ");
    scanf("%d", &x);

    for(i=0; i<s; i++)
    {
        if(a[i] == x)
        {
            pos = i;
            f = 1;
            break;
        }
    }
    if(f == 0)
    {
        printf("%d was not found", x);
    }
    else 
    {
        printf("%d found at position %d", x, pos);
    }
    return 0;
}