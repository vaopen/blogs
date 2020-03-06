/*
# ���������صĿ���
����������Ҫ�����ˣ�����Ҫ��İ��������ſ�ѧ������ħ�佫һ�ֶ�������һ�ֶ���ı��¡����罫è�������
��ħ����haha�������������ħ����hehe�ȵȡ�������仯��ħ����Ǽ򵥵ؽ�ԭ����ħ�䵹���������ahah��
�Խ�������è�����⣬������è����㣬����ͨ����һ��ֱ��ħ��lalala��Ҳ���Խ�è��������������ħ��
�������hahahehe��

���ڹ��������ص�������һ���̲ģ������г������еı���ħ����ܱ�Ķ����ʦ�������Լ���һֻ����ȥ������
Ҫ����������ֻ����������һָֻ������ı��¡������������㣺��ʲô����ȥ���������ѱ�����ֶ������
�����Ϊ�����������Լ���ȥ�Ķ�������Ҫ��ħ�������Ҫ��ħ����̣����磺���ֻ��è�����㣬����Ȼ��
��������Ӧ�ô���ȥ����Ϊ�����������ֶ��ﶼֻ��Ҫ��4���ַ����������èȥ����������Ҫ��6���ַ����ܰ�è
����㣻ͬ������ȥҲ������õ�ѡ��

# �����ʽ:
����˵���������1�и�������������N (��100)��M������N�ǿ����漰�Ķ���������M������ֱ�ӱ��ε�ħ��������Ϊ
����������ǽ����ﰴ1~N��š����M�У�ÿ�и�����3�����������ֱ������ֶ���ı�š��Լ�����֮�������
Ҫ��ħ��ĳ���(��100)������֮���ÿո�ָ���

# �����ʽ:
�������������Ӧ�ô�ȥ�����Ķ���ı�š��Լ���ı���ħ��ĳ��ȣ��м��Կո�ָ������ֻ��1ֻ�����ǲ���
��������б���Ҫ��ģ������0�����������ֻ���ﶼ���Ա�ѡ������������С����ֻ��

# ��������:
```
6 11
3 4 70
1 2 1
5 4 50
2 6 50
5 6 60
1 3 70
4 6 60
3 6 80
5 1 100
2 4 60
5 2 80
``` 

# �������:
```
4 70
```
*/


#include <iostream> 
#include <cstdlib>

#define MAXSIZE 100
#define INFINITY 999999

using namespace std;


class MGraph{
	public:
		int vertexNum;
		int graph[MAXSIZE][MAXSIZE];
		int dist[MAXSIZE][MAXSIZE];
		MGraph(int num){
			vertexNum = num;
		}
		void create(){
			for (int i = 0; i < vertexNum; i++)
			    for (int j = 0; j < vertexNum; j++)
			        graph[i][j] = INFINITY;
		}
		
		void insertEdge(int V, int W, int weight){
			graph[V][W] = graph[W][V] = weight;
		}
		
		bool Floyd(){
			for (int i = 0; i < vertexNum; i++)
			    for (int j = 0; j < vertexNum; j++)
			        dist[i][j] = graph[i][j];
//			this->show();
			for (int k = 0; k < vertexNum; k++)
			    for (int i = 0; i < vertexNum; i++)
			        for (int j = 0; j < vertexNum; j++)
			            if ((dist[i][k] + dist[k][j] < dist[i][j]) && i != j){
			            	dist[i][j] = dist[i][k] + dist[k][j];
			            	if (i == j && dist[i][j] < 0) // ���ָ�ֵȦ 
			            	    return false;
						}
			return true;
		}
		
		void FindAnimal(){
			int animal;
			int MinDist = INFINITY;
			for (int i = 0; i < vertexNum; i++){
				int MaxDist = this->FindMaxDist(i);
//				cout << MaxDist << endl;
				if (MaxDist == INFINITY){
					cout << 0 << endl;
					return;
				}
				if (MinDist > MaxDist){
					MinDist = MaxDist;
					animal = i+1;
				}
			}
			cout << animal << " " << MinDist << endl;
		}
		
		int FindMaxDist(int vertex){
			int MaxDist = 0;
			for (int i = 0; i < vertexNum; i++){
				if (vertex != i && dist[vertex][i] > MaxDist)
				    MaxDist = dist[vertex][i];
			}
			return MaxDist;
		}
		
		void show(){
			for (int i = 0; i < vertexNum; i++){
				for (int j = 0; j < vertexNum; j++)
			        cout << this->dist[i][j] << '\t';
			    cout << endl;
			}
		}
};

int main(){
	int N, M;
	int G[N][N];
	cin >> N >> M;
	MGraph graph(N);
	graph.create();
	while (M--){
		int V, W, weight;
		cin >> V >> W >> weight;
		graph.insertEdge(V - 1, W - 1, weight);
	}
	if (!graph.Floyd()) exit(0);
//	graph.show();
	graph.FindAnimal();
	return 0;
}
