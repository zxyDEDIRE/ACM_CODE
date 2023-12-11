/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int p[100];
int ans=0,fl;
void solve()
{
	int a=0,b=0;
	for(int i=0;i<=9;i++)
	{
		cin>>p[i];
		if(i>0)a+=p[i];
		if(p[i]&1){
			ans++;
			fl=i;
		}
	}
	if(p[0]==1&&a==0)
	{
		cout<<0<<endl;
		return ;
	}
	if(p[0]>1&&(a==1||a==0)){cout<<-1<<endl;return ;}
	if(ans>2){cout<<-1<<endl;return ;}
	string str;
	for(int i=1;i<=9;i++)
	{
		for(int j=1;j<=p[i]/2;j++)
			str+=(char)('0'+i);
		if(p[0]&&p[i])
		{
			for(int j=1;j<=p[0]/2;j++)
				str+=(char)('0');
			p[0]=0;
		}
	}
	string s;
	s+=str;
	if(ans)s+=(char)('0'+fl);
	reverse(str.begin(),str.end());
	s+=str;
	cout<<s<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

        solve();
    return 0;
}