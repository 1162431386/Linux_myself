#include "node_list.h"
#include<stdio.h>

/*链表初始化*/
link_list *node_Init()
{
  link_list *list;
  list = (link_list *)malloc(sizeof(link_list)); //申请空间
  list->size = 0;
  list->head = (node_list *)malloc(sizeof(node_list)); //为头结点申请空间
  list->head->data = NULL;                              //初始化头结点
  list->head->next = NULL; 
  return list;
}
/*插入数据*/
void Insert_link_list(link_list *list, int pos, void *data)
{
  if (list == NULL || data == NULL)
  {
    return;
  }
  if (pos < 0 || pos > list->size) //友好处理，如果越界，则插入到尾部
  {
    pos = list->size;
  }
  node_list *new_node = (node_list *)malloc(sizeof(node_list)); //创建新的结点
  new_node->data = data;                                        //把数据挂到新的结点
  new_node->next = NULL;                                         //
  node_list *pcurrent = list->head;                             //创建辅助指针变量找结点

  for (int i = 0; i < pos; i++)
  {
    pcurrent = pcurrent->next;
  }
  new_node->next = pcurrent->next;
  pcurrent->next = new_node;
  list->size++;
}

/*根据位置删除链表的元素*/
void removebypos_link_list(link_list *list, int pos)
{
  if (list == NULL)
  {
    return;
  }
 if (pos<0||pos>=list->size) //位置不合法判断
 {
   return;
 }
 node_list *pcurrent=list->head; //查找删除节点的前一个结点

 for(int i=0;i<pos;i++)
 {
  pcurrent=pcurrent->next;
 }
 node_list *del=pcurrent->next;//创建一个缓存删除的指针记录当前结点
 free(del);  //释放缓存删除的指针变量
 list->size--;  //size减少
}


/*返回链表的大小*/
int Size_link_list(link_list *list)
{
  if(list==NULL)
  {
    return -1;
  }
  return list->size;
}


/*查找数据*/
int Find_link_list(link_list *list, void *data)
{
  int i;
  if(list==NULL||data==NULL)
  {
    return -1;
  }
  node_list *pcurrent=list->head->next;
  while(pcurrent!=NULL)
  {
    if(pcurrent->data==data)
    {
     break; 
    } 
    i++;
    pcurrent=pcurrent->next;  
  }
  return i;
}


/*返回第一个结点*/
void *First_link_list(link_list *list)
{
   if(list==NULL)
   {
     return;
   }
 return list->head->next;
}

    /*打印链表元素*/
void print_link_list(link_list *list, PRINTF print)
{
  if(list==NULL)
   {
     return -1;
   }
  node_list *pcurrent=list->head->next;
  while(pcurrent!=NULL)
  {
    print(pcurrent->data);
    pcurrent = pcurrent->next;
  }

}


/*释放链表空间*/
void freespace_link_list(link_list *list)
{
  if(list==NULL)
  {
    return;
  }
  node_list *pcurrent=list->head;
  while(pcurrent!=NULL)
  {
    node_list *pnext=pcurrent->next;
    free(pcurrent);
    pcurrent=pnext;
  }
  list->size=0;
  free(list);
}
