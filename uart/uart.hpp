#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#define  STTY_DEV "/dev/ttyUSB0"
extern int fd;
extern int  Recv_Buf[512];
extern char send_Buf[15];
 //int  *send_Buf="12345678";
void usart_config(int fd);
int Uart_OpenDev(char *Dev);
void Uart_RecvFrame(int fd);
void Uart_SendFrame(int fd);

