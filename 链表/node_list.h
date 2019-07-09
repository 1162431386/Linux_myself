#ifndef _NODE_LIST_H
#define _NODE_LIST_H
#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
  char id[10];
  char name[10];
  int  age;
}Date;
typedef struct node
{
  void *data;          //创建无类型指针，指向任何类型的数据
  struct node *next;
}node_list;
typedef struct list
{
  node_list *head;
  int size;     //当前链表的大小
                 //这里没有容量的概念，随用随申请              
}link_list;
typedef void (*PRINTF)(void *); //返回值为void，参数为void*的函数指针。
link_list *node_Init();
void Insert_link_list(link_list *list, int pos, void *data);
void removebypos_link_list(link_list *list, int pos) ;
int Size_link_list(link_list *list);
int Find_link_list(link_list *list, void *data) ;
void *First_link_list(link_list *list);
void print_link_list(link_list *list, PRINTF print);
void freespace_link_list(link_list *list);
void my_print(void *data);
#endif