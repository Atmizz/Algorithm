#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
#define gc getchar()
typedef long long ll;
inline int read() {
	int s = 0, f = 1; char ch = gc;
	for(; ch < '0' || ch > '9'; ch = gc) if(ch == '-') f = -1;
	for(; ch >= '0' && ch <= '9'; ch = gc)
		s = (s << 1) + (s << 3) + (ch ^ 48);
	return s * f;
}
inline int abs(int a) {return a < 0 ? -a : a;}
inline int min(int a, int b) {return a < b ? a : b;}
inline int max(int a, int b) {return a > b ? a : b;}
const int MaxN = 1e5 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m, Q;
std :: string str1[MaxN], str2[MaxN];
namespace KMP {
	std :: vector <int> Next[MaxN];
	void init() {
		for(int i = 1; i <= n; ++ i)
			Next[i].clear(), Next[i].resize(m+1);
	}
	void get(int x) {
		int i = 0, j = -1; Next[x][0] = -1;
		while(i < m) {
			if(j == -1 || str1[i] == str1[j]) i ++, j ++, Next[x][i] = j;
			else j = Next[x][j];
		}
	}
	bool KMP(int x, int y) {
		int i = 0, j = 0;
		while(i < m * 2) {
			if(j == -1 || str2[x][i] == str1[y][j]) i ++, j ++;
			else j = Next[y][j];
			if(j == m) {
				puts("Yes");
				return true;
			}
		} return false;
	}
}
void solve() {
	n = read(); m = read();
	for(int i = 1; i <= n; ++ i)
		std :: cin >> str1[i], str2[i] = str1[i] + str1[i];
	KMP :: init();
	for(int i = 1; i <= n; ++ i) KMP :: get(i);
	Q = read();
	for(int i = 1; i <= Q; ++ i) {
		int x = read(), y = read();
		if(KMP :: KMP(y, x)) continue;
		else puts("No");
	}
}
int main() {
	int T = 1; T = read();
	while (T--) solve();
	return 0;
}
