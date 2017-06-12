#include <graphics.h>
#include <stdlib.h>
#include "Struct.h"
extern struct color bg_color, point_color, hangman_color, punkt_color, word_color, negative_color, temp_color;  
extern struct statistic Stats;

int Statist(){
    int button;
    cleardevice();
    settextstyle(1,0,6);
    settextjustify(1,1);
    setcolor(RGB(negative_color.red,negative_color.green,negative_color.blue));
    outtextxy(300,100,"HANGMAN"); 
    settextstyle(1,0,3);
    setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue)); 
    settextstyle(1,0,3);
    
    char *games, *wins, *loses, *money, *diff, *inrow, *maxinrow;
    money = new char[10];
    games = new char[10];
    loses = new char[10];
    wins = new char[10];
    diff = new char[10];
    maxinrow = new char[10];
    
    settextjustify(0,0);
    outtextxy(50,150,"Игр сыграно:");
    outtextxy(50,180,"Отгадано подряд:");
    outtextxy(50,210,"Отгадано слов:");
    outtextxy(50,240,"Убито висельников:");
    outtextxy(50,270,"Средняя сложность:");
 
    
    
    itoa(Stats.games,games,10);
    itoa(Stats.wins,wins,10);
    itoa(Stats.loses,loses,10);
    itoa(Stats.money,money,10);
    itoa(Stats.maxinrow,maxinrow,10);
    if (Stats.games==0) itoa(Stats.games,diff,10);
    else itoa((Stats.diff)/Stats.games,diff,10);
    
    settextstyle(1,0,1);
    outtextxy(520,30,money);
    outtextxy(500,30,"$");
    settextstyle(1,0,3);
    settextjustify(2,0);
    outtextxy(550,150,games);
    outtextxy(550,180,maxinrow);
    outtextxy(550,210,wins);
    outtextxy(550,240,loses);
    outtextxy(550,270,diff);
    
    setcolor(RGB(point_color.red,point_color.green,point_color.blue));
    settextjustify(1,0);
    outtextxy(300,370,"В меню");
    do{
    button=getch();
    if (button==27) break;
    }while(button!=13);
    cleardevice();
    return 0;
};
