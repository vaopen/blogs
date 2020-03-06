/*
# ����ͬ��
����������T1��T2�����T1����ͨ�����ɴ����Һ��ӻ����ͱ��T2�������ǳ��������ǡ�ͬ�����ġ�����ͼ1������
����������ͬ���ģ���Ϊ���ǰ�����һ�����Ľ��A��B��G�����Һ��ӻ����󣬾͵õ�����һ��������ͼ2�Ͳ���ͬ��
�ġ�
�ָ����������������ж������Ƿ���ͬ���ġ�
## ��ʽ:
IN
�������2�ö�����������Ϣ������ÿ������������һ���и���һ���Ǹ�����N (��10)���������Ľ��������ʱ����
����0��N?1��ţ������N�У���i�ж�Ӧ��ŵ�i����㣬�����ý���д洢��1��Ӣ�Ĵ�д��ĸ�������ӽ���
��š��Һ��ӽ��ı�š�������ӽ��Ϊ�գ�������Ӧλ���ϸ�����-�������������ݼ���һ���ո�ָ���ע�⣺
��Ŀ��֤ÿ������д洢����ĸ�ǲ�ͬ�ġ�
OUT
�����������ͬ���ģ������Yes�������������No����
## ����
IN
8
A 1 2
B 3 4
C 5 -
D - -
E 6 -
G 7 -
F - -
H - -
8
G - 4
B 7 6
F - -
A 5 1
H - -
C 0 -
D - -
E 2 -
 
OUT
Yes 

*/

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define ElementType char
#define Tree int
#define Null -1

struct TreeNode{
	ElementType Element;
	Tree Left;
	Tree Right;
} T1[MAXSIZE], T2[MAXSIZE];

Tree BuildTree(struct TreeNode T[], int* n);
int Isomorphic(Tree R1, Tree R2);

int main(){
	Tree R1, R2;
	int n1, n2;
	R1 = BuildTree(T1, &n1);
	R2 = BuildTree(T2, &n2);
	if(n1 == n2){
		if(Isomorphic(R1, R2)) printf("Yes\n");
	    else printf("No\n");
	}
	else printf("No\n");
	
	return 0;
}

Tree BuildTree(struct TreeNode T[], int* n){
	int N, i;
	Tree cl, cr, Root;
	scanf("%d\n",&N);
	*n = N;
	if(N){
		int check[N];
		for (i=0; i<N; i++) check[i] = 0;
		for (i=0; i<N; i++){
			scanf("%c %c %c\n", &T[i].Element, &cl, &cr);
			if(cl != '-'){
				T[i].Left = cl-'0';
				check[T[i].Left] = 1;
			}
			else T[i].Left = Null;
			if(cr != '-'){
				T[i].Right = cr-'0';
				check[T[i].Right] = 1;
			}
			else T[i].Right = Null;
		}
		for(i=0; i<N; i++){
			if(!check[i]) break;
		}
		Root = i;
	}
	else{
		Root = Null;
	} 
	return Root;
}

int Isomorphic(Tree R1, Tree R2){
	if((R1 == Null)&&(R2 == Null)) 
	return 1;
	if(((R1==Null)&&(R2!=Null))||((R1!=Null)&&(R2==Null))) 
	return 0;
	if(T1[R1].Element != T2[R2].Element) 
	return 0;
	if((T1[R1].Left == Null)&&(T2[R2].Left==Null))
	return Isomorphic(T1[R1].Right, T2[R2].Right);
	if(((T1[R1].Left!=Null)&&(T2[R2].Left!=Null))&&((T1[T1[R1].Left].Element)==(T2[T2[R2].Left].Element)))
	return (Isomorphic(T1[R1].Left,T2[R2].Right)&&Isomorphic(T1[R1].Right, T2[R2].Left));
}
