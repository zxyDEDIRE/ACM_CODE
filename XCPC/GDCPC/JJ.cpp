#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int t,l,r;
};
vector<node> v;
int n,m;
signed main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int t,l,r;
		cin>>t>>l>>r;
		v.push_back({t,l,r});
	}
	sort(v.begin(),v.end(),[](node &a,node &b){
		return a.l<b.l;
	});
	if(v[0].t==2)
	{
		cout<<"0/21/0"<<endl;
		return 0;
	}
	
	int pre=0;
	for(int i=1;i<m;i++)
	{
		if(v[i].t!=v[pre].t)
		{
			pre=i;
			continue;
		}
		v[i].t=0;
		v[pre].r=max(v[pre].r,v[i].r);
	}
	
	int now=0,cnt=0,ans=0;
	for(int i=v.size()-1;i>=0;i--)
	{
		auto [t,l,r]=v[i];
		if(t==0)
			continue;
		int k=r-l+1;
		if(t==1)
		{
			now+=k;
			int x=now/2;
			int y=k-x;
			ans+=y*3+x;
			now-=2*x;
		}
		else
		{
			now-=k;
			ans+=k;
			if(now<0)
			{
				int x=-now;
				int y=(x+1)/2*2;
				ans+=y*3;
				if(x&1)now=1;
				else now=0;
			}
		}
	}
	cout<<ans<<endl;
	
//	
//	for(auto [t,l,r]:v)
//	{
//		if(t==0)
//			continue;
//		int k=r-l+1;
//		/*
//		cout<<"t="<<t<<" l="<<l<<" r="<<r<<endl;
//		cout<<"k="<<k<<endl;
//		*/
//		if(t==1)
//		{
//			ans+=k*3;
//			now+=k;
//			cnt+=k;
//		}
//		else
//		{
//			if(k>=now)
//			{
//				ans+=k;
//				k-=now;
//				ans+=k*3;
//				now=0;
//				cnt=0;
//				if(k%2==1)
//				{
//					ans+=3;
//					now=1;
//				}
//			}
//			else
//			{
//				now-=k;
//				ans+=k;
//				cnt-=k;
//			}
//		}
//	//	cout<<"ans="<<ans<<" now="<<now<<endl;
//	}
//	cnt-=cnt%2;
//	ans-=cnt;
//	cout<<ans;
//}
}
