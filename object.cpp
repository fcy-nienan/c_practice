//
// Created by 80771 on 2021/7/22.
//
#include "using_cout.h"
namespace object_test{
    class point{
    private:
        int x;
        int y;
    public:
        point(int x,int y);
        ~point();
        void output();
        double circle();
    };
    point::point(int x, int y) {
        this->x=x;
        this->y=y;
    }
    point::~point() {
        cout<<"析构函数"<<endl;
        cout<<"析构函数调用的三种时机:"<<endl;
        cout<<"    本对象消亡"<<endl;
        cout<<"    delete对象的指针"<<endl;
        cout<<"    A是B对象的成员,B的析构调用的时候A的也会被调用"<<endl;
    }
    void point::output() {
        cout<<"x is "<<x<<endl;
        cout<<"y is "<<y<<endl;
    }
    double point::circle() {
        return x*3.14;
    }

    void test_1(){
        point p(1,2);
        point p1=point(1,2);
        point* p2=new point(1,2);
        delete p2;
        cout<<"创建对象的三种方式,前两种是栈上分配,最后一种是堆上分配"<<endl;
    }

    class point1{
    public:
        point1(){};
    protected://为什么使用protected而不是使用private?  使用private的话,无法解决继承问题
        ~point1(){};
    public:
        //为什么创建下面的函数?
        // 一个问题是，类的使用很不方便，使用new建立对象，却使用destory函数释放对象，而不是使用delete。
        // （使用delete会报错，因为delete对象的指针，会调用对象的析构函数，而析构函数类外不可访问）这种使用方式比较怪异。
        // 为了统一，可以将构造函数设为protected，然后提供一个public的static函数来完成构造，
        // 这样不使用new，而是使用一个函数来构造，使用一个函数来析构
        static point1* create(){
            return new point1();
        }
        void destroy(){
            delete this;
        }
    };
    void test_only_heap_create_object(){
//        point1 p1;//编译错误
//        point p2=point();//编译错误
        point1* p3=new point1();
        cout<<"析构函数私有时不能在栈上创建对象"<<endl;
        cout<<"当对象建立在栈上面时，是由编译器分配内存空间的，调用构造函数来构造栈对象。"<<endl<<
              "当对象使用完后，编译器会调用析构函数来释放栈对象所占的空间。编译器管理了对象的整个生命周期。"<<endl<<
              "如果编译器无法调用类的析构函数，情况会是怎样的呢？比如，类的析构函数是私有的，编译器无法调用析构函数来释放内存。"<<endl<<
              "所以，编译器在为类对象分配栈空间时，会先检查类的析构函数的访问性，"<<endl<<
              "其实不光是析构函数，只要是非静态的函数，编译器都会进行检查。"<<endl<<
              "如果类的析构函数是私有的，则编译器不会在栈空间上为类对象分配内存。"<<endl;
        cout<<"一个缺点就是，无法解决继承问题。如果A作为其它类的基类，则析构函数通常要设为virtual，然后在子类重写，以实现多态。"<<endl<<
              "因此析构函数不能设为private。还好C++提供了第三种访问控制，protected。"<<endl<<
              "将析构函数设为protected可以有效解决这个问题，类外无法访问protected成员，子类则可以访问。"<<endl;


    }

    class point3{
    private:
        void *operator new(size_t t){};
        void operator delete (void* ptr){};
    public:
        point3(){};
        ~point3(){};
    };
    void test_only_stack_create_object(){
        point3 a;
        point3 b=point3();
//        point3* p=new point3();//编译错误

        cout<<"只有使用new操作符才会在堆上创建对象,因此只要禁止使用new操作符就行了,将operate new 设置为私有就行了"<<endl;
    }
    void test(){
        test_1();
        test_only_heap_create_object();
        test_only_stack_create_object();
    }
}
