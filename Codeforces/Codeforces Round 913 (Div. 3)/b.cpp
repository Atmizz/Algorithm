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
const int N = 1e6 + 20;
struct Node {
	int pos;
	char ch;
	friend bool operator <(Node a, Node b) {
		return a.pos < b.pos;
	}
};
void solve() {
	std :: string str;
	std :: cin >> str;
	std :: stack <Node> A, a;
	for(int i = 0; i < str.length(); ++ i) {
		char c = str[i];
		if(c == 'b') {
			if(a.empty()) continue;
			a.pop();
		} else if(c == 'B') {
			if(A.empty()) continue;
			A.pop();
		} else if(c >= 'A' && c <= 'Z') {
			A.push({i, c});
		} else {
			a.push({i, c});
		}
	}
	std :: vector <Node> vec;
	while(a.size()) vec.push_back(a.top()), a.pop();
	while(A.size()) vec.push_back(A.top()), A.pop();
	std :: sort(vec.begin(), vec.end());
	for(auto x : vec)
		std :: cout << x.ch;
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