//
// Created by 80771 on 2021/7/23.
//
//单个参数列表  template<typename T>
//多个参数列表  template<typename T,typename S>
namespace template_test{
    template<typename T,typename S>
    T min(const T&a,T const &b,S s){
        cout<<s<<endl;
        if (a>b){
            return b;
        }
        return a;
    }
    template<typename T>
    T max(const T &a,T const &b){
        if(a>b){
            return a;
        }
        return b;
    }
    template<class T,class Z>
    class point{
    private:
            T x;
            T y;
            Z m;
            T* z;
    public:
            point(Z m,T x,T y,int size){
                this->m=m;
                this->x=x;
                this->y=y;
                this->z=new T[size];
            }
            ~point(){
                delete[] z;
            }
            void output(){
                cout<<this->x<<":"<<this->m<<":"<<this->y<<":"<<this->z<<endl;
            }
        };
    void test(){
        int a=1;
        int b=2;
        int c=max(a,b);
        cout<<c<<endl;
        point<int,char> p('a',1,2,3);
        p.output();
    }
}
