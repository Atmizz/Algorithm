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
const int MaxN = 2100;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, f[MaxN], ans = -INF;
std :: string str[MaxN];
int main() {
  n = read();
  for(int i = 1; i <= n; ++ i) std :: cin >> str[i];
  std :: sort(str + 1, str + 1 + n);
  for(int i = 1; i <= n; ++ i) {
    f[i] = 1;
    for(int j = 1; j < i; ++ j) {
      bool flag = 1;
      for(int k = 0; k < str[j].length(); ++ k)
        if(str[i][k] != str[j][k]) {flag = 0; break;}
      if(flag) f[i] = max(f[i], f[j] + 1);
    }
  }
  for(int i = 1; i <= n; ++ i) ans = max(ans, f[i]);
  printf("%d", ans);
	return 0;
}