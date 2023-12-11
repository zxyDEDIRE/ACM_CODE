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
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
string a[]={"geng","xin","ren","gui","jia","yi","bing","ding","wu","ji"};
// string b[]={"zi","chou","yin","mao","chen","si","wu","wei","shen","you","xu","hai"};
// string a[10] = { "jia","yi","bing","ding","wu","ji","geng","xin","ren","gui" };//天干
// string b[12] = { "zi","chou","yin","chen","si","wu","wei","shen","you","xu","hai" };//地支
string b[] = {"shen", "you", "xu", "hai", "zi", "chou", "yin", "mao", "chen", "si", "wu", "wei"};

void solve()
{
	int n;
	cin>>n;
	// int now=(n+56)%60;
	cout<<a[n%10]<<b[n%12]<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}