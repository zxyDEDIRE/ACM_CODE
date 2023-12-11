#include<bits/stdc++.h>
using namespace std;

#define int long long
const int maxn=1e6+100;
int a[maxn];
int n;
struct SaDown{
	//退火系数
	#define down 0.996
	int ansx,answ;
	//评估函数
	int energy(int mid){
		int ans=0;
		int flag=0;
		for(int i=1;i<=n;i++){
			if(flag==0)
			{
				ans+=a[i];
				if(ans>=mid)flag=1;
			}
			else ans=max(mid,ans+a[i]);
		}
		return ans;
	}
	void sa()
	{
		double t=3000;
		while(t>1e-10)
		{
			int ex=ansx+(rand()*2-RAND_MAX)*t;
			ex=min(ex,0ll);
			ex=max(ex,answ);
			int ew=energy(ex);
			int de=ew-answ; 
			if(answ<ew)
			{
				ansx=ex;
				answ=ew;
			}
			else if(exp(-de/t)*RAND_MAX>rand())
			{
				ansx=ex;
			}
			t*=down;
		}
	}
	void doit(){
		//退火次数
		for(int i=1;i<=5;i++)
			sa();
	}
}sa;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sa.ansx=0;
	sa.answ=sa.energy(sa.ansx);
	sa.doit();
	cout<<sa.ansx<<endl;
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