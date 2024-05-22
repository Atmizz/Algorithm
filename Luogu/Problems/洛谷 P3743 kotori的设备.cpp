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
int n;
struct Node
{
  double a, b, t;
  friend bool operator < (Node a, Node b) {
    return a.t < b.t;
  }
}e[MaxN];

double q;
bool Check(double x) {
  double T = x;
  for(int i = 1; i <= n; ++ i) {
    if(e[i].t > x) continue;
    T -= ((x - e[i].t) * e[i].a / q);
    if(T < 0) return 0;
  } return 1;
}
int main() {
	n = read(); scanf("%lf", &q); double sum = 0;
  for(int i = 1; i <= n; ++ i) scanf("%lf %lf", &e[i].a, &e[i].b), e[i].t = e[i].b / e[i].a, sum += e[i].a;
  if(sum <= q) {printf("-1"); return 0;}
  std :: sort(e + 1, e + 1 + n);
  double l = 0, r = 1e10, mid;
  while(r - l > 1e-6) {
    mid = (l + r) / 2.00;
    if(Check(mid)) l = mid;
    else r = mid;
  } printf("%.10lf", l);
	return 0;
}
/*
delt = (x - e[i].t) 
chong * q / a = t
*/