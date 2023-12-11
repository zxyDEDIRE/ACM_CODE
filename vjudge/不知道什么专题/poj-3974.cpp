/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<stdio.h>
using namespace std;
#define endl "\n"
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=2e6+100;
struct Manacher{
	char ch[maxn];
	int lc[maxn];
	int N;
	void init(char *s){
		int n=strlen(s+1);
		// puts(s+1);
		ch[n*2+1]='#';
		ch[0]='@';
		ch[n*2+2]='\0';
		for(int i=1;i<=n;i++)
			ch[i*2]=s[i],ch[i*2-1]='#';
		N=n*2+1;
	}
	void manacher(){
		lc[1]=1;  int k=1,ma=1;
		for (int i=2;i<=N;i++){
			int p = k+lc[k]-1;
			if (i<=p){
				lc[i]=min(lc[2*k-i],p-i+1);
			}else{	lc[i]=1;}
			while(ch[i+lc[i]]==ch[i-lc[i]])lc[i]++;
			if(i+lc[i]>k+lc[k])k=i;
			ma=max(ma,lc[i]-1);
		}
		int ans_1=0,ans_2=0;
		for(int i=1;i<=N;i++)
			if(i&1)ans_1=max(ans_1,lc[i]);
			else ans_2=max(ans_2,lc[i]);
		ans_1/=2;
		ans_2/=2;
		cout<<max(ans_1*2,ans_2*2-1)<<endl;
	}
	void debug(){
		puts(ch);
		for (int i=1;i<=N;i++){
			printf("lc[%d]=%d\n",i,lc[i]);
		}
	}
}Manch;
char ch[maxn];
string str;
int n;
void solve()
{
	n=str.size();
	for(int i=0;i<str.size();i++)
		ch[i+1]=str[i];
	ch[n+1]='\0';
	Manch.init(ch);
	Manch.manacher();
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int cnt=0;
	while(cin>>str&&str!="END"){
		cout<<"Case "<<++cnt<<": ";
		solve();
		// break;
	}
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}