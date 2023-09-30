// #include<stdio.h>
// #include<stdlib.h>
// char stack[15];
// int top = -1;

// void push(char x)
// {
//     top++;
//     stack[top] = x;
// }

// char pop()
// {
//     if(top == -1)
//     {
//         return -1;
//     }
//     else
//     {
//         return stack[top--];
//     }
// }

// int priority(char x)
// {
//     if(x == '(')
//         return 0;
//     if(x == '+' || x == '-')
//         return 1;
//     if(x == '*' || x == '/')
//         return 2;
//     if(x == '^')
//         return 3;
// }

// // int isalnum(char x)
// // {
// //     if(x >= 48 && x<=57 || x >=65 && x<=90 || x>= 97 && x<= 122)
// //         return 1;
// //     else
// //         return 0;
// // }

// int main()
// {
//     char exp[25];
//     printf("expression: ");
//     scanf("%s", exp);
//     char *p, x;
//     p = exp;
//     while(*p != '\0')
//     {
//         if(isalnum(*p))
//         {
//             printf("%c", *p);
//         }

//         else if(*p == '(')
//         {
//             push(*p);
//         }

//         else if(*p == ')')
//         {
//             while((x = pop()) != '(')
//             {
//                 printf("%c", x);
//             }
//         }
//         else
//         {
//             while (priority(stack[top]) >= priority(*p))
//             {
//                 printf("%c", pop());
//             }
//             push(*p);
//         }
//         p++;
//     }
//     while(top != -1)
//     {
//         printf("%c", pop());
//     }
// }

#include <stdio.h>
#include<stdlib.h>
char stack[10];
int top=-1;

void push(char x)
{
    top++;
    stack[top] = x;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x =='-')
        return 1;
    if(x == '*' || x =='/')
        return 2;
    if(x == '^')
        return 3;
}

int main()
{
    char exp[10];
    printf("expression: ");
    scanf("%s", exp);
    char *p, x;
    p = exp;

    while(*p != '\0')
    {
        if(isalnum(*p))
        {
            printf("%c", *p);
        }
        else if(*p == '(')
        {
            push(*p);
        }
        else if(*p == ')')
        {
            while((x = pop()) != '(')
            {
                printf("%c", x);
            }
        }
        else
        {
            while(priority(stack[top]) >= priority(*p))
            {
                printf("%c", pop());
            }
            push(*p);
        }
        p++;
    }
    while(top != -1)
    {
        printf("%c", pop());
    }
    return 0;
}