//
//  main.cpp
//  Lab5
//
//  Created by Ilya Onishenko on 16.10.14.
//  Copyright (c) 2014 Ilya Onishenko. All rights reserved.
//

#include <iostream>
#include "func.h"
int main(int argc, const char * argv[]) {
    // insert code here...
    int t;
    printf("Меню:\n1)Все числа от 1 до n\n2)Все числа от А до В\n3)Функция Аккермана\n4)Точная степень двойки\n5)Сумма цифр числа\n");
    printf("Выберите номер задания\n");
    scanf("%d",&t);
    while(t!=6)
    {
        switch(t)
        {
            case 1:
            {
                printf("Все числа от 1 до n\n");
                task1();
                break;
            }
            case 2:
            {
                printf("Все числа от А до В\n");
                task2();
                break;
            }
            case 3:
            {
                printf("Функция Аккермана\n");
                task3();
                break;
            }
            case 4:
            {
                printf("Точная степень двойки\n");
                task4();
                break;
            }
            case 5:
            {
                printf("Сумма цифр числа\n");
                task5();
                break;
            }
        }
        printf("\nМеню:\n1)Все числа от 1 до n\n2)Все числа от А до В\n3)Функция Аккермана\n4)Точная степень двойки\n5)Сумма цифр числа\n");
        printf("Выберите номер задания\n");
        scanf("%d",&t);
    }
    return 0;
}
