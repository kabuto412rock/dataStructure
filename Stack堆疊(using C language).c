#include<stdio.h>
#include<stdlib.h>
#define size 20			// 堆疊大小           
int* createStack();
int push(int* stack, int* top, int data);
int pop(int* stack ,int* top);
int isFull(int* top);
// stack的建立函數, 以陣列來實作
int* createStack() { 
    int* tmp = (int*)malloc(sizeof(int[size])); 
    return tmp; 
}
// stack 的 push函數, 
int push(int* stack, int* top, int data)
{
    if(*top == size-1)
	return -1;	    // push失敗
    stack[++(*top)] = data;
    return 1;		    // push成功
}
// stack 的 pop函數
int pop(int* stack ,int* top) {
    if(*top == -1)
	return -1;
    return stack[(*top)--];
}
// stack 是否已滿的函數
int isFull(int* top) {
    if(*top == size-1)	// stack已滿
	return 1;
    return -1;		// stack還有空間可以放資料
}
// 檢查stack是否已空的函數
int isEmpty(int* top) {
    if(*top == -1)	// stack已空
	return 1;
    return -1;		// stack還有元素在裡頭
}

int main()
{
    int* stack = createStack();		    // 以陣列實作 堆疊
    int *top = (int*)malloc(sizeof(int));   //top 指向堆疊最頂端的元素, -1代表 NULL
    *top = -1;

    int i = 0;
    for(i=0;i<30;i++){		     // 嘗試進行多次push，確認pop過多也不會出錯
	if(isFull(top) == 1) {
	    printf("堆疊：我push不進去啦～！\n");
	}else {
	    printf("Push %d 到堆疊stack裡\n", i+1); 
	    push(stack, top, i+1);   
    	}
    }
     for(i=0;i<30;i++){		     // 嘗試進行多次pop,確認pop過多也不會出錯	    
	if(isEmpty(top) == 1) {
	    printf("堆疊：你叫我pop, 可是我已經空空啦~!\n");
	}else {
	    int data = pop(stack, top);   // 從堆疊stack依序取出值
	    printf("從堆疊stack裡Pop出%d\n", data); 
	}
    }
 
    return 0;
}
