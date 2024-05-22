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
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 2e5 + 20;
int n, a[N];
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i)
		std :: cin >> a[i];
	bool isSame = 1;
	for(int i = 2; i <= n; ++ i)
		if(a[i] != a[i-1]) isSame = 0;
	if(isSame) {
		std :: cout << 1 << endl;
		for(int i = 1; i <= n; ++ i)
			std :: cout << 1 << ' ';
		puts("");
		return ;
	}
	if(n % 2 == 0) {
		std :: cout << 2 << endl;
		for(int i = 1; i <= n >> 1; ++ i)
			std :: cout << 1 << ' ' << 2 << ' ';
		std :: cout << endl;
		return ;
	}
	if(a[1] == a[n]) {
		std :: cout << 2 << endl;
		int x = 1;
		std :: cout << 1 << ' ';
		for(int i = 2; i < n; ++ i) {
			std :: cout << x + 1 << ' ';
			x ^= 1;
		}
		std :: cout << 1 << endl;
		return ;
	}
	int pos = -1;
	for(int i = 1; i < n; ++ i)
		if(a[i] == a[i+1]) {
			pos = i;
			break;
		}
	if(pos == -1) {
		std :: cout << 3 << endl;
		for(int i = 1; i <= n >> 1; ++ i)
			std :: cout << 1 << ' ' << 2 << ' ';
		std :: cout << 3 << endl;
	} else {
		std :: cout << 2 << endl;
		int x = 0;
		for(int i = 1; i <= n; ++ i) {
			if(i == pos) std :: cout << x + 1 << ' ' << x + 1 << ' ', i ++;
			else std :: cout << x + 1 << ' ';
			x ^= 1;
		}
		std :: cout << endl;
	}
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
