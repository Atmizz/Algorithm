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
struct Student {
  std :: string Name;
  int Final, Class, Essay, Money, Num;
  bool Leader = 0, West = 0;
  friend bool operator < (Student a, Student b) {
    if(a.Money == b.Money) return a.Num < b.Num;
    return a.Money > b.Money;
  }
}a[MaxN];
int n, ans;
int main() {
  n = read();
  for(int i = 1; i <= n; ++ i) {
    std :: cin >> a[i].Name; char ch;
    a[i].Final = read(); a[i].Class = read(); a[i].Num = i;
    std :: cin >> ch;
    if(ch == 'Y') a[i].Leader = 1;
    std :: cin >> ch;
    if(ch == 'Y') a[i].West = 1;
    a[i].Essay = read();
    if(a[i].Final > 80 && a[i].Essay >= 1) a[i].Money += 8000;
    if(a[i].Final > 85 && a[i].Class > 80) a[i].Money += 4000;
    if(a[i].Final > 90) a[i].Money += 2000;
    if(a[i].Final > 85 && a[i].West) a[i].Money += 1000;
    if(a[i].Class > 80 && a[i].Leader) a[i].Money += 850;
    ans += a[i].Money;
  }
  std :: sort(a + 1, a + 1 + n);
  std :: cout << a[1].Name << '\n';
  std :: cout << a[1].Money << '\n';
  std :: cout << ans;
}