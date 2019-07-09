#include "sequence_list.h"
int main(void)
{

  sequence_list *test_list = Init_sequence_list();
  printf ("当前长度：%d\n",length_sequence_list(test_list));
  for (int i = 0; i < 20; i++)
  {
     push_sequence_list(test_list, i);

  }   
      //clear_sequence_list(test_list);
      printf ("当前长度：%d\n",length_sequence_list(test_list)); 
      rmvalue_sequence_list(test_list, 1); 
      //remove_sequence_list(test_list, 0);
     // printf ("位置：%d\n",get_sequence_list(test_list, 10));
      printf_sequence_list(test_list);
      free_sequence_list(test_list);
     
     return 0;
}

