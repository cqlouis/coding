#include <stdio.h>
#include <string.h>
 
char * fun1(char * p)
{
    printf("%s\n",p);
    return p;
}
 
char * fun2(char * p)
{
    printf("%s\n",p);
    return p;
}
 
char * fun3(char * p)
{
    printf("%s\n",p);
    return p;
}
 
int main()
{
    char * (*a[3])(char * p);
    char * (*(*pf)[3])(char * p);
    pf = &a;
 
    a[0] = fun1;
    a[1] = &fun2;
    a[2] = &fun3;
 
    pf[0][0]("fun1");
    pf[0][1]("fun2");
    pf[0][2]("fun3");
    pf[1][0]("fun1");
    pf[1][0]("fun1");
    pf[1][1]("fun2");
    pf[2][2]("fun3");
    pf[2][1]("fun2");
    pf[2][2]("fun3");
    return 0;
}
