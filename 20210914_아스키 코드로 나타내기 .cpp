//�ƽ�Ű �ڵ�� ��Ÿ���� 
#include<stdio.h>
#include<conio.h> 

#define ENTER 13

int main(void)
{
	int ch;
	int i = 0;
	
	printf("�ƽ�Ű �ڵ�� ��ȯ�� Ű�� ��������... \n");
	printf("Enter Ű�� ������ ���α׷��� ����˴ϴ�. \n");
	
	do
	{
		ch = getch();
		
		printf("(%d), ���� : (%c) , �ƽ�Ű �ڵ� = (%d) \n",i++,ch,ch);
		
	} while(ch!=ENTER);
}
