#include"iostream"
#include"vector"
using namespace std;
    long long minEnd(int n, int x) {
        vector<int> v(64,0);
        vector<int> c(32,0);
        for(int i=0;i<32;i++){
            v[64-i-1]=(x & ( 1 << i )) >> i;
            c[32-i-1]=(n & ( 1 << i )) >> i;
        }
        for(auto i:v){
            cout<<i<<" ";
        }  
        cout<<endl;  
        for(auto i:c){
            cout<<i<<" ";
        }  
        cout<<endl<<c[c.size()-1]<<" ts last ";
        return 0;
    }
int main(){
minEnd(15,15);
}
