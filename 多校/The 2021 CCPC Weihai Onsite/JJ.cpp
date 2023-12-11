#include <iostream>
#include <stdio.h>
#include<bits/stdc++.h>
using namespace std;
int exgcd(int a,int b,int &x,int &y)
{
    if(b==0)
    {            //1的情况
        x=1;
        y=0;
        return a;
    }
    int r=exgcd(b, a%b, x, y);
    int t=y;
    y=x-(a/b)*y;     //2的情况
    x=t;
    return r;
}
int main()
{
    int x,y;
    exgcd(252,198, x, y);
    cout<<__gcd(252,198)<<endl;
    cout<<"252x+198y=18:"<<endl;
    cout<<"x="<<x<<" "<<"y="<<y<<" "<<endl;
    return 0;
}