#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int M = 100;
struct graph {
	int flag, n;
	int m[M][M];
};
struct canh {
	int dinhdau, dinhcuoi, trongso;
};
bool visited[M]; // true Vh false V
void nhap(graph& g) {
	cin >> g.n;
	for (int i = 1; i <= g.n; i++) {
		for (int j = 1; j <= g.n; j++) {
			cin >> g.m[i][j];
		}
	}
	memset(visited, false, sizeof(visited));
}
bool check(graph g) {
	for (int i = 1; i <= g.n; i++) {
		if (visited[i] == false)
			return true;
	}
	return false;
}
void prim(int u, vector<canh> dsc, graph g) {
	sort(dsc.begin(), dsc.end(), [](canh x, canh y)->bool {
			return x.trongso < y.trongso;
		});
	visited[u] = true;
	int price = 0;
	while (check(g)) {
		for (auto i : dsc) {
			int x = i.dinhdau, y = i.dinhcuoi;
			if (visited[x] != visited[y]) {
				visited[x] = visited[y] = true;
				price += i.trongso;
				cout << x << ' ' <<  y << ' ' << i.trongso << endl;
				break;
			}
		}
	}
	cout << price;
}
int main() {
	vector<canh> dsc;
	graph g;
	nhap(g);
	int socanh = 0;
	for (int i = 1; i <= g.n; i++) {
		for (int j = i + 1; j <= g.n; j++) {
			if (g.m[i][j] != 0) {
				dsc.push_back({ i,j,g.m[i][j] });
			}
		}
	}
	prim(1, dsc, g);
	getchar();
}
// Khoa ✅
// 6
// 0 8 0 9 5 3
// 8 0 6 3 0 0
// 0 6 0 5 0 0
// 9 3 5 0 7 0
// 5 0 0 7 0 4
// 3 0 0 0 4 0

// Khang❌
// 6
// 0 8 0 9 0 0
// 0 0 6 3 0 0
// 0 0 0 5 0 0
// 0 0 0 0 7 0
// 5 0 0 0 0 4
// 3 0 0 0 0 0