#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cout.tie(0);
#define int long long
typedef long long ll;
typedef pair<int,int> P;
const int N=2e5+7;
const int mod=998244353;
int n,m,x,y;
int p[N];
void solve()
{
	cin>>n>>m>>x>>y;
    int k;
    p[0]=0;
    for(int i=1;i<=m;i++)cin>>p[i];
    p[++m]=n+1;
    int a=0,b,len,ans=0;
    for(int i=1;i<=m;i++){
        len=p[i]-p[i-1]-1;
        //cout<<len<<endl;
        b=y-a;
        if(b<x){
        	// cout<<a<<" "<<b<<endl;
        	if(len+1+a>=y+2)
        	{
             	ans+=2*(len+1+a)/(y+2)-1;
	            k=(len+1+a)%(y+2);
	            printf("k=%d a=%d\n",k,a);
	            if(k<=a){
	                a=k;
	            }
	            else{
	                a=k-a-1;
	                ans++;
	                // cout<<"111111\n";
	            }       		
        	}
        }
        else{
            ans+=len/(y+2)*2;
            k=len%(y+2);
            if(k<=x){
                a=k;
            }
            else{
                a=k-x-1;
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}
signed main()
{
	//IOS
	int __=1;
	//cin >> __;
	while (__--)
		solve();
}
