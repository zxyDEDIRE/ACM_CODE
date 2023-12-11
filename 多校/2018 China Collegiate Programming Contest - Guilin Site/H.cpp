/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
void solve()
{
	string s,t;
	cin>>s>>t;
	int a=0,b=0;
	string str;
	int n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]=='a')a++;
		if(t[i]=='a')b++;
		str+='a';
	}
	int aa=min(a,b);
	a-=aa;
	b-=aa;
	for(int i=n-1;i>=0;i--)
	{
		if(s[i]=='a'&&t[i]=='a')continue;
		if(a!=0)
		{
			if(s[i]=='a')
			{
				if(a>=2)str[i]=t[i],a--;
				else if(a==1)
				{
					if(t[i]=='b')str[i]='c';
					else str[i]='b';
				}
			}
			else str[i]=t[i];
			a--;
		}
		else if(b!=0)
		{
			if(t[i]=='a')
			{
				if(b>=2)str[i]=s[i],b--;
				else if(b==1)
				{
					if(s[i]=='b')str[i]='c';
					else str[i]='b';
				}
			}
			else str[i]=s[i];
			b--;
		}
	}
	cout<<str<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	for(int i=1;i<=__;i++){
		cout<<"Case "<<i<<": ";
		solve();
	}
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
1
dkkkfdas
akfkdksa
aaaaaaab

1
dkkkfdab
akfkdksa
aaaaaaac

1
abandon
newyork

1
aaandoaaa
newyorkaa

aaaaaaaaa

aaaaorkaa 
5 5
*/
