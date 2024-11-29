#include <iostream>
using namespace std;
// Function prototypes
void pip(int n){
    if(n==0) return;
    cout<<"pre"<<n;
    pip(n-1);
    cout<<"pin"<<n;
    pip(n-1);
    cout<<"post"<<n;


}

int main() {
    // Call the greet function
   pip(2);
    // Return 0 to indicate successful execution
    return 0;
}
