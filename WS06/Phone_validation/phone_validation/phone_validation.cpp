#include <iostream>
using namespace std;

int main() {
    bool result = false;
    long long newPhone = 1416234567890LL;
    int justPhone = newPhone % 10000000;
    int country = (int)(newPhone / 10000000000);
    int area = (int)((newPhone % 10000000000) / 10000000);

    if (country < 100 && country != 0 && (int)(area / 100) != 0 && (int)(justPhone / 1000000) != 0)
        result = true;

    cout << country << endl;
    cout << area << endl;
    cout << justPhone << endl;
    cout << (int)(area / 100) << endl;
    cout << (int)(justPhone / 1000000) << endl;
    cout << result << endl;

    return 0;
}