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
string mp[111];
set<string>s;
int ma=0;
string str;
int n;
void init(){
mp[0]="bbbbbbbbbbbbbbbr";mp[1]="bbbbbbbbbbbbbbrb";mp[2]="bbbbbbbbbbbbbbrr";mp[3]="bbbbbbbbbbbbbrbr";mp[4]="bbbbbbbbbbbbbrrb";mp[5]="bbbbbbbbbbbbbrrr";mp[6]="bbbbbbbbbbbbrbrb";mp[7]="bbbbbbbbbbbbrrbb";mp[8]="bbbbbbbbbbbbrrbr";mp[9]="bbbbbbbbbbbbrrrr";mp[10]="bbbbbbbbbbbrbrbb";mp[11]="bbbbbbbbbbbrrbbb";mp[12]="bbbbbbbbbbbrrbbr";mp[13]="bbbbbbbbbbbrrbrr";mp[14]="bbbbbbbbbbbrrrrb";mp[15]="bbbbbbbbbbrbrbbb";mp[16]="bbbbbbbbbbrrbbbb";mp[17]="bbbbbbbbbbrrbbbr";mp[18]="bbbbbbbbbbrrbbrr";mp[19]="bbbbbbbbbbrrbrrb";mp[20]="bbbbbbbbbbrrrrbb";mp[21]="bbbbbbbbbrbrbbbb";mp[22]="bbbbbbbbbrrbbbbb";mp[23]="bbbbbbbbbrrbbbbr";mp[24]="bbbbbbbbbrrbbbrr";mp[25]="bbbbbbbbbrrbbrrb";mp[26]="bbbbbbbbbrrbrrbb";mp[27]="bbbbbbbbbrrrrbbb";mp[28]="bbbbbbbbrbrbbbbb";mp[29]="bbbbbbbbrrbbbbbb";mp[30]="bbbbbbbbrrbbbbbr";mp[31]="bbbbbbbbrrbbbbrr";mp[32]="bbbbbbbbrrbbbrrb";mp[33]="bbbbbbbbrrbbrrbb";mp[34]="bbbbbbbbrrbrrbbb";mp[35]="bbbbbbbbrrrrbbbb";mp[36]="bbbbbbbrbrbbbbbb";mp[37]="bbbbbbbrrbbbbbbb";mp[38]="bbbbbbbrrbbbbbbr";mp[39]="bbbbbbbrrbbbbbrr";mp[40]="bbbbbbbrrbbbbrrb";mp[41]="bbbbbbbrrbbbrrbb";mp[42]="bbbbbbbrrbbrrbbb";mp[43]="bbbbbbbrrbrrbbbb";mp[44]="bbbbbbbrrrrbbbbb";mp[45]="bbbbbbrbrbbbbbbb";mp[46]="bbbbbbrrbbbbbbbb";mp[47]="bbbbbbrrbbbbbbbr";mp[48]="bbbbbbrrbbbbbbrr";mp[49]="bbbbbbrrbbbbbrrb";mp[50]="bbbbbbrrbbbbrrbb";mp[51]="bbbbbbrrbbbrrbbb";mp[52]="bbbbbbrrbbrrbbbb";mp[53]="bbbbbbrrbrrbbbbb";mp[54]="bbbbbbrrrrbbbbbb";mp[55]="bbbbbrbrbbbbbbbb";mp[56]="bbbbbrrbbbbbbbbb";mp[57]="bbbbbrrbbbbbbbbr";mp[58]="bbbbbrrbbbbbbbrr";mp[59]="bbbbbrrbbbbbbrrb";mp[60]="bbbbbrrbbbbbrrbb";mp[61]="bbbbbrrbbbbrrbbb";mp[62]="bbbbbrrbbbrrbbbb";mp[63]="bbbbbrrbbrrbbbbb";mp[64]="bbbbbrrbrrbbbbbb";mp[65]="bbbbbrrrrbbbbbbb";mp[66]="bbbbrbrbbbbbbbbb";mp[67]="bbbbrrbbbbbbbbbb";mp[68]="bbbbrrbbbbbbbbbr";mp[69]="bbbbrrbbbbbbbbrr";mp[70]="bbbbrrbbbbbbbrrb";mp[71]="bbbbrrbbbbbbrrbb";mp[72]="bbbbrrbbbbbrrbbb";mp[73]="bbbbrrbbbbrrbbbb";mp[74]="bbbbrrbbbrrbbbbb";mp[75]="bbbbrrbbrrbbbbbb";mp[76]="bbbbrrbrrbbbbbbb";mp[77]="bbbbrrrrbbbbbbbb";mp[78]="bbbrbrbbbbbbbbbb";mp[79]="bbbrrbbbbbbbbbbb";mp[80]="bbbrrbbbbbbbbbbr";mp[81]="bbbrrbbbbbbbbbrr";mp[82]="bbbrrbbbbbbbbrrb";mp[83]="bbbrrbbbbbbbrrbb";

}
int f(string &str)
{
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++){
			int cnt=0;
			for(int k=i;k<=j;k++)
				if(str[k-1]=='1')cnt++;
			if(cnt&1)ans++;
		}
	return ans;
}
void dfs(int x,string str)
{
	if(s.size()==110)return ;
	if(x>n)
	{
		int now=f(str);
		if(now>ma)
		{
			s.clear();
			ma=now;
			s.insert(str);
		}
		else if(now==ma)
			s.insert(str);
		return ;
	}
	dfs(x+1,str+"0");
	dfs(x+1,str+"1");
}
void solve(int N)
{
	// cin>>n;
	n=N;
	s.clear();
	dfs(1,"");
	// cout<<"N:"<<n<<endl;
	cout<<ma<<endl;
	int cnt=0,pre=0;
	for(auto i:s){
		cnt++;
		for(auto j:i)
		{
			if(j=='0')cout<<"b";
			else cout<<"r";
		}
		cout<<endl;
		string x=i;
		reverse(x.begin(),x.end());
		ll now=0;
		for(int i=0;i<x.size();i++)
			if(x[i]=='1')now|=(1ll<<i);
		// cout<<now<<" "<<now-pre<<endl;
		pre=now;
		if(cnt==100)break;
	}
	// cout<<"cnt "<<cnt<<endl;
}
void f(int N)
{
	n=N;
	int round=100;
	int mid=(n/2)+1;
	int r=n;

	if(n&1)cout<<1ll*mid*mid<<endl;
	else cout<<1ll*mid*(mid-1)<<endl;
	while(round--)
	{
		int isout=0;
		if(round==99)			
		{
			for(int i=1;i<mid;i++)cout<<"b";
			cout<<"r";
			for(int i=mid+1;i<=n;i++)cout<<"b";
			cout<<endl;
			mid--;
		}
		else if(round==98&&n%2==0)
		{
			for(int i=1;i<mid;i++)cout<<"b";
			cout<<"r";
			for(int i=mid+1;i<=n;i++)cout<<"b";
			cout<<endl;
		}
		else
		{
			if(r==mid){
				mid--;
				isout=1;
				break;
			}
			for(int i=1;i<=n;i++)
				if(i==mid||i==r||i==r+1)cout<<"r";
				else cout<<"b";
			cout<<endl;
			r--;
		}
		if(isout)break;
	}
	int I=0;
	if(n&1)I=1;
	for(int i=0;i<=round;i++)
	{
		for(int j=1;j<=n-16;j++)
			if(j==mid)cout<<"r";
			else cout<<"b";
		cout<<mp[I]<<endl;
		I++;
	}


}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	init();
	int N;
	cin>>N;
	solve(N);
	// if(N<=30)
	// 	solve(N);
	// else{
	// 	f(N);
	// }
	return 0;
}