#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <ctype.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "textlcd.h"

#define TEXTLCD_DRIVER_NAME		"/dev/peritextlcd"

void doHelp(void)
{
	printf("usage: textlcdtest <linenum> <'string'>\n");
	printf("       linenum => 1 ~ 2\n");	
	printf("  ex) textlcdtest 2 'test hello'\n");
}

int main(int argc , char **argv)
{
	unsigned int linenum = 0;

	stTextLCD  stlcd; 
	
	int len; 
	
	memset(&stlcd,0,sizeof(stTextLCD));
	
	if (argc < 3 )	{
		perror(" Args number is less than 2\n");
		doHelp();
		return 1;
	}
	//ok
	printf("argv is  %d\n",argc);
     printf("argv is  %s\n",argv[0]);
	linenum = strtol(argv[1],NULL,10); 
	printf("linenum :%d\n", linenum);
	//ok

	if ( linenum == 1) 
	{
		stlcd.cmdData = CMD_DATA_WRITE_LINE_1;
	}
	else if ( linenum == 2) 
	{
		stlcd.cmdData = CMD_DATA_WRITE_LINE_2;
	}
	else 
	{
		printf("linenum : %d  wrong .  range (1 ~ 2)\n", linenum);
		return 1; 
	}
	
	printf("string:%s\n",argv[2]);
	len = strlen(argv[2]);
	//문자열 길이 반환 ok
	argv[2] = "forest";
	printf("string:%s\n",argv[2]);
	if ( len > COLUMN_NUM)//문자열 길이>열 
	{
		memcpy(stlcd.TextData[stlcd.cmdData - 1],argv[2],COLUMN_NUM);//arg[2]=s"fortest"라고 바꿔보기!!
	}
	else 
	{
		memcpy(stlcd.TextData[stlcd.cmdData - 1],argv[2],len);//첫번쨰 인자=복사될 변수 ,두번쨰인자 =복사 내용,바이트 수//arg[2]=s"fortest"라고 바꿔보기!!s
	}
	
	stlcd.cmd = CMD_WRITE_STRING;
	printf("TextData[stlcd.cmdData - 1]:%s",stlcd.TextData[stlcd.cmdData - 1]);//문자열이 나와야 됨
	lcdtextwrite(stlcd.cmd,stlcd.TextData[stlcd.cmdData - 1],linenum);
	
	return 0;
}
