#include <graphics.h>
#include <stdlib.h>
#include "Struct.h"
extern struct color bg_color, point_color, hangman_color, punkt_color, word_color, negative_color, temp_color;  
extern struct statistic Stats;

char** WordsFromFile(int &single_word, const char* file_name);

//   отрисовка виселицы и человека на ней
void Hangman(int mark){
    switch(Stats.difficulty){
    case 7:
        switch(mark){
        case 1: line(560,250,560,100); break;
        case 2: line(400,100,400,250); break;
        case 3: line(560,100,400,100); line(560,120,540,100); line(400,120,420,100);break;  
        case 4: line(480,100,480,120); break;
        case 5: line(465,250,465,230); line(495,250,495,230); line(460,230,500,230); break;
        case 6: circle(480,133,13); line(480,146,480,190); line(480,190,490,230); line(480,190,470,230); line(480,150,470,180); line(480,150,490,180); break;
        case 7: setcolor(RGB(bg_color.red,bg_color.green,bg_color.blue)); line(465,250,465,230); line(495,250,495,230); line(460,230,500,230); break;
        }; break;
     case 1:
        switch(mark){
        case 1: line(560,250,560,100); line(400,100,400,250); line(560,100,400,100); line(560,120,540,100); line(400,120,420,100); line(480,100,480,120); line(465,250,465,230); line(495,250,495,230); line(460,230,500,230); circle(480,133,13); line(480,146,480,190); line(480,190,490,230); line(480,190,470,230); line(480,150,470,180); line(480,150,490,180);         setcolor(0); line(465,250,465,230); line(495,250,495,230); line(460,230,500,230); break;
        }; break;
     case 2:
         switch(mark){
         case 1: line(560,250,560,100); line(400,100,400,250);line(560,100,400,100); line(560,120,540,100); line(400,120,420,100); line(480,100,480,120); break;
         case 2: line(465,250,465,230); line(495,250,495,230); line(460,230,500,230); circle(480,133,13); line(480,146,480,190); line(480,190,490,230); line(480,190,470,230); line(480,150,470,180); line(480,150,490,180); setcolor(RGB(bg_color.red,bg_color.green,bg_color.blue)); line(465,250,465,230); line(495,250,495,230); line(460,230,500,230); break;
         }; break;
     case 3:
         switch(mark){
         case 1: line(560,250,560,100); line(400,100,400,250); line(560,100,400,100); line(560,120,540,100); line(400,120,420,100);break;  
         case 2: line(480,100,480,120); break;
         case 3: line(465,250,465,230); line(495,250,495,230); line(460,230,500,230); circle(480,133,13); line(480,146,480,190); line(480,190,490,230); line(480,190,470,230); line(480,150,470,180); line(480,150,490,180); setcolor(RGB(bg_color.red,bg_color.green,bg_color.blue)); line(465,250,465,230); line(495,250,495,230); line(460,230,500,230); break;
         }; break;
     case 4:
         switch(mark){
         case 1: line(560,250,560,100); line(400,100,400,250); line(560,100,400,100); line(560,120,540,100); line(400,120,420,100); break; 
         case 2: line(480,100,480,120); break;
         case 3: line(465,250,465,230); line(495,250,495,230); line(460,230,500,230); break;
         case 4: circle(480,133,13); line(480,146,480,190); line(480,190,490,230); line(480,190,470,230); line(480,150,470,180); line(480,150,490,180); 
         setcolor(RGB(bg_color.red,bg_color.green,bg_color.blue)); line(465,250,465,230); line(495,250,495,230); line(460,230,500,230); break;
         }; break;
     case 5:
         switch(mark){
         case 1: line(560,250,560,100); 
          line(400,100,400,250); 
          line(560,100,400,100); line(560,120,540,100); line(400,120,420,100);break;  
         case 2: line(480,100,480,120); break;
         case 3: line(465,250,465,230); line(495,250,495,230); line(460,230,500,230); break;
         case 4: circle(480,133,13); line(480,146,480,190); line(480,190,490,230); line(480,190,470,230); line(480,150,470,180); line(480,150,490,180); break;
         case 5: setcolor(RGB(bg_color.red,bg_color.green,bg_color.blue)); line(465,250,465,230); line(495,250,495,230); line(460,230,500,230); break;
         };break;
     case 6:
         switch(mark){
         case 1: line(560,250,560,100); line(400,100,400,250); break;
         case 2: line(560,100,400,100); line(560,120,540,100); line(400,120,420,100);break;  
         case 3: line(480,100,480,120); break;
         case 4: line(465,250,465,230); line(495,250,495,230); line(460,230,500,230); break;
         case 5: circle(480,133,13); line(480,146,480,190); line(480,190,490,230); line(480,190,470,230); line(480,150,470,180); line(480,150,490,180); break;
         case 6: setcolor(RGB(bg_color.red,bg_color.green,bg_color.blue)); line(465,250,465,230); line(495,250,495,230); line(460,230,500,230); break;
         }; break; 
     case 8:
         switch(mark){
         case 1: line(560,250,560,100); break;
         case 2: line(400,100,400,250); break;
         case 3: line(560,100,400,100); break;
         case 4: line(560,120,540,100); line(400,120,420,100);break;
         case 5: line(480,100,480,120); break;
         case 6: line(465,250,465,230); line(495,250,495,230); line(460,230,500,230); break;
         case 7: circle(480,133,13); line(480,146,480,190); line(480,190,490,230); line(480,190,470,230); line(480,150,470,180); line(480,150,490,180); break;
         case 8: setcolor(RGB(bg_color.red,bg_color.green,bg_color.blue)); line(465,250,465,230); line(495,250,495,230); line(460,230,500,230); break;
         }; break;  
     case 9:
         switch(mark){
         case 1: line(560,250,560,100); break;
         case 2: line(400,100,400,250); break;
         case 3: line(560,100,400,100); break;
         case 4: line(560,120,540,100); break;
         case 5: line(400,120,420,100); break;
         case 6: line(480,100,480,120); break;
         case 7: line(465,250,465,230); line(495,250,495,230); line(460,230,500,230); break;
         case 8: circle(480,133,13); line(480,146,480,190); line(480,190,490,230); line(480,190,470,230); line(480,150,470,180); line(480,150,490,180); break;
         case 9: setcolor(RGB(bg_color.red,bg_color.green,bg_color.blue)); line(465,250,465,230); line(495,250,495,230); line(460,230,500,230); break;
         }; break;
     case 10:
         switch(mark){
         case 1: line(560,250,560,100); break;
         case 2: line(400,100,400,250); break;
         case 3: line(560,100,400,100); break;
         case 4: line(560,120,540,100); break;
         case 5: line(400,120,420,100); break;
         case 6: line(480,100,480,120); break;
         case 7: line(445,250,445,230); line(475,250,475,230); line(440,230,480,230); break;
         case 8: circle(495,153,13); line(495,166,495,210); line(495,210,505,250); line(495,210,485,250); line(495,170,485,200); line(495,170,505,200); break;
         case 9:  setfillstyle(0,RGB(bg_color.red,bg_color.green,bg_color.blue));bar (430,130,550,260); line(465,250,465,230); line(495,250,495,230); line(460,230,500,230); circle(480,133,13); line(480,146,480,190); line(480,190,490,230); line(480,190,470,230); line(480,150,470,180); line(480,150,490,180); break;
         case 10: setcolor(RGB(bg_color.red,bg_color.green,bg_color.blue)); line(465,250,465,230); line(495,250,495,230); line(460,230,500,230); break;
         }; break;      
     };
}






