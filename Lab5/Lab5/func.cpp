//
//  func.cpp
//  Lab5
//
//  Created by Ilya Onishenko on 16.10.14.
//  Copyright (c) 2014 Ilya Onishenko. All rights reserved.
//
#include <iostream>
#include "func.h"
#include <stack>
void oneton(int n)
{
    if(n==1)
    {
        printf("1\n");
        return;
    }
    else
    {
        printf("%d ",n);
        oneton(n-1);
    }
}
void task1()
{
    int a = 0;
    printf("Введите число n: ");
    scanf("%d",&a);
    printf("Выполнить задание рекурсивно или нет?\n1-рекурсивно\n2-не рекурсивно\n");
    int q;
    scanf("%d",&q);
    if (q==1)
    {
        oneton(a);
        return;
    }
    if (q==2)
    {
        notrec1(a);
        return;
    }
    else
        printf("Вы ввели что-то не то\n");
}
void rec2(int a,int b)
{
    if (a==b)
    {
        printf("%d\n",a);
        return;
    }
    if (a<b)
    {
        printf("%d ",a);
        rec2(a+1,b);
    }
    if (b<a)
    {
        printf("%d ",a);
        rec2(a-1,b);
    }
}
void task2()
{
    int a,b;
    printf("Введите а и b\n");
    scanf("%d %d",&a,&b);
    printf("Выполнить задание рекурсивно или нет?\n1-рекурсивно\n2-не рекурсивно\n");
    int q;
    scanf("%d",&q);
    if (q==1)
    {
        rec2(a,b);
        return;
    }
    if (q==2)
    {
        notrec2(a,b);
        return;
    }
    else
        printf("Вы ввели что-то не то");
}
int rec3(int m,int n)
{
    if(m==0)
    {
        return n+1;
    }
    else if(m>0&&n==0)
    {
        return rec3(m-1,1);
    }
    else if(m>0&&n>0)
    {
        return rec3(m-1,rec3(m,n-1));
    }
    else
    {
        return 0;
    }
}
void task3()
{
    int n,m;
    printf("Введите n и m\n");
    scanf("%d %d",&n,&m);
    printf("Выполнить задание рекурсивно или нет?\n1-рекурсивно\n2-не рекурсивно\n");
    int q;
    scanf("%d",&q);
    if (q==1)
    {
        printf("%d\n",rec3(m,n));
        return;
    }
    if (q==2)
    {
        printf("%d\n",notrec3(n, m));
        return;
    }
    else
        printf("Вы ввели что-то не то");
}
void rec4(double n)
{
    if (n==2){
        printf("YES\n");
        return;
    }
    if (n<2)
    {
        printf("NO\n");
        return;
    }
    else
    {
        rec4(n/2);
    }
}
void task4()
{
    printf("Введите число для проверки\n");
    int n;
    scanf("%d",&n);
    printf("Выполнить задание рекурсивно или нет?\n1-рекурсивно\n2-не рекурсивно\n");
    int q;
    scanf("%d",&q);
    if (q==1)
    {
        rec4((double)n);
        return;
    }
    if (q==2)
    {
        notrec4((double)n);
        return;
    }
    else
        printf("Вы нажали что-то не то");
}
void rec5(int n,int sum)
{
    if (n<1)
    {
        printf("%d\n",sum);
        return;
    }
    sum+=n%10;
    rec5(n/10,sum);
}
void task5()
{
    printf("Введите число для проверки\n");
    int n;
    int sum=0;
    scanf("%d",&n);
    printf("Выполнить задание рекурсивно или нет?\n1-рекурсивно\n2-не рекурсивно\n");
    int q;
    scanf("%d",&q);
    if (q==1)
    {
        rec5(n,sum);
        return;
    }
    if (q==2)
    {
        notrec5(n, sum);
        return;
    }
    else {
        printf("Вы нажали что-то не то");
    }
}
void notrec1(int a)
{
    while (a!=1)
    {
        printf("%d ",a);
        a-=1;
    }
    printf("%d\n",a);
}
void notrec2(int a,int b)
{
    if (a>b)
    {
        while (a>=b)
        {
            printf("%d ",a);
            a-=1;
        }
    }
    else
    {
        while(a<=b)
        {
            printf("%d ",a);
            a+=1;
        }
        
    }
    printf("\n");
}
int notrec3(int m,int n)
{
    std::stack <int> st;
    st.push(m);
    while(!st.empty())
    {
        m = st.top();
        st.pop();
        if (m==0||n==0)
        {
            n+=m+1;
        }
        else
        {
            st.push(--m);
            st.push(++m);
            n--;
        }
        
    }
    return n;
}
void notrec4(double n)
{
    while (n!=0)
    {
        if (n==2)
        {
            printf("YES\n");
            return;
        }
        if (n<2)
        {
            printf("NO\n");
            return;
        }
        n/=2;
    }
    
}
void notrec5(int n, int sum)
{
    
    while (n>=1)
    {
        sum+=n%10;
        n/=10;
    }
    if (n<1)
    {
        printf("%d\n",sum);
        return;
    }
}















