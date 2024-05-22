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
int n, m, team[MaxN], pos[302], cnt, Now;
std :: queue <int> q[MaxN];
int main() {
  n = read(); m = read();
  memset(pos, -1, sizeof pos);
  for(int i = 0; i < n; ++ i) team[i] = read();
  int T = read();
  while(T --) {
    std :: string str; int x;
    std :: cin >> str;
    if(str == "push") {
      x = read();
      if(pos[team[x]] == -1 || pos[team[x]] < Now) {
        pos[team[x]] = cnt, cnt ++;
        q[pos[team[x]]].push(x);
        // std :: cout << "pos : " << pos[team[x]] << '\n';
      } else q[pos[team[x]]].push(x);
    } else {
      printf("%d\n", q[Now].front()); q[Now].pop();
      // std :: cout << Now << " " << q[Now].size() << "\n";
      if(q[Now].empty()) Now ++;
    }
  }
  return 0;
}