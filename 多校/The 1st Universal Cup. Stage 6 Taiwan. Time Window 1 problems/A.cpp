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
map<string,int>mp;

void solve()
{
	string str;
	cin>>str;
	for(int i=0;i<str.size();i+=3)
	{
		string now=str.substr(i,3);
		int x=mp[now];
		if(x==0)break;
		else cout<<(char)(x);
	}
	cout<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
mp["UUU"]=mp["UUC"]='F';
mp["UUA"]=mp["UUG"]=mp["CUU"]=mp["CUC"]=mp["CUA"]=mp["CUG"]='L';
mp["AUU"]=mp["AUC"]=mp["AUA"]='I';
mp["AUG"]='M';
mp["GUU"]=mp["GUC"]=mp["GUA"]=mp["GUG"]='V';
mp["UCU"]=mp["UCC"]=mp["UCA"]=mp["UCG"]=mp["AGU"]=mp["AGC"]='S';
mp["CCU"]=mp["CCC"]=mp["CCA"]=mp["CCG"]='P';
mp["ACU"]=mp["ACC"]=mp["ACA"]=mp["ACG"]='T';
mp["GCU"]=mp["GCC"]=mp["GCA"]=mp["GCG"]='A';
mp["UAU"]=mp["UAC"]='Y';
mp["CAU"]=mp["CAC"]='H';
mp["CAA"]=mp["CAG"]='Q';
mp["AAU"]=mp["AAC"]='N';
mp["AAA"]=mp["AAG"]='K';
mp["GAU"]=mp["GAC"]='D';
mp["GAA"]=mp["GAG"]='E';
mp["UGU"]=mp["UGC"]='C';
mp["UGG"]='W';
mp["CGU"]=mp["CGC"]=mp["CGA"]=mp["CGG"]=mp["AGA"]=mp["AGG"]='R';
mp["GGU"]=mp["GGC"]=mp["GGA"]=mp["GGG"]='G';
mp["UAA"]=mp["UAG"]=mp["UGA"]=0;

	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}