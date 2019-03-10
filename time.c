
/*#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<time.h>
#include<sys/time.h>
#include<stdio.h>
#define N 100  //设置最大的定时器个数
int i=0,t=1;   //i代表定时器的个数；t表示时间，逐秒递增
  

void timeout() //判断定时器是否超时，以及超时时所要执行的动作
{   
   alarm(1);
  printf("Time: %d\n",t++);
    
}
  
int main() //测试函数，定义三个定时器
{
    setTimer(1,1);
    setTimer(1000,2);
    //setTimer(5,3);
    signal(SIGALRM,timeout); //接到SIGALRM信号，则执行timeout函数
    alarm(1);
    while(1)
    {
      
      
    }
    exit(0);
}*/
#include <stdio.h>        //printf()
#include <unistd.h>        //pause()
#include <signal.h>        //signal()
#include <string.h>        //memset()
#include <sys/time.h>    //struct itimerval, setitimer()

static int count = 0;

void printMes(int signo)
{
    printf("Get a SIGALRM, %d counts!\n", ++count);
}

int main()
{
    int res = 0;
    struct itimerval tick;
    
    signal(SIGALRM, printMes);
    memset(&tick, 0, sizeof(tick));

    //Timeout to run first time
    tick.it_value.tv_sec = 0;
    tick.it_value.tv_usec = 100000;

    //After first, the Interval time for clock
    tick.it_interval.tv_sec = 0;
    tick.it_interval.tv_usec = 100000;

    if(setitimer(ITIMER_REAL, &tick, NULL) < 0)
            printf("Set timer failed!\n");

    //When get a SIGALRM, the main process will enter another loop for pause()
    while(1)
    {
       
    }
    return 0;
}
