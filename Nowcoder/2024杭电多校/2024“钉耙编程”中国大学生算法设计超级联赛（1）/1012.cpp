#include<bits/stdc++.h> 
#define int long long
#define i64 long long
using namespace std;

const int mod=998244353;

i64 quickPower(i64 a, i64 b) {
  i64 sum = 1;
  while(b) {
    if(b & 1) {
      sum = sum * a % mod;
    }
    a = a * a % mod;
    b >>= 1LL;
  }
  return sum;
}

int f(int base){
  return quickPower(base,mod-2);
}

int a[2010][4];

signed main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  //预处理出所有两两矩形相交块的面积
  //块出现概率*块面积 p=c(n-1,i-1)/c(n,i)=i/n
  //-重叠概率*重叠面积 p=c(n-2,i-2)/c(n,i)=i(i-1)/n(n-1) 
  
  
  int n;
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>a[i][0]>>a[i][1]>>a[i][2]>>a[i][3];
  }
  
  //预处理:面积之和和重叠面积之和
  int s1=0,s2=0;
  for(int i=1;i<=n;i++){
    int x1=a[i][0],y1=a[i][1];//左下角 
    int x2=a[i][2],y2=a[i][3];//右上角
    s1=(s1+abs(x1-x2)*abs(y1-y2))%mod;
    for(int j=i+1;j<=n;j++){
      //看哪个点被另一个矩形包含
      int xx1=a[j][0],yy1=a[j][1];//左下角 
      int xx2=a[j][2],yy2=a[j][3];//右上角
      int fx1=max(xx1,x1),fx2=min(xx2,x2);
      int fy1=max(yy1,y1),fy2=min(yy2,y2);
      if(fx1<fx2&&fy1<fy2){
        s2=(s2+(fx2-fx1)*(fy2-fy1))%mod;
      }
    }
  } 
//  cout<<"所有面积="<<s1<<endl<<"重叠面积="<<s2<<endl;
  for(int i=1;i<=n;i++){
    int p1=(i*f(n))%mod;
    int p2=(((i*(i-1))%mod*f(n))%mod*f(n-1))%mod;
    int ans=((p1*s1)%mod-(p2*s2)%mod)%mod;
    while(ans<0)ans=(ans+mod)%mod;
    cout<<ans<<endl; 
  }
}