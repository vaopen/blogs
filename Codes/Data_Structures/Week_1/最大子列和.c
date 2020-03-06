//������к�����
//����K��������ɵ����С���������к͡��򱻶���Ϊ������������Ԫ�صĺ�������ߡ�
//IN:�����1�и���������K (��100000)����2�и���K������������Կո�ָ���
//OUT:��һ�������������к͡��������������������Ϊ�����������0��
//Example:
//    IN:
//	    6
//        -2 11 -4 13 -5 -2
//    OUT:
//        20

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100001
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
};

List ReadInput(); /* ����ʵ�֣�ϸ�ڲ���Ԫ�ش��±�1��ʼ�洢 */
ElementType MaxSubList( List L);

int main()
{
    List L;

    L = ReadInput();
    ElementType Max;
	Max = MaxSubList(L);
    printf("%d\n", Max);

    return 0;
}

List ReadInput(){
    int N;
    ElementType i;
    scanf("%d",&N);
    List L = (struct LNode*)malloc(sizeof(struct LNode));
    L->Last = N;
    for(i=0;i<N;i++){
        scanf("%d",&L->Data[i]);
    }
    return L;
}

/* ��Ĵ��뽫��Ƕ������ */
ElementType MaxSubList( List L){
	ElementType Max = L->Data[0];
	ElementType sum = 0;
	Position i;
	for(i=0;i<L->Last;i++){
		if (sum <= 0){
			sum = 0;
		}
		sum += L->Data[i];
		if (sum > Max){
			Max = sum;
		}
		
	}
	return Max;
}

