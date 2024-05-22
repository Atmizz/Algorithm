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
std :: mt19937 rd(114514);
void solve() {
	std :: string str;
	std :: cin >> str;
	std :: queue <int> q;
	bool ok = false;
	for(int i = 0; i < (int) str.size(); ++ i) {
		if(str[i] == '0') {
			ok = true;
			q.push(1);
		} else {
			if(ok) {
				q.push(0);
			}
		}
	}
	if(q.empty()) {
		std :: cout << (str[str.size()-1] == '1' ? 2 : 1);
	}
	while(q.size()) {
		std :: cout << q.front();
		q.pop();
	}
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