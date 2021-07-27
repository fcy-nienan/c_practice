#include "object.cpp";
#include "sort.cpp";

int main() {
    int y=100;
    int x[10];
    for (int i = 0; i < 10; ++i) {
        cout<<&x[i]<<endl;
    }
    int a=1111;
    int b;
    int c;
    cout<<&y<<endl;
    cout<<&a<<endl;
    cout<<&b<<endl;
    cout<<&c<<endl;
    cout<<x+1<<endl;
    cout<<*(x-3)<<endl;
//    sort_test::test();
//    object_test::test();
}


