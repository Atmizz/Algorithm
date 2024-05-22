#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define PII std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
// const int N = ;
struct Node1 {
	int h, w;
	friend bool operator < (Node1 a, Node1 b) {
		return a.h == b.h ? a.w < b.w : a.h < b.h;
	}
};
struct Node2 {
	int h, w;
	friend bool operator < (Node2 a, Node2 b) {
		return a.w == b.w ? a.h < b.h : a.w < b.w;
	}
};
void solve() {
	int n;
	std :: cin >> n;
	std :: vector <PII> a(n), b(n);
	std :: map <PII, int> mp;
	for(auto &[x, y] : a) {
		std :: cin >> x >> y;
		mp[{x, y}] ++;
	}
	int H, W;
	// The h is comfirmedd.
	std :: set <Node1> sh;
	std :: set <Node2> sw;
	std :: map <PII, int> mp1;
	for(auto [x, y] : mp) {
		mp1[x] = y;
		auto [h, w] = x;
		sh.insert({h, w});
		sw.insert({h, w});
	}
	H = (*sh.rbegin()).h;
	W = (*sh.rbegin()).w;
	mp1[(*sh.rbgin())] --;
	while(1) {

	}
	// The w is comfirmed.
	sh.clear(); sw.clear();
	std :: map <PII, int> mp2;
	for(auto [x, y] : mp) {
		mp2[x] = y;
		auto [h, w] = x;
		sh.insert({h, w});
		sw.insert({h, w});
	}
	H = 0, W = 0;
	while(1) {
		
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