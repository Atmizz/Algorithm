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
const int MaxN = 1e5 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
char str[MaxN];
int main() {
  int T, n, k;
  T = read();
  while(T --) {
    n = read(); k = read();
    scanf("%s", str + 1);
    std :: sort(str + 1, str + 1 + n);
    if(str[k] == str[1]) {
      if(str[k+1] == str[n]) {
        putchar(str[1]);
        for(int i = 1; i <= ((n - k - 1) / k + 1  ); ++ i)
          putchar(str[k+1]);
      } else {
        putchar(str[1]);
        printf("%s", str + k + 1);
      }
    } else putchar(str[k]);
    puts("");
  }
  return 0;
}