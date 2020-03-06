/*
# ���ȿռ�
�����ȿռ䡱�����ֳ��������ȷָ���Six Degrees of Separation�������ۡ�������ۿ�
��ͨ�׵ز���Ϊ��������κ�һ��İ����֮����������˲��ᳬ��������Ҳ����˵�����ͨ
�����������ܹ���ʶ�κ�һ��İ���ˡ�����ͼ1��ʾ��
![ͼ1 ���ȿռ�ʾ��ͼ]()
�����ȿռ䡱������Ȼ�õ��㷺����ͬ���������ڵõ�Խ��Խ���Ӧ�á�������ʮ������
��ͼ��֤�������ʼ����������ѧ��Ŭ��׷���Ŀ�ꡣȻ��������ʷ��ԭ���������о�
����̫��ľ����Ժ����ѡ����ŵ����˵�������Ҫ�����ڵ绰�����š�΢���Լ��������ϼ�
ʱͨ�ŵȹ��ߣ��ܹ������罻�����ϵ��һ�������Ѿ���ʹ�á����ȿռ䡱���۵���֤��
Ϊ���ܡ�

�������һ���罻����ͼ�������ÿ���ڵ������ϡ����ȿռ䡱���۵Ľ��ռ���������
�ٷֱȡ�
# �����ʽ:
�����1�и����������������ֱ��ʾ�罻����ͼ�Ľ����N��1<N��10
?4
?? ����ʾ������������M����33��N����ʾ�罻��ϵ����������M�ж�ӦM���ߣ�ÿ�и���һ
�����������ֱ��Ǹ�����ֱ����ͨ���������ı�ţ��ڵ��1��N��ţ���
# �����ʽ:
��ÿ����������ý����벻����6�Ľ����ռ��������İٷֱȣ���ȷ��С�����2λ��
ÿ����ڵ����һ�У���ʽΪ�������:���ո񣩰ٷֱ�%����
# ��������:
```
10 9
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
```
# �������:
```
1: 70.00%
2: 80.00%
3: 90.00%
4: 100.00%
5: 100.00%
6: 100.00%
7: 100.00%
8: 90.00%
9: 80.00%
10: 70.00%
```
*/ 

#include <iostream> 
#include <cstring>
#include <queue>
#include <vector>
#define MAXSIZE 10005
using namespace std;

vector<int> graph[MAXSIZE];
bool visited[MAXSIZE];

int BFS(int v){
	queue<int> q;
	q.push(v);
	int last = v;
	int counter = 0;
	int count = 1;
	int tail = v;
	visited[v] = true;
	while (!q.empty()){
		int vertex = q.front();
		q.pop();
		for (int i = 0; i < graph[vertex].size(); i++){
			int t = graph[vertex][i];
			if (!visited[t]){
				visited[t] = true;
//				cout << t << endl;
				q.push(t);
				count++;
//				cout << q.back() << endl;
				tail = t;
			}
		}
		if (vertex == last){
			counter++;
			last = tail;
		}
		if (counter == 6) break;
	}
	return count;
}

int main(){
	int N, E;
	scanf("%d %d\n", &N, &E);
    for (int i = 0; i < N; i++){
    	visited[i] = false;
	}
	while (E--){
		int p1, p2;
		scanf("%d %d", &p1, &p2);
		graph[p1-1].push_back(p2-1);
		graph[p2-1].push_back(p1-1);
	}
	
	for (int i = 0; i < N; i++){
		int count = BFS(i);
		printf("%d: %.2lf%%\n", i+1, (double)count/N * 100);
		memset(visited, false, sizeof(visited));
//		for (int i = 0; i < N; i++){
//    	    visited[i] = false;
//	    } 
	}
	
	return 0;
}

