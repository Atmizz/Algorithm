#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define PII std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
std :: mt19937 rd(114514);
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
template <class T>
T max(T a, T b) {
	return a > b ? a : b;
}
template <class T>
T min(T a, T b) {
	return a < b ? a : b;
}
template <class T>
T abs(T a) {
	return a < 0 ? -a : a;
}
// const int N = ;
struct Mathematic {
	// determine whether it is a prime number
	// O(sqrt(N))
	template <class T>
	bool isPrime(T x) {
		if(x < 2) {
			return false;
		}
		for(T i = 2; i <= sqrt(x); ++ i) {
			if(x % i == 0) {
				return false;
			}
		}
		return true;
	}
	// decomposed into prime factors
	// O(sqrt(N))
	template <class T> 
	auto devide(T x) {
		std :: vector < std :: pair <T, T> > v;
		for(T i = 2; i <= x / i; ++ i) {
			T sum = 0;
			while(x % i == 0) {
				x /= i;
				sum ++;
			}
			if(sum) {
				v.push_back(MP(i, sum));
			}
		}
		if(x) {
			v.push_back(MP(x, 1));
		}
		return v;
	}
	// Euler Sieve
	// O(N)
	template <class T>
	auto EulerSieve(std :: vector <T> &v) {
		T n = v.size() - 1, cnt = 0;
		std :: vector <T> prime;
		for(T i = 2; i <= n; ++ i) {
			if(!v[i]) {
				prime.push_back(i);
				cnt ++;
			}
			for(T j = 0; j < cnt && i * prime[j] <= n; ++ j) {
				v[i*prime[j]] = 1;
				if(i % prime[j] == 0) {
					break;
				}
			}
		}
		return prime;
	}
	// Find the divisors
	// O(sqrt(N))
	template <class T>
	auto getDivisors(T x) {
		std :: vector <T> v;
		for(T i = 1; i <= x / i; ++ i) {
			if(x % i == 0) {
				v.push_back(i);
				if(i * i != x) {
					v.push_back(x / i);
				}
			}
		}
		std :: sort(v.begin(), v.end());
		return v;
	}
	// Euclidean algorithm
	// O(log(N))
	i64 gcd(i64 a, i64 b) {
		return !b ? a : gcd(b, a % b);
	}
	// exEuclidean algorithm
	i64 exgcd(i64 a, i64 b, i64 &x, i64 &y) {
		if(b == 0) {
			x = 1;
			y = 0;
			return a;
		}
		i64 d = exgcd(b, a % b, x, y);
		i64 tmp = x;
		x = y;
		y = tmp - (a / b) * y;
		return d;
	}
	// Euler's totient function
	// O(sqrt(N))
	i64 EulerFuction(i64 x) {
		i64 res = x;
		for(int i = 2; i * i <= x; ++ i) {
			if(x % i == 0) {
				res = res / i * (i - 1);
				while(x % i == 0) {
					x /= i;
				}
			}
		}
		if(x > 1) {
			res = res / x * (x - 1);
		}
		return res;
	}
	// get Euler's totient function by Euler Sieve
	// O(N)
	template <class T>
	auto getEulersBySieve(std :: vector <T> &v) {
		T n = v.size() - 1, cnt = 0;
		std :: vector <T> phi(n+1), prime;
		phi[1] = 1;
		for(T i = 2; i <= n; ++ i) {
			if(!v[i]) {
				prime.push_back(i);
				phi[i] = i - 1;
				cnt ++;
			}
			for(T j = 0; j < cnt && i * prime[j] <= n; ++ j) {
				v[i*prime[j]] = 1;
				if(i % prime[j] == 0) {
					phi[i*prime[j]] = phi[i] * prime[j];
					break;
				}
				phi[i*prime[j]] = phi[i] * (prime[j] - 1);
			}
		}
		return phi;
	}
	// Binary Exponentiation
	// O(log(N))
	i64 quickPower(i64 a, i64 b) {
		i64 fac = 1;
		while(b) {
			if(b & 1LL) {
				fac = fac * a;
			}
			b >>= 1LL;
			a = a * a;
		}
		return fac;
	}
	i64 quickPower(i64 a, i64 b, i64 p) {
		i64 fac = 1;
		while(b) {
			if(b & 1LL) {
				fac = fac * a % p;
			}
			b >>= 1LL;
			a = a * a % p;
		}
		return fac % p;
	}
	// bignum calc + -
	// 0 -> m : low -> high
	auto strToVec(std :: string &s) {
		std :: vector <int> a;
		for(int i = s.length() - 1; i >= 0; -- i) {
			a.push_back(s[i]-48);
		}
		return a;
	}
	auto vecToStr(std :: vector <int> &v) {
		std :: string s = "";
		for(int i = v.size() - 1; i >= 0; -- i) {
			if(v[i] == 10) {
				s += '-';
			} else {
				s += char(v[i] + 48);
			}
		}
		return s;
	}
	auto add(std :: string &s1, std :: string &s2) {
		std :: vector <int> a = strToVec(s1), b = strToVec(s2);
		int x = 0;
		std :: vector <int> c;
		for(int i = 0; i < max(a.size(), b.size()); ++ i) {
			if(i < a.size()) {
				x += a[i];
			}
			if(i < b.size()) {
				x += b[i];
			}
			c.push_back(x % 10);
			x /= 10;
		}
		if(x) {
			c.push_back(x);
		}
		return c;
	}
	auto sub(std :: string &s1, std :: string &s2) {
		bool ok = false;
		if((s1 < s2 && s1.size() == s2.size()) || s1.size() < s2.size()) {
			std :: swap(s1, s2);
			ok = true;
		}
		std :: vector <int> c, a = strToVec(s1), b = strToVec(s2);
		int x = 0;
		for(int i = 0; i < a.size(); ++ i) {
			x = a[i] - x;
			if(i < b.size()) {
				x -= b[i];
			}
			c.push_back((x + 10) % 10);
			if(x < 0) {
				x = 1;
			} else {
				x = 0;
			}
		}
		while(c.size() > 1 && c.back() == 0) {
			c.pop_back();
		}
		if(ok) {
			c.push_back(10);
		}
		return c;
	}
	// Find inverse element by pow
	// make sure p is a prime number
	i64 getInv(i64 x, i64 p) {
		return quickPower(x, p-2, p);
	}
}Math;
void solve() {
	std :: string s1, s2;
	std :: cin >> s1 >> s2;
	std :: vector <int> c = Math.add(s1, s2);
	std :: cout << Math.vecToStr(c);
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int _ = 1;
	//std :: cin >> _; 
	while(_ --) solve();
	return 0;
}