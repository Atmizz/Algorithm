#include<bits/stdc++.h>
#define int long long
const int INF = 1e9 + 7;
int T, k, p;
int check(int x) {
	if(x + x / p < p) return x;
  return x / p * p + check(x % p + x / p);
}
signed main() {
    std :: cin >> T;
//    std :: cout << check(3) << '\n';
    while(T --) {
        std :: cin >> p >> k;
        if(k == 0) {
            std :: cout << 0 << '\n';
            continue;
        }
        if(p == 1) {
            std :: cout << 1 << '\n';
            continue;
        }
        int l = 0, r = 1e9 + 10;
        while(l < r) {
            int mid = (l + r) >> 1;
            if(check(mid) >= k) r = mid;
            else l = mid + 1;
        }
        std :: cout << r << '\n';
    }
    return 0;
}