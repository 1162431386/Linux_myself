#include "node_list.h"

typedef struct Student
{
    char name[10];
    int years;
    char sex[5];
} student;
void my_print(void *data)
{
    student *p = (student *)data;
    printf("name is: %s   age is: %d   sex is: %s\n", p->name, p->years, p->sex);
}
int main()
{
    link_list *list = node_Init();
    student p1 = {"小明",12,
                  "男"};
    student p2 = {"小凯",10,
                  "女"};
    student p3 = {"小王",19,
                  "男"};
    student p4 = {"冰泉",16,
                  "男"};
    student p5 = {"二狗",15,
                  "男"};
    student p6 = {"红红",14,
                  "女"};
    student p7 = {"大哥",13,
                  "男"};
    student p8 = {"灭霸",13,
                  "男"};
    Insert_link_list(list, 0, &p1); 
    Insert_link_list(list, 1, &p2);
    Insert_link_list(list, 2, &p3);
    Insert_link_list(list, 3, &p4);
    Insert_link_list(list, 4, &p5);
    Insert_link_list(list, 5, &p6);
    Insert_link_list(list, 6, &p7);
    Insert_link_list(list, 7, &p8);
   print_link_list(list, my_print);
     //removebypos_link_list(list,6);
     //print_link_list(list, my_print);
    int pos;
    pos=Find_link_list(list,&p5);
   // pos=Size_link_list(list);
      printf("%d\n",pos);
    freespace_link_list(list);
   // printf("%d\n",list->size);
   
 
   
}
