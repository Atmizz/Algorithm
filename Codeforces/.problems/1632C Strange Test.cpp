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
const int N = 1e6 + 20;
int solution1(int a, int b) {
	return b - a;
}
int solution2(int a, int b) {
	int ans = 1;
	while(1) {
		if((a | b) == b) return ans;
		ans ++; a ++;
	}
}
int solution3(int a, int b) {
	int ans = 1;
	while(1) {
		if((a | b) == b) {
			return ans;
		}
		b ++; ans ++;
	}
}
void solve() {
	int a, b;
	std :: cin >> a >> b;
	std :: cout << std :: min(solution1(a, b), 
		std :: min(solution2(a, b), solution3(a, b))) << endl;
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