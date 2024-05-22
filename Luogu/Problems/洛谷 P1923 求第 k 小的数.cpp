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
const int MaxN = 5e6 + 200;
const int mod = 1e9 + 7;
const int INF = 0x7fffffff;
int a[MaxN];
std :: string str1, str2;
int main() {
	int n = read(), k = read();
	for(int i = 0; i < n; ++ i) a[i] = read();
	std :: sort(a, a + n);
	std :: cout << a[k];
}