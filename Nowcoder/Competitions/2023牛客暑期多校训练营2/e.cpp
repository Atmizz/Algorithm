#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        LL x;cin>>x;
        bool fl=false;
        for(int k=0;x<=9223372036854775807/(LL)pow(10,k);k++)
        {
            LL kk=pow(10,k);
            LL z = x*kk;
            LL ans = sqrt(z);
            //cout<<z<<' '<<ans<<' '<<ans*ans<<' '<<(ans+1)*(ans+1)/kk<<endl;
            if(ans<=1e9&&ans*ans==z)
            {
                cout<<ans<<endl;
                fl = true;
                break;
            }
            else
            {
                if(ans<1e9&&(ans+1)*(ans+1)/kk==x) 
                {
                    cout<<ans+1<<endl;
                    fl = true;
                    break;
                }
            }
        }
        if(!fl) cout<<-1<<endl;
    }
}