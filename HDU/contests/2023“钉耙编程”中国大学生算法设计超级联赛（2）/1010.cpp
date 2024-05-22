#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
#define pr pair<int, int>
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;

const int N = 2e4 + 200;
const int INF = 0x3f3f3f3f;
const int Mod = 1e9 + 7;
int a[N], ans;
struct Node {
	int pos, val;
};
void solve() {
	int n, m;
	std :: cin >> n >> m;
	std :: vector <bool> flag(n+1);
	std :: priority_queue <Node> q;
	for(int i = 1; i <= n; ++ i) std :: cin >> a[i];
	for(int i = 1; i <= m; ++ i) q.push({i, a[i]});
	ans += q.top().val;
	int pos1 = q.top().pos, val1 = q.top().val; q.pop();
	int pos2 = q.top().pos, val2 = q.top().val; ans += q.top().val;
	flag[pos1] = flag[pos2] = true;
	q.push({pos1, val1});
	for(int i = m + 1; i <= n; ++ i) {
		pos1 = q.top().pos; val1 = q.top().val; q.pop();
		pos2 = q.top().pos; val2 = q.top().val; q.pop();
		if(pos1 < i - m + 1) pos1 = -1;
		if(pos2 < i - m + 1) pos2 = -1;

	}
}

int main() {
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	std :: cin >> T;
	while(T --) solve();
	return 0;
}