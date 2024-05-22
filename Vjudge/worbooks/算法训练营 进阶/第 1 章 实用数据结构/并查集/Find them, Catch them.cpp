#include <iostream>
#include <cstdio>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1e5 + 20;
int pa[N<<1], n, m; 
int find(int x) {
	return x == pa[x] ? x : pa[x] = find(pa[x]);
}
void unite(int x, int y) {
	pa[y] = x;
}
void solve() {
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n << 1; ++ i)
		pa[i] = i;
	while(m --) {
		char opt[2]; int x, y;
		scanf("%s", opt);
		scanf("%d %d", &x, &y);
		int x1 = find(x), x2 = find(x+n);
		int y1 = find(y), y2 = find(y+n);
		if(opt[0] == 'D') {
			unite(x1, y2); unite(y1, x2);
		} else {
			if(x1 == y1 || x2 == y2) printf("In the same gang.\n");
			else if(x1 == y2 || x2 == y1) printf("In different gangs.\n");
			else printf("Not sure yet.\n");
		}
	}
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int T = 1;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}