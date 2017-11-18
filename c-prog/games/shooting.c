#include<stdio.h>
#include<stdlib.h>
//#include<windows.h>
//#include<conio.h>
#include<time.h>
 
void intro_game(void );
void horizontal_slide(int x, int y, char c2[]);
void draw_rectangle(int r, int c);
void display_text(int count, int r_count);
void game_control(int *r_c, int rnd);
void gotoxy(int x, int y);
 
int main(void )
{
    int count=0, rnd;
    int r_count=0;
    char *target="□";
    srand((unsigned int)time(NULL));
    intro_game();
    do
    {
        system("cls");
        draw_rectangle(20, 20);
        rnd=rand()%35+4;
        gotoxy(rnd, 2);
        printf("%s", target);
        count++;
        display_text(count, r_count);
        game_control(&r_count, rnd);
    }while(count<10);
    return 0;
}
//게임에대한설명을출력하는함수
void intro_game(void )
{
    printf("목표물에화살쏘기\n\n");
    printf("목표물(□)을맞추는게임입니다.\n");
    printf("화살은스페이스키로발사합니다.\n\n");
    printf("아무키나누르면시작합니다. ");
    _getch();
}
//로켓의위치를좌우로이동시키는함수
void horizontal_slide(int x, int y, char c2[])
{
    gotoxy(x,y);
    printf("%s", c2);
    Sleep(50);
    printf("\b ");
}
void draw_rectangle(int r, int c)
{
    int i, j;
    unsigned char a=0xa6, b[7];
 
    for(i=1;i<7;i++)
        b[i]=0xa0+i;
    printf("%c%c", a, b[3]);
    for(i=0;i<c;i++)
        printf("%c%c", a, b[1]);
 
    printf("%c%c", a, b[4]);
    printf("\n");
    for(i=0;i<r;i++)
    {
        printf("%c%c", a, b[2]);
        for(j=0;j<c;j++)
            printf(" ");
        printf("%c%c", a, b[2]);
        printf("\n");
    }
    printf("%c%c", a, b[6]);
    for(i=0;i<c;i++)
        printf("%c%c", a, b[1]);
    printf("%c%c", a, b[5]);
    printf("\n");
}
 
//시도한횟수와성공한횟수를화면에출력하는함수
void display_text(int count, int r_count)
{
    gotoxy(46, 2);
    printf("스페이스키를누르면\n");
    gotoxy(46,3);
    printf("화살이발사됩니다.\n");
    gotoxy(46,5);
    printf("횟수: %d", count);
    gotoxy(46,6);
    printf("성공: %d", r_count);
}
//목표물에화살쏘기게임의제어함수
void game_control(int *r_c, int rnd)
{
    int i=1, k=1, y;
    char *horse="▲", chr;
    do
    {
        i+=k;
        if(i>39)
            k=-1;
        else if(i<3)
            k=+1;
        horizontal_slide(i+1, 21, horse);
    }while(!_kbhit());
    chr=_getch();
    y=21;
    if(chr==32)
    {
        while(y>2)
        {
            y-=1;
            gotoxy(i+1, y);
            printf("↑");
            Sleep(50);
            printf("\b ");
        }
        if((i>=rnd-2) && (i<=rnd))
        {
            gotoxy(rnd, 2);
            printf("☆");
            gotoxy(46, 8);
            printf("맞았습니다. ");
            Sleep(50);
            *r_c=*r_c+1;
        }
        gotoxy(1, 24);
        printf("아무키나누르면다음진행...");
        _getch();
    }
}
void gotoxy(int x, int y)
{
    COORD Pos = { x-1, y-1 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
