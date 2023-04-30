#include <iostream>
using namespace std;

template <typename T> class Pair {
    T first, second;

  public:
    Pair(T f, T s) {
        first = f;
        second = s;
    }

    T getFirst() { return first; }

    T getSecond() { return second; }
};

int main() { 
    Pair<int> p1(10,20);
    Pair<char> p2('a', 'b');


    cout <<p1.getFirst()<<endl;
    cout <<p1.getSecond()<<endl;
    cout <<p2.getFirst()<<endl;
    cout <<p2.getSecond()<<endl;

    return 0; 

}