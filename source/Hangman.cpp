#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <iostream>
#include <graphics.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <io.h>

#include "Struct.h"
#include "Options.h"
#include "Stats.h"
#include "Filework.h"
#include "Game.h"

struct color bg_color, point_color, hangman_color, punkt_color, word_color, negative_color, temp_color;  
// цвет фона, цвет выделения, цвет отрисовки висельника, цвет пунктов меню, цвет выделения пунктов, 
// цвет заполнения слова, отрицательный цвет, структура для отдельных нужд.
struct statistic Stats;



int MenuCategory(){
    int button, point=1;
    cleardevice();
    do{
        settextstyle(1,0,1);
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        char *money;
        money = new char[10];
        itoa(Stats.money,money,10);
        settextjustify(0,1);
        outtextxy(520,30,money);
        outtextxy(500,30,"$");  
        settextstyle(0,0,4);
        settextjustify(1,1);
        settextstyle(1,0,6);
        setcolor(RGB(negative_color.red,negative_color.green,negative_color.blue));
        outtextxy(300,100,"HANGMAN"); 
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        settextstyle(1,0,3); 
        outtextxy(300,180,"ВЫБОР КАТЕГОРИИ:");
        if (point==1) setcolor(RGB(point_color.red,point_color.green,point_color.blue));
        outtextxy(300,220,"Программирование");
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        if (point==2) setcolor(RGB(point_color.red,point_color.green,point_color.blue));
        outtextxy(300,250,"Спорт");
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        if (point==3) setcolor(RGB(point_color.red,point_color.green,point_color.blue));
        outtextxy(300,280,"География");
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        if (point==4) setcolor(RGB(point_color.red,point_color.green,point_color.blue));
        outtextxy(300,310,"Музыка");
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        if (point==5) setcolor(RGB(point_color.red,point_color.green,point_color.blue));
        outtextxy(300,340,"Кинематограф");
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        if (point==6) setcolor(RGB(negative_color.red,negative_color.green,negative_color.blue));
        outtextxy(300,370,"Назад");
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        button=getch();
        switch(button){
        case 72: if (point>1) point--; break;
        case 80: if (point<6) point++; break;
        case 13: if (point!=6) {for(;Game(point);); Statist();}; cleardevice(); return 0; break;       
        case 27: cleardevice(); return 0;
        };
    } while(1);        
}

int MainMenu(){
int button, point=1, red=0;
settextstyle(1,0,1);
setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
char *money;
money = new char[10];
itoa(Stats.money,money,10);
settextjustify(0,1);
outtextxy(520,30,money);
outtextxy(500,30,"$");  
settextjustify(1,1);
setcolor(15);
    do{ 
        setbkcolor(RGB(bg_color.red,bg_color.green,bg_color.blue));
        cleardevice();
        settextstyle(1,0,6);
        if (red <250) red++;
        setcolor(RGB(negative_color.red,negative_color.green,negative_color.blue));
        outtextxy(300,100,"HANGMAN"); 
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        settextstyle(1,0,3);  
        if (point==1) setcolor(RGB(point_color.red,point_color.green,point_color.blue));
        outtextxy(300,250,"Играть");
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        if (point==2) setcolor(RGB(point_color.red,point_color.green,point_color.blue));
        outtextxy(300,280,"Настройки");
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        if (point==3) setcolor(RGB(point_color.red,point_color.green,point_color.blue));
        outtextxy(300,310,"Статистика");
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        if (point==4) setcolor(RGB(negative_color.red,negative_color.green,negative_color.blue));
        outtextxy(300,340,"Выход");
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        button=getch();
        switch(button){
        case 72: if (point>1) point--; break;
        case 80: if (point<4) point++; break;
        case 13: 
             switch(point){
             case 1: return 1;
             case 2: return 2;
             case 3: return 3;
             case 4: return 0;     
             }; 
        case 27: return 0;
        };
    } while(1);      
}

int main(){
    setlocale(LC_ALL, "rus");
    LoadOptions();
    if (!Stats.console) {
        FreeConsole();
    };
    initwindow(600,400,"Hangman");
    setbkcolor(RGB(bg_color.red, bg_color.green, bg_color.blue));
    cleardevice();
    POINT mypoint;                //класс координат точки
    mypoint.x=getmaxwidth()/2-300; mypoint.y=getmaxheight()/2-200;   //максимальные параметры дисплея
    HWND BGI_window = FindWindow(NULL, "Hangman");      // переменной дескриптора передаётся дескриптор окна "Hangman"
    MoveWindow(BGI_window,mypoint.x,mypoint.y,608,423,false);  //окно ставится по центру
    int menu_choice;
    do{
        menu_choice=MainMenu();
        switch (menu_choice){
        case 1: MenuCategory(); break;
        case 2: Options(); break;
        case 3: Statist(); break;
        case 0: return 0;    
        };
        SaveOptions();         
    }while(1);
}
