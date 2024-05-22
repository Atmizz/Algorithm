#include <bits/stdc++.h>
//#pragma GCC optimize ("O3")
#define nl '\n'
#define ls k << 1
#define rs k << 1 | 1
#define pb push_back
#define sz(x) (int)x.size()
#define mk std :: make_pair
#define PII std :: pair <int, int>
#define PIL std :: pair <int, i64>
#define PLL std :: pair <i64, i64>
#define DEB std :: cout << "ok" << endl;
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
typedef unsigned long long ull;
template <class T>
T max(T a, T b) {
	return a > b ? a : b;
}
template <class T>
T min(T a, T b) {
	return a < b ? a : b;
}
template <class T>
T abs(T a) {
	return a < 0 ? -a : a;
}
std :: mt19937 rd(114514);
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
// const int N = ;
struct Node {
	int x, num;
	friend bool operator < (Node a, Node b) {
		return a.num < b.num;
	}
};
void solve() {
	int n, k;
	std :: cin >> n >> k;
	std :: vector <int> a(n);
	std :: map <int, int> mp;
	for(auto &x : a) {
		std :: cin >> x;
		mp[x] ++;
	}
	std :: priority_queue <Node> q;
	for(auto &[x, y] : mp) {
		q.push({x, y});
	}
	int res = 0, sum = n;
	while(sz(q)) {
		auto [x, num] = q.top();
		if(num + res < k) {
			break;
		}
		q.pop();
		if(num >= k) {
			sum -= num / k * k;
			res += num / k * (k - 1);
			num = num % k;
		} else {
			sum -= num;
			res -= k - num;
			res += k - 1;
			num = 0;
		}
		if(num > 0) {
			q.push({x, num});
		}
	}
	if(res >= k) {
		res = k - 1;
	}
	// deb(sz(q));
	// deb(res);
	std :: cout << sum + res << nl;
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int _ = 1;
	std :: cin >> _; 
	while(_ --) solve();
	return 0;
}