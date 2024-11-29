#include<iostream>
using namespace std;
//bottom up approach
int path(int r,int c){
    return (r==0 || c==0)?1:path(r-1,c)+path(r,c-1);
}

int main(){
cout<<path(4,4);
return 0;

} 