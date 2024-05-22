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
#define ls k << 1
#define rs k << 1 | 1
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
int Num[27], ans, len, maxn, minn=INF;
std :: string str;
bool Prime(int x) {
  if(x == 0 || x == 1) return false;
  for(int i = 2; i <= sqrt(x); ++ i)
    if(x % i == 0) return false;
  return true;
}
int main() {
  std :: cin >> str; len = str.length();
  for(int i = 0; i < len; ++ i) Num[str[i]-'a'+1] ++;
  for(int i = 1; i <= 26; ++ i) {
    maxn = max(Num[i], maxn);
    if(Num[i] != 0) minn = min(Num[i], minn);
  }
  if(Prime(maxn - minn)) printf("Lucky Word\n%d", maxn - minn);
  else printf("No Answer\n0");
  return 0;
}