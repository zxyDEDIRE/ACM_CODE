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
string str;
int n,k;
void NO(){cout<<"No"<<endl;}
void YES(){cout<<"Yes"<<endl;}
void solve()
{
	cin>>n>>k;
	cin>>str;
	int l=n,r=0;
	int ma_1=0,ma_2=0;
	int len=0;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]=='1')
		{
			l=min(l,i);
			r=max(r,i);
		}
		if(str[i]=='?')len++;
		else len=0;
		ma_2=max(ma_2,len);
		if(ma_2>ma_1)swap(ma_1,ma_2);
	}
	if(r<l)
	{
		if(ma_1==k&&ma_2!=k)return YES();
		else return NO();
	}
	if(r-l+1>k)return NO();
	for(int i=l;i<r;i++)
		if(str[i]=='0')
			return NO();
	if(r-l+1==k)return YES();
	int a=0,b=0;
	while(1)
	{
		if(r<n-1&&(str[r+1]=='?'))r++,a++;
		else break;
	}
	while(1)
	{
		if(l>0&&(str[l-1]=='?'))l--,b++;
		else break;
	}
	int alen=r-l+1;
	if(alen==k)return YES();
	else if(alen>k&&(a==0||b==0))return YES();
	else return NO();
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
/*
4
3 2
1??
4 2
?1?0
6 3
011?1?
10 5
00?1???10?

1
7 5
0111110


10 5
00?1???10?
0123456789
8 7
????????

7 4
?1?????

7 4
?1??1??

*/