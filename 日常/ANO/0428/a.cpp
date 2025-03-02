#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
const int maxn=1e6;
struct node{
	string name;
	int num,fa;
}p[maxn];
string name,str;
int n,m,cnt;
bool cmp(node a,node b)
{
	if(a.num!=b.num)return a.num>b.num;
	if(a.fa!=b.fa)return a.fa<b.fa;
	return a.name<b.name;
}
int main()
{
	cin>>n>>m;
	while(cin>>name)
	{
		p[++cnt].name=name;
		for(int k=1;k<=n;k++)
		{
			cin>>str;
			if(str[0]=='-'||str[0]=='0')continue;

			int ans=0,b=0,flag=0;
			for(int i=0;i<str.size();i++)
			{
				if(!flag)
				{
					if(str[i]=='(')flag=1;
					else
					{
						ans=ans*10+str[i]-'0';
					}
				}
				else
				{
					if(str[i]!=')')b=b*10+str[i]-'0';
				}
			}
			p[cnt].num++;
			p[cnt].fa+=ans+b*m;
		}
	//	cout<<p[cnt].name<<" "<<p[cnt].num<<" "<<p[cnt].fa<<endl;
	}
	sort(p+1,p+1+cnt,cmp);
	for(int i=1;i<=cnt;i++)
		cout<<p[i].name<<" "<<p[i].num<<" "<<p[i].fa<<endl;
}
/*
8 20
Smith -1 -16 8 0 0 120 39 0
John 116 -2 11 0 0 82 55(1) 0
Josephus 72(3) 126 10 -3 0 47 21(2) -2
Bush 0 -1 -8 0 0 0 0 0
Alice -2 67(2) 13 -1 0 133 79(1) -1
Bob 0 0 57(5) 0 0 168 -7 0
*/