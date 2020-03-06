/*
# ���ι滮
����һ���Լ�����·��ͼ�����֪�����м�ĸ��ٹ�·���ȡ��Լ��ù�·Ҫ��ȡ�Ĺ�·�ѡ�������Ҫ��дһ������
����ǰ����ѯ���ο���һ�������غ�Ŀ�ĵ�֮������·���������������·��������̵ģ���ô��Ҫ�������˵�
һ��·����

# �����ʽ:
����˵�����������ݵĵ�1�и���4��������N��M��S��D������N��2��N��500���ǳ��еĸ�����˳�������еı��Ϊ
0~(N?1)��M�Ǹ��ٹ�·��������S�ǳ����صĳ��б�ţ�D��Ŀ�ĵصĳ��б�š�����M���У�ÿ�и���һ�����ٹ�
·����Ϣ���ֱ��ǣ�����1������2�����ٹ�·���ȡ��շѶ�м��ÿո�ֿ������־�Ϊ�����Ҳ�����500�����뱣
֤��Ĵ��ڡ�

# �����ʽ:
��һ�������·���ĳ��Ⱥ��շ��ܶ���ּ��Կո�ָ��������β�����ж���ո�

# ��������:
```
4 5 0 3
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20
``` 

# �������:
```
3 40
```
*/


#include <iostream> 
#include <cstdlib>
#include <vector>

#define MAXSIZE 505
#define INFINITY 999999

using namespace std;

class Way{
	public:
		int price;
		int dist;
		int nextCity;
		Way(int city, int d, int p){
			nextCity = city;
			dist = d;
			price = p;
		}
};

vector<Way> map[MAXSIZE];
bool collected[MAXSIZE];
int dist[MAXSIZE];
int path[MAXSIZE];
int price[MAXSIZE];

void Dijkstra(int city){
	while (true){
		int d = INFINITY;
		int v;
		for (int i = 0; i < map[city].size(); i++){
			if (map[city][i].dist < d && !collected[map[city][i].nextCity]){
				d = map[city][i].dist;
				v = map[city][i].nextCity;
			}
		}
//		cout << v << endl; 
		if (d == INFINITY) break;
		collected[v] = true;
		for (int i = 0; i < map[v].size(); i++){
			if (!collected[map[v][i].nextCity]){
//				cout << "bls" << map[v][i].nextCity << endl;
				if ((dist[v] + map[v][i].dist < dist[map[v][i].nextCity]) ||
				    (dist[v] + map[v][i].dist == dist[map[v][i].nextCity] && price[v] + map[v][i].price < price[map[v][i].nextCity])){
					dist[map[v][i].nextCity] = dist[v] + map[v][i].dist;
					path[map[v][i].nextCity] = v;
					price[map[v][i].nextCity] = price[v] + map[v][i].price;
				}
			}
		}
	}
}

int main(){
	int N, M, S, D;
	cin >> N >> M >> S >> D;
	for (int i = 0; i < N; i++){
		collected[i] = false;
		dist[i] = INFINITY;
		path[MAXSIZE] = -1;
		price[MAXSIZE] = 0;
	}
	while (M--){
		int city1, city2, d, p;
		cin >> city1 >> city2 >> d >> p;
		map[city1].push_back(Way(city2, d, p));
		map[city2].push_back(Way(city1, d, p));
	}

	dist[S] = 0;
	collected[S] = true;
	for (int i = 0; i < map[S].size(); i++){
		dist[map[S][i].nextCity] = map[S][i].dist;
		price[map[S][i].nextCity] = map[S][i].price;
	}
//	for (int i = 0; i < N; i++){
//    	cout << i << ' '<< dist[i] << ' ' << path[i] << ' ' << price[i] << endl;
//	}
	Dijkstra(S);
//	for (int i = 0; i < N; i++){
//		cout << i << " : ";
//		for (int j = 0; j < map[i].size(); j++){
//			cout << ' ' << map[i][j].nextCity;
//		}
//		cout << endl;
//	}
//    for (int i = 0; i < N; i++){
//    	cout << i << ' '<< dist[i] << ' ' << path[i] << ' ' << price[i] << endl;
//	}
	cout << dist[D] << ' ' << price[D] << endl;
	
	return 0;
}
