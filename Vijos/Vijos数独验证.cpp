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
const int MaxN = 2e5 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, a[10][10], vis[10];
int main() {
  n = read(); int flag;
  for(int k = 1; k <= n; ++ k) {
    flag = 1;
    for(int i = 1; i <= 9; ++ i)
      for(int j = 1; j <= 9; ++ j)
        a[i][j] = read();
    for(int i = 1; i <= 9; ++ i) {
      memset(vis, 0, sizeof vis);
      for(int j = 1; j <= 9; ++ j) {
        vis[a[i][j]] ++;
        if(vis[a[i][j]] > 1) {flag = 0; break;}
      }
      if(!flag) break;
    }
    for(int j = 1; j <= 9; ++ j) {
      memset(vis, 0, sizeof vis);
      for(int i = 1; i <= 9; ++ i) {
        vis[a[i][j]] ++;
        if(vis[a[i][j]] > 1) {flag = 0; break;}
      }
      if(!flag) break;
    }
    for(int i = 1; i <= 7; i += 3) {
      for(int j = 1; j <= 7; j += 3) {
        memset(vis, 0, sizeof vis);
        for(int h = i; h <= i + 2; ++ h) {
          for(int l = j; l <= j + 2; ++ l) {
            vis[a[h][l]] ++;
            if(vis[a[h][l]] > 1) {flag = 0; break;}
          }
          if(!flag) break;
        }
      }
      if(!flag) break;
    }
    if(flag) printf("Right\n");
    else printf("Wrong\n");
  }
	return 0;
}