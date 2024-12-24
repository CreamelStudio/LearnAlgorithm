#include <stdio.h>
#define MAX 100

int Stack[MAX];
int top;

//함수 원형
void InitiStack() {
	top = 0;
	for (int i = 0;i < MAX;i++) {
		Stack[i] = 0;
	}
}
void Push(int data) {
	if (top >= MAX) {
		printf("스택이 넘칩니다");
		return;
	}
	//Stack 배열 Top이 갖고 있는 번호에 Data변수의 값을 넣고
	//Top 변수의 값을 1씩 증가 시킨다
	Stack[top] = data;
	top++; //99 => 100
}
int Pop() {
	//top 변수의 값을 1씩 줄이고 다시 Stack 의 top 번쨰 값을 0으로 초기화
	if (top <= 0) {
		printf("더이상 남은 스택이 없습니다");
		return -1;
	}
	top--;
	return Stack[top];
	
}

bool IsEmpty() {
	return (top == 0);
}
int Top() {
	return Stack[top - 1];
}



int main() {
	Push(1);
	Push(2);
	Push(3);
	Push(4);
	Push(5);

	printf("Top : %d\n", Top());

	while (!IsEmpty()) {
		printf("Popped : %d\n", Pop());
	}

	if (IsEmpty()) printf("스택이 비었습니다\n");
	return 0;
}