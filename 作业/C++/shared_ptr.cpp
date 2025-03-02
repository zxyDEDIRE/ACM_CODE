#include<bits/stdc++.h>
using namespace std;
#define endl "\n"


namespace A{
	// 定义
	void solve()
	{
		shared_ptr<string> p1;
		shared_ptr<list<int>> p2;

		shared_ptr<int> p3 = make_shared<int>(42);  // 调用构造函数
		shared_ptr<string> p4 = make_shared<string>(10, 'a');
		shared_ptr<int> p5 = make_shared<int>();

		auto p6 = make_shared<vector<string>>();


	}
}

namespace B{
	// 拷贝和赋值
	void solve()
	{
		auto p = make_shared<int>(42); // p指向的对象只有p一个引用者
		auto q(p); //p,q指向相同的对象，此对象有两个引用
		// printf(p.use_count())
		cout<<p.use_count()<<endl;
	}
}

namespace C{
	// 动态内存
	class StrBlob{
	public:
		using size_type=vector<string>::size_type;
		StrBlob();
		StrBlob(initializer_list<string>il);
		size_type size() const{ return data->size(); }
		bool empty() const{ return data->empty(); }
		// add del
		void push_back(const string &t){data->push_back(t);}
		void pop_back();
		//
		const string& front() const;
		const string& back() const;
	private:
		shared_ptr<vector<string>> data;
		void check(size_type i, const string &msg)const;
	};
	// 构造
	StrBlob::StrBlob(): data(make_shared<vector<string>>()){}
	StrBlob::StrBlob(initializer_list<string>li):
		data(make_shared<vector<string>>(li)){}
	void StrBlob::check(size_type i, const string &msg)const{
		if(i >= data->size())
			throw out_of_range(msg);
	}
	const string& StrBlob::front() const
	{
		check(0, "front on empty StrBlob");
		return data->front();
	}
	const string& StrBlob::back() const
	{
		check(0, "back on empty StrBlob");
		return data->back();
	}
	void StrBlob::pop_back()
	{
		check(0, "pop_back on empty StrBlob");
		data->pop_back();
	}



	void solve()
	{
		vector<string>a;
		{
			vector<string> b={"a", "bc", "cd"};
			a=b;
			b.push_back("sdf");
		}
		cout<<a.size()<<endl;
	}
	void solve1()
	{
		StrBlob b1;
		{
			StrBlob b2={"a", "ab", "bc"};
			b1 = b2;
			b2.push_back("about");
		}
		cout<<b1.size()<<endl;
	}
}

namespace D{
	void process(shared_ptr<int>ptr)
	{
		cout<<"Process use_count="<<ptr.use_count()<<endl;
	}
	void solve()
	{
		shared_ptr<int>p(new int(42));
		process(p);
		cout<<p.use_count()<<endl; // 计数为1
		cout<<"8888888"<<endl;
		int *x(new int(24));
		// process(x);  wa x为普通指针，不能转换
		process(shared_ptr<int>(x)); // ac 显示转换 但是 x指针将会被销毁
	}
	void solve_reset()
	{
		shared_ptr<int>p1 = make_shared<int>(12);
		shared_ptr<int>p2 = p1;
		cout<<*p1<<" "<<p1.use_count()<<endl;

		p1.reset(new int(1024)); // 原来内存的计数器--，指向了一个新的对象
		cout<<p2.use_count()<<endl;

		// 如果用户不止一个拷贝原来的值
		shared_ptr<int>p3 = p2;


		if(!p3.unique()){
			cout<<"用户不止一个"<<endl;
			// p3 = make_shared<int>(*p3);
			p3.reset(new int(*p3));
			cout<<*p3<<endl;
		}
	}
	void solve_test1()
	{
		shared_ptr<int>p(new int(42));
		process(shared_ptr<int>(p));
		// 这个传入的参数是临时的指针 所以函数内部use_count=2,函数结束后销毁变成1
		cout<<p.use_count()<<endl;
	}
	void solve_test2()
	{
		shared_ptr<int>p(new int(147));
		process(shared_ptr<int>(p.get())); // 删了两次
	}
	void solve_test3()
	{
		auto p = new int(12);
		auto sp =make_shared<int>();

		// process(sp); ac
		// process(new int()); wa
		// process(p); wa
		process(shared_ptr<int>(p));
	}
	void solve_test4()
	{
		// struct de;
		// struct co;
		// co connect(de*);
		// void dis(co);
		// de d
		// co c = connect(&d);
	}
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	
	// C::solve();
	// C::solve1();
	// D::solve();
	// D::solve_reset();
	D::solve_test4();
	return 0;
}