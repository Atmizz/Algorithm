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
const int MaxN = 0;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, t;
bool isPrime(int x) {
  for(int i = 2; i <= sqrt(x); ++ i)
    if(x % i == 0) return false;
  return true;
}
int devide(int x) {
  int sum = 0, res = x;
  for(int i = 2; i <= sqrt(x); ++ i) {
    int cnt = 0;
    while(res % i == 0) cnt ++, res /= i;
    sum += cnt;
  } if(res) sum += 1;
  return sum;
}
int main() {
  t = read();
  while(t --) {
    n = read();
    if(n <= 4) {
      printf("0\n");
      continue;
    }
    if(isPrime(n)) {
      printf("1\n");
      continue;
    }
    int res = devide(n);
    printf(res >= std :: log2(n) ? "0\n" : "1\n");
  }
  return 0;
}