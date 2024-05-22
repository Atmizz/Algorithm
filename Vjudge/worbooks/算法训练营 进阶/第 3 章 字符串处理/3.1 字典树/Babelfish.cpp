#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <stack>
#include <cmath>
#include <bitset>
#include <complex>
#include <cstdlib>
#include <set>
#include <cstring>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
typedef long long i64;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1e5 + 20;
int trie[N*20][30], end[N*20], cnt;
std :: string dic[N];
void insert(std :: string str, int k) {
	int len = str.length(), p = 0;
	for(int i = 0; i < len; ++ i) {
		int x = str[i] - 'a';
		if(!trie[p][x]) trie[p][x] = ++ cnt;
		p = trie[p][x];
	}
	end[p] = k;
}
void search(char s[]) {
	int len = strlen(s), p = 0;
	for(int i = 0; i < len; ++ i) {
		int x = s[i] - 'a';
		if(!trie[p][x]) {
			printf("eh\n");
			return ;
		} p = trie[p][x];
	}
	std :: cout << dic[end[p]] << endl;
}
void solve() {
	int t = 1; dic[0] = "eh";
	while(1) {
		char s[100];
		std :: string s1 = "", s2 = "";
		gets(s); int j = 0, flag = 0;
		int len = strlen(s);
		if(len == 0) break;
		for(int i = 0; i < len; ++ i)
			if(s[i] == ' ') flag = 1, j = 0;
			else if(flag == 0) s1 += s[i];
			else s2 += s[i];
//			deb(s1);
		dic[t] = s1;
		insert(s2, t); t ++;
	}
	char s[30];
	while(~scanf("%s", s)) search(s);
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int T = 1;
	//scanf("%d", &T); 
	while(T --) solve();
	return 0;
}
