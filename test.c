/*
 ============================================================================
 Name        : test.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
/*#define MAX 10

int creates(int[]);         // �إ߰��|
int isEmpty(int);           // ���|�w��
int stacktop(int[], int);   // �Ǧ^���ݤ���
int add(int[], int, int);   // ���J����
int delete(int[], int);     // �R������
void list(int[], int);      // ��ܩҦ����e

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

    int stack[MAX];
    int top;
    int input, select;

    top = creates(stack);

    while(1) {
        printf("�п�J�ﶵ(-1����)�G\n");
        printf("(1)���J�Ȧܰ��|\n");
        printf("(2)��ܰ��|����\n");
        printf("(3)�R�����ݭ�\n");
        printf("(4)��ܩҦ����e\n");
        printf(">");
        scanf("%d", &select);

        if(select == -1)
            break;

        switch(select) {
            case 1:
                printf("��J�ȡG");
                scanf("%d", &input);
                top = add(stack, top, input);
                break;
            case 2:
                printf("���ݭȡG%d", stacktop(stack, top));
                break;
            case 3:
                top = delete(stack, top);
                break;
            case 4:
                list(stack, top);
                break;
            default:
                printf("\n�ﶵ���~�I");
        }
    }

    printf("\n");

    return 0;
}

// �H�U�����|�ާ@����@
int creates(int stack[]) {
    int i;

    for(i = 0; i < MAX; i++)
        stack[i] = 0;

    return -1;
}

int isEmpty(int top) {
    return (top == -1);
}

int stacktop(int stack[], int top) {
    return stack[top];
}

int add(int stack[], int top, int item) {
    int t = top;

    if(t >= MAX-1) {
        printf("\n���|�w���I");
        return t;
    }

    stack[++t] = item;

    return t;
}

int delete(int stack[], int top) {
    int t = top;

    if(isEmpty(t)) {
        printf("\n���|�w�šI");
        return t;
    }

    return --t;
}

void list(int stack[], int top) {
    int t = top;

    printf("\n���|���e�G");
    while(!isEmpty(t)) {
        printf("%d ", stack[t]);
        t--;
    }
}
*/

#define ASIZE 5

int stack[ASIZE]={0};
int top=-1;

void push();
void pop();
void display();
void release();

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int choice;

	printf("�}�C���|���յ{��(�i�x�s��Ƶ���%d)\n", ASIZE+1);

	while(1)
	{
		printf("1) �s�W\t2) �R��\t3) ���\t0) ���� : ");
		scanf("%d",&choice);

		if(!choice)
			break;

		switch(choice)
		{
			case 1:		push();		break;
			case 2:		pop();		break;
			case 3:		display();	break;
			default:	display();	break;
		}
	}
	printf("�M�Ű��|\n");
	release();

	return 0;
}

void push()
{
	int d;

	if(top < ASIZE)
	{
		printf("�п�J���(���) : ");
		scanf("%d",&d);
		top++;
		stack[top] = d;
	}
	else
	{
		printf("���|���F\n");
	}
}


void pop()
{
	if(top >= 0)
	{
		printf("%3d\n",stack[top]);
		top--;
	}
	else
	{
		printf("���|�O�Ū�\n");
	}
}

void display()
{
	int pos = top;
	while(pos >= 0)
	{
		printf("%3d ",stack[pos]);
		pos--;
	}
	printf("\n");
}

void release()
{
	while(top >= 0)
		pop();
}
