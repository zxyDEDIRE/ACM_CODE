/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int a[20],b[20];
void solve()
{
	int n;
	cin>>n;
	vector<int>v;
	int m=n;
	int sum=0;
	while(m){
		v.push_back(m%10);
		sum+=m%10;
		m/=10;
	}
	for(int i=0;i<20;i++)
		a[i]=b[i]=0;
	reverse(v.begin(),v.end());
	int aa=0;
	int t=sum/2;
	for(int i=0;i<v.size();i++)
	{
		if(aa<t)
		{
			if(aa+v[i]>t)
			{
				a[i]=t-aa;
				b[i]=v[i]-a[i];
				aa=t;
			}
			else
			{
				a[i]=v[i];
				aa+=v[i];
			}
		}
		else b[i]=v[i];
	}
	int flag=0;
	for(int i=0;i<v.size();i++)
	{
		if(a[i]||flag)
		{
			flag=1;
			cout<<a[i];
		}
	}
	if(flag==0)cout<<0;
	cout<<" "; 
	flag=0;
	for(int i=0;i<v.size();i++)
	{
		if(b[i]||flag)
		{
			flag=1;
			cout<<b[i];
		}
	}
	cout<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}