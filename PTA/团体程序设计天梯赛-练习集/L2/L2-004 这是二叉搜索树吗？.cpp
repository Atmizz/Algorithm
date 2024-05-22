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
const int MaxN = 1e5;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, maxDepth, val[MaxN];
struct Node {
  int l, r, val, maxx, minn;
  Node() {l = r = val = 0;}
}t[MaxN << 2];
void dfs1(int k, int val, int depth) {
  t[k].val = val; t[k].maxx = -INF; t[k].minn = INF;
  if(depth == maxDepth) {
    t[k].maxx = t[k].minn = val;
    return ;
  }
  t[k].l = ls; dfs1(ls, read(), depth + 1);
  t[k].r = rs; dfs1(rs, read(), depth + 1);
  t[k].maxx = max(max(t[ls].maxx, t[rs].maxx), t[k].maxx);
  t[k].minn = min(min(t[ls].minn, t[rs].minn), t[k].minn);
  // std :: cout << k << ' ' << t[k].maxx << ' ' << t[k].minn << '\n';
}
bool check1(int k, int depth) {
  if(depth == maxDepth) return true;
  // std :: cout << t[ls].maxx << ' ' << t[k].val << ' ' << t[rs].minn << ' ' << depth << '\n';
  if(t[k].val <= t[ls].maxx || t[k].val > t[rs].minn) return false;
  return (check1(ls, depth + 1) && check1(rs, depth + 1));
}
bool check2(int k, int depth) {
  if(depth == maxDepth) return true;
  if(t[k].val > t[ls].minn || t[k].val <= t[rs].maxx) return false;
  return (check2(ls, depth + 1) && check2(rs, depth + 1));
}
void print(int k) {
  if(t[k].l) print(t[k].l), print(t[k].r);
  if(k != 1) printf("%d ", t[k].val);
}
int main() {
  n = read(); maxDepth = std :: log2(n + 1);
  if(1 << maxDepth != n + 1) {
    printf("NO");
    return 0;
  }
  dfs1(1, read(), 1);
  if(check1(1, 1) || check2(1, 1)) printf("YES\n"), print(1), printf("%d", t[1].val);
  else printf("NO");
  return 0;
}