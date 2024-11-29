#include<iostream>
using namespace std;

string shortestPalindrome(string s) {
    int i=0,j=s.length()-1;
    while(i<j){
if(s[i]==s[j])
{
    i++;
    j--;
    continue;
}
string left=s.substr(0,i);
string right=s.substr(i);
// cout<<"left : "<<left<<endl;
// cout<<"right : "<<right<<endl;

left.push_back(s[j]);
s=left+right;
i++;

    }
    return s;
        
    }

int main(){

cout<<shortestPalindrome("aacecaaa");







}