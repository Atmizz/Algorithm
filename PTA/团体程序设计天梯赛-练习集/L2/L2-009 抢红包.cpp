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
const int MaxN = 1e4 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n;
struct Node {
  int id, cnt;
  double money;
  Node() {money = 0; cnt = 0;}
  friend bool operator < (Node a, Node b) {
    if(a.money == b.money) return a.cnt == b.cnt ? a.id < b.id : a.cnt > b.cnt;
    return a.money > b.money;
  }
}a[MaxN];
int main() {
  n = read();
  for(int i = 1; i <= n; ++ i) {
    int k = read(); a[i].id = i;
    for(int j = 1; j <= k; ++ j) {
      int x = read(); double y; scanf("%lf", &y);
      a[i].money -= y; a[x].money += y; a[x].cnt ++;
    }
  } std :: sort(a + 1, a + 1 + n);
  for(int i = 1; i <= n; ++ i)
    printf("%d %.2lf\n", a[i].id, a[i].money / 100.0);
  return 0;
}