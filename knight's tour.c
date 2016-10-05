/*
 ============================================================================
 Name        : knight's.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int board[8][8] = {0}; //棋盤初始化

int main(void) {
    int startx, starty; //起始點
    int i, j;

    printf("輸入起始點：");
    scanf("%d %d", &startx, &starty);

    if(travel(startx, starty)) {
        printf("巡邏完成！\n");
    }
    else {
        printf("巡邏失敗！\n");
    }

    for(i = 0; i < 8; i++) {
        for(j = 0; j < 8; j++) {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}
int travel(int x, int y) {
    // 對應騎士可走的八個方向
    int ktmove1[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int ktmove2[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    // 測試下一步的出路
    int nexti[8] = {0};
    int nextj[8] = {0};

    // 記錄出路的個數
    int exists[8] = {0};

    int i, j, k, m, l;
    int tmpi, tmpj;
    int count, min, tmp;

    i = x;
    j = y;

    board[i][j] = 1;

    for(m = 2; m <= 64; m++) {
        for(l = 0; l < 8; l++) {
            exists[l] = 0;
        }

        l = 0;

        // 試探八個方向
        for(k = 0; k < 8; k++) {
            tmpi = i + ktmove1[k];
            tmpj = j + ktmove2[k];

            // 如果是邊界了，不可走
            if(tmpi < 0 || tmpj < 0 || tmpi > 7 || tmpj > 7)
                continue;

            // 如果這個方向可走，記錄下來
            if(board[tmpi][tmpj] == 0) {
                nexti[l] = tmpi;
                nextj[l] = tmpj;
                // 可走的方向加一個
                l++;
            }
        }

        count = l;

        // 如果可走的方向為0個，返回
        if(count == 0) {
            return 0;
        }
        else if(count == 1) {
            // 只有一個可走的方向
            // 所以直接是最少出路的方向
            min = 0;
        }
        else {
            // 找出下一個位置的出路數
            for(l = 0; l < count; l++) {
                for(k = 0; k < 8; k++) {
                    tmpi = nexti[l] + ktmove1[k];
                    tmpj = nextj[l] + ktmove2[k];

                    if(tmpi < 0 || tmpj < 0 ||
                       tmpi > 7 || tmpj > 7) {
                        continue;
                    }

                    if(board[tmpi][tmpj] == 0)
                        exists[l]++;
                }
            }

            tmp = exists[0];
            min = 0;

            // 從可走的方向中尋找最少出路的方向
            for(l = 1; l < count; l++) {
                if(exists[l] < tmp) {
                    tmp = exists[l];
                    min = l;
                }
            }
        }

        // 走最少出路的方向
        i = nexti[min];
        j = nextj[min];
        board[i][j] = m;
    }

    return 1;
}

