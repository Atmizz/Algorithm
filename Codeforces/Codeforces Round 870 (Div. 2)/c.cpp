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
const int MaxN = 1e6 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
bool check(int a, int b) {
  for(int i = 2; i <= sqrt(a); ++ i)
    if(a % i == 0 && i <= b) return true;
  return false;
}
int main() {
  int t = read(), a, b;
  while(t --) {
    a = read(), b = read();
    if(a == 1 || b == 1) {
      printf("YES\n");
      continue;
    }
    if(a % b == 0 || a <= b || a % 2 == 0 || check(a, b)) printf("NO\n");
    else printf("YES\n");
  }
  return 0;
}