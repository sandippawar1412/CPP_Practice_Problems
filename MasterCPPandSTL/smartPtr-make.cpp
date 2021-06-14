#include<iostream>
#include<memory>
using namespace std;

int main(){
    unique_ptr<int> up (new int{5});
    //OR
    auto up1 = make_unique<int>(5);

    shared_ptr<float> sp (new float{1.2});
    //OR
    auto sp1 = make_shared<float>(1.2);

    //Dynamic array
    unique_ptr<int[]> upArr(new int[5]{1,2,3});
    //OR
    auto upArr1 = make_unique<int[]>(5); // We can not initialize 

    shared_ptr<int[]> spArr(new int[5]{1,2,3}); 
    //auto spArr1 = make_shared<int[]>(5); // in >=C++17

}