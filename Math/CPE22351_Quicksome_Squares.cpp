#include <iostream>
#include <cmath>  //pow
#include <iomanip> //setw, setfill
using namespace std;
void Map(int n){
    int head, tail;
    int divide = pow(10.0,n/2);
    for(int i=0; i<divide; i++){
        head=(i*i)/divide;
        tail=(i*i)%divide;
        if(i==head+tail)  cout << setw(n) << setfill('0') << i*i << endl;
    }
}
int main(){
    int n;
    while(cin >> n) Map(n);
    return 0;
}
