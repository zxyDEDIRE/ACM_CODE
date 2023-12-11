#include<bits/stdc++.h>
#define PI acos(-1)
using namespace std;
using ld=long double;
using ll=long long;
ld n,r,s,w,f,L1,L2,D;
struct node{
	ld x,y;
}p[1000];
void doit(int i)
{
	ld R=r+(i-1)*w;
	if(i==1)R+=L1;
	else R+=L2;

	int flag=1;
	ld ans=D;

	ld L;
	if(i==1)L=L1;
	else L=L2;

	p[i].x=-f;
	p[i].y=-R;

	while(ans)
	{
		if(flag==1)
		{
			ld len=f+f;
			if(ans<=len)
			{
				p[i].x-=ans;
				ans=0;
				cout<<p[i].x<<" "<<p[i].y-L<<endl;
			}
			else
			{
				p[i].x-=f+f;
				ans-=f+f;
			}
		}
		else if(flag==2)
		{
			ld rr=PI*R;


			if(ans<=rr)
			{
				ld O=acos(ans);
				cout<<O<<endl;
				p[i].x-=(R)*sin(O);
				p[i].y+=(R-R*cos(O));
				p[i].x+=L*sin(O);
				p[i].y+=L*cos(O);
				cout<<p[i].x<<" "<<p[i].y<<endl;
			}
			else
			{
				ans-=rr;
				p[i].y+=R+R;
			}
		}
		else if(flag==3)
		{
			ld len=f+f;
			if(ans<=len)
			{
				p[i].x+=ans;
				ans=0;
				cout<<p[i].x<<" "<<p[i].y+L<<endl;
			}
			else
			{
				p[i].x+=f+f;
				ans-=f+f;
			}
		}
		else if(flag==4)
		{
			ld rr=PI*R;

			if(ans<=rr)
			{
				ld O=acos(ans);

				p[i].x+=(R)*sin(O);
				p[i].y-=(R-R*cos(O));
				p[i].x-=L*sin(O);
				p[i].y-=L*cos(O);
				cout<<p[i].x<<" "<<p[i].y<<endl;
			}
			else
			{
				ans-=rr;
				p[i].y+=R+R;
			}
		}
		flag++;
		flag%=5;
	}


}
int main()
{
	cin>>n>>r>>s>>w>>f>>L1>>L2;
	while(cin>>D)
	{
		for(int i=1;i<=n;i++)
			doit(i);
	}
}