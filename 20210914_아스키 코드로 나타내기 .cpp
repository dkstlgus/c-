//아스키 코드로 나타내기 
#include<stdio.h>
#include<conio.h> 

#define ENTER 13

int main(void)
{
	int ch;
	int i = 0;
	
	printf("아스키 코드로 변환할 키를 누르세요... \n");
	printf("Enter 키를 누르면 프로그램은 종료됩니다. \n");
	
	do
	{
		ch = getch();
		
		printf("(%d), 문자 : (%c) , 아스키 코드 = (%d) \n",i++,ch,ch);
		
	} while(ch!=ENTER);
}
