#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
	char ch;
	struct _Node* link;
} Node;

Node* InsertNode(Node* pList, char newch);
void PrintList(Node* pList);
int CountList(Node* pList);
int SearchNode(Node* pList, char sech);
Node* DeleteNode(Node* pList, char delch);
Node* FreeList(Node* pList);

int main() {
	Node* pList = NULL;

	printf("(1) Insert: A, B, D, E\n");
	pList = InsertNode(pList, 'A');
	pList = InsertNode(pList, 'B');
	pList = InsertNode(pList, 'D');
	pList = InsertNode(pList, 'E');
	PrintList(pList);
	printf("리스트 노드의 개수: %d\n\n", CountList(pList));

	printf("(2) Insert: C\n");
	pList = InsertNode(pList, 'C');
	PrintList(pList);
	printf("리스트 노드의 개수: %d\n\n", CountList(pList));

	printf("(3) Search: D\n");
	int index = SearchNode(pList, 'D');
	printf("D를 [%d]번째에서 찾았습니다.\n\n", index);

	printf("(4) Delete: A\n");
	pList = DeleteNode(pList, 'A');
	PrintList(pList);

	return 0;
}

Node* InsertNode(Node* pList, char newch) {
	Node* newNode, *trace, *prevNode;
	trace = pList;
	prevNode = NULL;
	newNode = (Node*)malloc(sizeof(Node));
	newNode->ch = newch;
	newNode->link = NULL;

	if (pList == NULL || pList->ch > newch) {
		newNode->link = pList;
		pList = newNode;
	}
	else {
		while (trace != NULL && trace->ch < newch) {
			prevNode = trace;
			trace = trace->link;
		}
		newNode->link = prevNode->link;
		prevNode->link = newNode;
	}
	return pList;
}

void PrintList(Node* pList) {
	Node* trace = pList;
	printf("List = ( ");
	while (trace != NULL) {
		printf("%c", trace->ch);
		trace = trace->link;
		if (trace != NULL) printf(", ");
	}
	printf(" )\n\n");
}

int CountList(Node* pList) {
	int cnt = 0;
	Node* trace = pList;
	while (trace != NULL) {
		trace = trace->link;
		cnt++;
	}
	return cnt;
}

int SearchNode(Node* pList, char sech) {
	int index = 0;
	Node* trace = pList;
	while (trace != NULL) {
		if (sech == trace->ch) break;
		trace = trace->link;
		index++;
	}
	return index + 1;
}

Node* DeleteNode(Node* pList, char delch) {
	Node* trace = pList, * prevNode = NULL;
	while (trace != NULL && trace->ch != delch) {
		prevNode = trace;
		trace = trace->link;
	}
	if (trace != NULL) {
		if (prevNode == NULL) {
			pList = pList->link;
		}
		else {
			prevNode->link = trace->link;
		}
		free(trace);
	}
	return pList;
}

Node* FreeList(Node* pList) {
	Node* temp;
	while (pList != NULL) {
		temp = pList->link;
		free(pList);
		pList = temp;
	}
	printf("리스트의 모든 노드가 삭제되었습니다...\n\n");
	return pList;
}
