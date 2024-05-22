#include <bits/stdc++.h>
//#pragma GCC optimize ("O3")
#define nl '\n'
#define ls k << 1
#define rs k << 1 | 1
#define pb push_back
#define PII std :: pair <int, int>
#define PIL std :: pair <int, i64>
#define PLL std :: pair <i64, i64>
#define DEB std :: cout << "ok" << endl;
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
typedef unsigned long long ull;
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
std :: mt19937 rd(114514);
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
// const int N = ;
class Solution {
public:
    long long gcd(long long a, long long b) {
        return !b ? a : gcd(b, a % b);
    }
    long long findKthSmallest(std :: vector<int>& coins, int k) {
        long long l = 1, r = 50000000000, ans;
        std :: vector <int> v;
        std :: sort(coins.begin(), coins.end());
        for(int i = 0; i < (int) coins.size(); ++ i) {
            bool ok = true;
            for(int j = 0; j < i; ++ j) {
                if(coins[i] % coins[j] == 0) {
                    ok = false;
                    break;
                }
            }
            if(ok) {
                v.push_back(coins[i]);
            }
        }
        int n = v.size();
        auto check = [&](long long x) {
            long long cnt = 0;
            for(auto y : v) {
                cnt += x / y;
            } 
            for(int _ = 1; _ < 1 << n; ++ _) {
                int cnt = 0;
                for(int j = 0; j < n; ++ j) {
                    if(_ >> j & 1) {
                        cnt ++;
                    }
                }
                if(cnt == 1) {
                    continue ;
                }
                vector <long long> res;
                for(int i = 0; i < n; ++ i) {
                    if(_ >> i & 1) {
                        res.push_back(v[i]);
                    }
                }
                for(int i = 1; i < (int)res.size(); ++ i) {
                    res[0] = res[0] * res[i] / gcd(res[0], res[1]);
                }
                cnt -= x / res[0] * (cnt - 1);
            }
            return cnt >= k;
        };
        while(l <= r) {
            long long mid = (l + r) / 2;
            if(check(mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if(v.empty()) {
            return -1;
        }
        return ans;
    }
};
void solve() {
    std :: cout << Solution.findKthSmallest();
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