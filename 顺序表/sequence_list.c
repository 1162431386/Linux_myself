#include "sequence_list.h"
/*顺序表初始化函数*/
sequence_list *Init_sequence_list(void) //返回一个sequence_list类型的结构
{
   sequence_list *my_list;
  if (NULL == (my_list = (sequence_list *)malloc(sizeof(sequence_list))))
  {
    printf("malloc error!"); //判断内存是否申请成功
    return NULL;
  }
  my_list->size = SIZE; //定义初始化数组大小 在.h文件中

  my_list->length = 0;  //记录当前的位置

  my_list->head = (int *)malloc(sizeof(int) * SIZE); //为数组开辟空间

  return my_list;
}

/*查找顺序表中的元素，返回此元素的位置*/
int find_sequence_list(sequence_list *my_list, int find_elem)
{
  if (my_list == NULL)
  {
    printf("find fail!");
    return -1;
  }
  for (int i = 0; i < my_list->length; i++)
  {
    if (find_elem == my_list->head[i])
    {

      printf("%d\n", my_list->length);
    }
    return 0;
  }
}
/*打印顺序表*/
void printf_sequence_list(sequence_list *my_list)
{
  if (my_list == NULL)
  {
    return;
  }
  for (int i = 0; i < my_list->length; i++)
  {
    printf(" %d", my_list->head[i]);   //加空格以好区分
  }
  printf("\n");
}
/*清空顺序表*/
void clear_sequence_list(sequence_list *my_list)
{
  if (my_list == NULL)
  {
    return;
  }
  my_list->length = 0;                 //让当前的长度为0就可以实现
}
/*释放顺序表表空间*/
void free_sequence_list(sequence_list *my_list)
{

  if (my_list == NULL)
  {
    return;
  }
  if (my_list->head != NULL)
  {
    free(my_list->head);
  }
  free(my_list);
}
/*获得某个位置的元素*/
int get_sequence_list(sequence_list *my_list, int pos)
{
  if (my_list == NULL)
  {
    return -1;
  }
  return my_list->head[pos];
}
/*尾部插入某个元素*/
void push_sequence_list(sequence_list *my_list, int value)
{
  if (my_list == NULL)
  {
    return;
  }
  if (my_list->size == my_list->length) //这里判断数组的元素个数是否满了，满了则开辟新的空间
  {
    int *newSpace = (int *)malloc(sizeof(int) * my_list->size * 2); //默认个新空间是旧空间的两倍
    memcpy(newSpace, my_list->head, my_list->size * sizeof(int));   //注意memcpy的第三个参数是字节数，而不是元素个数
    free(my_list->head);                                            //释放原来的旧空间
    my_list->size = my_list->size * 2;
    my_list->head = newSpace;
  }
  my_list->head[my_list->length] = value; //插入新的元素
  my_list->length++;                      //长度++
}
/*根据位置删除元素*/
void remove_sequence_list(sequence_list *my_list, int pos)
{
  if (my_list == NULL)
  {
    return;
  }
  if (pos < 0 || pos >= my_list->length)
  {
    printf("pos error");
    return;
  }
  for (int i = pos; i < my_list->length; i++)
  {
    my_list->head[i] = my_list->head[i+1];
  }
  my_list->length--;
}
/*根据值删除*/
void rmvalue_sequence_list(sequence_list *my_list, int value)
{
  int pos = -1;
  if (my_list == NULL)
  {
    return;
  }
  for (int i = 0; i < my_list->length; i++)
  {
    if (my_list->head[i] == value)
    {
      pos = i; 
      printf("%d\n",pos);
      break;
    }
  }
  remove_sequence_list(my_list, pos);
}
/*获得当前数组容量*/
int Size_sequence_list(sequence_list *my_list)
{
if (my_list == NULL)
  {
    return -1;
  }
  return my_list->size;
}
/*获得当前长度*/
int length_sequence_list(sequence_list *my_list)
{
  if (my_list == NULL)
  {
    return -1;
  }
  return my_list->length;
}
