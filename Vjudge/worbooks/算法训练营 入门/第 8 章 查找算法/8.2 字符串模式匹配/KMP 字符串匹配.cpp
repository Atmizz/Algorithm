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
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1e6 + 20;
int next[N];
void getNext(std :: string s) {
	int j = -1, i = 0; next[0] = -1;
	int len = s.length();
	while(i < len) {
		if(j == -1 || s[i] == s[j]) next[++i] = ++ j;
		else j = next[j];
	}
}
void kmp(std :: string s1, std :: string s2) {
	int len1 = s1.length(), len2 = s2.length(), i = 0, j = 0;
	while(i < len1) {
		if(j == -1 || s1[i] == s2[j]) i ++, j ++;
		else j = next[j];
		if(j == len2) std :: cout << i - len2 + 1 << endl;
	}
}
void solve() {
	std :: string s1, s2;
	std :: cin >> s1 >> s2;
	getNext(s2);
	kmp(s1, s2);
	for(int i = 1; i <= s2.length(); ++ i)
		std :: cout << next[i] << ' ';
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