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

void solve() {
	int n;
	std :: cin >> n;
	n *= 2;
	std :: vector <int> a(n);
	for(int i = 0; i < n; ++ i) a[i] = i + 1;
	int ans = 0;
	do {
		ans ++;
		for(int i = 1; i < n; ++ i)
			if(a[i-1] <= (n >> 1) && a[i] > a[i-1]) ans ++;
			else if(a[i-1] > (n >> 1) && a[i] < a[i-1]) ans ++;
			else {
				ans ++;
				break;
			}
	}while(std :: next_permutation(a.begin(), a.end()));
	std :: cout << ans;
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