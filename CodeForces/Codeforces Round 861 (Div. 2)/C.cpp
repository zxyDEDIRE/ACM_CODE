/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e18+7;
const int maxn=1e6+100;
string ans,mi;
string a,b;
int l,r,flag;
int len_l,len_r;
int num_mi;
int f(string x)
{
	sort(x.begin(),x.end());
	return x.back()-x[0];
}
void dfs(int step,string num)
{
	if(num.size()==len_l)
	{
		for(int i=len_l-1;i>step;i--)
			if(num[i]>a[i])break;
			else if(num[i]<a[i])return ;
	}
	if(num.size()==len_r)
	{
		for(int i=len_r-1;i>step;i--)
			if(num[i]<b[i])break;
			else if(num[i]>b[i])return ;
	}
	{
		char mi='9';
		char ma='0';
		for(int i=num.size()-1;i>step;i--)
			mi=min(mi,num[i]),ma=max(ma,num[i]);
		if(ma-mi>num_mi)return ;
	}
	// cout<<"OK"<<endl;
	if(step==-1)
	{
		ans=num;
		int num_ans=f(ans);
		if(num_ans<num_mi)
		{
			num_mi=num_ans;
			mi=ans;
		}
		// flag=1;
		return ;
	}
	char pre=num[step+1];
	for(int i=0;i<=9;i++)
	{
		string now;
		if(i==0)
		{
			now=num;
			now[step]=pre;
			dfs(step-1,now);
		}
		else
		{
			if((pre+i)<='9')
			{
				now=num;
				now[step]=(char)(pre+i);
				dfs(step-1,now);
			}
			if((pre-i)>='0')
			{
				now=num;
				now[step]=(char)(pre-i);
				dfs(step-1,now);
			}
		}
		
	}
}
void solve()
{
	cin>>l>>r;
	a=to_string(l);
	b=to_string(r);
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	len_l=a.size();
	len_r=b.size();
	num_mi=INF;
	for(int i=len_l;i<=len_r;i++)
	{
		string x=string(i,'0');
		for(char j='1';j<='9';j++)
		{
			flag=0;
			ans="";
			string now=x;
			now.back()=j;
			dfs(i-2,now);
			// cout<<"****************"<<endl;
		}
	}
	reverse(mi.begin(),mi.end());
	cout<<mi<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
123
*/