#include <cstdio>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdlib>
#include <map>
#include <vector>
#include <iostream>
#include <cstring>
#include <set>
#include <algorithm>
#define gc getchar()
typedef unsigned long long ll;
inline int read() {
	int s = 0, f = 1; char ch = gc;
	for(; ch < '0' || ch > '9'; ch = gc) if(ch == '-') f = - 1;
	for(; ch >= '0' && ch <= '9'; ch = gc) s = (s << 3) + (s << 1) + (ch ^ 48);
	return s * f;
}
inline int abs(int a) { return a < 0 ? -a : a;}
inline int max(int a, int b) { return a > b ? a : b;}
inline int min(int a, int b) { return a < b ? a : b;}
const int MaxN = 1e6 + 200;
const int mod = 1e9 + 7;
const int INF = 0x7fffffff;
int N, Num, ans[200001];
int main() {
	N = read();
	for(int i = 2; i <= N; ++ i) {
		if(N == 1) continue;
		while(N % i == 0) ans[++Num] = i, N /= i;
	}
	if(Num == 1) std :: cout << ans[1];
	else {
		for(int i = 1; i < Num; ++ i) std :: cout << ans[i] << '*';
		std :: cout << ans[Num];
	}
}