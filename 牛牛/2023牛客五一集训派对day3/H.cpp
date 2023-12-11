#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int q[N],cnt;
bool vis[N];
void init(int n=N-10)
{
    vis[1]=true;
    for(int i=2;i<=n;i++)
    {
        if(vis[i]==false)
        {
            q[cnt++]=i;
        }
        for(int j=0;1ll*i*q[j]<=n;j++)
        {
            int nu=i*q[j];
            vis[nu]=true;
            if(i%q[j]==0) break;
        }
    }
}
bool vvis[N];
void solve()
{
	int n;
    cin>>n;
    for(int i=1;i<=n;i++) vvis[i]=false;
    int t=upper_bound(q,q+cnt,n/2)-q;
    if(t==cnt||q[t]>n) t--;
    vector<int>b;
    for(int i=0;i<t;i++) b.push_back(q[i]);
    vector<pair<int,int>>ans;
    for(int j=(int)b.size()-1;j>=0;j--)
    {
        vector<int>o;
        o.push_back(b[j]);
        for(int i=3*b[j];i<=n;i+=b[j])
        {
            if(vvis[i]==false)
            o.push_back(i);
        }
        for(int i=0;i+1<o.size();i+=2)
        {
            vvis[o[i]]=true;vvis[o[i+1]]=true;
            ans.push_back({o[i],o[i+1]});
        }
        if((int)o.size()%2==1&&vvis[b[j]*2]==false) {
            ans.push_back({o.back(),b[j]*2});
            vvis[o.back()]=true;vvis[b[j]*2]=true;
        }
    }
    cout<<(int)ans.size()<<'\n';
    for(auto [v,u]:ans)
    {
        cout<<v<<" "<<u<<'\n';
    }
    
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    init();
	int t=1;
	cin>>t;
	while(t--)
	{
		solve();
	}
	
	return 0;
}