/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
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
char def_char(char a)
{
	if(a=='b')return 'q';
	if(a=='d')return 'p';
	if(a=='p')return 'd';
	if(a=='q')return 'b';
	if(a=='n')return 'u';
	if(a=='u')return 'n';
	if(a=='o')return a;
	if(a=='s')return a;
	if(a=='x')return a;
	if(a=='z')return a;
	return '!';
}
class StringHash{
public:
	const ull prime=233317;
	const ull base=131;
	vector<ull>h;
	vector<ull>bas;
	StringHash():h(1),bas(1,1){}
	void push_back(char ch){
		h.push_back((h.back()*base+ch)%mod + prime);
		bas.push_back(bas.back()*base%mod);
	}
	ull get(int l,int r){
		return (h[r] + __int128(h[l])*(mod-bas[r-l]))%mod;
	}
};
void A()
{
	string str;
	StringHash hs,rhs;
	int N=int(str.size());
	for(int i=0;i<N;i++)
		hs.push_back(str[i]);
	for(int i=N-1;i>=0;i--)
		rhs.push_back(str[i]);
}
char ch[maxn];
int n;
void NO(){cout<<"No"<<endl;}
void solve()
{
	cin>>ch+1;
	n=strlen(ch+1);
	StringHash hs,rhs;
	for(int i=1;i<=n;i++)
		hs.push_back(ch[i]);
	for(int i=n;i>=1;i--)
		rhs.push_back(def_char(ch[i]));
	cout<<hs.get(2,n)<<endl;
	cout<<rhs.get(2,n)<<endl;
	int pre=-1;
	for(int i=1;i<=n;i++)
	{
		if(def_char(ch[i])==ch[i])continue;
		char def=def_char(ch[i]);
		if(def=='!')return NO();
		if(pre==-1){
			pre=i;
			continue;
		}
		if(ch[pre]!=def)continue;
		if(hs.get(pre,i)!=rhs.get(pre,i))continue;
		int mid=i+pre;
		if((mid%2==0)&&def_char(ch[mid])!=ch[mid])continue;
		pre=-1;
	}
	if(pre==-1)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
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
/*
123
*/