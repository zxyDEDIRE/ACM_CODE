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
#define nullptr 0
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=300;
char mp[maxn][maxn];
int n,sx,sy,tx,ty;
int f(string &str)
{
	int x=sx,y=sy;
	for(int i=0;i<str.size();i++)
	{
		char op=str[i];
		if(op=='L')y--;
		else if(op=='R')y++;
		else if(op=='U')x--;
		else if(op=='D')x++;
		if(x<1||x>n||y<1||y>n)return 1;
		if(mp[x][y]=='#')return 2;
		if(x==tx&&y==ty)return 4;
	}
	if(x!=tx||y!=ty)return 3;
	return 4;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			cin>>mp[i][j];
			if(mp[i][j]=='S')sx=i,sy=j;
			if(mp[i][j]=='T')tx=i,ty=j;
		}
	int q;
	cin>>q;
	while(q--)
	{
		string str;
		cin>>str;
		int ans=f(str);
		if(ans==1)cout<<"I am out!"<<endl;
		else if(ans==2)cout<<"I am dizzy!"<<endl;
		else if(ans==3)cout<<"I have no idea!"<<endl;
		else cout<<"I get there!"<<endl;
	}

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