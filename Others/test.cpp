#include<iostream>
using namespace std;
main ()
{int i,j,n;
cin>>n;    
 for(i=1;i<=(n+1);i++)   
 {for(j=1;j<=(n-i+1);j++)cout<<' ';
    for(j=1;j<=(2*(i-1)+1);j++) cout<<'*';
    cout<<endl;
 }
    for(i=(n+2);i<=(2*(n-1)+1);i++)
    {for(j=(2*(n-1)+1);j>=(n-(i+1)/2);j--)cout<<' ';
      for(j=2*n;j>=(2*n-i);j--) cout<<'*';
      cout<<endl;
    }
    return 0;
}