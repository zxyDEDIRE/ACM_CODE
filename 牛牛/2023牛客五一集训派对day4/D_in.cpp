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
const int maxn=1e5+100;
const int N=1e5+100;
struct node_1
{
	int _mi[maxn];
	int _ma[maxn];
	int p[maxn];
	char s[maxn];
	int n,ans=INF;
	int f(int len)
	{
		for(int i=1;i<=len;i++)
			_ma[i]=-1,_mi[i]=10;
		for(int i=1;i+len-1<=n;i+=len)
		{
			if(p[i]==0)return 111;
			int fa=0,fb=0;
			for(int j=1;j<=len;j++)
			{
				if(fa==0&&p[i+j-1]>_ma[j])fa=1;
				else if(fa==0&&p[i+j-1]<_ma[j])fa=-1;

				if(fb==0&&p[i+j-1]<_mi[j])fb=1;
				else if(fb==0&&p[i+j-1]>_mi[j])fb=-1;
			}
			if(fa==1){
				for(int j=1;j<=len;j++)
					_ma[j]=p[i+j-1];
			}
			if(fb==1){
				for(int j=1;j<=len;j++)
					_mi[j]=p[i+j-1];
			}
		}
		int now=0;
		for(int i=1;i<=len;i++){
			now=now*10+(_ma[i]-_mi[i]);
			if(now>1000)return 1111;
		}
		// cout<<"LEN "<<len<<" now "<<now<<endl;
		return now;
	}
	int h(int len)//991
	{
		if(len*2>=n)return 1111;
		int _MI=999,_MA=-1;
		for(int i=1;i<=n;i++)
		{
			if(p[i]==9)
			{
				for(int j=1;j<len;j++)
					if(p[i+j-1]!=9)return 1111;
				_MI=min(_MI,p[i+len-1]);
				_MA=max(_MA,p[i+len-1]);
				i=i+len-1;
			}
			else if(p[i]==1)
			{
				if(i+len>n)return 1111;
				for(int j=2;j<=len;j++)
					if(p[i+j-1]!=0)return 1111;
				_MI=min(_MI,10+p[i+len]);
				_MA=max(_MA,10+p[i+len]);
				i=i+len;
			}
			else if(len>1)return 111;
			else if(len==1)
			{
				_MI=min(_MI,p[i]);
				_MA=max(_MA,p[i]);
			}
		}
		// cout<<"H "<<len<<" now "<<_MA-_MI+10<<endl;
		return _MA-_MI;
	}
	int solve(int N,char *S)
	{
		n=N;
		// cin>>n>>s+1;
		ans=INF;
		int _MA=0,_MI=9;
		for(int i=1;i<=n;i++)
		{
			// p[i]=s[i]-'0';
			p[i]=S[i]-'0';
			_MA=max(_MA,p[i]);
			_MI=min(_MI,p[i]);
		}
		p[n+1]=-1;
		ans=min(ans,_MA-_MI);
		for(int i=2;i*i<=n;i++)
			if(n%i==0){
				ans=min(ans,f(i));
				ans=min(ans,f(n/i));
			}
		int len=1;
		for(int i=1;i<=n;i++)
			if(p[i]==1){
				while(p[i+len]==0)len++;
				break;
			}
		// cout<<"LEN "<<len<<endl;
		ans=min(ans,h(len+2));
		ans=min(ans,h(len+1));
		ans=min(ans,h(len));
		if(len>1)ans=min(ans,h(len-1));
		if(len>2)ans=min(ans,h(len-2));
		// cout<<ans<<endl;
		return ans;
	}
}A;
struct node_2
{
	int n,ans,mx,mn; char s[N];
	void calc(int x) {
		static int a[N],b[N];
		for(int i=0;i<x;i++) a[i]=-1,b[i]=10;
		for(int i=1;i<=n;i+=x) {
			if(!s[i]) return ;
			int big=0,sma=0;
			for(int j=0;j<x;j++) {
				if(!big&&s[i+j]!=a[j]) big=(s[i+j]>a[j])?1:-1;
				if(!sma&&s[i+j]!=b[j]) sma=(s[i+j]<b[j])?1:-1;
			}
			for(int j=0;j<x;j++) {
				if(big==1) a[j]=s[i+j];
				if(sma==1) b[j]=s[i+j];
			}
		}
		int num=0;
		for(int i=0;i<x;i++) {
			num=num*10+a[i]-b[i];
			if(num>=ans) return ;
		}
		ans=num;
	}
	void solve(int x) {//x 表示 999..t 的位数
		int mx=0,mn=1000,cnt=0;
		for(int i=1;i<=n;i++)
			if(s[i]==1) {
				if(i+x>n) return ;
				bool v=1;
				for(int j=1;j<x;j++) if(s[i+j]) {v=0; break;}
				if(!v) return ;
				mx=max(mx,10+s[i+x]);
				mn=min(mn,10+s[i+x]);
				i+=x; cnt++;
			}
			else {
				if(i+x-1>n) return;
				bool v=1;
				for(int j=0;j<x-1;j++) if(s[i+j]<9) {v=0; break;}
				if(!v) return; 
				mx=max(mx,(int)s[i+x-1]);
				mn=min(mn,(int)s[i+x-1]);
				i+=x-1; cnt++;
			}
		if(cnt<2) return ;
		ans=min(ans,mx-mn);
	}
	int solve(int N,char *S) {
			n=N;
			for(int i=1;i<=n;i++)
				s[i]=S[i];
			mx=0; mn=10;
			for(int i=1;i<=n;i++) s[i]-='0',mx=max(mx,(int)s[i]),mn=min(mn,(int)s[i]);
			ans=mx-mn;
			for(int i=2;i*i<=n;i++) if(n%i==0) calc(i),calc(n/i);
			int k=0;
			for(int i=1;i<=n;i++) 
				if(s[i]==1) {
					k=1;
					while(i+k<=n&&!s[i+k]) k++;
					break;
				}
			//长度不等的话,要么是1000...x,要么是99999...x.
			if(k)solve(k); 
			if(k>1) solve(k-1);
			// printf("%d\n",ans);
			return ans;
	}
}B;

char ch[maxn];
signed main(){
	srand(time(0));
	int cnt=0;
	while(1)
	{
		cnt++;
		if(cnt%100==0)cout<<cnt<<endl;
		int n=rand();
		while(n<2||n>10)n=rand();
		for(int i=1;i<=n;i++)
		{
			ch[i]=(char)('0'+rand()%10);
		}
		int ans_1=A.solve(n,ch);
		int ans_2=B.solve(n,ch);
		if(ans_1!=ans_2)
		{
			cout<<"************************"<<endl;
			cout<<ans_1<<" "<<ans_2<<endl;
			cout<<n<<endl;
			for(int i=1;i<=n;i++)
				cout<<ch[i];
			cout<<endl;
			cout<<"************************"<<endl;
			return 0;
		}
	}
	

	return 0;
}