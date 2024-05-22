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
int a[MaxN], n, m, block, blk[MaxN], jump[MaxN], step[MaxN];
struct Node {
  int l, r;
}b[MaxN];
void update(int l, int r) {
  for(int i = r; i >= l; -- i)
    if(i + a[i] > b[blk[i]].r)
      jump[i] = i + a[i], step[i] = 1;
    else jump[i] = jump[i+a[i]], step[i] = step[i+a[i]] + 1;
}
int ask(int x) {
  int sum = 0;
  while(x <= n) {
    sum += step[x];
    x = jump[x];
    //  std :: cout << "x < " << x << '\n';
  } return sum;
}
int main() {
  n = read(); block = sqrt(n);
  for(int i = 1; i <= n; ++ i) a[i] = read();
  for(int i = 1; i <= n; ++ i) blk[i] = (i - 1) / block + 1;
  for(int i = 1; i <= blk[n]; ++ i)
    b[i].l = (i - 1) * block + 1, b[i].r = i * block;
  b[blk[n]].r = n;
  update(1, n); m = read();
  for(int i = 1; i <= m; ++ i) {
    int opt = read(), x = read(), y; x ++;
    if(opt == 1) printf("%d\n", ask(x));
    else y = read(), a[x] = y, update(b[blk[x]].l, b[blk[x]].r);
  }
  return 0;
}