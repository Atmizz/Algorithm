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
const int MaxN = 120;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n;
struct Node {
  std :: map <int, int> m;
  std :: string name;
  int cnt;
  double ave;
  friend bool operator < (Node a, Node b) {
    return a.cnt == b.cnt ? a.ave > b.ave : a.cnt > b.cnt;
  }
}e[MaxN];
int main() {
  n = read();
  for(int i = 1; i <= n; ++ i) {
    std :: cin >> e[i].name;
    int k = read();
    for(int j = 1; j <= k; ++ j) {
      int x = read();
      if(!e[i].m[x]) e[i].cnt ++, e[i].m[x] ++;
    }
    e[i].ave = double((double)e[i].cnt / (double)k);
  }
  std :: sort(e + 1, e + 1 + n);
  if(n == 0) {
    std :: cout << "- - -";
    return 0;
  }
  else if(n == 1) {
    std :: cout << e[1].name;
    std :: cout << " - -";
    return 0;
  }
  for(int i = 1; i <= min(2, n); ++ i)
    std :: cout << e[i].name << ' ';
  if(n >= 3) std :: cout << e[3].name;
  else if(n == 2) std :: cout << '-';
  return 0;
}