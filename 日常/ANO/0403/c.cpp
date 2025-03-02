#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
string s1[100000];
map<string,int>mp1,mp2,mp111,mp222;
map<string,string> mp11,mp22;
string fun(string s)
{
	for(int i=0;i<s.size();i++){
		if(s[i]>='a'&&s[i]<='z')s[i]-=32;
	}
	return s;
}
string gai(string s)
{
	string a,b,c,t;
	int len=0;
	for(int i=0;i<=s.size();i++){
		if(s[i]==' '||i==s.size()){
			len++;
			if(len==1){
				a=t;
			}
			else if(len==2)b=t;
			else if(len==3)c=t;
			t.clear();
            continue;
		}
		t+=s[i];
	}
	t=c+" "+b+" "+a;
	return t;
}
void solve()
{
    int len=0,fen=0;
	while(getline(cin,s1[++len])){
        if(s1[len].size()==0)fen=len;
    }
    // for(int i=1;i<=len;i++){
    //     cout<<s1[i]<<endl;
    // }
    // cout<<fen<<endl;
    for(int i=1;i<fen;i++){
        string t1=gai(s1[i]);//翻转
		string t2=fun(t1);//变大写
        mp11[t2]=t1;
		mp1[t2]++;

        string a,b,c,t,s=t2;
        int lf=0;
        for(int i=0;i<=s.size();i++){
		    if(s[i]==' '||i==s.size()){
		    	lf++;
		    	if(lf==1)a=t;
			    else if(lf==2)b=t;
			    else if(lf==3)c=t;
			    t.clear();
                continue;
		    }
		    t+=s[i];
	    }
        mp111[a]++;
        mp111[b+c]++;

    }

    for(int i=fen+1;i<len;i++){

        string t1=gai(s1[i]);//翻转
		string t2=fun(t1);//变大写
        mp22[t2]=t1;
		mp2[t2]++;

        string a,b,c,t,s=t2;
        int lf=0;
        for(int i=0;i<=s.size();i++){
		    if(s[i]==' '||i==s.size()){
		    	lf++;
		    	if(lf==1)a=t;
			    else if(lf==2)b=t;
			    else if(lf==3)c=t;
			    t.clear();
                continue;
		    }
		    t+=s[i];
	    }
        mp222[a]++;
        mp222[b+c]++;
    }
    int flag=0;
    for(auto i=mp1.begin();i!=mp1.end();i++){

        string a,b,c,t,s=i->first;
	    int lf=0;
	    for(int i=0;i<=s.size();i++){
	    	if(s[i]==' '||i==s.size()){
	    		lf++;
	    		if(lf==1){
	    			a=t;
	    		}
	    		else if(lf==2)b=t;
	    		else if(lf==3)c=t;
	    		t.clear();
                continue;
	    	}
	    	t+=s[i];
	    }
        if(mp222[a]||mp222[b+c])continue;
        cout<<"I"<<" ";
        string t1=mp11[i->first];//true string
		//cout<<i->first;
		cout<<t1<<endl;//test
		flag=1;
    }


    for(auto i=mp2.begin();i!=mp2.end();i++){

        string a,b,c,t,s=i->first;
	    int lf=0;
	    for(int i=0;i<=s.size();i++){
	    	if(s[i]==' '||i==s.size()){
	    		lf++;
	    		if(lf==1){
	    			a=t;
	    		}
	    		else if(lf==2)b=t;
	    		else if(lf==3)c=t;
	    		t.clear();
                continue;
	    	}
	    	t+=s[i];
	    }
        if(mp111[a]||mp111[b+c])continue;
        cout<<"O"<<" ";
        string t1=mp22[i->first];//true string
		//cout<<i->first;
		cout<<t1<<endl;//test
		flag=1;
    }
    if(!flag)cout<<"No mismatches."<<endl;
}
signed main()
{
	int __;
	//cin>>__;
	__=1;
	while(__--)solve();
}