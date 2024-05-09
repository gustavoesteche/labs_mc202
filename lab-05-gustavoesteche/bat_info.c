#include <stdio.h>
#include <stdlib.h>
#include "bat_info.h"


info_bat info_create(){

    info_bat info = malloc(sizeof(struct info_mem));

    info->data = calloc(8 , sizeof(int));
    info->total_size = 8;
    info->n = 0;

    return info;
}

void info_mem_increase(info_bat info){

    int *new_data = calloc(2 * info->total_size ,sizeof(int));

    for(int i = 0;i < info->total_size ;i++){
        new_data[i] = info->data[i];
    }

    free(info->data);

    info->data = new_data;
    info->total_size *= 2;
}


void info_add(info_bat info, int index, int size){

    if(index + size > info->total_size){
        info_mem_increase(info);    
    }
    info->n += size;
    for(int i=0;i<size;i++){
        info->data[index + i] = 1;
    }
    
}


void info_remove(info_bat info, int index, int size){

    info->n -= size;
    for(int i = 0; i< size ;i++){
        info->data[index + i] = 0;
    }
}


void info_free(info_bat info){

    free(info->data);
    free(info);
}


int find_empty(info_bat info, int size){

    int k = 0;
    for(int i = 0; i < info->total_size;i++){
        if(info->data[i] == 0){
            k++;
            if(k == size){
                return i - size + 1;
            }
        }else{
            k = 0;
        }
    }

    if(k == 0){
        return info->total_size;
    }else{
        return info->total_size - k;
    }

    return -1;
}


void info_half(info_bat info){
    
    int *new_data = calloc(info->total_size / 2 , sizeof(int));
    

    for(int i=0;i<info->total_size / 4;i++){
        new_data[i] = info->data[i];
                
    }

    free(info->data);

    info->data = new_data;
    info->total_size /= 2;
}