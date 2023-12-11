/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
void solve()
{
	int n,cnt=0;
	string str;
	cin>>n;
	getchar();
	while(n--)
	{
		getline(cin,str);
		int len=str.size();
		int fl=1,out=0;
		for(int i=0;i<len;i++)
		{
			if(fl==1&&str[i]=='#')
			{
				if(i+1<len&&str[i+1]==' ')
				{
					for(int j=i+1;j<len;j++)
					if(str[j]!=' '){
						cnt++;
						break;
					}
				}
				out=1;
			}
			else if(fl==1&&(str[i]!='#'&&str[i]!=' '))out=1;

			if(out)break;
		}

	}
	cout<<cnt<<endl;
}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}