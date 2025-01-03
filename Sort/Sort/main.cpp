#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10

void MakeRandomNum();
void Display();
void Swap(int* n1, int* n2);
void SelectionSort();
void BubbleSort();
void QuickSort(int left, int right);
int Partition(int left, int right);

int list[MAX];

int main() {
    MakeRandomNum();
    printf("정렬 전:"); Display();
    //SelectionSort();
    //BubbleSort();
    QuickSort(0, MAX - 1);
    printf("정렬 후:"); Display();
    return 0;
}

void MakeRandomNum() {
    srand((unsigned int)time(NULL));
    for (int i = 0; i < MAX; i++) {
        list[i] = rand() % 100;
        //0-99까지의 랜덤한 숫자를 넣고싶다. 
    }
}
void Display() {
    for (int i = 0; i < MAX; i++)
        printf("%d ", list[i]);
    printf("\n\n");
}

void Swap(int* n1, int* n2) {
    int t;
    t = *n1;
    *n1 = *n2;
    *n2 = t;
}
void SelectionSort() {
    int i, j, indexMin;
    for (i = 0; i < MAX - 1; i++) {
        indexMin = i;
        for (j = i + 1; j < MAX; j++) {
            if (list[j] < list[indexMin]) {
                indexMin = j;
            }
        }
        Swap(&list[indexMin], &list[i]);
    }

}
void BubbleSort() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX - 1 - i; j++) {
            if (list[j] > list[j + 1]) {
                Swap(&list[j], &list[j + 1]);
            }
        }
    }
}

void QuickSort(int left, int right) { //QuickSort(0, MAX-1);
    if (left < right) {
        int Index = Partition(left, right);
        QuickSort(left, Index - 1);
        QuickSort(Index + 1, right);
    }
}
int Partition(int left, int right) {
    int first = left;
    int pivot = list[first];
    left++;
    while (left <= right) {
        while (list[left] <= pivot && left < right) left++;
        while (list[right] >= pivot && left <= right) right--;
        if (left < right) Swap(&list[left], &list[right]);
        else break;
    }
    Swap(&list[first], &list[right]);
    return right;
}
