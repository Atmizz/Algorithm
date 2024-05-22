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
const int N = 10010;
int trie[N*10][10], cnt, n, end[N*10];
bool insert(char s[]) {
	int len = strlen(s), num = 0, p = 0;
	for(int i = 0; i < len; ++ i) {
		int x = s[i] - '0';
		if(!trie[p][x]) num ++, trie[p][x] = ++ cnt;
		p = trie[p][x];
		if(end[p]) return 1;
	}
	end[p] = 1;
	if(!num) return 1;
	return 0;
}
void solve() {
	scanf("%d", &n); cnt = 0;
	memset(end, 0, sizeof end);
	memset(trie, 0, sizeof trie);
	bool flag = 0;
	for(int i = 1; i <= n; ++ i) {
		char s[12];
		scanf("%s", s);
		if(!flag) flag = insert(s);
	}
	if(flag) printf("NO\n");
	else printf("YES\n");
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int T = 1;
	scanf("%d", &T); 
	while(T --) solve();
	return 0;
}