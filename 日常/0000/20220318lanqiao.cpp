#include<bits/stdc++.h>
#define int long long
using namespace std;
string a,b,c;
int f[10],m[10],e[10],T;
void A()
{
	for(int i=0;i<a.size();i++){
		if(a[i]=='O')f[3]=2;
		else if(a[i]=='A'&&a[i+1]=='B')f[1]++,f[2]++,i++;
		else if(a[i]=='A'&&(a[i+1]=='-'||a[i+1]=='+'))f[1]=2;
		else if(a[i]=='B'&&(a[i+1]=='-'||a[i+1]=='+'))f[2]=1,f[3]=1;
		else if(a[i]=='+')f[4]++,f[5]++;
		else if(a[i]=='-')f[5]++;
	}
		
	for(int i=0;i<b.size();i++){
		if(b[i]=='O')m[3]=2;
		else if(b[i]=='A'&&b[i+1]=='B')m[1]++,m[2]++,i++;
		else if(b[i]=='A'&&(b[i+1]=='-'||b[i+1]=='+'))m[1]=2;
		else if(b[i]=='B'&&(b[i+1]=='-'||b[i+1]=='+'))m[2]=1,m[3]=1;
		else if(b[i]=='+')m[4]++,m[5]++;
		else if(b[i]=='-')m[5]++;
	}
		
//	for(int i=1;i<=5;i++)cout<<f[i];cout<<endl;
//	for(int i=1;i<=5;i++)cout<<m[i];cout<<endl;
		
		
	int xx=0,yy=0;
	string x[100],y[100],z;
	for(int i=1;i<=3;i++)
	{
		if(f[i]==0)continue;
		for(int j=1;j<=3;j++)
		{
			if(m[j]==0)continue;
			z="";
			if((i==j&&i==1)||(i==1&&j==3)||(i==3&&j==1))
			{
				z+='A';
			}
			else if((i==j&&i==2)||(i==2&&j==3)||(i==3&&j==2)) 
			{
				z+='B';
			}
			else if(i!=j&&i!=3&&j!=3)
			{
				z+="AB";
			}
			else if(i==j&&i==3)
			{
				z+='O';
			}
			int flag=1;
			for(int k=1;k<=xx;k++)
				if(x[k]==z)flag=0;
			if(flag&&z!="")x[++xx]=z;
		}
	}
//	for(int i=1;i<=xx;i++)
//		cout<<x[i]<<" ";
//	cout<<endl;
	for(int i=4;i<=5;i++)
	{
		if(f[i]==0)continue;
		for(int j=4;j<=5;j++)
		{
			z="";
			if(m[j]==0)continue;
			if(i==j&&i==5)
			{
				z+="-";
			}
			else z+="+";
			int flag=1;
			for(int k=1;k<=yy;k++)
				if(y[k]==z)flag=0;
			if(flag&&z!="")y[++yy]=z;
		}
	}
//	for(int i=1;i<=yy;i++)
//		cout<<y[i]<<" ";
//	cout<<endl;
	string ans="{";
	int num=0;
	for(int i=1;i<=xx;i++)
	{
		for(int j=1;j<=yy;j++)
		{
			num++;
			z=x[i]+y[j];
			ans+=z+",";
		}
	}
	ans[ans.size()-1]='}';
	cout<<"Case "<<T<<": ";
	cout<<a<<" "<<b<<" ";
	if(num>1)cout<<ans<<endl;
	else
	{
		for(int i=1;i<ans.size()-1;i++)cout<<ans[i];
		cout<<endl;
	}
}
void B(){
	for(int i=0;i<c.size();i++){
		if(c[i]=='O')e[3]=2;
		else if(c[i]=='A'&&c[i+1]=='B')e[1]++,e[2]++,i++;
		else if(c[i]=='A'&&(c[i+1]=='-'||c[i+1]=='+'))e[1]=2;
		else if(c[i]=='B'&&(c[i+1]=='-'||c[i+1]=='+'))e[2]=2;
		else if(c[i]=='+')e[4]++,e[5]++;
		else if(c[i]=='-')e[5]++;
	}
	if(a[0]!='?')
	for(int i=0;i<a.size();i++){
		if(a[i]=='O')f[3]=2;
		else if(a[i]=='A'&&a[i+1]=='B')f[1]++,f[2]++,i++;
		else if(a[i]=='A'&&(a[i+1]=='-'||a[i+1]=='+'))f[1]=2;
		else if(a[i]=='B'&&(a[i+1]=='-'||a[i+1]=='+'))f[2]=2;
		else if(a[i]=='+')f[4]++,f[5]++;
		else if(a[i]=='-')f[5]++;
	}
	else
	for(int i=0;i<b.size();i++){
		if(b[i]=='O')m[3]=2;
		else if(b[i]=='A'&&b[i+1]=='B')f[1]++,f[2]++,i++;
		else if(b[i]=='A'&&(b[i+1]=='-'||b[i+1]=='+'))f[1]=2;
		else if(b[i]=='B'&&(b[i+1]=='-'||b[i+1]=='+'))f[2]=2;
		else if(b[i]=='+')f[4]++,f[5]++;
		else if(b[i]=='-')f[5]++;
	}
	
//	for(int i=1;i<=5;i++)cout<<f[i];cout<<endl;
//	for(int i=1;i<=5;i++)cout<<e[i];cout<<endl;
	
	
	int xx=0,yy=0;
	string x[100],y[100],z;
	for(int i=1;i<=3;i++)
		if(e[i]==2&&!f[i]){
			cout<<"Case "<<T<<": ";
			if(a[0]=='?')cout<<"IMPOSSIBLE ";
			else cout<<a<<" ";
			if(b[0]=='?')cout<<"IMPOSSIBLE ";
			else cout<<b<<" ";
			cout<<c<<endl;
			return ;
		}
		else if(e[i]&&!f[i])m[i]++;
//	for(int i=1;i<=5;i++)cout<<m[i];
//	cout<<endl;
	for(int i=1;i<=3;i++)
	{
		if(!m[i])continue;
		for(int j=1;j<=3;j++)
		{
			z="";
			if((i==j&&i==1)||(i==1&&j==3)||(i==3&&j==1))z+='A';
			else if((i==j&&i==2)||(i==2&&j==3)||(i==3&&j==2)) z+='B';
			else if(i!=j&&i!=3&&j!=3)z+="AB";
			else if(i==j&&i==3)z+='O';
			int flag=1;
			for(int k=1;k<=xx;k++)
				if(x[k]==z)flag=0;
			if(flag&&z!="")x[++xx]=z;
		}
	}
//	cout<<xx<<endl;
//	for(int i=1;i<=xx;i++)
//		cout<<x[i]<<" ";
//	cout<<endl;
	int fl=1;
	for(int i=4;i<=5;i++)
	{
		if(e[i]&&!f[i])m[i]++,fl=0;
	}
//	for(int i=1;i<=5;i++)cout<<m[i];
//	cout<<endl;
	
	if(!fl)
	for(int i=4;i<=5;i++)
	{
		if(!m[i])continue;
		for(int j=4;j<=5;j++)
		{
			z="";
			if(i==j&&i==5)z="-";
			else z="+";
			int flag=1;
			for(int k=1;k<=yy;k++)
				if(y[k]==z)flag=0;
			if(flag&&z!="")y[++yy]=z;
		}
	}
	else y[++yy]="+",y[++yy]="-"; 
//	for(int i=1;i<=yy;i++)
//		cout<<y[i]<<" ";
//	cout<<endl;
	string res="";
	string ans="{";
	int num=0;
	for(int i=1;i<=xx;i++)
	{
		for(int j=1;j<=yy;j++)
		{
			num++;
			z=x[i]+y[j];
			ans+=z+",";
		}
	}
	ans[ans.size()-1]='}';
	if(num>1)res=ans;
	else
	{
		for(int i=1;i<ans.size()-1;i++)res+=ans[i];
	}
//	cout<<ans<<endl;
	cout<<"Case "<<T<<": ";
	if(a[0]=='?')cout<<res<<" ";
	else cout<<a<<" ";
	if(b[0]=='?')cout<<res<<" ";
	else cout<<b<<" ";
	cout<<c<<endl;
}
void solve()
{
	if(c[0]=='?')A();
	else B();
} 
signed main()
{
	while(1)
	{
		T++;
		memset(f,0,sizeof(f));
		memset(m,0,sizeof(m));
		memset(e,0,sizeof(e));
		cin>>a>>b>>c;
		if(a[0]=='E')return 0;
		solve();
	}
}
/*
+-   --
--   +-


B+ ? A-
O- O- ?
E N D


*/
