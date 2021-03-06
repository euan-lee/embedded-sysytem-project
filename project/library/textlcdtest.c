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
#define TEXTLCD_DRIVER_NAME	 "/dev/peritextlcd"

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
	
	if (argc < 3 )
		
	{
		perror(" Args number is less than 2\n");
		doHelp();
		return 1;
	}
	
	linenum = strtol(argv[1],NULL,10); 
	printf("linenum :%d\n", linenum);
	
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
	if ( len > COLUMN_NUM)
	{
		memcpy(stlcd.TextData[stlcd.cmdData - 1],argv[2],COLUMN_NUM);
	}
	else
	{
		memcpy(stlcd.TextData[stlcd.cmdData - 1],argv[2],len);
	}
	
	stlcd.cmd = CMD_WRITE_STRING;
	
	lcdtextwrite(stlcd.cmd,stlcd.TextData[stlcd.cmdData - 1],linenum);
	
	return 0;
}
