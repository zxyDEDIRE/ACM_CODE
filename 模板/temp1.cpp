#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
struct node{
	int x,y,step;
	string str;
};
map<string,bool>vis;
int mp[10][10];
string s,t="123804765";
int n=3;
void solve()
{
	cin>>s;
	int fl=0,sx,sy;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(s[fl]=='0')sx=i,sy=j;
			mp[i][j]=fl++;
		}
	}
	queue<node>q;
	q.push({sx,sy,0,s});
	while(!q.empty())
	{
		auto [x,y,step,str] = q.front();q.pop();
		if(str==t){
			cout<<step<<endl;
			break;
		}
		if(vis.count(str))continue;
		// cout<<str<<" "<<step<<endl;
		vis[str]=true;

		for(int i=0;i<4;i++)
		{
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(xx<0||yy<0||xx >= 3||yy>=3)continue;
			string _s = str;
			swap(_s[mp[xx][yy]]  ,_s[mp[x][y]]);
			q.push({xx,yy,step+1,_s});
		}
	}
}


template<class T>
void Swap(T& a, T& b)
{
	T c=a;
	a=b;
	b=c;
}

signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		// solve();
	double a=1,b=2;
	int a1=3,b1=10;
	Swap(a,b);
	swap(a1,b1);
	cout<<a<<" "<<b<<endl;
	cout<<a1<<" "<<b1<<endl;

	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;gggggggggggggggg
}\
-----------------------------

#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_wity_stdio(flase);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;    /'7'
}
#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
	#include<bits/
}
*/