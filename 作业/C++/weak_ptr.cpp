// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>
#include<memory>
#include <stdexcept>
// using namespace std;


// namespace A{

// 	void solve()
// 	{
// 		cout<<"定义\n";
// 		auto p1 = make_shared<int>(42);
// 		cout<<p1.use_count()<<endl;
// 		weak_ptr<int> wp(p1);
// 		cout<<p1.use_count()<<" "<<wp.use_count()<<"\n\n";

// 		// lock
// 		if(shared_ptr<int>np = wp.lock())
// 		{
// 			// 在这个域中 np与p共享对象
// 			cout<<wp.use_count()<<endl;
// 		}
// 	}
// }



class StrBlobPtr;

class StrBlob{
	friend class StrBlobPtr;
public:
	typedef std::vector<std::string>::size_type size_type;
	StrBlob();
	StrBlob(std::initializer_list<std::string>il);
	size_type size() const{ return data->size(); }
	bool empty() const{ return data->empty(); }
	// add del
	void push_back(const std::string &t){data->push_back(t);}
	void pop_back();
	//
	const std::string& front() const;
	const std::string& back() const;
	StrBlobPtr begin();
	StrBlobPtr end();

private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(size_type i, const std::string &msg)const;
	
	// friend class StrBlobPtr;
};
// 构造
StrBlob::StrBlob(): data(std::make_shared<std::vector<std::string>>()){}
StrBlob::StrBlob(std::initializer_list<std::string>li):
	data(std::make_shared<std::vector<std::string>>(li)){}
void StrBlob::check(size_type i, const std::string &msg)const{
	if(i >= data->size())
		throw std::out_of_range(msg);
}
const std::string& StrBlob::front() const
{
	check(0, "front on empty StrBlob");
	return data->front();
}
const std::string& StrBlob::back() const
{
	check(0, "back on empty StrBlob");
	return data->back();
}
void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}
// StrBlobPtr StrBlob::begin(){
// 	return StrBlobPtr(*this);
// }



// 核查指针类
class StrBlobPtr{
public:
	StrBlobPtr(): curr(0){}
	StrBlobPtr(StrBlob &a, size_t sz=0):wptr(a.data), curr(sz){}
	std::string& deref() const;
	StrBlobPtr& incr(); // 前缀递增
	bool operator==(const StrBlobPtr &r)const{
		auto lp = wptr.lock();
		auto rp = r.wptr.lock();
		if(lp==rp){
			return (!lp||curr==r.curr);
		}
		return false;
	}
	bool operator!=(const StrBlobPtr &r)const{
		return !(*this==r);
	}
private:
	// 
	std::shared_ptr<std::vector<std::string>>check(size_t, const std::string&)const;
	std::weak_ptr<std::vector<std::string>>wptr;
	size_t curr; 
};

StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }
StrBlobPtr StrBlob::end(){
	auto tmp = StrBlobPtr(*this, data->size());
	return tmp;
}


std::shared_ptr<std::vector<std::string>> 
StrBlobPtr::check(size_t i, const std::string &msg) const
{
	auto ret = wptr.lock();
	if(!ret)
		throw std::runtime_error("unbound");
	if(i >= ret->size())
		throw std::out_of_range(msg);
	return ret;
}
std::string& StrBlobPtr::deref() const
{
	auto p = check(curr, "past end");
	return (*p)[curr];
}
StrBlobPtr& StrBlobPtr::incr()
{
	check(curr, "incr past end");
	++curr;
	return *this;
}
void solve()
{
	StrBlob p1({"ab", "bc", "cd"});
	StrBlobPtr a = p1.begin();

	// if(a!=p1.end())
	// 	std::cout<<"SDF\n";
	while(a!=p1.end())
	{
		std::cout<<a.deref()<<std::endl;
		a.incr();
	}
}


signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);std::cout.tie(nullptr);

	// A::solve();
	solve();
	return 0;
}