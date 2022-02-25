//별 숫자 세기게임 
#include<conio.h>	//getch, putch 용 
#include<windows.h>	//system, Sleep,SetConsoleCursorPosition 용 
#include<stdio.h>	//printf, scnaf 용 
#include<time.h>	//time 용 
#include<stdlib.h>	//rand, srand 용 

#define STAR "바보"	//특수 기호 문자열 "#"의 매크로 상수
#define INTERVAL 300	//별 반짝임의 주기 
#define MIN 5	//최소 별 반짝임 횟수 
#define MAX 12	//최대 별 반짝임 횟수 

void gotoxy(int x, int y);	// 커서를(x,y) 좌표로 이동 
void draw_rectangle(int, int, int, int);	//별이 나타날 영역의 테두리 그리기 

int main()
{
	int input;	//게임을 하는 사용자가 입력한 별반짝임 횟수 
	int repeats;	//실제 병의 반짝임 횟수 
	int start_x = 10;	//사각형 영역 왼쪽 상단 x 좌표 
	int start_y = 3;	//사각형 영역 왼쪽 상단 x 좌표 
	int width = 50;		//별이 나타날 사각형 영역의 가로 폭 
	int height = 10;	//현재 별이 나타날 좌표 
	int x, y, i;
	
	printf("별이 반짝이는 횟수를 맞추는 게임입니다. 아무키나 누르면 시작됩니다.");
	getch();	//임의의 키를 누르면 게임을 시작하도록 기다리게 함 
	
	system("cls");	//화면 지우기 
	Sleep(1000);	//위의 getch()에서 키를 누르자마자 갑자기 실행되지 않도록 
	
	srand(time(NULL));	//rand함수의 seed를 현재 시간으로 설정 
	
	//별 반짝임 횟수를 최소 MIN번 중 임의의 값으로 설정하기 
	repeats = rand() % (MAX - MIN + 1) + MIN;
	
	//별이 나타날 사각형 영역 바깥으로 테두리를 그린후 1초 동안 중지하기 
	draw_rectangle(start_x, start_y, width, height);
	Sleep(1000);
	
	//별이 나타날 영역 안에서 임의의 (x,y) 좌표에 INTERVAL 간격으로 병을 repeats번 반짝이기 
	for(i=1;i<=repeats;i++)
	{
		//rand 함수를 이영하여 별이 나타날 (x,y) 좌표 구하기 
		//"#"은 두칸을 차지하므로 일반 문자를 출력할 때보다 최대x 좌표는 1더 작아야 하다. 
		x = start_x + rand()%(width-2);
		y = start_y + rand()%(height - 1);
		
		//별을 (x,y) 좌표에 표시한 후 INTERVAL밀리초 동안 중지하기 
		gotoxy(x,y);
		printf("%s",STAR);
		Sleep(INTERVAL);
		
		//(x,y)좌표에 있는 별 지우기 
		gotoxy(x, y);
		printf("%s","   ");
		Sleep(INTERVAL);
	}
	
	//사용자에게 별 반짝임 횟수를 물어서 답을 입력받기 
	gotoxy(20,21);
	printf("별은 몇 본 (%d~%d 번) 반짝거렸을까요?",MIN,MAX);
	scanf("%d",&input);
	
	//사용자가 잡한 횟수에 따라 정답을 맞혔는지 틀렸는지 메시지 출력하기 
	gotoxy(10,22);
	if(input == repeats)
		printf("맞았습니다!\n");
	else
		printf("틀렸습니다. 답은 %d번입니다!\n",repeats);
		
		return 0;
}

//(start_x, start_y) 좌표에서 시작하는 가로 폭이 width이고 세로 높이가 height인 사각형 바깥으로 테두리를 그리는 함수 
void draw_rectangle(int start_x, int start_y, int width, int height)
{
	int col, row;
	
	//사각형 위 경계선 그리기 
	gotoxy(start_x - 1, start_y -1);
	for(col=0;col<=width+1;col++)
		putch('=');
	
	//사각형 아래 경계선 그리기 
	gotoxy(start_x - 1, start_y + height);
	for(col=0;col<=width+1;col++)
		putch('=');

	//사각형 왼쪽 끝에 '|' 그리기 
	for(row=0;row<height;row++)
	{
		gotoxy(start_x - 1, start_y + row);
		putch('|');
	}
	
	//사각형 오른쪽 끝에 '|' 그리기 
	for(row=0;row<height;row++)
	{
		gotoxy(start_x + width, start_y + row);
		putch('|');
	}
}

//커서를 (x,y) 좌표로 이동하는 함수 
void gotoxy(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Cur);
}
