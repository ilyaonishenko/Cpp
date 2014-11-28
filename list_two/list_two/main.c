//
//  main.c
//  list_two
//
//  Created by Ilya Onishenko on 29.11.14.
//  Copyright (c) 2014 Ilya Onishenko. All rights reserved.
//

#include <stdio.h>
#include "func.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int get_count = 0;
    struct lst_List lst_names;
    struct lst_Link* curr;
    lst_init(&lst_names);
    lst_push_back(&lst_names,(struct lst_Link*)make_name("Saruman"));
    lst_push_back(&lst_names,(struct lst_Link*)make_name("John"));
    lst_push_back(&lst_names,(struct lst_Link*)make_name("David"));
    lst_push_back(&lst_names,(struct lst_Link*)make_name("Richard"));
    lst_push_back(&lst_names,(struct lst_Link*)make_name("Roger"));
    lst_push_back(&lst_names,(struct lst_Link*)make_name("Nick"));
    lst_push_front(&lst_names,(struct lst_Link*)make_name("Gendalf"));
    //lst_erase(&lst_names,lst_get_next(lst_names.first, 1));
    printf("Hello, World!\n");
    curr = lst_names.first;
    
    printf("size: %d\n", lst_names.size);
    
    for(; curr != 0; curr = curr->next) {
        get_count++;
        
        printf("element %d: %s\n", get_count, ((struct lst_Value*)curr)->p);
    }
    printf("\n searching... \n\n");
    
    curr = lst_find(&lst_names, "Saruman");
    
    if(curr != 0) {
        printf("found: %s\n", ((struct lst_Value*)curr)->p);
    }
    return 0;
}
