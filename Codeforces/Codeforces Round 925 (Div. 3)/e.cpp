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
struct Node {
	int val, num;
	friend bool operator < (Node a, Node b) {
		return a.num < b.num;
	}
};
void solve() {
	int n, m, non = 0;
	std :: cin >> n >> m;
	std :: vector <int> a(n+1);
	std :: priority_queue <Node> q;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
		int cnt = 0, tmp = a[i];
		while(tmp % 10 == 0) {
			tmp /= 10;
			cnt ++;
		}
		q.push({a[i], cnt});
	}
	int ok = 0;
	while(1) {
		auto tmp = q.top();
		if(tmp.num == 0) {
			break;
		}
		q.pop();
		if(!ok) {
			for(int i = 1; i <= tmp.num; ++ i) {
				tmp.val /= 10;
			}
		}
		tmp.num = 0;
		q.push(tmp);
		ok ^= 1;
	}
	int cnt = 0;
	while(q.size()) {
		int x = q.top().val; q.pop();
		while(x) {
			cnt ++;
			x /= 10;
		}
	}
	std :: cout << (cnt > m ? "Sasha\n" : "Anna\n");
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