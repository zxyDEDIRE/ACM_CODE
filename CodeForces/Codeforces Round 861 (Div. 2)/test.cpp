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
const int INF=1e9+7;
const int maxn=1e6+100;
string a,b,ans;
int len_l,len_r;
int final_flag;
int l,r;
void dfs(int step,string num,int cnt_fl)
{
	if(final_flag)return ;
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
		if(ma-mi>cnt_fl)return ;
	}

	if(step==-1)
	{
		ans=num;
		final_flag=1;
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
			dfs(step-1,now,cnt_fl);
		}
		else
		{
			if((pre+i)<='9')
			{
				now=num;
				now[step]=(char)(pre+i);
				dfs(step-1,now,cnt_fl);
			}
			if((pre-i)>='0')
			{
				now=num;
				now[step]=(char)(pre-i);
				dfs(step-1,now,cnt_fl);
			}
		}
		
	}

}
int solve(int l,int r)
{
	// cin>>l>>r;
	a=to_string(l);
	b=to_string(r);
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	len_l=a.size();
	len_r=b.size();
	final_flag=0;
	for(int k=0;k<=9;k++)
	{
		if(final_flag)break;
		for(int len=a.size();len<=b.size();len++)
		{
			for(char top='1';top<='9';top++)
			{
				string now=string(len,'0');
				now[len-1]=top;
				dfs(len-2,now,k);
			}
		}
	}
	reverse(ans.begin(),ans.end());
	int x=stoll(ans);
	return x;
	// cout<<ans<<endl;
}
int test(int l,int r)
{
	int mi=INF,fl=0;
	for(int i=l;i<=r;i++)
	{
		string a=to_string(i);
		sort(a.begin(),a.end());
		int x=a.back()-a[0];
		if(x<mi)
		{
			mi=x;
			fl=i;
		}
	}
	return fl;
}
int MI(int x)
{
	string y=to_string(x);
	sort(y.begin(),y.end());
	return y.back()-y[0];
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	srand(time(0));
	while(1)
	{
		int x=rand()%1000000000000+1;
		int y=rand()%1000000000000+1;
		if(x>y)swap(x,y);
		int ans_1=solve(x,y);
		int ans_2=test(x,y);
		int A=MI(ans_1);
		int B=MI(ans_2);
		cout<<x<<" "<<y<<endl;
		if(A!=B)
		{
			cout<<x<<" "<<y<<endl;
			cout<<A<<" "<<B<<endl;
			cout<<ans_1<<" "<<ans_2<<endl;
			return 0;
		}
	}

//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
558 565
558 569
*/