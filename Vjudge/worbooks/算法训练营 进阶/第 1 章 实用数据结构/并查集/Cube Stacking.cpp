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
const int N = 30010;
int pa[N], d[N], cnt[N];
int find(int x) {
	int p = pa[x];
	if(x != pa[x]) {
		pa[x] = find(pa[x]);
		d[x] += d[p];
	} return pa[x];
}
void solve() {
	int p;
	while(~scanf("%d", &p)) {
		for(int i = 1; i < N; ++ i) pa[i] = i, cnt[i] = 1;
		while(p --) {
			char ch; int l, r;
			std :: cin >> ch >> l;
			if(ch == 'M') {
				std :: cin >> r;
				l = find(l); r = find(r);
				d[l] = cnt[r];
				pa[l] = r; cnt[r] += cnt[l];
			} else {
				find(l);
				std :: cout << d[l] << endl;
			}
		}
	}
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