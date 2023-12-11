/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
vector<string>v;
string str,now;
string dp[maxn];
int n,tot;
void solve()
{
	cin>>str;now="";
	v.push_back("");
	for(int j=0;j<str.size();j++)
	{
		char i=str[j];
		if(i>='A'&&i<='Z')v.push_back(now),now=i;
		else now=now+i;
	}
	v.push_back(now);
	n=v.size()-1;
	vector<int>ans,last;
	last.push_back(1);
	for(int i=1;i<=n;i++)
	{
		if(v[i]>dp[tot]||tot==0){
			dp[++tot]=v[i];
			last.push_back(tot);
		}
		else
		{
			int fl=lower_bound(dp+1,dp+1+tot,v[i])-dp;
			dp[fl]=v[i];
			last.push_back(fl);
		}
	}
	for(int i=n;i>0;i--){
		if(last[i]==tot){
			ans.push_back(i);
			tot--;
		}
	}
	for(int i=ans.size()-1;i>=0;i--)
		cout<<v[ans[i]];

}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
Adpo Cxfx E GypsIkeffKaEfxBcoeLUvVabYgpRenzkVwZnim
Adpo Cxfx E Gyps Ikeff Ka L Uv Vab Vw Znim
Adpo Bcoe E Efx Ikeff Ka L Renzk Vab Vw Znim

输入：
AdpoCxfxEGypsIkeffKaEfxBcoeLUvVabYgpRenzkVwZnim
正解：
AdpoCxfxEGypsIkeffKaLUvVabVwZnim
AdpoCxfxEGypsIkeffKaLUvVabVwZnim
AdpoCxfxEGypsIkeffKaLUvVabVwZnim
wa：
AdpoBcoeEEfxIkeffKaLRenzkVabVwZnim

*/