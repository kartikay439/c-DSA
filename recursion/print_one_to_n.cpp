#include<iostream>
using namespace std;
void counting(int n,int t){
    if(n==t+1){
        return ;
    }
    cout<<n<<endl;
    counting(n+1,t);
}

int main(){
counting(1,10);
return 0;

}