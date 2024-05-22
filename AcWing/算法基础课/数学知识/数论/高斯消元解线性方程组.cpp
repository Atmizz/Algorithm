#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pr pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const int Mod = 1e9 + 7;
const int N = 112;
const double eps = 1e-6;

double a[N][N];
int n;

int gauss() {
	int r, c;
	for(r = 0, c = 0; c < n; ++ c) {
		int t = r;
		for(int i = r; i < n; ++ i)
			if(std :: fabs(a[i][c]) > std :: fabs(a[t][c])) t = i;
		if(std :: fabs(a[t][c]) < eps) continue;
		for(int i = c; i <= n; ++ i) std :: swap(a[t][i], a[r][i]);
		for(int i = n; i >= c; -- i)
			a[r][i] /= a[r][c];
		for(int i = 0; i < n; ++ i)
			if(std :: fabs(a[i][c]) > eps && i != r)
				for(int j = n; j >= c; -- j)
					a[i][j] -= a[i][c] * a[r][j];
		r ++;
	}
	if(r < n) {
		for(int i = r; i < n; ++ i)
			if(std :: fabs(a[i][n]) > eps) return 2;
		return 1;
	} return 0;
}

void solve() {
	std :: cin >> n;
	for(int i = 0; i < n; ++ i)
		for(int j = 0; j <= n; ++ j)
			std :: cin >> a[i][j];
	int t = gauss();
	if(t == 0) {
		for(int i = 0; i < n; ++ i) printf("%.2lf\n", a[i][n]);
	} else if(t == 1) std :: cout << "Infinite group solutions";
	else std :: cout << "No solution";
}

int main() {
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	//std :: cin >> T; 
	while(T --) solve();
	return 0;
}