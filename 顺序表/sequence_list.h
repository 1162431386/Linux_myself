#ifndef _SEQUENCE_LIST_H_
#define _SEQUENCE_LIST_H_
#define SIZE 20
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct sequence_list
{
    int *head;    //申明长度不确定的数组
    int length;   //记录当前顺序表的长度
    int size;     //记录书序表分配的存储容量

} sequence_list;
sequence_list *Init_sequence_list(void);//返回一个sequence_list类型的结构
void rmvalue_sequence_list(sequence_list *my_list, int value);
int find_sequence_list(sequence_list *my_list, int find_elem);
void push_sequence_list(sequence_list *my_list, int value);
void remove_sequence_list(sequence_list *my_list, int pos);
int get_sequence_list(sequence_list *my_list, int pos);
void printf_sequence_list(sequence_list *my_list);
void clear_sequence_list(sequence_list *my_list);
void free_sequence_list(sequence_list *my_list);
int Size_sequence_list(sequence_list *my_list);
int length_sequence_list(sequence_list *my_list);

#endif
