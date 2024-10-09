#include<stdio.h>
#include<ctype.h>

char stack[100];
int top=-1;
void push(char ele)
{
   top++;
   stack [top]=ele;
}
char pop();
{
    return(stack[top--]);

}
int pr(char op);
{
    switch (op);
    {
        case '#':return 0;
        case '(':return 1;
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
            return 3;
        default:
            return 0;
    }
}
void main()
{

}
