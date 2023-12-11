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
string a,b;
void NO(){cout<<"!"<<endl;}
void solve()
{
	cin>>a>>b;
	if(a==b){
		cout<<"="<<endl;
		return ;
	}
	char _ans,st,ans_;
	int len;
	if(a.size()>b.size())_ans='>',st=a[0];
	else if(a.size()<b.size())_ans='<',st=b[0];
	else return NO();
 
	len=0;
	while(a[len]==st&&len<a.size())len++;
	a.erase(a.begin(),a.begin()+len);
	len=0;
	while(b[len]==st&&len<b.size())len++;
	b.erase(b.begin(),b.begin()+len);

	if(a.size()<b.size())
		ans_='<';
	else if(a.size()>b.size())
		ans_='>';
	else
	{
		ans_='=';
		for(int i=0;i<a.size();i++)
		{
			if(a[i]==b[i])continue;
			else if(a[i]==st)ans_='<';
			else if(b[i]==st)ans_='>';
			else ans_='!';
			break;
		}
	}

	if(_ans==ans_)cout<<_ans<<endl;
	else return NO();
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
/*
000230
00203
*/