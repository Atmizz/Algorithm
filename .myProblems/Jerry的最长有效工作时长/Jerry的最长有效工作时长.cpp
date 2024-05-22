#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define root 1,n,1
#define ls (rt<<1)
#define rs (rt<<1|1)
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
inline ll read() {
	ll x=0,w=1;char ch=getchar();
	for(;ch>'9'||ch<'0';ch=getchar()) if(ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*w;
}
//inline void print(__int128 x){
//	if(x<0) {putchar('-');x=-x;}
//	if(x>9) print(x/10);
//	putchar(x%10+'0');
//}
#define maxn 1000000
#define int long long
const double eps=1e-8;
#define	int_INF 0x3f3f3f3f
#define ll_INF 0x3f3f3f3f3f3f3f3f
int d[maxn],a[maxn];
struct Segment_tree{
	int l,r,GCD;
}tree[maxn<<2];
void pushup(int rt) {
	tree[rt].GCD=gcd(tree[ls].GCD,tree[rs].GCD);
}
void build(int l,int r,int rt) {
	tree[rt].l=l;tree[rt].r=r;
	if(l==r) {
		tree[rt].GCD=abs(d[l]);
		return ;
	}
	int mid=(l+r)>>1;
	build(lson);build(rson);
	pushup(rt);
}
int query(int l,int r,int rt) {
//	cout<<l<<" "<<r<<" "<<rt<<endl;
	if(tree[rt].l==l&&tree[rt].r==r) {
		return tree[rt].GCD;
	}
	int mid=(tree[rt].l+tree[rt].r)>>1;
	if(r<=mid) return query(l,r,ls);
	else if(l>mid) return query(l,r,rs);
	else return gcd(query(l,mid,ls),query(mid+1,r,rs));
}
signed main() {
	freopen("xr2.in", "r", stdin);
	freopen("xr2.out", "w", stdout);
	int T=1;
	while(T--) {
		int n=read();
		for(int i=1;i<=n;i++) {
			a[i]=read();
			d[i]=a[i]-a[i-1];
		}
		if(n==1) {
			cout<<1<<endl;
			continue;
		}
		build(root);
		int ans=2;int l=2,r=2;
		if(abs(d[2])==1) {
			ans=1;
		}
		while(r<n) {
			r++;
//			cout<<l<<" "<<r<<endl;
			while(query(l,r,1)==1) {
				l++;
				if(l==r) break;
			}
			if(query(l,r,1)==1) ans=max(ans,r-l+1);
			else ans=max(ans,r-l+1+1);
		} 
		cout<<ans<<endl;
	}
	return 0;
}