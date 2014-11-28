//
//  func.h
//  list_two
//
//  Created by Ilya Onishenko on 29.11.14.
//  Copyright (c) 2014 Ilya Onishenko. All rights reserved.
//

#ifndef __list_two__func__
#define __list_two__func__

#include <stdio.h>
#include <stdlib.h>
struct lst_List {
    struct lst_Link* first;
    struct lst_Link* last;
    unsigned int size;
};

struct lst_Link {
    struct lst_Link* prev;
    struct lst_Link* next;
};

struct lst_Value {
    struct lst_Link lnk;
    char* p;
};

/* инициализирует lst пустым */
void lst_init(struct lst_List* lst);

/* создает новый пустой список в свободной памяти */
struct lst_List* lst_create();

/* удаляет все элементы списка lst */
void lst_clear(struct lst_List* lst);

/* удаляет все элементы списка lst, а затем удаляет сам lst */
void lst_destroy(struct lst_List* lst);

/* добавляет элемент p в конец списка lst */
void lst_push_back(struct lst_List* lst, struct lst_Link* p);

/* добавляет элемент p в начало списка lst */
void lst_push_front(struct lst_List* lst, struct lst_Link* p);

/* вставляет элемент q после элемента p в lst */
void lst_insert_after(struct lst_List* lst, struct lst_Link* p, struct lst_Link* q);

/* вставляет элемент q перед элементом p в lst */
void lst_insert_before(struct lst_List* lst, struct lst_Link* p, struct lst_Link* q);

/* удаляет элемент p из списка lst
 возвращает указатель на узел, расположенный после узла p */
struct lst_Link* lst_erase(struct lst_List* lst, struct lst_Link* p);

/* возвращает элемент, находящийся через n узлов после узла p */
struct lst_Link* lst_get_next(struct lst_Link* p, int n);

/* возвращает элемент, находящийся до n узлов перед узлом p */
struct lst_Link* lst_get_prev(struct lst_Link* p, int n);

/* выделяем память для значения списка */
struct lst_Value* make_name(char* n);

/* находит n в списке lst. если не находит, возвращает 0 */
struct lst_Link* lst_find(struct lst_List* lst, char* n);



#endif /* defined(__list_two__func__) */
