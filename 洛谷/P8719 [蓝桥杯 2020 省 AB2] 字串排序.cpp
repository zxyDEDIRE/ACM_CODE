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
char ch[maxn];
int p[maxn];
int len;
int n;
void solve()
{
	cin>>n;
	for(int i=1,sum=0;;i++){
		sum+=i;
		if(sum>=n){
			len=i;
			break;
		}
	}
	int sum=0;
	for(int i=1;i<=len;i++)
		p[i]=i,sum+=i;
	// for(int k=1;k<=26;k++)
	// {
		for(int i=len;i>=1;i-=2)
			if(sum>n)p[i]=p[i-1],sum-=1;
	// }
	
	// cout<<sum<<endl;
	// for(int i=1;i<=len;i++)
	// 	cout<<p[i]<<" ";cout<<endl;
	set<int>s;
	for(int i=0;i<=len;i++)
		s.insert(p[i]);
	int m=s.size();
	ch[0]=(char)('a'+m-1);
	for(int i=1;i<=len;i++)
	{
		if(p[i]!=p[i-1])
			ch[i]=ch[i-1]-1;
		else ch[i]=ch[i-1];
	}
	// cout<<len+1<<endl;
	for(int i=0;i<=len;i++)
		cout<<ch[i];
	cout<<endl;
}
void f()
{
	char p[100];
	cin>>p+1;
	int n=strlen(p+1);
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<n;j++)
			if(p[j]>p[j+1])swap(p[j],p[j+1]),cnt++;
	}
	cout<<cnt<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
		// f();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
jihgfeeddccbbaa 
ajihgfeeddccbba 0+13=13
aajihgfeeddccbb 13+13=26
aabjihgfeeddccb 26+11=37
aabbjihgfeeddcc 37+11=48
aabbcjihgfeeddc 48+9=57
aabbccjihgfeedd 57+9=66
aabbccdjihgfeed 66+7=73
aabbccddjihgfee 73+7=80
aabbccddejihgfe 80+5=85
aabbccddeejihgf 85+5=90
aabbccddeefjihg 90+4=94
aabbccddeefgjih 94+3=97
aabbccddeefghji 97+2=99
1 2 3 4 5 6 7 8 9 10 11 12 13 14
1 2 3 4 5 5 7 7 9 9  11 11 13 13
5
1 2 3 = 6
0 2 2
 
bbaa
 022  

hggffeeddccbbaa
27*26/2=351

1 2 3 4 
1 2 3
bbaa
bd

bdca
311
*/