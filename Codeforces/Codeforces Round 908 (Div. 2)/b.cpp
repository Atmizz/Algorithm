#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const int INF = 0x3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 110;
struct Node {
	int x, id;
	friend bool operator < (Node a, Node b) {
		return a.x < b.x;
	}
}e[N];
void solve() {
	int n; std :: cin >> n;
	std :: vector <int> a(n);
	std :: vector <int> b(n);
	for(int i = 0; i < n; ++ i)
		std :: cin >> a[i];
	for(int i = 1; i <= n; ++ i)
		e[i].x = a[i-1], e[i].id = i - 1;
	std :: sort(e + 1, e + 1 + n);
	int sameCnt = 0, cnt = 0;
	for(int i = 2; i <= n; ++ i)
		if(e[i].x == e[i-1].x) {
			cnt ++; sameCnt ++;
			if(sameCnt >= 2) cnt --;
		} else sameCnt = 0;
	if(cnt < 2) {
		std :: cout << -1 << endl;
		return ;
	}
	bool flag = 0;
	for(int i = 1; i <= n;) {
		int num = 1, j = i + 1;
		while(e[j].x == e[i].x) num ++, j ++;
		// deb(flag);
		if(flag == 0) {
			if(num >= 3) { // 1 2
				int x = 0;
				for(int k = i; k <= num + i - 1; ++ k)
					b[e[k].id] = x + 1, x ^= 1;
				flag = 1;
			} else if(num == 2) {
				b[e[i].id] = 1;
				b[e[i+1].id] = 2;
				flag = 1;
			} else b[e[i].id] = 1;
		} else {
			if(num >= 3) {
				int x = 1;
				for(int k = i; k <= num + i - 1; ++ k)
					b[e[k].id] = x + 2, x ^= 1;
			} else if(num == 2) {
				b[e[i].id] = 2;
				b[e[i+1].id] = 3;
			} else b[e[i].id] = 1;
		}
		i = j;
	}
	for(int i = 0; i < n; ++ i)
		std :: cout << b[i] << ' ';
	std :: cout << '\n';
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	std :: cin >> T; 
	while(T --) solve();
	return 0;
}
