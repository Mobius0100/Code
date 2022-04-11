#include <iostream>

using namespace std;

int main()
{
    int x;

    while(Q.length() != 0){
        S.push(Q.dequeue());
    }

    while(S.top != 0){
        x = S.topValue();
        Q.enqueue(x);
    }

    return 0;
}