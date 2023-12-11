#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int maxn=1e5+7;
const int mod=998244353;
int n,d[maxn],ans;
vector<int> G[maxn];

void getans(int now)
{
  int cnt0=0,cnt1=0,cnt2=0;
  int sum=0;
  vector<int> v;
  for(auto i:G[now])
  {
    if(d[i]>2)
    {
      cnt2++;
      sum+=(d[i]-1);
      v.push_back(d[i]-1);
    }
    else if(d[i]==2)
      cnt1++;
    else if(d[i]==1)
      cnt0++;
  }
  //cnt0个头，cnt1个胳膊，cnt2个腰

  for(int k=0;k<(int)v.size();k++)
  {
    int x=v[k];
    //选择当前腰
   	int a=x*(x-1)/2;
    //考虑胳膊
    //剩的cnt1个纯胳膊，cnt2-1个替胳膊
    int tot=0,psum=0;
  	for(int i=0;i<(int)v.size();i++)
  	{
      if(i==k)continue;
      
      tot+=psum*v[i];
      psum+=v[i];
      
      tot%=mod;
      psum%=mod;
  	}
    //纯+纯。	+	 纯+不纯。 + 	不纯+不纯
    int b=cnt1*(cnt1-1)/2+cnt1*(sum-x)+tot;
    //cout<<now<<" "<<cnt1*(cnt1-1)/2<<" "<<cnt1*(sum-x)<<" "<<tot<<endl;
    //然后别的都能当头的
    int c=cnt0+cnt1+cnt2-2;
    if(b<=0||c<=0)continue;
    //cout<<a<<" "<<b<<" "<<c<<endl;
    ans+=a*b*c%mod;
    ans%=mod;
  }
}

void solve()
{
  cin>>n;ans=0;
  for(int i=0;i<=n;i++)
    G[i].clear();
  
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    G[u].push_back(v);
    G[v].push_back(u);
    d[u]++;d[v]++;
  }
  for(int i=1;i<=n;i++)
  	getans(i);
  cout<<ans/2<<endl;
}    
signed main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  int t;cin>>t;
  while(t--)solve();
  return 0;
}