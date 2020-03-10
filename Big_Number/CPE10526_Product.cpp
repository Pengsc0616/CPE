#include <iostream>
#include <cstring>
#include <algorithm> //reverse
using namespace std;

string operator * (string &a, string &b){
    for(int i=0; i<a.size(); i++)   a.at(i)-=48;
    for(int j=0; j<b.size(); j++)   b.at(j)-=48;
    reverse(a.begin(), a.end());  //neccessarily   012345...=>....543210
    reverse(b.begin(), b.end());
    string c( a.size()+b.size(), 0); 
    for(int i=0; i<a.size(); i++){
        for(int j=0; j<b.size(); j++){
            c.at(i+j) += a.at(i)*b.at(j);
        }
        for(int k=0; k<c.size()-1; k++){
            c.at(k+1) += c.at(k)/10;
            c.at(k) %= 10;
        }
    }
    for(int k=0; k<c.size(); k++)   c.at(k)+=48;
    if(c.at(c.size()-1)=='0')    c.resize(a.size()+b.size()-1);
    reverse(c.begin(), c.end());

    return c;
}
int main(){
    string first, second;
    while(cin >> first >> second){
        if (first.at(0) != '0' && second.at(0) != '0')    cout << first * second << endl;
        else cout << "0" << endl;
    }
    return 0;
}