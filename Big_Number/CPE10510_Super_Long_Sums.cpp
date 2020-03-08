#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
    char carry[1000001], first[1000001], second[1000000]; 
    //, ans[1000003];
    
    int times=0, digit=0;
    int counts=0;
    cin >> times;
    while(times--){
        cin >> digit;
        memset(carry, 0, sizeof(carry));
        memset(first, 0, sizeof(first));
        memset(second, 0, sizeof(second));
        //memset(ans, 0, sizeof(ans));
        for(int i=digit-1; i>=0; i--){
            cin >> first[i] >> second[i];
            first[i]-=48;
            second[i]-=48;
        }
        for(int i=0; i<digit; i++){
            carry[i+1]=(first[i]+second[i]+carry[i])/10;
            first[i]=(first[i]+second[i]+carry[i])%10;   //put answer back in first_array
        }
        if(counts!=0)   cout << '\n';
        if(carry[digit]!=0) cout << int(carry[digit]);
        for(int i=digit-1; i>=0; i--){
            cout << int(first[i]);
        }
        cout << '\n';
        counts++;
    }
    return 0;
}
