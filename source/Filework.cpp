#include <graphics.h>
#include <stdlib.h>
#include "Struct.h"

extern struct color bg_color, point_color, hangman_color, punkt_color, word_color, negative_color, temp_color;  
extern struct statistic Stats;

//   процедура заполняет структуры с натройками и статистикой изначальными значениями
void RestoreOptions(){
            hangman_color.blue=200;
            hangman_color.green=200;
            hangman_color.red=200;

            point_color.blue=200;
            point_color.green=50;
            point_color.red=50;
    
            punkt_color.blue=200;
            punkt_color.green=200;
            punkt_color.red=200;
    
            word_color.blue=200;
            word_color.green=200;
            word_color.red=200;
    
            negative_color.blue=20;
            negative_color.green=20;
            negative_color.red=250;
    
            bg_color.red=0;
            bg_color.blue=0;
            bg_color.green=0;
    
            Stats.console=1;
            Stats.diff=0;
            Stats.games=0;
            Stats.loses=0;
            Stats.money=0;
            Stats.wins=0;
            Stats.inrow=0;
            Stats.maxinrow=0;
            Stats.difficulty=7; 
            return;
}


//  страница сброса настроек и статистики
void RestoreOptionsWindow(){
    int point=1, button; 
    do{ cleardevice();
        outtextxy(300,70,"СБРОСИТЬ");
        outtextxy(300,100,"настройки и статистику?");
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        if (point==1) {
            
            outtextxy(300,250,"настройки и статистика");
            setcolor(RGB(negative_color.red,negative_color.green,negative_color.blue));
            outtextxy(300,280,"сбросятся");
            setcolor(RGB(point_color.red,point_color.green,point_color.blue));
        };
        outtextxy(300,160,"Да");
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        if (point==2) {
            
            outtextxy(300,250,"настройки и статистика");
            outtextxy(300,280,"не сбросятся");
            setcolor(RGB(point_color.red,point_color.green,point_color.blue));
        };
        outtextxy(300,190,"Нет");
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        
        button = getch();
        switch(button){
        case 72: if (point>1) point--; break;
        case 80: if (point<2) point++; break;
        case 13: RestoreOptions(); cleardevice(); return;
        case 27: return;
        };
    }while(1);                                       

    
}


//   процедура загружает настройки и статистику из файла options.dat в соотвтствующие структуры
//   если этого файла нет в каталоге, создаёт его и заполняет изначальными значениями
void LoadOptions(){
    FILE *options_file;
    if ((options_file=fopen("..\\saves\\options.dat","rb"))==NULL){
        options_file=fopen("..\\saves\\options.dat","wb");
        RestoreOptions();
    };
    fread(&Stats,sizeof(statistic),1,options_file);  
    fread(&bg_color,sizeof(color),1,options_file);  
    fread(&point_color,sizeof(color),1,options_file);  
    fread(&hangman_color,sizeof(color),1,options_file);  
    fread(&punkt_color,sizeof(color),1,options_file);  
    fread(&word_color,sizeof(color),1,options_file);  
    fread(&negative_color,sizeof(color),1,options_file);
    fclose(options_file);
    return;
}

// процедура сохраняет настройки и статистику в файл options.dat
void SaveOptions(){
    FILE *options_file;
    options_file=fopen("..\\saves\\options.dat","wb");
    fwrite(&Stats,sizeof(statistic),1,options_file);  
    fwrite(&bg_color,sizeof(color),1,options_file);  
    fwrite(&point_color,sizeof(color),1,options_file);  
    fwrite(&hangman_color,sizeof(color),1,options_file);  
    fwrite(&punkt_color,sizeof(color),1,options_file);  
    fwrite(&word_color,sizeof(color),1,options_file);  
    fwrite(&negative_color,sizeof(color),1,options_file);
    fclose(options_file);  
    return;                             
}

char** WordsFromFile(int &single_word, const char* file_name){
    FILE *text_file;
    
    int num_bukva=0;             //Количество символов в файле (предполагаемое)
    int *single_word_length;        //Длина каждого отдельного слова
    char *words;                    //Массив всех букв из файла
    char **words_arr;               //Массив со словами из файла
    
    int i=0, k=0, j=0, t;
                 
    if ((text_file = fopen(file_name, "r"))== NULL){
        perror("Error open file"); 
    };
    
    while(!feof(text_file)){ 
        fgetc(text_file);
        num_bukva++;
    };
    rewind(text_file);
    words = new char[num_bukva];
    fgets(words,num_bukva,text_file);
        
    single_word=0;
    if (words[1]==0) return NULL;
    else{
        while(words[i]!=0){
            if ((words[i]==' ')||(words[i+1]==0)){single_word++;};           //находим количество слов
            i++;
        };
        
        i=j=k=0;
        single_word_length=new int[single_word];
        while(words[i]!=0){
            if ((words[i]==' ')||(words[i+1]==0)){single_word_length[k]=j+1; k++; j=0;}  //находим длину кадого отдельного слова
            else j++;
            i++;
        };
                    
        words_arr= new char*[single_word];
        for (i=0;i<single_word;i++){
            words_arr[i]=new char[single_word_length[i]];   //создаём двумерный динамический массив, каждая строка длиной в слово
        };
        
        i=j=k=0;
        while(words[i]!=0){   if ((words[i]==' ')&&(words[i+1]==' ')) return NULL;              
        if (words[i]==' '){j++;k=0;}
            else { if ((words[i]>-65)&&(words[i]<-32)) words_arr[j][k]=words[i]+32; else if( words[i]==-88) words_arr[j][k]=-72; else if ((words[i]<0)&&(words[i>-33])) words_arr[j][k]=words[i]; k++;};           //заполнение массива словами
            i++;
        };
        return words_arr;    
    };
}
