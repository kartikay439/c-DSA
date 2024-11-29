#include<iostream>
using namespace std;
void TOH(int n,char source,char helper,char destination){
    if(n==1){
        cout<<source<<" -->  "<<destination<<endl ;
        return;
     }
    TOH(n-1,source,destination,helper);
    cout<<source<<" -->  "<<destination<<"\n" ;
    TOH(n-1,helper,source,destination);

}

int main(){
TOH(5,'A','B','C');
}