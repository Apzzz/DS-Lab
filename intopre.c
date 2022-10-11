#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int priority(char n)
{
    switch(n)
    {
        case '+':return 2;
        case '-':return 2;
        case '*':return 3;
        case '/':return 3;
        case '^':return 4;
        case '(':return 5;
        case ')':return 5;
    }
}
main()
{
    char infix[30],rev[30],pre[30],inter[30],st[30];
    int i,k=0,top=-1;
    printf("Enter the infix expression\n");
    gets(infix);
    for(i=0;infix[i]!='\0';i++)
    {
        top++;
        st[top]=infix[i];
    }
    i=0;
    while(top>-1)
    {
        rev[i]=st[top];
        top--,i++;
    }
    rev[i]='\0';
    for(i=0;rev[i]!='\0';i++)
    {
         if(isalpha(rev[i]))
        {
            inter[k]=rev[i];
            k++;
        }
        else if(rev[i]=='(')
        {
           while(st[top]!=')')
            {
                inter[k]=st[top];
                k++,top--;
            }
            top--;
        }
        else
        {
            if(top==-1)
                {
                    top++;
                    st[top]=rev[i];
                    continue;
                }
            if(st[top]==')')
                {
                    top++;
                    st[top]=rev[i];
                    continue;
                }
                while(priority(rev[i])<priority(st[top]))
                    {
                        inter[k]=st[top];
                        k++;
                        top--;
                        if(st[top]==')')
                            break;
                    }
                    top++;
                    st[top]=rev[i];
        }

    }
    while(top>-1)
    {
        inter[k]=st[top];
        k++,top--;
    }
    inter[k]='\0';
    for(i=0;inter[i]!='\0';i++)
    {
        top++;
        st[top]=inter[i];
    }
    i=0;
    while(top>-1)
    {
        pre[i]=st[top];
        top--,i++;
    }
    pre[i]='\0';
    printf("\nPerfix Expression is\n");
    printf("\n%s\n",pre);
}
//(a+b)*k+d/(e+f*g)+h
