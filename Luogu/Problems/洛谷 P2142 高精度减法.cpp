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
const int MaxN = 1e5+300;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
std :: string str1, str2, ans;
int main() {
  std :: cin >> str1 >> str2;
  int len1 = str1.length(), len2 = str2.length();
  if(len1 < len2) for(int i = 1; i <= len2 - len1; ++ i) str1 = "0" + str1;
  else for(int i = 1; i <= len1 - len2; ++ i) str2 = "0" + str2;
  if(str1 < str2) printf("-"), std :: swap(str1, str2);
  int len = str1.length(), x = 0;
  for(int i = len - 1; i >= 0; -- i) {
    int a = str1[i] - '0', b = str2[i] - '0', c = a - b - x;
    if(c < 0) c += 10, x = 1;
    else x = 0;
    ans = char(c + '0') + ans;
  }
  int num = 0;
  while(ans[num] == '0' && num != ans.length() - 1) ++ num;
  for(int i = num; i < ans.length(); ++ i) std :: cout << ans[i];
  return 0;
}