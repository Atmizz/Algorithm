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
typedef long long i64;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 220;
int n, dp[N][2], head[N], cnt, m, num;
struct Node {
	int to, net;
}e[N];
void insert(int u, int v) {
	e[++cnt].to = v;
	e[cnt].net = head[u];
	head[u] = cnt;
}
void dfs(int u) {
	int sum = 0;
	dp[u][1] = 1; dp[u][0] = 0;
	for(int i = head[u]; i; i = e[i].net) {
		int v = e[i].to;
		dfs(v);
		dp[u][1] += dp[v][0];
		dp[u][0] += std :: max(dp[v][0], dp[v][1]);
	}
}
void solve() {
	while(1) {
		scanf("%d", &n);
		if(n == 0) return ;
		memset(head, 0, sizeof head);
		cnt = 0; m = 0; num = 0;
		std :: string s1, s2;
		std :: cin >> s1;
		std :: map <std :: string, int> mp;
		mp[s1] = ++ m;
		for(int i = 1; i < n; ++ i) {
			std :: cin >> s1 >> s2;
			if(!mp[s1]) mp[s1] = ++ m;
			if(!mp[s2]) mp[s2] = ++ m;
			insert(mp[s2], mp[s1]);
		}
		dfs(1);
		printf("%d ", std :: max(dp[1][1], dp[1][0]));
		bool flag = 1;
		for(int i = 1; i <= n; ++ i)
			if(dp[i][0] >= dp[i][1]) {
				for(int j = head[i]; j; j = e[j].net) {
					int v = e[j].to;
					if(dp[v][0] == dp[v][1]) {
						flag = 0;
						break ;
					}
				}
				if(!flag) break;
			}
		if(dp[1][0] == dp[1][1] || !flag)
			std :: cout << "No\n";
		else printf("Yes\n");
	}
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int T = 1;
	//scanf("%d", &T); 
	while(T --) solve();
	return 0;
}