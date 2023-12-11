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
	string T;
	for(char i='a';i<='z';i++)
		T=T+i;
	for(char i='A';i<='Z';i++)
		T=T+i;
	srand(time(0));
	int tmp=0;
	while(tmp==0)
		tmp=rand()%52;
	string str;
	cout<<"Original text: ";
	getline(cin,str);
	for(auto &i:str)
	{
		int x;
		if(i>='a'&&i<='z')x=i-'a';
		else x=26+i-'A';
		if(i==' ')i='@';
		else i=T[(x+tmp)%52];
	}
	cout<<"ciphertext: "<<str<<endl;
	cout<<"key: "<<tmp<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}