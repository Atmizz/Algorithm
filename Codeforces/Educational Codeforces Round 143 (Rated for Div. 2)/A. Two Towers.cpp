#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
#define gc getchar()
typedef long long ll;
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
const int MaxN = 1e6+300;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int T, n, m;
int main() {
  T = read();
  while(T --) {
    n = read(); m = read();
    bool f1 = 0, f2 = 0, f = 0;
    int a[25] = {0}, b[25] = {0};
    std :: string str1, str2;
    std :: cin >> str1 >> str2;
    a[0] = 1; b[0] = 1;
    for(int i = 1; i < n; ++ i)
      if(str1[i] == str1[i-1]) {
        a[i] = a[i-1] + 1;
        if(a[i] > 2) {f = 1; break;}
        if(a[i] == 2) {
          if(f1) {f = 1; break;}
          f1 = 1;
        }
      }
      else a[i] = 1;
    if(f) {printf("NO\n"); continue;}
    for(int i = 1; i < m; ++ i)
      if(str2[i] == str2[i-1]) {
        b[i] = b[i-1] + 1;
        if(b[i] > 2) {f = 1; break;}
        if(b[i] == 2) {
          if(f2) {f = 1; break;}
          f2 = 1;
        }
      }
      else b[i] = 1;
    if(f) {printf("NO\n"); continue;}
    if((!f1) && (!f2)) printf("YES\n");
    else if(f1 && (!f2)) {
      if(str1[n-1] != str2[m-1]) printf("YES\n");
      else printf("NO\n");
    } else if(f2 && (!f1)) {
      if(str1[n-1] != str2[m-1]) printf("YES\n");
      else printf("NO\n");
    } else printf("NO\n");
  }
  return 0;
}