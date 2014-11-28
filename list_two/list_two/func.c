//
//  func.c
//  list_two
//
//  Created by Ilya Onishenko on 29.11.14.
//  Copyright (c) 2014 Ilya Onishenko. All rights reserved.
//

#include "func.h"


void lst_init(struct lst_List* lst) {
    lst->first = lst->last = 0;
    lst->size = 0;
}

struct lst_List* lst_create() {
    struct lst_List* lst = (struct lst_List*)malloc(sizeof(struct lst_List));
    lst_init(lst);
    return lst;
}

void lst_clear(struct lst_List* lst) {
    struct lst_Link* curr = lst->first;
    
    while(curr) {
        struct lst_Link* next = curr->next;
        free(curr);
        curr = next;
    }
    
    lst->first = lst->last = 0;
    lst->size = 0;
}

void lst_destroy(struct lst_List* lst) {
    lst_clear(lst);
    free(lst);
}

void lst_push_back(struct lst_List* lst, struct lst_Link* p) {
    struct lst_Link* last = lst->last;
    
    if(last) {
        /* добавляем узел p после узла last */
        last->next = p;
        p->prev = last;
    } else {
        /* p - первый элемент */
        lst->first = p;
        p->prev = 0;
    }
    
    /* p - новый последний элемент */
    
    lst->last = p;
    p->next = 0;
    
    ++lst->size;
}

void lst_push_front(struct lst_List* lst, struct lst_Link* p) {
    struct lst_Link* first = lst->first;
    
    if(lst->last) {
        first->prev = p;
        p->next = first;
    } else {
        /* p у нас будет первым и единственным на данный момент узлом */
        lst->last = p;
        p->next = 0;
    }
    
    lst->first = p;
    p->prev = 0;
    
    ++lst->size;
}

void lst_insert_after(struct lst_List* lst, struct lst_Link* p, struct lst_Link* q) {
    
    if(lst->last == p) {
        /* вставляем в конец */
        
        lst->last = q;
        q->next = 0;
        
    } else {
        /* после p есть как минимум еще один узел */
        q->next = p->next;
    }
    
    p->next = q;
    
    q->prev = p;
    
    ++lst->size;
}

void lst_insert_before(struct lst_List* lst, struct lst_Link* p, struct lst_Link* q) {
    if(lst->first == p) {
        /* вставляем в начало */
        
        lst->first = q;
        q->prev = 0;
        
    } else {
        /* перед p есть как минимум еще один узел */
        q->prev = p->prev;
        p->prev->next = q;
    }
    
    q->next = p;
    
    p->prev = q;
    
    ++lst->size;
}

struct lst_Link* lst_erase(struct lst_List* lst, struct lst_Link* p) {
    if(p == 0) return 0;
    
    if(lst->size == 0) {
        return 0;
    }
    
    --lst->size;
    
    if(p == lst->first) {
        if(p->next) {
            /* next узел становится первым */
            lst->first = p->next;
            p->next->prev = 0;
            
            free(p);
            return p->next;
            
        } else {
            /* список становится пустым */
            
            lst->first = lst->last = 0;
            
            free(p);
            return 0;
        }
    } else if(p == lst->last) {
        if(p->prev) {
            /* prev узел становится последним */
            lst->last = p->prev;
            p->prev->next = 0;
            
            free(p);
            return 0;
            
        } else {
            /* список становится пустым, и вообще то это условие не должно выполняться */
            
            lst->first = lst->last = 0;
            
            free(p);
            return 0;
        }
        
    } else {
        /* узел находится где-то между первым и последним */
        p->next->prev = p->prev;
        p->prev->next = p->next;
        
        free(p);
        return p->next;
    }
}

struct lst_Link* lst_get_next(struct lst_Link* p, int n) {
    
    struct lst_Link* get_next = p->next; /* указатель на след. узел */
    n--;
    
    if(get_next == 0) {
        return 0;
    }
    
    while(n > 0){
        
        get_next = get_next->next; /* едем дальше */
        
        if(get_next == 0) {
            /* мы уже достигли конца (переборщили с n) */
            
            return 0;
            
        }
        
        n--;
    }
    
    return get_next;
}

struct lst_Link* lst_get_prev(struct lst_Link* p, int n) {
    
    struct lst_Link* get_prev = p->prev; /* указатель на пред. узел */
    n--;
    
    if(get_prev == 0) {
        return 0;
    }
    
    while(n > 0){
        
        get_prev = get_prev->prev; /* едем назад */
        
        if(get_prev == 0) {
            /* мы уже достигли начала (переборщили с n) */
            
            return 0;
            
        }
        
        n--;
    }
    
    return get_prev;
}

struct lst_Value* make_name(char* n) {
    struct lst_Value* p = (struct lst_Value*)malloc(sizeof(struct lst_Value));
    p->p = n;
    
    return p;
}

struct lst_Link* lst_find(struct lst_List* lst, char* n) {
    struct lst_Link* get_link = lst->first;
    
    while(get_link) {
        
        if(((struct lst_Value*)get_link)->p == n) {
            return get_link;
        }
        
        get_link = get_link->next; /* едем дальше */
    }
    
    return 0;
}

