#include<bits/stdc++.h>

class StrBlobPtr;

class StrBlob {
   friend class StrBlobPtr;
public:
   typedef std::vector<std::string>::size_type size_type;
   StrBlob();
   StrBlob(std::initializer_list<std::string> il);
   StrBlob(const StrBlob &obj)
   		: data(new std::vector<std::string>(*obj.data)) {}
   StrBlob &operator=(const StrBlob &rhs) {
   		data = rhs.data;
   		return *this;
   }
   size_type size() { return data->size(); }
   const size_type size() const { return data->size(); }
   bool empty() { return data->empty(); }
   void push_back(const std::string &s) { data->push_back(s); }
   void push_back(std::string &&s) {data->push_back(std::move(s));}
   void pop_back();
   std::string& front();
   const std::string& front() const;
   std::string& back();
   const std::string& back() const;
private:
   std::shared_ptr<std::vector<std::string>> data;
   void check(size_type i, const std::string &msg) const;

   friend class StrBlobPtr;
   StrBlobPtr begin(); // 不建议将实现写在此处，会造成"incomplete type is not allowed" error
   StrBlobPtr end();
};
StrBlob::StrBlob() {
   data = std::make_shared<std::vector<std::string>>();
}

StrBlob::StrBlob(std::initializer_list<std::string> il) {
   data = std::make_shared<std::vector<std::string>>(il);
}

void StrBlob::check(size_type i, const std::string &msg) const {
   if (i >= data->size()) {
      throw std::out_of_range(msg);
   }
}

void StrBlob::pop_back() {
   check(0, "pop_back on empty StrBlob");
   data->pop_back();
}

std::string& StrBlob::front() {
   check(0, "front on empty StrBlob");
   return data->front();
}

const std::string& StrBlob::front() const {
   check(0, "front on empty StrBlob");
   return data->front();
}

std::string& StrBlob::back() {
   check(0, "back on empty StrBlob");
   return data->back();
}

const std::string& StrBlob::back() const {
   check(0, "back on empty StrBlob");
   return data->back();
}



class StrBlobPtr
{
public:
   StrBlobPtr():curr{0}{}
   StrBlobPtr(StrBlob &a, size_t sz = 0)
      : wptr(a.data), curr(sz){}
   ~StrBlobPtr() {};
   std::string &deref() const;
   StrBlobPtr &incr();
   friend bool eq(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
private:
   std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;
   std::weak_ptr<std::vector<std::string>> wptr;
   std::size_t curr;
};
StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }
StrBlobPtr StrBlob::end() { return StrBlobPtr(*this, data->size()); }



std::string & StrBlobPtr::deref() const {
   auto p = check(curr, "Dereference past the end");
   return (*p)[curr];
}
StrBlobPtr & StrBlobPtr::incr() {
   check(curr, "Increment past the end");
   ++curr;
   return *this;
}

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(std::size_t sz, const std::string &msg) const {
   auto p = wptr.lock();
   if (p) {
      if (p->size() > sz) {
         return p;
      }
      else {
         throw std::out_of_range(msg);
      }
   }
   else {
      throw std::runtime_error("unbound StrBlobPtr");
   }
}

bool eq(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
   auto lp = lhs.wptr.lock(), rp = rhs.wptr.lock();
   if (lp == rp) {
      return (!lp || lhs.curr == rhs.curr);
   }
   else {
      return false;
   }
}


void solve()
{
}
signed main(){

		solve();
	return 0;
}