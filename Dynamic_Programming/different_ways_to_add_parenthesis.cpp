#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void diffWaysToCompute(string expression) {
        ev(0,expression, 0);
    }

private:
    int ev(int evalu,const string& s, int index) {
        if (index >= s.length()) {
            return evalu; 
        }

       
            ev(evalu,s, index + 1);
            cout << evalu << " "; 
       
          
            if (index + 1 < s.length()) {
                char op = s[index];
                int left = s[index - 1] - '0'; 
                int right = s[index + 1] - '0'; 

                int evalu = 0;

                if (op == '*') {
                    evalu = left * right;
                } else if (op == '+') {
                    evalu = left + right;
                } else if (op == '-') {
                    evalu = left - right;
                }

                cout << evalu << " ";
                ev(evalu,s, index + 2);
            }
        
    }
};

int main() {
    Solution solution;
    solution.diffWaysToCompute("2*3-4*5");
    return 0;
}
