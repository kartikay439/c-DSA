#include <iostream>
#include <vector>
using namespace std;

int c = 0;

void fun(vector<int>& v, int count, int and_curr, int index) {
    if (index >= v.size()) {
        c = max(c, count);
        return;
    }
    if ((and_curr & v[index]) >= and_curr) {
        fun(v, count + 1, and_curr & v[index], index + 1);
    }
    fun(v, count, and_curr, index + 1);
}

int main() {
    vector<int> v = {16, 17, 71, 62, 12, 24, 14};
    fun(v, 0, ~0, 0);  // Changed initial value of and_curr to bitwise NOT of 0 to ensure correct comparison
    cout << c << endl;
    return 0;
}
