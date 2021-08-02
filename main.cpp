#include "object.cpp";
#include "sort.cpp";
#include "template.cpp";
struct point{
    int x;
    int y;
};
#define print_point(p) printf("%d %d\r\n",p.x,p.y)
int main() {
    int (*p)[3];
    int a[3]={123,456,789};
    int b=1234;
    p = &a;
    cout<<&b<<endl;

    cout<<a<<endl;
    cout<<a+1<<endl;
    cout<<a+2<<endl;
    cout<<a+3<<endl;
    cout<<a+4<<endl;

    cout<<&a<<endl;
    cout<<&a+1<<endl;
    cout<<&a+2<<endl;
    cout<<&a+3<<endl;
    cout<<&a+4<<endl;
    //对比a+x和&a+x的输出,会发现递增的字节数不一样
    // a+x是  8 12 16 20 24
    // &a+x是 12 24 36 48 60
    // 为什么呢?  因为a代表了数组第一个元素的地址 &a代表的是这块数组整个的地址
    // 虽然a和&a的输出是一样的,但是他两跨步的幅度不是一样的,一个是以单个元素增长,一个是整个数组元素长度增长

    cout<<(&a+3)-(&a+2)<<endl;

    cout<<*a+2<<endl;
    cout<<&a<<endl;
    cout<<p<<endl;
    cout<<&p<<endl;
    cout<<p+2<<endl;
    cout<<*(p+2)<<endl;
//    sort_test::test();
//    object_test::test();
//    template_test::test();

}


