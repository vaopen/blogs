//���ֲ��� 
//L���û������һ�����Ա�����ElementTypeԪ�ؿ���ͨ��>��==��<���бȽϣ�������Ŀ��֤����������ǵ�������ġ�
//����BinarySearchҪ����X��Data�е�λ�ã��������±꣨ע�⣺Ԫ�ش��±�1��ʼ�洢����
//�ҵ��򷵻��±꣬���򷵻�һ�������ʧ�ܱ��NotFound��

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
};

List ReadInput(); /* ����ʵ�֣�ϸ�ڲ���Ԫ�ش��±�1��ʼ�洢 */
Position BinarySearch( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch( L, X );
    printf("%d\n", P);

    return 0;
}

List ReadInput(){
    int N;
    scanf("%d",&N);
    List L = (struct LNode*)malloc(sizeof(struct LNode));
    L->Last = N;
    for(ElementType i=1;i<=N;i++){
        scanf("%d",&L->Data[i]);
    }
    return L;
}

/* ��Ĵ��뽫��Ƕ������ */
Position BinarySearch( List L, ElementType X ){
	Position position;
	Position left = 0;
	Position right = L->Last;
	int flag = 0;
	while(left <= right){
		Position mid = (left + right) / 2;
		if (L -> Data[mid] == X){
			position = mid;
			flag = 1;
			break;
		}
		else if (L -> Data[mid] > X){
			right = mid - 1;
		}
		else{
			left = mid + 1;
		}
	}
	if(flag == 0){
		return NotFound;
	}
	return position;
} 
