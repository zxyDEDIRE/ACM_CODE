#include<bits/stdc++.h>
using namespace std;
#define double long double
double x[10],y[10],z[10],r1,r2;

struct pp{
	double A,B,C;
}xc[10];
double ex=1e-8;
pp getxc(double x1,double yy1,double z1,double x2,double y2,double z2)
{
	pp a;
	a={yy1*z2-z1*y2,z1*x2-x1*z2,x1*y2-yy1*x2};
	return a;
	
}

double getd(double x,double y,double z,double A,double B,double C,double b)
{
	return abs(x*A+y*B+z*C+b)/sqrt(A*A+B*B+C*C);
}

void solve()
{
	scanf("%Lf%Lf%Lf%Lf%Lf%Lf%Lf",&r2,&x[3],&y[3],&z[3],&x[4],&y[4],&z[4]);
	xc[0]=getxc(x[2],y[2],z[2],x[4],y[4],z[4]);
	
	double xx,yy,zz;
	if(xc[0].A)
	{
		xx=0;
		yy=(-x[1]*x[2]*z[4]-y[1]*y[1]*z[4]-z[1]*z[2]*z[4]+x[3]*x[4]*z[2]+y[3]*y[4]*z[2]+z[3]*z[4]*z[2])/(y[4]*z[2]-z[4]*y[2]);
		zz=(-x[1]*x[2]*y[4]-y[1]*y[1]*y[4]-z[1]*z[2]*y[4]+x[3]*x[4]*y[2]+y[3]*y[4]*y[2]+z[3]*z[4]*y[2])/(y[2]*z[4]-z[2]*y[4]);
	}
	else if(xc[0].B)
	{
		xx=(-x[1]*x[2]*z[4]-y[1]*y[1]*z[4]-z[1]*z[2]*z[4]+x[3]*x[4]*z[2]+y[3]*y[4]*z[2]+z[3]*z[4]*z[2])/(z[2]*x[4]-x[2]*z[4]);
		yy=0;
		zz=(-x[1]*x[2]*x[4]-y[1]*y[1]*x[4]-z[1]*z[2]*x[4]+x[3]*x[4]*x[2]+y[3]*y[4]*x[2]+z[3]*z[4]*x[2])/(z[4]*x[2]-x[4]*z[2]);
	}
	else if(xc[0].C)
	{
		yy=(-x[1]*x[2]*x[4]-y[1]*y[1]*x[4]-z[1]*z[2]*x[4]+x[3]*x[4]*x[2]+y[3]*y[4]*x[2]+z[3]*x[4]*z[2])/(x[2]*y[4]-y[2]*x[4]);
		xx=(-x[1]*x[2]*y[4]-y[1]*y[1]*y[4]-z[1]*z[2]*y[4]+x[3]*x[4]*y[2]+y[3]*y[4]*y[2]+z[3]*z[4]*y[2])/(x[4]*y[2]-y[4]*x[2]);
		zz=0;
	}
	xc[2]=getxc(x[2],y[2],z[2],xc[0].A,xc[0].B,xc[0].C);
	xc[3]=getxc(x[4],y[4],z[4],xc[0].A,xc[0].B,xc[0].C);
	double b1=-xx*xc[2].A-yy*xc[2].B-zz*xc[2].C;
	double b2=-xx*xc[3].A-yy*xc[3].B-zz*xc[3].C;
	double d1=getd(x[1],y[1],z[1],xc[2].A,xc[2].B,xc[2].C,b1);
	double d2=getd(x[3],y[3],z[3],xc[3].A,xc[3].B,xc[3].C,b2);
	if(r1-d1<0||r2-d2<0)
	{
		puts("0");
	}
	else
	{
		double d11=sqrt(r1*r1-d1*d1);
		double r22=sqrt(d11*d11+d2*d2);
		if(r22-r2>=0)
		{
			double d22=sqrt(r2*r2-d2*d2);
			printf("%.20Lf\n",d22*2.0);
		}
		else
		{
			printf("%.20Lf\n",d11*2.0);
		}
	}
}

int main()
{
	while(~scanf("%Lf%Lf%Lf%Lf%Lf%Lf%Lf",&r1,&x[1],&y[1],&z[1],&x[2],&y[2],&z[2]))
		solve();
	return 0;
}
