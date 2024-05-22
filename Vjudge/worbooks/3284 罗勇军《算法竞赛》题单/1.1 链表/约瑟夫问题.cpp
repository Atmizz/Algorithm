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
const int MaxN = 110;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m, num, nowNum = 1;
struct Node {
  int Id;
  Node *front, *back;
}a[MaxN];
void Work(Node *now) {
  now = now->front;
  now->back = now->back->back;
  now = now->back;
  now->front = now->front->front;
}
int main() {
  n = read(); m = read();
  for(int i = 2; i < n; ++ i) a[i].Id = i, a[i].back = a + i + 1, a[i].front = a + i - 1;
  a[1].Id = 1; a[1].back = a + 2; a[1].front = a + n;
  a[n].Id = n; a[n].back = a + 1; a[n].front = a + n - 1;
  Node *now = a + 1;
  while(num < n) {
    if(nowNum == m) {
      printf("%d ", now->Id);
      Work(now);
      nowNum = 1; num ++;
      now = now->back;
    } else nowNum ++, now = now->back;
  }
  return 0;
}