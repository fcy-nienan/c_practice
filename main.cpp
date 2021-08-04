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

    cout<<sizeof a<<endl; //数组占用空间的大小 3*4=12bytes
    cout<<sizeof &a<<endl;//指针的大小 8byte

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


    cout<<&a[0]<<endl;
    cout<<&a[1]<<endl;
    //  &a[0]又是什么???
    //  arr &arr and &arr[0] all store the address of the first value in your array that is the address of arr[0].
    //  Note that the type of arr and &arr[0] is different from the type of &arr. Also, the behaviour of arr + 1 and &arr + 1 is quite different in genera

    cout<<(&a+3)-(&a+2)<<endl; // 1

    cout<<*a+2<<endl; //123 + 2 = 125
    cout<<&p<<endl;

    cout<<&a<<endl;
    cout<<p<<endl;
    cout<<*p<<endl;
    cout<<p+2<<endl; // p是指向一个有三个元素的数组,p与&a类似,p的跨度也是三个元素的大小,所以p+2= 3*4*2=24的跨度
    cout<<*(p+2)<<endl;
//    sort_test::test();
//    object_test::test();
//    template_test::test();

}


