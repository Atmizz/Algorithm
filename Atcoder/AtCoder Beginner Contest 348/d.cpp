#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define PII std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
std :: mt19937 rd(114514);
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 330;
int n, m, p, stx, sty, dis[N][N], edx, edy;
bool ok, vis[N];
char g[N][N];
struct Node {
	int x, y, z;
}a[N];
int xx[4] = {0, 0, 1, -1};
int yy[4] = {1, -1, 0, 0};
void calcDis(int k) {
	std :: vector res(n+1, std :: vector <int> (m+1, INF));
	std :: queue <PII> q;
	q.push({a[k].x, a[k].y});
	res[a[k].x][a[k].y] = 0;
	while(q.size()) {
		auto [x, y] = q.front(); q.pop();
		for(int i = 0; i < 4; ++ i) {
			int dx = x + xx[i];
			int dy = y + yy[i];
			if(dx < 1 || dx > n || dy < 1 || dy > m || g[dx][dy] == '#') {
				continue;
			}
			if(res[dx][dy] > res[x][y] + 1) {
				res[dx][dy] = res[x][y] + 1;
				q.push({dx, dy});
			}
		}
	}
	for(int i = 0; i <= p; ++ i) {
		if(i != k) {
			dis[k][i] = res[a[i].x][a[i].y];
		}
	}
}
void solve() {
	std :: cin >> n >> m;
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) {
			std :: cin >> g[i][j];
			if(g[i][j] == 'S') {
				stx = i;
				sty = j;
			} else if(g[i][j] == 'T') {
				edx = i;
				edy = j;
			}
		}
	}
	std :: cin >> p;
	for(int i = 1; i <= p; ++ i) {
		std :: cin >> a[i].x >> a[i].y >> a[i].z;
	}
	a[0].x = edx; a[0].y = edy;
	for(int i = 1; i <= p; ++ i) {
		for(int j = 0; j <= p; ++ j) {
			if(i != j) {
				dis[i][j] = INF;
			}
		}
	}
	for(int i = 1; i <= p; ++ i) {
		calcDis(i);
	}
	std :: queue <int> q;
	for(int i = 1; i <= p; ++ i) {
		if(a[i].x == stx && a[i].y == sty) {
			ok = true;
			vis[i] = 1;
			q.push(i);
			break;
		}
	}
	if(ok == false) {
		std :: cout << "No";
		return ;
	}
	while(q.size()) {
		int u = q.front(); q.pop();
		for(int i = 0; i <= p; ++ i) {
			if(!vis[i] && dis[u][i] <= a[u].z) {
				if(i == 0) {
					std :: cout << "Yes";
					return ;
				}
				vis[i] = 1;
				q.push(i);
			}
		}
	}
	std :: cout << "No";
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	//std :: cin >> T; 
	while(T --) solve();
	return 0;
}