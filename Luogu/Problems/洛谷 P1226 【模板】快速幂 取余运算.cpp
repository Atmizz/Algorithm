#include <bits/stdc++.h>
#define gc getchar()
#define ll long long
inline ll read() {
	ll s = 0, f = 1; char ch = gc;
	for(; ch < '0' || ch > '9'; ch = gc) if(ch == '-') f = -1;
	for(; ch >= '0' && ch <= '9'; ch = gc)
		s = (s << 1) + (s << 3) + (ch ^ 48);
	return s * f;
}
const int MaxN = 2200;
const int Mod = 1e9 + 7;
ll p, a, b, B, A;
ll Pow() {
	ll Sum = 1;
	while(b) {
		if(b & 1) Sum = (Sum * a) % p;
		a = (a * a) % p; b >>= 1;
	} return Sum;
}
int main() {
	a = A = read(), b = B = read(), p = read();
	printf("%lld^%lld mod %lld=%lld", A, B, p, Pow());
}