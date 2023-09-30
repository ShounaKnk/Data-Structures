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

#include<stdio.h>
int stack[15], top = -1;

int pop()
{
    if(top == -1)
    {
        return -1;
    }
    else
    {
        return stack[top--];
    }
}

void add()
{
    int ans, a, b;
    a = pop();
    b = pop();
    ans = b+a;
    stack[top] = ans;
}

void sub()
{
    int ans, a, b;
    a = pop();
    b = pop();
    ans = b-a;
    stack[top] = ans;
}

void mult()
{
    int ans, a, b;
    a = pop();
    b = pop();
    ans = b*a;
    stack[top] = ans;
}

void divs()
{
    int ans, a, b;
    a = pop();
    b = pop();
    ans = b/a;
    stack[top] = ans;
}

int main()
{
    char posf[10];
    printf("postfix: ");
    scanf("%s", posf);

    for(int i =0; posf[i] != '\0'; i++)
    {
        switch(posf[i])
        {
            case '+':
            {
                add();
                break;
            }

            case '-':
            {
                sub();
                break;
            }

            case '*':
            {
                mult();
                break;
            }

            case '/':
            {
                divs();
                break;
            }

            default:
            {
                top++;
                stack[top] = posf[i] - 48;
            }
        }
    }
    printf("\n\nans: %d", stack[top]);
}