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

int board[8][8] = {0}; //�ѽL��l��

int main(void) {
    int startx, starty; //�_�l�I
    int i, j;

    printf("��J�_�l�I�G");
    scanf("%d %d", &startx, &starty);

    if(travel(startx, starty)) {
        printf("���ާ����I\n");
    }
    else {
        printf("���ޥ��ѡI\n");
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
    // �����M�h�i�����K�Ӥ�V
    int ktmove1[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int ktmove2[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    // ���դU�@�B���X��
    int nexti[8] = {0};
    int nextj[8] = {0};

    // �O���X�����Ӽ�
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

        // �ձ��K�Ӥ�V
        for(k = 0; k < 8; k++) {
            tmpi = i + ktmove1[k];
            tmpj = j + ktmove2[k];

            // �p�G�O��ɤF�A���i��
            if(tmpi < 0 || tmpj < 0 || tmpi > 7 || tmpj > 7)
                continue;

            // �p�G�o�Ӥ�V�i���A�O���U��
            if(board[tmpi][tmpj] == 0) {
                nexti[l] = tmpi;
                nextj[l] = tmpj;
                // �i������V�[�@��
                l++;
            }
        }

        count = l;

        // �p�G�i������V��0�ӡA��^
        if(count == 0) {
            return 0;
        }
        else if(count == 1) {
            // �u���@�ӥi������V
            // �ҥH�����O�̤֥X������V
            min = 0;
        }
        else {
            // ��X�U�@�Ӧ�m���X����
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

            // �q�i������V���M��̤֥X������V
            for(l = 1; l < count; l++) {
                if(exists[l] < tmp) {
                    tmp = exists[l];
                    min = l;
                }
            }
        }

        // ���̤֥X������V
        i = nexti[min];
        j = nextj[min];
        board[i][j] = m;
    }

    return 1;
}

