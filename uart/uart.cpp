/*********************************************************************************
  *      Copyright:  (C) 2017 TangBin<tangbinmvp@gmail.com>
  *                  All rights reserved.
  *
  *       Filename:  s_uart1.c
  *    Description:  This file 
  *                 
  *        Version:  1.0.0(06/04/2017)
  *         Author:  wwk <1162431386@qq.com>
  *      ChangeLog:  1, Release initial version on "06/04/2017 07:51:59 PM"
  *                 
  ********************************************************************************/
#include "uart.hpp"
int fd;
int  Recv_Buf[512]={0};
char send_Buf[15];
void usart_config(int fd)
{
   
   struct termios opt;
   tcgetattr(fd,&opt);
   tcflush(fd,TCIOFLUSH);     //配置串口

/* 设置波特率*/ 
cfsetispeed(&opt,B115200);
cfsetospeed(&opt,B115200);

/*设置数据位*/
opt.c_cflag &= ~CSIZE;
opt.c_cflag |=CS8;             //有需要可设置为7位


 /*设置奇偶校验*/
 opt.c_cflag &=~PARENB;
 opt.c_iflag &=~INPCK;      //无奇偶校验


 /*设置停止位*/
 opt.c_cflag &=~CSTOPB;     //               这里。可以选择2位停止，具体配置可查资料

 /* 设置超时时间   -15s*/
  opt.c_cc[VTIME] = 150;
  opt.c_cc[VMIN] = 0;

   
   /*设置写入设备*/
   if (0!=tcsetattr(fd,TCSANOW,&opt))
   {
      perror("set baudrate");
      
   }
tcflush(fd,TCIOFLUSH);


}



int Uart_OpenDev(char *Dev)
{
        int fd = open( Dev, O_RDWR | O_NOCTTY );         //| O_NOCTTY | O_NDELAY | O_NONBLOCK
        if (-1 == fd)
        { 
                perror("Can't Open Serial Port");
                return -1;
        }
        else
	{
		printf("%d \n",fd);	
                return fd;
	}
 
}
void Uart_SendFrame(int fd)
{
      if(0==write(fd,send_Buf , strlen(send_Buf)))
        {
		printf("send end");
               // break;
	} 

          printf("%s\n",send_Buf);

}                                 
               


void Uart_RecvFrame(int fd)
{
        while(1)
   {  
      if(0>=read(fd,Recv_Buf, 512)) ;
        {
		printf("error");
                break;
	} 

          printf("%s\n",Recv_Buf);

    }    
}

