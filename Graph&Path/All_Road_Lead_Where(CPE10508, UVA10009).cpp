#include <iostream>
#include <cstring>
#include <map> //map
#include <algorithm> //reverse
using namespace std;
int main(){
    int n, path, ask;
    string start, end;
    string path1, path2;
    cin >> n;
    bool first=true;
    while(n--){
        cin >> path >> ask;
        map<char, char> from;
        while(path--){
            cin >> start >> end;
            from.insert(pair<char, char> (end.at(0), start.at(0)));   //from[end]=start !!!!, not from[start]=end
        }
        if(first==1)    first=0;
        else    cout << endl;
        while(ask--){
            cin >> start >> end;
            path1.clear();
            path2.clear();
            //path1[0] = start[0];  //error if doing like this way :(
            //path2[0] = end[0];
            path1.push_back(start[0]);
            path2.push_back(end[0]);
            /*char last1=path1.back(), last2=path2.back();  //can, but actually don't need last1 & last2
            while(last1!='R'){
                path1.push_back(from[last1]);
                last1=path1.back();
            }   
            while(last2!='R'){
                path2.push_back(from[last2]);
                last2=path2.back();
            }  
            char add_back;
            while(path1.back()==path2.back()){
                add_back = path1.back();
                path1.pop_back();
                path2.pop_back();
            }
            path1.push_back(add_back);*/

            while (path1.back() != 'R')    path1.push_back(from[path1.back()]);
            while (path2.back() != 'R')    path2.push_back(from[path2.back()]);
            char add_back;
            while (path1.back() == path2.back())
            {
                add_back = path1.back();
                path1.pop_back();
                path2.pop_back();
            }
            path1.push_back(add_back);

            /*while(path1.back()!='R'&&path2.back()!='R'){           //this one is fault and no needed
                last1 = path1.back();
                last2 = path2.back();
                if(last1!='R')   path1.push_back(from[last1]);
                if(last2!='R')   path2.push_back(from[last2]);
                if(path1.back()==path2.back()){
                    //path1.erase(path1.end()-1); //this way also can
                    path1.pop_back();
                    while()
                    break;
                }
            }*/
            reverse(path2.begin(), path2.end());
            path1 += path2;
            cout << path1 << endl;
            
        }
        //cout << endl; //uva suck :(((
    }
    return 0;
}
