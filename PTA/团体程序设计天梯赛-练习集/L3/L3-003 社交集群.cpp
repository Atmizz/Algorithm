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
const int MaxN = 1e3 + 20;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int in[MaxN][MaxN], pa[MaxN], n;
std :: vector <int> ans;
int Find(int x) {
  return x == pa[x] ? pa[x] : pa[x] = Find(pa[x]);
}
int main() {
  n = read();
  for(int i = 1; i <= n; ++ i) {
    int k = read(); pa[i] = i;
    for(int j = 1; j <= k; ++ j) {
      int x = read();
      in[x][++in[x][0]] = i;
    }
  }
  for(int i = 1; i <= 1000; ++ i)
    if(in[i][0]) {
      int fa = Find(in[i][1]);
      for(int j = 2; j <= in[i][0]; ++ j) {
        int son = Find(pa[in[i][j]]);
        pa[son] = fa;
      }
    }
  for(int i = 1; i <= n; ++ i) pa[i] = Find(pa[i]);
  for(int i = 1; i <= n; ++ i) {
    int cnt = 1;
    if(pa[i] == -1) continue;
    for(int j = i + 1; j <= n; ++ j) {
      if(pa[j] == -1) continue;
      if(pa[j] == pa[i]) cnt ++, pa[j] = -1;
    }
    ans.push_back(cnt);
  }
  std :: sort(ans.begin(), ans.end());
  std :: reverse(ans.begin(), ans.end());
  printf("%d\n%d", ans.size(), ans[0]);
  for(int i = 1; i < ans.size(); ++ i) printf(" %d", ans[i]);
  return 0;
}