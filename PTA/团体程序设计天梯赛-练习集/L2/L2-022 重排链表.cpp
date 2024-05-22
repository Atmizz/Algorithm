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
const int MaxN = 1e5 + 20;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n;
std :: map <std :: string, int> id;
struct Node {
  std :: string Address, Next;
  int val;
}a[MaxN];
std :: vector <Node> ans;
int main() {
  std :: string Begin; std :: cin >> Begin; n = read();
  for(int i = 1; i <= n; ++ i) {
    std :: cin >> a[i].Address >> a[i].val >> a[i].Next;
    id[a[i].Address] = i;
  } Node p = (Node) {a[id[Begin]].Address, a[id[Begin]].Next, a[id[Begin]].val};
  ans.push_back({"-", "-", -1});
  while(1) {
    ans.push_back({p.Address, p.Next, p.val});
    if(p.Next == "-1") break;
    p = a[id[p.Next]];
  }
  int pos = n;
  if(n > 2) {while(1) {
      std :: cout << ans[pos].Address << ' ' << ans[pos].val << ' ' << ans[n-pos+1].Address << '\n';
      std :: cout << ans[n-pos+1].Address << ' ' << ans[n-pos+1].val << ' ' << ans[pos-1].Address << '\n';
      if(pos == (n >> 1) + 2) break;
      pos --;
  } pos --;}
  if(n % 2)
    std :: cout << ans[pos].Address << ' ' << ans[pos].val << ' ' << -1;
  else {
    std :: cout << ans[pos].Address << ' ' << ans[pos].val << ' ' << ans[n-pos+1].Address << '\n';
    std :: cout << ans[n-pos+1].Address << ' ' << ans[n-pos+1].val << ' ' << -1;
  }
  return 0;
}