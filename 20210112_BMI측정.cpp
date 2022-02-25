//BMI측정 
#include<stdio.h>

int main()
{
	float cm;
	int kg;
	int BMI;
	
	printf("키를 입력주세요.");
	scanf("%f", &cm);
	printf("몸무게를 입력주세요.");
	scanf("%d", &kg);
	
	cm = cm / 100;
	cm = cm * cm;
	BMI = kg / cm;
	
	printf("당신의 BMI는 %d입니다.\n", BMI);
	
	if(BMI >= 30)
		printf("당신은 비만입니다.");
}
