/*
# �����������Ĳ����� 
����Ҫ��ʵ�ָ���������������5�ֳ��ò�����
# �����ӿڶ��壺
``` 
BinTree Insert( BinTree BST, ElementType X );
BinTree Delete( BinTree BST, ElementType X );
Position Find( BinTree BST, ElementType X );
Position FindMin( BinTree BST );
Position FindMax( BinTree BST );
```
����BinTree�ṹ�������£�
```
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};
```
* ����Insert��X�������������BST�����ؽ�����ĸ����ָ�룻
* ����Delete��X�Ӷ���������BST��ɾ���������ؽ�����ĸ����ָ�룻���X�������У����ӡһ��Not Found������ԭ���ĸ����ָ�룻
* ����Find�ڶ���������BST���ҵ�X�����ظý���ָ�룻����Ҳ����򷵻ؿ�ָ�룻
* ����FindMin���ض���������BST����СԪ����ָ�룻
* ����FindMax���ض���������BST�����Ԫ����ָ�롣
# ���в��Գ���������
���� 
# ����������
```
10
5 8 6 2 4 1 0 10 9 7
5
6 3 10 0 5
5
5 7 0 10 3
```
# ���������
```
Preorder: 5 2 1 0 4 8 6 7 10 9
6 is found
3 is not found
10 is found
10 is the largest key
0 is found
0 is the smallest key
5 is found
Not Found
Inorder: 1 2 4 6 8 9
```
*/



#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreorderTraversal( BinTree BT ); /* ����������ɲ���ʵ�֣�ϸ�ڲ��� */
void InorderTraversal( BinTree BT );  /* ����������ɲ���ʵ�֣�ϸ�ڲ��� */

BinTree Insert( BinTree BST, ElementType X );
BinTree Delete( BinTree BST, ElementType X );
Position Find( BinTree BST, ElementType X );
Position FindMin( BinTree BST );
Position FindMax( BinTree BST );

int main()
{
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BST = NULL;
    scanf("%d", &N);
    for ( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    printf("Preorder:"); PreorderTraversal(BST); printf("\n");
    MinP = FindMin(BST);
    MaxP = FindMax(BST);
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL) printf("%d is not found\n", X);
        else {
            printf("%d is found\n", Tmp->Data);
            if (Tmp==MinP) printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp==MaxP) printf("%d is the largest key\n", Tmp->Data);
        }
    }
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Delete(BST, X);
    }
    printf("Inorder:"); InorderTraversal(BST); printf("\n");

    return 0;
}
/* ��Ĵ��뽫��Ƕ������ */
void PreorderTraversal( BinTree BT ){
	if(BT){
		printf(" %d", BT->Data);
		PreorderTraversal(BT->Left);
		PreorderTraversal(BT->Right);
	}
}

void InorderTraversal( BinTree BT ){
	if(BT){
		PreorderTraversal(BT->Left);
		printf(" %d", BT->Data);
		PreorderTraversal(BT->Right);
	}
}

// emmmmm �����insert����delete����������װ�����ڸ��ϡ��� 

BinTree Insert( BinTree BST, ElementType X ){
	if(BST){
		if (X > BST->Data){
			BST->Right = Insert(BST->Right, X);
		}
		else if (X < BST->Data){
			BST->Left = Insert(BST->Left, X);
		}
	}
	else{
		BST = (BinTree)malloc(sizeof(struct TNode));
		BST->Data = X;
		BST->Left = NULL;
		BST->Right = NULL;
	}
	return BST; 
}

BinTree Delete( BinTree BST, ElementType X ){
//	printf("%d\n",X);
	Position Tmp;
	if (BST){
		if(X > BST->Data){
			BST->Right = Delete(BST->Right, X);
//			printf("here1 %d\n",X);
		}
		else if(X < BST->Data){
			BST->Left = Delete(BST->Left, X);
//			printf("here2 %d\n",X);
		}
		else{
//			printf("here6 %d\n",X);
			if ((BST->Left)&&(BST->Right)){
//				Tmp = FindMin(BST->Right);
				Tmp = FindMax(BST->Left);
				BST->Data = Tmp->Data;
//				BST->Right = Delete( BST->Right, BST->Data);
				BST->Left = Delete( BST->Left, BST->Data);
			}
			else{
//				printf("here3 %d\n",X);
				Tmp = BST;
				if (BST->Left){
					BST = BST->Left;
				}
				else if(BST->Right){
					BST = BST->Right;
				}
				else{
					BST = NULL;
				}
				free(Tmp);
			}
		}
	}
	else {
		printf("Not Found\n");
	}
	return BST;
}
Position Find( BinTree BST, ElementType X ){
	if(BST){
		if(X > BST->Data){
			return Find(BST->Right, X);
		}
		else if(X < BST->Data){
			return Find(BST->Left, X);
		}
		else{
			return BST;
		}
	}
	else{
		return NULL;
	}
}

Position FindMin( BinTree BST ){
	if(BST){
		if (BST->Left){
			return FindMin(BST->Left);
		}
		else return BST;
	}
	else return NULL; 
}

Position FindMax( BinTree BST ){
	if(BST){
		if(BST->Right){
			return FindMax(BST->Right);
		}
		else return BST;
	}
	else{
		return NULL;
	}
}
