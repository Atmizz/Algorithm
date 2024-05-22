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
const int MaxN = 3e5 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int T, n, a[MaxN], last[MaxN];
int main() {
  T = read();
  while(T --) {
    n = read(); int value = 0; 
    for(int i = 1; i <= n; ++ i) a[i] = read(); last[1] = a[1];
    for(int i = 1; i < n; ++ i) value += abs(a[i] - a[i+1]);
    for(int i = 2; i < n; ++ i)
      if(a[i] == a[i-1]) last[i] = last[i-1];
      else last[i] = a[i-1];
    if(value == 0) {
      printf("%d\n", 1);
      continue;
    }
    if(n == 1) {
      printf("1\n");
      continue;
    } else if(n == 2) {
      printf("2\n");
      continue;
    }
    int cnt = 0;
    for(int i = 2; i < n; ++ i)
      if((a[i] > last[i] && a[i] > a[i+1]) || (a[i] < last[i] && a[i] < a[i+1])) cnt ++;
    printf("%d\n", cnt + 2);
  }
  return 0;
}