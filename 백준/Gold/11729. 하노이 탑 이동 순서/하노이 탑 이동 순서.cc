#include <iostream>
using namespace std;

void func(int currentIndex, int SiftIndex, int deep)
{
    if (deep <= 0)
    {
        return;
    }
    int nextSift = SiftIndex == 1 ? 2 : 1;
    int nextIndex = (currentIndex + SiftIndex) % 3;
    func(currentIndex, nextSift, deep - 1);
    cout << currentIndex + 1 << " " << nextIndex + 1  <<  '\n';
    func((currentIndex + nextSift) % 3, nextSift, deep - 1);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int count = 0;
    cin >> count;
    cout << (1 << count) - 1 << '\n';
    cin >> count;
    func(0, 2, count);
}