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
inline int abs(int a) {return a < 0 ? -a : a;}
inline int min(int a, int b) {return a < b ? a : b;}
inline int max(int a, int b) {return a > b ? a : b;}
const int MaxN = 150;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, a[10];
int main() {
  n = read();
  for(int i = 1; i <= n; ++ i) a[i] = i;
  do {
    for(int i = 1; i <= n; ++ i) printf("    %d", a[i]);
    puts("");
  } while(std :: next_permutation(a + 1, a + n + 1));
	return 0;
}