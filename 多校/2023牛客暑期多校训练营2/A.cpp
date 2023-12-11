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
int F[maxn];
bool check(char a,char b)
{
	if(a=='b'&&b=='q')return 1;
	if(a=='d'&&b=='p')return 1;
	if(a=='p'&&b=='d')return 1;
	if(a=='q'&&b=='b')return 1;
	if(a=='n'&&b=='u')return 1;
	if(a=='u'&&b=='n')return 1;
	if(a=='o'&&a==b)return 1;
	if(a=='s'&&a==b)return 1;
	if(a=='x'&&a==b)return 1;
	if(a=='z'&&a==b)return 1;
	if(a=='#'&&a==b)return 1;
	return 0;
}
int def(char a)
{
	if(a=='b')return 'q'-'a';
	if(a=='d')return 'p'-'a';
	if(a=='p')return 'd'-'a';
	if(a=='q')return 'b'-'a';
	if(a=='n')return 'u'-'a';
	if(a=='u')return 'n'-'a';
	return -1;
}
int A()
{
	int n=strlen(ch+1);
	for(int i=1;i<=n;i++)
	{
		if(check(ch[i],ch[i]))continue;
		int k=def(ch[i]);
		if(k==-1)return 0;
		int fl=-1;
		for(int j=i+1;j<=n;j++)
			if(ch[j]-'a'==k){
				fl=j;
				break;
			}
		int l=i,r=fl;
		while(l<r)
		{
			if(check(ch[l],ch[r]))l++,r--;
			else return 0;
		}
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>ch+1;
	cout<<A()<<endl;
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}