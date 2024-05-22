#include <stdio.h>
#define SIZE 20
unsigned char screen[SIZE][SIZE];
int chess[SIZE][SIZE];
//定义棋盘

void blank() {
    screen[0][0] = ' ';
    for (int i = 1; i < SIZE; i++) {
        screen[i][0] = '1' + i - 1; 
        // 从'0'开始标记行标
        for (int j = 1; j < SIZE; j++) {
            screen[0][j] = '1' + j - 1;
            //从'0'开始标记列标5
            screen[i][j] = ' '; 
            chess[i][j] = 0;
            // 主体部分初始化
        }
    }
}//初始化棋盘

void display() {
    for (int i = 1; i < SIZE; i++) {
        for (int j = 1; j < SIZE; j++) {
            switch (chess[j][i]){
                case 0:
                screen[i][j] = ' ';
                break;

                case 1:
                screen[i][j] = '*';
                break;

                case 2:
                screen[i][j] = 'o';
                break;

                default:
                screen[i][j] = ' ';
            }
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if(screen[i][j] > 57 && screen[i][j] < 68){
                printf("%d  ", screen[i][j]-48);
            }else{
                printf("%c  ",screen[i][j]);
            }
        }
        printf("\n");
    }
}//显示棋盘

int main(){
   int x,y;
   blank();
   for(int h = 1 ; h==1;){
    printf("heng\n");
   scanf("%d",&x);
   printf("zong\n");
   scanf("%d",&y);
   chess[x][y] = 1;
   display();
    printf("heng\n");
   scanf("%d",&x);
   printf("zong\n");
   scanf("%d",&y);
   chess[x][y] = 2;
   display();
   }
   
   return 0;
}