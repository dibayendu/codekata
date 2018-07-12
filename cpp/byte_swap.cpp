/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <iostream>
#include <vector>

class A {
    int b =5;
    public:
        int *a=&b;

};

int main()
{
    unsigned int num = 1;
    unsigned int x = 1;

    unsigned int swapped = ((num>>24)&0xff) | // move byte 3 to byte 0
                    ((num<<8)&0xff0000) | // move byte 1 to byte 2
                    ((num>>8)&0xff00) | // move byte 2 to byte 1
                    ((num<<24)&0xff000000); // byte 0 to byte 3

                    // num = swapped;

                    // swapped = ((num>>24)&0xff) | // move byte 3 to byte 0
                    // ((num<<8)&0xff0000) | // move byte 1 to byte 2
                    // ((num>>8)&0xff00) | // move byte 2 to byte 1
                    // ((num<<24)&0xff000000); // byte 0 to byte 3

    unsigned int s1 = x&(0xff);
    // x=x>>8;
    unsigned int s2 = x&(0xff00);
    // x=x>>8;
    unsigned int s3 = x&(0xff0000);
    // x=x>>8;
    unsigned int s4 = x&(0xff000000);

    unsigned int s = 0;
    s |= s1<<24;
    s |= s2<<16;
    s |= s3<<8;
    s |= s4;

    printf("%d\n", s);


    int v = 10;
    int *ref=&v;

    std::cout << ref << std::endl;
    std::cout << &v << std::endl;
    std::cout << *&v << std::endl;
    std::cout << &ref << std::endl;

    std::vector<int>  items;
    items.push_back(1);
    items.push_back(2);
    items.push_back(NULL);
    std::cout << items.size() << std::endl;
    items.erase(items.begin()+1);

    A a;
    *(a.a) = 4;
    A B=a;
    *(B.a)=10;

    std::cout << *(a.a) << std::endl;
    std::cout << std::stoi("0012") << std::endl;
    return 0;
}

