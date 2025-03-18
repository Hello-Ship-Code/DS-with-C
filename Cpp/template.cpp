#include<stdio.h>
#include<iostream>
using namespace std;

template <class T>
class Arithmetic
{
    private:
        T a;
        T b;
    
    public:
        Arithmetic(T a, T b)
        {
            this->a=a;
            this->b=b;
        }
    
    T add();
    T sub();
};
template <class T>
T Arithmetic<T>::add() /*scope resolution :: as they are declare outside the class we need to add this scope resolution*/
{
    T c;
    c=a+b;
    return c;
}
template<class T>
T Arithmetic<T>::sub()
{
    T c;
    c=a-b;
    return c;
}

int main()
{
    /*Arithmetic<int> a(10,5);*/
    Arithmetic<float> a(10.2,5.1);

    cout<<"Addition  : "<<a.add()<<endl;
    cout<<"Subraction: "<<a.sub()<<endl;

}