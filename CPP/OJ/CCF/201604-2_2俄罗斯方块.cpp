#include <stdio.h>

int board[20][15];
int block[4][4];

int main() {
    for(int i=1; i<=15; i++) {
        for(int j=1; j<=10; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    for(int a=0; a<4; a++) {
        for(int b=0; b<4; b++) {
            scanf("%d", &block[a][b]);
        }
    }
    for(int j=1; j<=10; j++) { // 底部加上全1边框
        board[16][j] = 1;
    }
    int col;
    scanf("%d", &col);
    bool over = false;
    int i;
    for(i=0; i<=15; i++) { // 模拟方块的掉落
        for(int a=0; a<4; a++) {
            for(int b=0; b<4; b++) {
                if(block[a][b] && board[i+a][col+b]) {
                    over = true;
                } 
            }
        }
        if(over) break;
    }
    for(int a=0; a<4; a++) { // 合并方块到棋盘上
        for(int b=0; b<4; b++) {
            board[i+a-1][col+b] += block[a][b];
        }
    }
    for(int i=1; i<=15; i++) {
        for(int j=1; j<=10; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}