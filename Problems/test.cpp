#include <bits/stdc++.h>
#define gc getchar()
#define ll long long
inline int read() {
	int s = 0, f = 1; char ch = gc;
	for(; ch < '0' || ch > '9'; ch = gc) if(ch == '-') f = -1;
	for(; ch >= '0' && ch <= '9'; ch = gc)
		s = (s << 1) + (s << 3) + (ch ^ 48);
	return s * f;
}
inline int min(int a, int b) {return a < b ? a : b;}
inline int max(int a, int b) {return a > b ? a : b;}
inline int abs(int a) {return a < 0 ? -a : a;}
const int INF = 0x7fffffff;
const int MaxN = 5e5 + 200;
const int Mod = 1e9 + 7;
int main() {
	printf("Hello World");
}