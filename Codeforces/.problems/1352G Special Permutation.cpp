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
int n, T;
int main() {
  T = read();
  while(T --) {
    n = read(); int x = (n % 2) ? n : (n - 1);
    if(n <= 3) {
      std :: cout << "-1\n";
      continue;
    }
    for(int i = x; i >= 1; i -= 2) std :: cout << i << ' ';
    x = (n % 2) ? (n - 1) : n;
    std :: cout << "4 2 ";
    for(int i = 6; i <= x; i += 2) std :: cout << i << ' ';
    puts("");
  }
  return 0;
}