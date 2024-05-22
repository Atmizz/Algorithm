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
const int N = 2e5 + 20;
int trie[N*30][3], cnt, n, sum[N*30];
void add(int x) {
	int p = 0;
	for(int i = 30; i >= 0; -- i) {
		int val {x >> i & 1};
		if(!trie[p][val]) {
			trie[p][val] = ++ cnt;
		}
		sum[trie[p][val]] ++;
		p = trie[p][val];
	}
}
void del(int x) {
	int p = 0;
	for(int i = 30; i >= 0; -- i) {
		int val {x >> i & 1};
		sum[trie[p][val]] --;
		p = trie[p][val];
	}
}
int query(int x) {
	int s = 0, p = 0;
	// if(!sum[trie[0][0]] && !sum[trie[0][1]]) {
	// 	return x;
	// }
	for(int i = 30; i >= 0; -- i) {
		int val {x >> i & 1};
		if(sum[trie[p][!val]]) {
			s += 1 << i;
			p = trie[p][!val];
		} else if(sum[trie[p][val]]) {
			p = trie[p][val];
		} else {
			break;
		}
	}
	return s;
}
void solve() {
	std :: cin >> n;
	add(0);
	while(n --) {
		char ch;
		int x;
		std :: cin >> ch >> x;
		if(ch == '+') {
			add(x);
		} else if(ch == '-') {
			del(x);
		} else {
			std :: cout << query(x) << '\n';
		}
	}
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	//std :: cin >> T; 
	while(T --) solve();
	return 0;
}