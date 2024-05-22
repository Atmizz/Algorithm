#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <cstdlib>
#include <map>
#include <set>
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
int n, n1, n2;
ll ans;
int main() {
  while(1) {
    n1 = read(); n2 = read(); n = read();
    if(!n1 && !n2 && !n) break; ans = 0;
    std :: priority_queue <int, std :: vector<int>, std :: less<int> > Q1;
    std :: priority_queue <int, std :: vector<int>, std :: greater<int> > Q2;
    for(int i = 1; i <= n; ++ i) {
      int x = read(); ans += x;
      Q1.push(x); Q2.push(x);
      if(Q1.size() > n2) Q1.pop();
      if(Q2.size() > n1) Q2.pop();
    }ll n3 = n - n1 - n2;
    while(!Q1.empty()) ans -= Q1.top(), Q1.pop();
    while(!Q2.empty()) ans -= Q2.top(), Q2.pop();
    printf("%.6lf\n", 1.0 * ans / n3);
  }
  return 0;
}