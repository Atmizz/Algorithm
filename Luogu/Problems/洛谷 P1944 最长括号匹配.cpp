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
const int MaxN = 1e6+300;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int ans, dp[MaxN], max_k, K;
std :: string str;
int main() {
  std :: cin >> str;
  int len = str.length();
  for(int i = 1; i < len; ++ i) {
    if((str[i] == ')' && str[i-dp[i-1]-1] == '(') || (str[i] == ']' && str[i-dp[i-1]-1] == '['))
      dp[i] = dp[i-1] + 2 + dp[i-dp[i-1]-2];
    if(max_k < dp[i]) max_k = dp[i], K = i;
//    printf("%d %d\n", i, dp[i]);
  }
  for(int i = K-dp[K]+1; i <= K; ++ i)
    std :: cout << str[i];
  return 0;
}