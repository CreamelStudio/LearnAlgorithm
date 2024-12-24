#include <stdio.h>
#define MAX 100

int Stack[MAX];
int top;

//�Լ� ����
void InitiStack() {
	top = 0;
	for (int i = 0;i < MAX;i++) {
		Stack[i] = 0;
	}
}
void Push(int data) {
	if (top >= MAX) {
		printf("������ ��Ĩ�ϴ�");
		return;
	}
	//Stack �迭 Top�� ���� �ִ� ��ȣ�� Data������ ���� �ְ�
	//Top ������ ���� 1�� ���� ��Ų��
	Stack[top] = data;
	top++; //99 => 100
}
int Pop() {
	//top ������ ���� 1�� ���̰� �ٽ� Stack �� top ���� ���� 0���� �ʱ�ȭ
	if (top <= 0) {
		printf("���̻� ���� ������ �����ϴ�");
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

	if (IsEmpty()) printf("������ ������ϴ�\n");
	return 0;
}