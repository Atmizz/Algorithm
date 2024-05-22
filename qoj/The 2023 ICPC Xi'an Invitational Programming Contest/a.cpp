#include <bits/stdc++.h>

using namespace std;
const int mod = 998244353;
typedef long long LL;
#define int long long
const int N = 1e7 + 20;
const int M = 1e7;

LL fac[N], inFac[N];

LL qmi(LL a, LL b) {
	LL sum = 1;
	while(b) {
		if(b & 1LL) {
			sum = sum * a % mod;
		}
		b >>= 1LL; a = a * a % mod;
	}
	return sum % mod;
}

LL C(LL n, LL m) {
	if(n < m) {
		return 0;
	}
	return fac[n] * inFac[m] % mod * inFac[n-m] % mod;
}

signed main()
{
    int n;
    cin >> n;
    fac[0] = 1;
    for(int i = 1; i <= n; ++ i) {
    	fac[i] = fac[i-1] * i % mod;
    }
    inFac[n] = qmi(fac[n], mod - 2);
    for(int i = n - 1; i >= 0; -- i) {
    	inFac[i] = inFac[i+1] * (i + 1) % mod;
    }
    vector<LL> s(n+10);
    s[0]=1;
    for(int i=1;i<=n;i++) s[i]=s[i-1]*i%mod;
    int sum=0;
    for(int x=1;x<=n;x++){
        sum=(sum+C(n-x,x-1)*s[n-x]%mod*s[x-1]%mod)%mod;
    }
    while(sum < 0) {
    	sum += mod;
    }
    cout<<(sum+mod)%mod<<endl;
}