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

int creates(int[]);         // 建立堆疊
int isEmpty(int);           // 堆疊已空
int stacktop(int[], int);   // 傳回頂端元素
int add(int[], int, int);   // 插入元素
int delete(int[], int);     // 刪除元素
void list(int[], int);      // 顯示所有內容

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

    int stack[MAX];
    int top;
    int input, select;

    top = creates(stack);

    while(1) {
        printf("請輸入選項(-1結束)：\n");
        printf("(1)插入值至堆疊\n");
        printf("(2)顯示堆疊頂端\n");
        printf("(3)刪除頂端值\n");
        printf("(4)顯示所有內容\n");
        printf(">");
        scanf("%d", &select);

        if(select == -1)
            break;

        switch(select) {
            case 1:
                printf("輸入值：");
                scanf("%d", &input);
                top = add(stack, top, input);
                break;
            case 2:
                printf("頂端值：%d", stacktop(stack, top));
                break;
            case 3:
                top = delete(stack, top);
                break;
            case 4:
                list(stack, top);
                break;
            default:
                printf("\n選項錯誤！");
        }
    }

    printf("\n");

    return 0;
}

// 以下為堆疊操作的實作
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
        printf("\n堆疊已滿！");
        return t;
    }

    stack[++t] = item;

    return t;
}

int delete(int stack[], int top) {
    int t = top;

    if(isEmpty(t)) {
        printf("\n堆疊已空！");
        return t;
    }

    return --t;
}

void list(int stack[], int top) {
    int t = top;

    printf("\n堆疊內容：");
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

	printf("陣列堆疊測試程式(可儲存資料筆數%d)\n", ASIZE+1);

	while(1)
	{
		printf("1) 新增\t2) 刪除\t3) 顯示\t0) 結束 : ");
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
	printf("清空堆疊\n");
	release();

	return 0;
}

void push()
{
	int d;

	if(top < ASIZE)
	{
		printf("請輸入資料(整數) : ");
		scanf("%d",&d);
		top++;
		stack[top] = d;
	}
	else
	{
		printf("堆疊滿了\n");
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
		printf("堆疊是空的\n");
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
