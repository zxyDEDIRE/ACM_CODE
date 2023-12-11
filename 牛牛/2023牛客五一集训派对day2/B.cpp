#include<bits/stdc++.h>
using namespace std;

const int N=2010;
long long x[N],y[N];
int n;
bool check(int i,int j)
{
    return abs(x[i]*y[j]-x[j]*y[i])==0;
} 
map<pair<__int128,__int128>,int>mp;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
	}
	if(n<=2)
	{
		cout<<n<<'\n';return 0;
	}
    int mx=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(check(i,j)) continue;
			__int128 tp=1.0*(x[i]*x[i]+y[i]*y[i])*y[j]-1.0*(x[j]*x[j]+y[j]*y[j])*y[i];
            __int128 xx=2.0*x[i]*y[j]-2.0*x[j]*y[i];
            __int128 tp1=(1.0*x[i]*x[i]+y[i]*y[i])*x[j]-1.0*(x[j]*x[j]+y[j]*y[j])*x[i];
            __int128 yy=2.0*y[i]*x[j]-2.0*y[j]*x[i];
            if(x[i]==0.0)
            {
                tp1=x[i]*x[i]+y[i]*y[i];
                yy=2*y[i];
            }
            if(y[j]==0.0)
            {
                tp=x[j]*x[j]+y[j]*y[j];
                xx=2*x[j];
            }
            if(x[j]==0.0)
            {
                tp1=x[j]*x[j]+y[j]*y[j];
                yy=2*y[j];
            }
            if(y[i]==0.0)
            {
                tp=x[i]*x[i]+y[i]*y[i];
                xx=2*x[i];
            }
            __int128 tx=(tp);
            tx=tx*1e20/xx;
            __int128 ty=tp1;
            ty=ty*1e20/yy;
           mp[{tx,ty}]++;
            mx=max(mp[{tx,ty}],mx);
		}   
	}
   
    mx*=2;
    for(int i=1;i<=n;i++)
    {
        if(i*(i-1)==mx)
        {
            cout<<i;return 0;
        }
    }

	return 0;
}