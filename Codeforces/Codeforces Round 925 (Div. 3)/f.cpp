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
// const int N = ;
int t = 0;
void solve() {
	int n, k; 
	t ++;
	std :: cin >> n >> k;
	std :: vector a(k+1, std :: vector <int> (n+1));
	for(int i = 1; i <= k; ++ i) {
		for(int j = 1; j <= n; ++ j) {
			std :: cin >> a[i][j];
		}
	}
	if(k == 1) {
		std :: cout << "YES\n";
		return ;
	}
	std :: vector <int> b(n+1);
	for(int i = 2; i <= k; ++ i) {
		int pos1 = 1, posi = 1;
		// find pos of a[1][1] in a[i];
		for(int j = 1; j <= n; ++ j) {
			if(a[i][j] == a[1][1]) {
				pos1 = j;
				break;
			}
		}
		// find pos of a[i][1] in a[1];
		for(int j = 1; j <= n; ++ j) {
			if(a[1][j] == a[i][1]) {
				posi = j;
				break;
			}
		}
		// a[1][1] is adjacnt to a[i][1];
		if(pos1 == posi) {
			continue;
		}
		bool ok = true;
		for(int j = 2; j < pos1; ++ j) {
			if(a[1][j] != a[i][j]) {
				ok = false;
				break;
			}
		}
		int cnt = 2;
		if(ok) {
			b[pos1-1] = a[1][1];
		} else {
			b[pos1] = a[1][1];
		}
		for(int j = 1; j <= n; ++ j) {
			if(b[j]) {
				continue ;
			}
			b[j] = a[1][cnt++];
		}
		break;
	}
	if(b[1] == 0) {
		int pos1 = 1, pos2 = -1;
		for(int j = 1; j <= n; ++ j) {
			if(a[2][j] == a[1][1]) {
				pos1 = j;
				break;
			}
		}
		if(k > 2) {
			for(int j = 1; j <= n; ++ j) {
				if(a[3][j] == a[1][1]) {
					pos2 = j;
					break;
				}
			}
		}
		b[std::max(pos1-1, pos2-1)] = a[1][1];
		int cnt = 2;
		for(int j = 1; j <= n; ++ j) {
			if(b[j]) {
				continue ;
			}
			b[j] = a[1][cnt++];
		}
	}
	// for(int i = 1; i <= n; ++ i) {
	// 	std :: cout << b[i] << " \n"[i == n];
	// }
	for(int i = 1; i <= k; ++ i) {
		std :: vector <int> c(n+1);
		int cnt = 2;
		c[1] = a[i][1];
		for(int j = 1; j <= n; ++ j) {
			if(b[j] == a[i][1]) {
				continue;
			}
			c[cnt++] = b[j];
		}
		for(int j = 1; j <= n; ++ j) {
			// std :: cout << c[j] << " \n"[j == n];
			if(c[j] != a[i][j]) {
				std :: cout << "NO\n";
				return ;
			}
		}
	}
	std :: cout << "YES\n";
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T;
	std :: cin >> T; 
	while(T --) solve();
	return 0;
}