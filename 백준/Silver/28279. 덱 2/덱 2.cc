#include <iostream>
#include <memory>
#include <utility>
#include <deque>

#define fi first
#define se second

using namespace std;

using ll=long long;


template<class T>
class Deque{
    struct Node{
        Node *l,*r;
        T val;
        Node(Node *l=nullptr,Node *r=nullptr,T val=T()):l(l),r(r),val(val){}
        ~Node(){}
    };
    
    Node *beg,*ed;
    std::size_t sz;
    
    using Alloc=std::allocator<Node>;
    using Traits=std::allocator_traits<Alloc>;
    
    Alloc alloc;
    
    
public:
    Deque(){
        beg=Traits::allocate(alloc,1);
        ed=beg;
        Traits::construct(alloc,beg);

        sz=0;
    }
    ~Deque(){
        Node* it=beg;
        while(it!=nullptr){
            Node *tmp=it->r;
            Traits::destroy(alloc,it);
            Traits::deallocate(alloc,it,1);
            it=tmp;
        }
    }
    
    void push_front(T val){
        Node *newNode=Traits::allocate(alloc,1);
        Traits::construct(alloc,newNode,nullptr,beg,val);
        
        beg->l=newNode;
        beg=newNode;
        sz++;
    }
    
    void push_back(T val){
        Node *newEnd=Traits::allocate(alloc,1);
        *ed=Node(ed->l,newEnd,val);
        Traits::construct(alloc,newEnd,ed,nullptr,T());
        ed=newEnd;
        sz++;
    }
    
    void pop_front(){
        if(sz==0)throw std::invalid_argument("No elements in deque.\n");
        Node *tmp=beg;
        beg=beg->r;
        Traits::destroy(alloc,tmp);
        Traits::deallocate(alloc,tmp,1);
        sz--;
    }
    
    void pop_back(){
        if(sz==0)throw std::invalid_argument("No elements in deque.\n");
        Node *tmp=ed;
        ed=ed->l;
        ed->r=nullptr;
        Traits::destroy(alloc,tmp);
        Traits::deallocate(alloc,tmp,1);
        sz--;
    }
    
    T front(){
        if(sz==0)throw std::invalid_argument("No elements in deque.\n");
        return beg->val;
    }
    
    T back(){
        if(sz==0)throw std::invalid_argument("No elements in deque.\n");
        return ed->l->val;
    }
    
    bool empty(){
        return sz==0;
    }
    
    size_t size(){
        return sz;
    }
    
    class iterator{
        Node *x;
    public:
        iterator(Node *x=nullptr):x(x){}
        
        iterator& operator++(){
            x=x->r;
            return *this;
        }
        iterator operator++(int){
            iterator t=*this;
            ++(*this);
            return t;
        }
        
        iterator& operator--(){
            x=x->l;
            return *this;
        }
        iterator operator--(int){
            iterator t=*this;
            --(*this);
            return t;
        }
        
        
        bool operator!=(const iterator &ref) const{
            return x!=ref.x;
        }
        
        bool operator==(const iterator &ref) const{
            return x==ref.x;
        }
        
        T& operator*() const {
            return x->val;
        }
    };
    
    iterator begin(){
        return iterator(beg);
    }
    
    iterator end(){
        return iterator(ed);
    }
};

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    Deque<int>ls;
    int N;cin>>N;
    while(N--){
        string s;cin>>s;
        if(s=="1"){
            int x;cin>>x;
            ls.push_front(x);
        }else if(s=="2"){
            int x;cin>>x;
            ls.push_back(x);
        }else if(s=="3"){
            if(ls.empty())cout<<"-1\n";
            else{
                cout<<ls.front()<<"\n";
                ls.pop_front();
            }
        }else if(s=="4"){
            if(ls.empty())cout<<"-1\n";
            else{
                cout<<ls.back()<<"\n";
                ls.pop_back();
            }
        }else if(s=="5"){
            cout<<ls.size()<<"\n";
        }else if(s=="6"){
            cout<<ls.empty()<<"\n";
        }else if(s=="7"){
            if(ls.empty())cout<<"-1\n";
            else cout<<ls.front()<<"\n";
        }else if(s=="8"){
            if(ls.empty())cout<<"-1\n";
            else cout<<ls.back()<<"\n";
        }
    }
    return 0;
}
