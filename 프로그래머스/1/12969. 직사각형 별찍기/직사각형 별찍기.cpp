#include <iostream>

using namespace std;

int main(void) {
    int a;
    int b;
    cin >> a >> b;
    
    for (int col = 0; col < b; col++){
        cout << string(a, '*') << endl;
    }
    return 0;
}