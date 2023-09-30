#include<stdio.h>
#include<math.h>
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

void power()
{
    int ans, a, b;
    a = pop();
    b = pop();
    ans = pow(b, a);
    stack[top]= ans;
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

            case '^':
            {
                power();
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