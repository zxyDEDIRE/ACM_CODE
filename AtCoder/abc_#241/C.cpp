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
const int maxn=1111;
string mp[maxn];
int n;
bool A(int x,int y)
{
	int num;
	if(y+5<n){num=0;
		for(int i=0;i<6;i++)
			if(mp[x][y+i]=='#')num++;
		if(num>=4)return 1;
	}
	if(x+5<n){num=0;
		for(int i=0;i<6;i++)
			if(mp[x+i][y]=='#')num++;
		if(num>=4)return 1;
	}
	return 0;
}
bool B(int x,int y)
{
	int num=0;
	if(x+1<n&&y+2<n){num=0;
		for(int i=0;i<2;i++)
			for(int j=0;j<3;j++)
				if(mp[x+i][y+j]=='#')
					num++;
		if(num>=4)return 1;
	}
	if(x+2<n&&y+1<n){num=0;
		for(int i=0;i<3;i++)
			for(int j=0;j<2;j++)
				if(mp[x+i][y+j]=='#')
					num++;
		if(num>=4)return 1;
	}
	return 0;
}
void solve()
{
	cin>>n;
	for(int i=0;i<n;i++)cin>>mp[i];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(A(i,j)||B(i,j)){
				cout<<"Yes"<<endl;
				return ;
			}}}
	cout<<"No"<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}