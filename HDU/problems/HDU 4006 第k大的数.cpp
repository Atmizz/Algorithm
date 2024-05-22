#include <bits/stdc++.h>
#define gc getchar()
#define ll long long
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
const int MaxN = 1e6+300;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, k;
int main() {
  while(~scanf("%d %d", &n, &k)) {
    std :: priority_queue <int, std :: vector <int>, std :: greater <int> > q;
    for(int i = 1; i <= n; ++ i) {
      char ch; std :: cin >> ch;
      if(ch == 'I') {
        int x = read();
        if(q.size() < k) q.push(x);
        else
          if(x > q.top()) q.pop(), q.push(x);
      } else printf("%d\n", q.top());
    }
  }
  return 0;
}