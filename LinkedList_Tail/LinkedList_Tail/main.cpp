#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int data;
    struct NODE* next;
    struct NODE* prev;
} Node;

Node* head = NULL;
Node* tail = NULL;

void addNode(int data);
void deleteNode(int data);
void printFront();
void printBack();
void clearMemory();

int main() {
    addNode(10);
    addNode(20);
    addNode(30);

    printFront();
    printBack();

    deleteNode(20);

    printFront();

    clearMemory();

    return 0;
}

void addNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("메모리 할당 실패\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = tail;

    if (tail) {
        tail->next = newNode;
    }
    else {
        head = newNode;
    }
    tail = newNode;

    printf("노드 추가: %d\n", data);
}

void deleteNode(int data) {
    Node* curr = head;

    while (curr) {
        if (curr->data == data) {
            if (curr->prev) {
                curr->prev->next = curr->next;
            }
            else {
                head = curr->next; 
            }

            if (curr->next) {
                curr->next->prev = curr->prev;
            }
            else {
                tail = curr->prev;
            }

            free(curr);
            printf("노드 삭제: %d\n", data);
            return;
        }
        curr = curr->next;
    }
    printf("노드를 찾을 수 없음: %d\n", data);
}

void printFront() {
    Node* curr = head;
    printf("순방향 출력: ");
    while (curr) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void printBack() {
    Node* curr = tail;
    printf("역방향 출력: ");
    while (curr) {
        printf("%d ", curr->data);
        curr = curr->prev;
    }
    printf("\n");
}

void clearMemory() {
    Node* curr = head;
    while (curr) {
        Node* temp = curr;
        curr = curr->next;
        free(temp);
    }
    head = NULL;
    tail = NULL;
    printf("메모리 정리 완료\n");
}
