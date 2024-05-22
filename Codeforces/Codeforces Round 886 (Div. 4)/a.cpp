#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
#define pr pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const int Mod = 1e9 + 7;

void solve() {
	int a[4];
	for(int i = 1; i <= 3; ++ i) std :: cin >> a[i];
	std :: sort(a + 1, a + 4);
	if(a[3] + a[2] >= 10) std :: cout << "Yes\n";
	else std :: cout << "No\n";
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