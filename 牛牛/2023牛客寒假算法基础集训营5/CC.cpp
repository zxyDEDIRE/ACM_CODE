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
void solve()
{
	string a="0123456789";
	string s,t;
	cin>>s>>t;
	int x=0,y=0,z=0;
	do{
		string ss=s;
		string tt=t;
		for(int i=0;i<ss.size();i++)
			ss[i]=a[(ss[i]-'0')];
		for(int i=0;i<tt.size();i++)
			tt[i]=a[(tt[i]-'0')];
		while(ss[0]=='0')ss.erase(ss.begin());
		while(tt[0]=='0')tt.erase(tt.begin());
		if(ss.size()>tt.size())y++;
		else if(ss.size()<tt.size())x++;
		else
		{
			int fl=0;
			for(int i=0;i<ss.size();i++)
				if(ss[i]<tt[i]){
					fl=1;
					x++;
					break;
				}
				else if(ss[i]>tt[i]){
					y++;
					fl=1;
					break;
				}
			if(!fl){
				z++;
			}
		}
	}while(next_permutation(a.begin(),a.end()));
	cout<<x<<" "<<y<<" "<<z<<endl;
	if(!y&&!z)cout<<"<";
	else if(!x&&!z)cout<<">";
	else if(!x&&!y)cout<<"=";
	else cout<<"!"<<endl;
	cout<<endl;
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
000012
1234

00000034
00000012

0001234
123

11111
11

13
310

00001
11111
*/