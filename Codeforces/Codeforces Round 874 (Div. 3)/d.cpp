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
const int MaxN = 2010;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int T, n, a[MaxN];
std :: vector <int> ans;
void Compare(int l, int r) {
  std :: vector <int> b;
  for(int i = r + 1; i <= n; ++ i) b.push_back(a[i]);
  for(int i = r; i >= l; -- i) b.push_back(a[i]);
  for(int i = 1; i < l; ++ i) b.push_back(a[i]);
  if(b > ans) ans = b;
}
int main() {
  T = read();
  while(T --) {
    n = read(); ans.clear();
    for(int i = 1; i <= n; ++ i) a[i] = read();
    for(int i = 2; i <= n; ++ i) ans.push_back(a[i]);
    ans.push_back(a[1]);
    int pos = 1;
    for(int i = 1; i <= n; ++ i)
      if(a[i] == n) {
        pos = i;
        break;
      }
    if(pos > 1 && pos <= n) {
      for(int i = 1; i < pos; ++ i)
        Compare(i, pos-1);
      Compare(pos, pos);
    }
    else {
      int poss = 1;
      for(int i = 2; i <= n; ++ i)
        if(a[i] == n - 1) poss = i;
      for(int i = 1; i < poss; ++ i)
        Compare(i, poss-1);
      Compare(poss, poss);
    }
    for(auto x : ans) printf("%d ", x);
    puts("");
  }
  return 0;
}
/*
1
5
2 3 1 5 4


*/