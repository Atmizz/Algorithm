#include <cstdio>
#include <iostream>
#include <stack>
#include <queue>
#include <cstdlib>
#include <map>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>
#define gc getchar()
typedef long long ll;
inline int read() {
	int s = 0, f = 1; char ch = gc;
	for(; ch < '0' || ch > '9'; ch = gc) if(ch == '-')  f = -1;
	for(; ch >= '0' && ch <= '9'; ch = gc) s = (s << 3) + (s << 1) + (ch ^ 48);
	return s * f;
}
inline int abs(int a) { return a < 0 ? -a : a;}
inline int max(int a, int b) { return a > b ? a : b;}
inline int min(int a, int b) { return a < b ? a : b;}
const int MaxN = 1e6 + 200;
const int mod = 1e9 + 7;
const int INF = 0x7fffffff;
int ans[MaxN];
std :: string str1, str2;
int main() {
	memset(ans, 0, sizeof ans);
	std :: cin >> str1 >> str2;
	int len1 = str1.length(), len2 = str2.length();
	if(len1 >= len2) {
		int x = 0;
		for(int i = len - 1; i >= 0; -- i) {
			int a = str1[i] - '0', b = str2[i] - '0', c = 0;
			c = a * b + x; x = c / 10; c = c % 10; ans[i] = c;
	}
	}
	if(x > 0) std :: cout << x;
	for(int i = 0; i < len; ++ i) std :: cout << ans[i];
}