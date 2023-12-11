/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=(1<<16);
const int maxn=1e6+100;
map<string,int>st;
vector<string>p[maxn];
stack<int>s;
int si=1,ti=0;
int f(string x){
	if(st.count(x))return st[x]%mod;
	else return stoll(x)%mod;
}
void init()
{
	st["ax"]=0;
	st["bx"]=0;
	st["cx"]=0;
	st["dx"]=0;
}
void MOV(vector<string>&q)
{
	st[q[1]]=f(q[2]);
}
void ADD(vector<string>&q)
{
	st[q[1]]+=f(q[2]);
	st[q[1]]%=mod;
}
void SUB(vector<string>&q)
{
	st[q[1]]-=f(q[2]);
	st[q[1]]%=mod;
}
void MUL(vector<string>&q)
{
	st["ax"]*=f(q[1]);
	st["ax"]%=mod;
}
void DIV(vector<string>&q)
{
	if(f(q[1])==0)return ;
	st["ax"]=floor(st["ax"]/f(q[1]));
	st["ax"]%=mod;
}
void PUSH(vector<string>&q)
{
	s.push(f(q[1]));
}
void POP(vector<string>&q)
{
	st[q[1]]=s.top()%mod;s.pop();
}
void solve()
{
	string op;
	int flag=0;
	while(cin>>op)
	{
		if(op=="a")
		{
			flag=1;
		}
		else if(op=="g")
		{
			flag=0;
			int _num;cin>>_num;
			while(si<=_num)
			{
				vector<string>q=p[si];
				if(q[0]=="mov")MOV(q);
				else if(q[0]=="add")ADD(q);
				else if(q[0]=="sub")SUB(q);
				else if(q[0]=="mul")MUL(q);
				else if(q[0]=="div")DIV(q);
				else if(q[0]=="push")PUSH(q);
				else if(q[0]=="pop")POP(q);
				si++;
			}
		}
		else if(op=="u")
		{
			flag=0;
			for(int i=si;i<=ti;i++)
			{
				for(int j=0;j<p[i].size();j++)
				{
					cout<<p[i][j];
					if(j!=p[i].size()-1)cout<<" ";
				}
				cout<<endl;
			}
		}
		else if(op=="d")
		{
			flag=0;
			string a;cin>>a;
			cout<<st[a]%mod<<endl;
		}
		else if(op=="r")
		{
			flag=0;
			string to;int num;cin>>to>>num;num%=mod;
			st[to]=num;
		}
		else if(op=="mov")
		{
			string a,b;cin>>a>>b;
			vector<string>now={op,a,b};
			if(flag==1)p[++ti]=now;
		}
		else if(op=="add")
		{
			string a,b;cin>>a>>b;
			vector<string>now={op,a,b};
			if(flag==1)p[++ti]=now;
		}
		else if(op=="sub")
		{
			string a,b;cin>>a>>b;
			vector<string>now={op,a,b};
			if(flag==1)p[++ti]=now;
		}
		else if(op=="mul")
		{
			string a;cin>>a;
			vector<string>now={op,a};
			if(flag==1)p[++ti]=now;
		}
		else if(op=="div")
		{
			string a;cin>>a;
			vector<string>now={op,a};
			if(flag==1)p[++ti]=now;
		}
		else if(op=="push")
		{
			string a;cin>>a;
			vector<string>now={op,a};
			if(flag==1)p[++ti]=now;
		}
		else if(op=="pop")
		{
			string a;cin>>a;
			vector<string>now={op,a};
			if(flag==1)p[++ti]=now;
		}
	}
	
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
a
add ax 1
add ax 2
add ax 3
r
ax 1
*/