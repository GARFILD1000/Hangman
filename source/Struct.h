#ifndef STRUCT_H
#define STRUCT_H

struct statistic{         //структура, хранит информацию:
    int console;       //активность консоли
    int games;         //сыграно игр
    int money;         //накоплено очков
    int wins;          //побед
    int loses;         //поражений
    int diff;          //предпочтительная сложность
    int inrow;         //в ряд
    int maxinrow;      //максимум в ряд
    int difficulty;    //текущая сложность игры
};

struct color{             //структура, хранящая RGB параметры цвета
    int red;
    int green;
    int blue;
};

#endif
