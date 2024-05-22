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
const int MaxN = 5e5 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int L, n, k, a[MaxN], b[MaxN];
bool Check(int x) {
 // if(x > b[n]) return 0;
  int N = k;
  for(int i = n; i >= 2; -- i) {
  //  if(b[i] % x != 0) return 0;
    N -= (b[i] / x - 1);
    if(b[i] % x != 0) N --;
    if(N < 0) return 0;
  }  
//std :: cout << x << " " << N << '\n';
  return 1;
}
int main() {
	L = read(), n = read(), k = read(); a[1] = read();
  for(int i = 2; i <= n; ++ i) a[i] = read(), b[i] = a[i] - a[i-1];
  std :: sort(b + 2, b + 1 + n);
  int l = 1, r = L, mid;
  while(l < r) {
    mid = (l + r) >> 1;
    if(Check(mid)) r = mid;
    else l = mid + 1;
  } printf("%d", l);
	return 0;
}
/*
101 2 2
0 101
0 34 68 101
*/