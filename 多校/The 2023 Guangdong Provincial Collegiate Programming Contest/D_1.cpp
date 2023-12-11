#include<bits/stdc++.h>
using namespace std;
using ll=long long;
long long ksm(long long a,long long b,long long mod){
    long long res=1;
    a%=mod;
    while(b){
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
const int N=5e5+10;
int n,m;
namespace A{
long long a[N],b[N],c[N];
long long sum[N];

ll solve(){
    long long ans=0;
    for(int i=1;i<=n;i++){
        // cin>>a[i]>>b[i];
        ans+=a[i]+b[i];
        c[i]=b[i]-a[i];
    }
    sort(c+1,c+n+1,[&](long long x,long long y){
        return x>y;
    });
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+c[i];
    }
    long long res=0;
    for(int i=0;i<=n;i++){
        if(i==n-1) continue;
        if(i+n-(i==n)<=m){
            res=max(res,ans+sum[i]+sum[i]-sum[n]);
        }
    }
    // cout<<res/2<<'\n';
    return res/2;
}
};
struct node{
	int x,y;
};
ll solve1()
{
	vector<node>a,b;
	for(int i=1;i<=n;i++)
	{
		int x,y;
		// cin>>x>>y;
		x=A::a[i];
		y=A::b[i];
		if(x>=y)a.push_back({x,y});
		else b.push_back({x,y});
	}
	sort(b.begin(),b.end(),[&](node a,node b){
		return a.y-a.x>b.y-b.x;
	});
	int numa=a.size();
	int numb=b.size();
	int len=m;
	ll ans=0;
	for(int i=0;i<numb;i++)
	{
		int yu=n-i-1;
		if(len-2>=yu)
		{ 
			len-=2;
			ans+=b[i].y;
		}
		else
		{
			for(int j=i;j<numb;j++)
				a.push_back(b[j]);
			break;
		}
	}

	if(a.size()==1)
	{
		ans+=a[0].y;
	}
	else if(a.size()>1)
	{
		for(auto x:a)
			ans+=x.x;
	}
	return ans;

}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    srand(time(0));
    while(1)
    {
    	n=100;
    	m=rand()%20+n;
    	for(int i=1;i<=n;i++)
    	{
    		A::a[i]=rand();
    		A::b[i]=rand();
    	}
    	ll ans_1=A::solve();
    	ll ans_2=solve1();
    	cout<<ans_1<<" "<<ans_2<<endl;
    	if(ans_1!=ans_2)
    	{
    		cout<<endl;
    		cout<<n<<" "<<m<<endl;
    		for(int i=1;i<=n;i++)
    			cout<<A::a[i]<<" "<<A::b[i]<<endl;
    		cout<<endl;
    	}
    }
    return 0;
}
