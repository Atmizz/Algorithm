#include <bits/stdc++.h>
//#pragma GCC optimize ("O3")
#define nl '\n'
#define ls k << 1
#define rs k << 1 | 1
#define pb push_back
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
const int N = 3e6 + 20;
struct TrieAlgorithm {
	int tot, trie[N][70], cnt[N];
	void init() {
		for(int i = 0; i <= tot; ++ i) {
			cnt[i] = 0;
			for(int j = 0; j < 70; ++ j) {
				trie[i][j] = 0;
			}
		}
		tot = 0;
	}
	int get(char &ch) {
		if(ch >= 'a' && ch <= 'z') {
			return ch - 'a';
		} else if(ch >= 'A' && ch <= 'Z') {
			return ch - 'A' + 26;
		} else {
			return ch - '0' + 52;
		}
	}
	void insert(std :: string &s) {
		int p = 0;
		for(int i = 0; i < (int) s.size(); ++ i) {
			int x = get(s[i]);
			if(!trie[p][x]) {
				trie[p][x] = ++ tot;
			}
			p = trie[p][x];
			cnt[p] ++;
		}
	}
	int query(std :: string &s) {
		int p = 0;
		for(int i = 0; i < (int) s.size(); ++ i) {
			int x = get(s[i]);
			if(!trie[p][x]) {
				return 0;
			}
			p = trie[p][x];
		}
		return cnt[p];
	}
}Trie;
void solve() {
	int n, q;
	std :: cin >> n >> q;
	Trie.init();
	for(int i = 1; i <= n; ++ i) {
		std :: string s;
		std :: cin >> s;
		Trie.insert(s);
	}
	while(q --) {
		std :: string s;
		std :: cin >> s;
		std :: cout << Trie.query(s) << nl;
	}
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