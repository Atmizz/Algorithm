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
const int MaxN = 1e6 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, Next[MaxN], cnt, num[MaxN];
char str[MaxN];
void getNext() {
  memset(Next, 0, sizeof Next);
  int i = 0, j = - 1; Next[0] = -1;
  while(i < n) {
    if(j == -1 || str[i] == str[j]) {
      if(str[i] == str[j]) {
        num[j] ++;
      }
      i ++, j ++, Next[i] = j, num[i] ++;
    }
    else j = Next[j];
  }
}
int main() {
  while(n = read() && n != 0) {
    scanf("%s", str); getNext();
    std :: cout << "Test case #" << cnt << '\n';
    for(int i = 1; i <= n; ++ i)
      if(Next[i] > 0) printf("%d %d\n" );
  }
  return 0;
}