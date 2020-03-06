/*
# �Ƿ�ͬһ�ö���������
����һ���������оͿ���Ψһȷ��һ�ö�����������Ȼ����һ�ø����Ķ���������ȴ�����ɶ��ֲ�ͬ�Ĳ������еõ�
������ֱ�������{2, 1, 3}��{2, 3, 1}�����ʼΪ�յĶ��������������õ�һ���Ľ�������Ƕ�������ĸ��ֲ�
�����У�����Ҫ�ж������Ƿ�������һ���Ķ�����������
# �����ʽ:
�������������������ݡ�ÿ�����ݵĵ�1�и�������������N (��10)��L���ֱ���ÿ�����в���Ԫ�صĸ�������Ҫ��
������и�������2�и���N���Կո�ָ�������������Ϊ��ʼ�������С����L�У�ÿ�и���N�������Ԫ�أ�����L
����Ҫ�������С�

����������Ǳ�֤ÿ���������ж���1��N��һ�����С�������NΪ0ʱ����־����������������ݲ�Ҫ����
# �����ʽ:
��ÿһ����Ҫ�������У���������ɵĶ�������������Ӧ�ĳ�ʼ�������ɵ�һ���������Yes�������������No����
# ����������
```
4 2
3 1 4 2
3 4 1 2
3 2 4 1
2 1
2 1
1 2
0
```
# ���������
```
Yes
No
No
```
*/



#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef int bool;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree Insert( BinTree BST, ElementType X );
BinTree CreatTree(int N);
bool isSameTree(BinTree T1, BinTree T2);

int main()
{
    BinTree BST;
    int N, i;
    while(1){
    	scanf("%d", &N);
    	if (N){
    		scanf("%d", &i);
    		BST = CreatTree(N);
    		while(i--){
    			if (isSameTree(BST, CreatTree(N))){
    				printf("Yes\n");
				}
				else printf("No\n");
			}
		}
		else break;
	}

    return 0;
}

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

BinTree CreatTree(int N){
	BinTree BST = NULL;
	ElementType X;
	while(N--){
		scanf("%d", &X);
		BST = Insert(BST, X);
	}
	return BST;
}
bool isSameTree(BinTree T1, BinTree T2){
	if(T1&&T2){
		if((T1->Data == T2->Data)&&(isSameTree(T1->Left, T2->Left)&&isSameTree(T1->Right,T2->Right))) return 1;
		else return 0;
	}
	else if(!T1&&!T2) return 1;
	else return 0;
}
