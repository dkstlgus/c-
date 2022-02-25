//휴대폰 사용요금 청구서 나타내기 
#include<stdio.h>

#define FREE_VOICE 100		//무료 음성 시간 
#define FREE_TEXT 20		//무료 문자 건 
#define BASIC_CHARGE 10000	//기본 요금 
#define TEXT_RATE 20		//건당 문자 전송 요금

int voice_charge(int voice);
int text_charge(int text);

int main()
{
	int voice, text;			//음성통화시간, 문자 전송 건수 
	int V_charge, T_charge;		//음성 요금, 문자 전송 요금(기본 20건 제외) 
	int charge;					//총 전화 요금
	
	printf("음성 통화 시간은(분)?"); scanf("%d", &voice);
	printf("문자 전송 건수는?"); scanf("%d", &text);
	
	V_charge = voice_charge(voice);		//음성 전화 요금 계산 
	T_charge = text_charge(text);		//문자 전송 요금 계산(기본 20건 제외) 
	
	charge = BASIC_CHARGE + V_charge + T_charge;
	
	//전화 요금 멍세서 출력
	
	printf("\n\n");
	printf("휴대폰 사용 요금 청구서    \n");
	printf("======================================== \n");
	printf("음성 통화 시간 %2d분                      \n", voice);
	printf("문주 전송 건수 %2d분                      \n", text);
	printf("---------------------------------------- \n");
	printf("기본요금                        %6d원 \n", BASIC_CHARGE);
	printf("음성 통화료 %3d                 %6d원 \n", voice, V_charge);
	if(text >= FREE_TEXT)
		printf("문자 전송료 초과 %2d건(20건 무료)%6d원 \n", text - FREE_TEXT, T_charge);
	printf("---------------------------------------- \n");
	printf("합계                            %6d원 \n", charge);
	printf("부가세(10%%)                     %6.0f원 \n", charge * 0.1);
	printf("======================================== \n");
	printf("이번 달 요금                    %6.0f원 \n", charge * 1.1);
	
	return 0;	
}

//음성 전화 요금 계산, 100분까지는 분당 100원, 100분 초과분은 분당 80원
int voice_charge(int voice)
{
	if(voice >= FREE_VOICE)
		return(FREE_VOICE * 100 + (voice - FREE_VOICE) * 80);
	else
		return(voice * 100);
}

//문자 전송 요금 계산, 20건까지는 무료, 20건 초과분은 건낭 20원 
int text_charge(int text)
{
	if(text >= FREE_TEXT)
		return(text - FREE_TEXT) * 20;
	else
		return 0;
} 


