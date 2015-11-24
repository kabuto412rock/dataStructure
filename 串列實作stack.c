#include<stdio.h>
#include<stdlib.h>
struct node {		    // 設計一個堆疊元素結構
    int data;
    struct node* next;
};
struct stack		    // 設計一個堆疊stack結構
{
    struct node* top;    
};
struct stack* createStack() // 回傳一個空堆疊
{
    struct stack* tmp = (struct stack*)malloc(sizeof(struct stack));
    tmp->top = NULL; 
}
// 沒有isFull()因為堆疊push會同時增加容量大小，所以不會有滿的情況發生
int isEmpty(struct stack* s) { //當是空堆疊回傳1, 不是空堆疊回傳-1 
    if(s->top == NULL)  
	return 1;
    return -1;		    
}
int push(struct stack* s, int sdata){	// 推入sdata到stack裡
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    tmp->data = sdata;
    tmp->next = s->top;
    s->top = tmp;
    return 1;				// push成功
}
int pop(struct stack* s) {
    if(isEmpty(s) == 1)			// 無法pop時,回傳-1
	return -1;
    int sdata = s->top->data;
    struct node* tmp = s->top->next;
    free(s->top);
    s->top = tmp;
    
    return sdata;
}
int main()
{
    struct stack* stack = createStack();    // 建立一個堆疊
    long size = 11111;
    int i = 0;
    for(i=0;i<size;i++){
	push(stack,i+1);    // push 1~size
    }    

    for(i=0;i<size;i++) {
	if(isEmpty(stack) == 1)
	    printf("pop到沒東西啦！！八個耶魯！");
	else
	    printf("%d ", pop(stack));
	if(i%20 == 0)
	    printf("\n");
    }    
    return 0;
}
