//BMI���� 
#include<stdio.h>

int main()
{
	float cm;
	int kg;
	int BMI;
	
	printf("Ű�� �Է��ּ���.");
	scanf("%f", &cm);
	printf("�����Ը� �Է��ּ���.");
	scanf("%d", &kg);
	
	cm = cm / 100;
	cm = cm * cm;
	BMI = kg / cm;
	
	printf("����� BMI�� %d�Դϴ�.\n", BMI);
	
	if(BMI >= 30)
		printf("����� ���Դϴ�.");
}
