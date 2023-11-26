#include<iostream>

using namespace std;

int f(int a) {
    int b = 0;
    static int c = 2;
    a = c++, b++;
    return (a);
}

int main() {
    int a = 3, i, k;
    for (i = 0; i < 3; i++)
        k = f(a++);
    cout << k << endl;
    return 0;
}