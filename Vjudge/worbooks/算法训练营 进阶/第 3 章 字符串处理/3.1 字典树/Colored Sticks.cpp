#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <stack>
#include <cmath>
#include <bitset>
#include <complex>
#include <cstdlib>
#include <set>
#include <cstring>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
typedef long long i64;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 3e5 + 20;
int trie[N*26][30], end[N*30], tot, col, pa[N], deg[N];
int insert(char s[]) {
	int len = strlen(s), p = 0;
	for(int i = 0; i < len; ++ i) {
		int x = s[i] - 'a';
		if(!trie[p][x]) trie[p][x] = ++ tot;
		p = trie[p][x];
	}
	return end[p] ? end[p] : end[p] = ++ col;
}
int find(int x) {
	return x == pa[x] ? x : pa[x] = find(pa[x]);
}
void unite(int u, int v) {
	u = find(u); v = find(v);
	pa[v] = u;
}
void solve() {
	char s1[20], s2[20];
	for(int i = 1; i < N; ++ i) pa[i] = i;
	while(~scanf("%s %s", s1, s2)) {
		int a = insert(s1);
		int b = insert(s2);
		deg[a] ++; deg[b] ++;
		unite(a, b);
	}
	int s = find(1), num = 0;
	for(int i = 1; i <= col; ++ i) {
		if(deg[i] % 2) num ++;
		if(num > 2 || s != find(i)) {
			printf("Impossible\n");
			return ;
		}
	}
	if(num == 0 || num == 2) printf("Possible\n");
	else printf("Impossible\n");
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int T = 1;
	//scanf("%d", &T); 
	while(T --) solve();
	return 0;
}
