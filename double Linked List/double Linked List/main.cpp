#include <stdio.h>
#include <stdlib.h>

typedef struct _BTNode {
	char data;
	struct _BTNode* left;
	struct _BTNode* right;
}BTNode;

BTNode* CreateNode(char newData);
void DestroyNode(BTNode* Node);
void DestroyTree(BTNode* Node);

void PreorderPrintTree(BTNode* Node);
void InorderPrintTree(BTNode* Node);
void PostorderPrintTree(BTNode* Node);

int GetNodeCount(BTNode* Node);
int Max(int n1, int n2);
int GetHeight(BTNode* Node);

int main() {
	BTNode* Anode = CreateNode('A');
	BTNode* Bnode = CreateNode('B');
	BTNode* Cnode = CreateNode('C');
	BTNode* Dnode = CreateNode('D');
	BTNode* Enode = CreateNode('E');
	BTNode* Fnode = CreateNode('F');
	BTNode* Gnode = CreateNode('G');
	BTNode* Hnode = CreateNode('H');

	Anode->left = Bnode;
	Bnode->left = Cnode;
	Bnode->right = Dnode;
	Anode->right = Enode;
	Enode->left = Fnode;
	Enode->right = Gnode;
	Gnode->left = Hnode;

	printf("Preorder(전위순위:Root-Left-Right)");
	PreorderPrintTree(Anode);
	printf("\n\n");

	printf("Inorder(중위순위:Left-Root-Right)");
	InorderPrintTree(Anode);
	printf("\n\n");

	printf("Postorder(후위순위:Left-Right-Root)");
	PostorderPrintTree(Anode);
	printf("\n\n");

	printf("트리 노드의 개수: %d\n", GetNodeCount(Anode));
	printf("\n\n");

	printf("트리의 높이 : %d\n", GetHeight(Anode));
	printf("\n\n");

	return 0;
}

BTNode* CreateNode(char newData) {
	BTNode* NewNode = (BTNode*)malloc(sizeof(BTNode));
	NewNode->data = newData;
	NewNode->left = NULL;
	NewNode->right = NULL;

	return NewNode;
}
void DestroyNode(BTNode* Node) {
	free(Node);
}
void DestroyTree(BTNode* Node) {
	if (Node == NULL) return;
	DestroyTree(Node->left);
	DestroyTree(Node->right);
	DestroyNode(Node);
}
void PreorderPrintTree(BTNode* Node) {
	if (Node == NULL) return;

	printf(" %c", Node->data);
	PreorderPrintTree(Node->left);
	PreorderPrintTree(Node->right);
}
void InorderPrintTree(BTNode* Node) {
	if (Node == NULL) return;

	printf(" %c", Node->data);
	PreorderPrintTree(Node->left);
	PreorderPrintTree(Node->right);
}
void PostorderPrintTree(BTNode* Node) {
	if (Node == NULL) return;

	PostorderPrintTree(Node->left);
	PostorderPrintTree(Node->right);
	printf(" %c", Node->data);
}
int GetNodeCount(BTNode* Node) {
	if (Node == NULL) return 0;
	else return GetNodeCount(Node->left) + GetNodeCount(Node->right) + 1;
}
int Max(int n1, int n2) {
	if (n1 == n2) return n1;
	return (n1 > n2) ? n1 : n2;
}
int GetHeight(BTNode* Node) {
	if (Node == NULL) return 0;
	return 1 + Max(GetHeight(Node->left), GetHeight(Node->right));
}