//функция самой игры
//Stats.money зависит от сложности, количества угаданных подряд слов и оставшихся после угадывания попыток
//Stats.diff суммирует сложность
//stats.games считает количество законченныйх игр 
//Stats.wins считает количество угаданных слов
//Stats.loses считает количество повешанных
//Stats.inrow считает количество угаданных подряд слов
//Stats.maxinrow равен максимальному полученному Stats.inrow

int Game(int point){
    cleardevice();
    setlinestyle(0,0,2);
    int *find_indx;
    char **alphabet1;
    char **alphabet2;
    char **words;
    char **word;
    const char *filename=new char[20];
    int k_words=0, k_bukv=33,  i=0, k=0, j=0, x, y, num_word, point_bukva=0, button, mark=0, single_word_length=0;
    alphabet1=new char*[k_bukv];
    alphabet2=new char*[k_bukv];
    alphabet1=WordsFromFile(k_bukv,"..\\saves\\Alphabet.txt");
    for (i=0; i<k_bukv; i++){
    alphabet2[i]=new char[2]; alphabet1[i][1]=alphabet2[i][1]=0; alphabet2[i][0]=13;};
    switch(point){
    case 1: filename="..\\categories\\Development.txt"; break;
    case 2: filename="..\\categories\\Sport.txt"; break;
    case 3: filename="..\\categories\\Geography.txt"; break;
    case 4: filename="..\\categories\\Music.txt"; break;
    case 5: filename="..\\categories\\Cinema.txt"; break;
    };
//--------------------------------------------------------------------------------------------------------    
    words=WordsFromFile(k_words,filename);
    if (words==NULL) {
        settextstyle(1,0,3);
        settextjustify(1,1);
        setcolor(RGB(negative_color.red,negative_color.green,negative_color.blue));
        outtextxy(300,200,"Файл со словами не найден"); 
        outtextxy(300,230,"или не заполнен"); 
        getch(); 
        return 0;
    };   
    //вывод всех слов, полученных из файла
    for (int i=0; i<k_words; i++){
        for (int j=0; words[i][j]!=0;j++) 
            printf("%c ",words[i][j]);
        printf("\n");
    };
//--------------------------------------------------------------------------------------------------------  
    num_word=rand()%k_words;
    for( ; words[num_word][single_word_length]!=0; single_word_length++);
    find_indx=new int[single_word_length];
    word=new char*[single_word_length];
    for (i=0; i<single_word_length; i++){
        word[i]=new char[2];
        word[i][0]=words[num_word][i]; 
        word[i][1]=0; 
        find_indx[i]=-1;
    };
//--------------------------------------------------------------------------------------------------------
    settextstyle(1,0,1);
    setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
    char *money;
    money = new char[10];
    itoa(Stats.money,money,10);
    settextjustify(0,1);
    outtextxy(520,30,money);
    outtextxy(500,30,"$");  
    settextstyle(0,0,4);
    settextjustify(0,2);
//--------------------------------------------------------------------------------------------------------      
    j=0;    
    do{
        char *difficulty_out;
        difficulty_out=new char[3];
        itoa(Stats.difficulty-mark-1,difficulty_out,10);
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        outtextxy(30,20,"Попыток: ");
        if ((Stats.difficulty-mark-1)==0) setcolor(RGB(negative_color.red,negative_color.green,negative_color.blue));
        outtextxy(300,20,difficulty_out);
        setcolor(RGB(point_color.red,point_color.green,point_color.blue));
        x=30; y=300; 
        setcolor(RGB(word_color.red,word_color.green,word_color.blue));
        for(i=0; i<single_word_length; i++){
            rectangle(x,y,x+35,y+32);
            x+=35;
        };
        x=30; 
        y=50;
        k=0;
        setcolor(RGB(word_color.red,word_color.green,word_color.blue)); 
        for (i=0;i<k_bukv;i++){ 
            if (k%10==0){
                y+=30;
                x=30;
            };  
            if (alphabet2[i]==alphabet1[i]) setcolor(RGB(negative_color.red,negative_color.green,negative_color.blue)); 
            if (point_bukva==i) setcolor(RGB(point_color.red,point_color.green,point_color.blue));
            outtextxy(x,y,alphabet1[i]); 
            setcolor(RGB(word_color.red,word_color.green,word_color.blue)); 
            x+=30; 
            k++;
        };
        button=getch();
        outtextxy(400,50," ");
        switch(button){
        case 72: if (point_bukva>9) point_bukva-=10; break;
        case 80: if (point_bukva<23) point_bukva+=10;  break;
        case 75: if (point_bukva%10!=0) point_bukva--; break;
        case 77: if (((point_bukva-9)%10!=0)&&(point_bukva<32)) point_bukva++; break;
        case 13: if (alphabet2[point_bukva]!=alphabet1[point_bukva]){
                     x=30; y=300; k=j; 
                     for (i=0;i<single_word_length;i++){ 
                         if((!(strcmp(alphabet1[point_bukva], word[i])))&&(find_indx[i]==-1)){
                             j++; 
                             setcolor(RGB(word_color.red,word_color.green,word_color.blue));
                             outtextxy(x,y,word[i]); 
                             find_indx[i]=1;
                         }; 
                         if (find_indx[i]==-1){
                             alphabet2[point_bukva]=alphabet1[point_bukva];
                         };
                         x+=35;  
                     }; 
                     if (k==j) mark++;
                 }
                 else {
                     setcolor(RGB(negative_color.red,negative_color.green,negative_color.blue)); 
                     outtextxy(400,50,"X"); 
                 };
        break;       
        case 27: return 0;
        };
        setcolor(RGB(hangman_color.red,hangman_color.green,hangman_color.blue));
        Hangman(mark);
    }while((j!=single_word_length)&&(mark<Stats.difficulty));
//--------------------------------------------------------------------------------------------------------    
    setcolor(RGB(word_color.red,word_color.green,word_color.blue));
    if (mark<Stats.difficulty) {
        outtextxy(400,50,"Win"); 
        Stats.inrow++;
        Stats.wins++; 
        Stats.money+=((Stats.difficulty-mark-1)+Stats.inrow)*(10-Stats.difficulty);
        setcolor(RGB(point_color.red,point_color.green,point_color.blue));
    } 
    else {
        x=30; y=300; 
        for(i=0; i<single_word_length; i++){ 
            outtextxy(x,y-50,word[i]); 
            x+=35;
        };
        if (Stats.inrow > Stats.maxinrow) 
        Stats.maxinrow = Stats.inrow;
        Stats.inrow=0;
        Stats.loses++; 
        setcolor(RGB(negative_color.red,negative_color.green,negative_color.blue)); outtextxy(400,50,"Lose");
    };
    Stats.games++;
    Stats.diff+=Stats.difficulty-1;
    point=1;
    settextstyle(1,0,3);
    do{
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        if (point == 1) setcolor(RGB(point_color.red,point_color.green,point_color.blue));
        outtextxy(100, 350, "Играть ещё?");
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        if (point == 2) setcolor(RGB(point_color.red,point_color.green,point_color.blue));
        outtextxy(400, 350, "Выход");
        button=getch();
        if ((button == 77) && (point < 2)) point++;
        if ((button == 75) && (point > 1)) point--;
        if (button == 13){
            if (point == 2) return 0; 
            if (point == 1) return 1;
        };
    }while(button != 27);
    return(0);
}
