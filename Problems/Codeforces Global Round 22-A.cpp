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
int T, n, Id[MaxN];
int main() {
	T = read();
	for(; T > 0; -- T) {
		n = read(); int x;
		std :: vector <int> a, b;
		for(int i = 1; i <= n; ++ i) {
			Id[i] = read();
		for(int i = 1; i <= n; ++ i) {
			x = read()
			if(Id[i] == 0) a.push_back(x);
			else b.push_back(x);
		}
		std :: sort(a.begin(), a.end());
		std :: sort(b.begin(), b.end());
		while((!a.empty()) || (!b.empty())) {
			if(a.end() > b.end()) ans += (a.end() * 2), ans += b.begin(), b.erase(b.begin()), a.erase(a.end());
			else if(a.end() < b.end()) ans += (b.end() * 2), ans += a.begin(), a.erase((a.begin())), b.erase(b.end());
			else
				if(a.begin() < b.begin()) ans += (2 * b.end()), ans += a.begin(), 
		}
	}
}