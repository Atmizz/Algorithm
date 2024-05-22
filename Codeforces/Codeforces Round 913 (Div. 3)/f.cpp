#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define PII std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1e5 + 20;
int a[N], n;
int solve1() {
	std :: deque <int> s;
	int ans = 0;
	for(int i = 1; i <= n; ++ i)
		s.push_back(a[i]);
	while(1) {
		int x = s.back(); s.pop_back();
		int y = s.back(); s.pop_back();
		if(x <= s.front()) {
			s.push_front(x);
			s.push_back(y);
		} else {
			s.push_back(y);
			s.push_back(x);
			break;
		}
		ans ++;
//		if(ans == n); break;
	}
	std :: vector <int> vec;
	while(s.size()) vec.push_back(s.front()), s.pop_front();
	int cnt0 = 0, cnt1 = 0;
	if(vec[0] > vec[n-1]) cnt0 ++;
	if(vec[0] < vec[n-1]) cnt1 ++; 
	for(int i = 1; i < n; ++ i) {
		if(vec[i] > vec[i-1]) cnt0 ++;
		if(vec[i] < vec[i-1]) cnt1 ++;
	}
	// deb(ans);
	if(cnt1 >= 2 && cnt0 >= 2) 
		return -1;
	for(int i = 1; i < n; ++ i)
		if(vec[i] < vec[i-1]) return INF;
	deb(ans);
	return std :: min(ans, n - ans + 1);
}
int solve2() {
	std :: deque <int> s;
	int ans = 0;
	for(int i = 1; i <= n; ++ i)
		s.push_back(a[i]);
	while(1) {
		int x = s.back(); s.pop_back();
		int y = s.back(); s.pop_back();
		if(x >= s.front()) {
			s.push_front(x);
			s.push_back(y);
		} else {
			s.push_back(y);
			s.push_back(x);
			break;
		}
		ans ++;
	}
	std :: vector <int> vec;
	while(s.size()) vec.push_back(s.front()), s.pop_front();
	int cnt0 = 0, cnt1 = 0;
	if(vec[0] > vec[n-1]) cnt0 ++;
	if(vec[0] < vec[n-1]) cnt1 ++; 
	for(int i = 1; i < n; ++ i) {
		if(vec[i] > vec[i-1]) cnt0 ++;
		if(vec[i] < vec[i-1]) cnt1 ++;
	}
	if(cnt1 >= 2 && cnt0 >= 2) 
		return -1;
	for(int i = 1; i < n; ++ i)
		if(vec[i] > vec[i-1]) return INF;
	deb(ans + 1);
	return std :: min(ans + 1, n - ans);
}
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i)
		std :: cin >> a[i];

	if(n == 1) {
		std :: cout << '0' << '\n';
		return ;
	}
	if(n == 2) {
		if(a[1] <= a[2])
			std :: cout << 0 << '\n';
		else std :: cout << 1 << '\n';
		return ;
	}
	
	std :: cout << std :: min(solve1(), solve2()) << '\n';
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	std :: cin >> T; 
	while(T --) solve();
	return 0;
}
