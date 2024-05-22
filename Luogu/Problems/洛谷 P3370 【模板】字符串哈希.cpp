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
const int MaxN = 1e5+300;
const int Mod1 = 1e9 + 7;
const int Mod2 = 19260817;
const int INF = 2147483647;
int n, len, ans;
char ch[MaxN >> 4];
struct Hash{
  int hash1, hash2;
  friend bool operator < (Hash a, Hash b) {
    return a.hash1 == b.hash1 ? a.hash2 < b.hash2 : a.hash1 < b.hash1;
  }
}str[MaxN];
int main() {
  n = read();
  for(int i = 1; i <= n; ++ i) {
    scanf("%s", ch + 1); len = strlen(ch + 1);
    for(int j = 1; j <= len; ++ j) {
      str[i].hash1 = (str[i].hash1 * 10 % Mod1 + int(ch[j]) * j % Mod1) % Mod1;
      str[i].hash2 = (str[i].hash2 * 10 % Mod2 + int(ch[j]) * j % Mod2) % Mod2;
    }
  } std :: sort(str + 1, str + 1 + n);
  for(int i = 1; i <= n; ++ i)
    if(str[i].hash1 != str[i-1].hash1 || str[i].hash2 != str[i-1].hash2) ans ++;
  printf("%d", ans);
  return 0;
}