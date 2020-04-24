#include <iostream>
using namespace std;

typedef struct segment{
    int left, right;
}Segment;
Segment gave[100000], ans[100000];
Segment dynamic_range;
Segment temp_choose = {0, 0};
int num, range, ans_num; //, temp_right;
int Calculate(){
    dynamic_range = {0, 0};
    //temp_right = -100;
    ans_num = 0;
    while(temp_choose.right < range){
        for(int i=0; i<num; i++){
            if(gave[i].left>dynamic_range.left || gave[i].right<=dynamic_range.right)   continue;
            if(gave[i].right > temp_choose.right){
                temp_choose = gave[i];
            }
        }
        if(temp_choose.left!=0 && temp_choose.right!=0){
            ans[ans_num++] = temp_choose;
            dynamic_range.right = temp_choose.right;
        }
        else return 0;
    }
    return ans_num;
}
int main(){
    int n;
    //, range;
    cin >> n;
    bool first = true;
    while(n--){
        cin >> range;
        num = 0;
        while(cin >> gave[num].left >> gave[num].right){  //then num will be the total number of "gave"
            if(gave[num].left==0 && gave[num].right==0) break;
            num++;
        }
        if(first==true) first=false;
        else cout << endl;
        cout << Calculate();
        for(int i=0; i<ans_num; i++){
            cout << ans[i].left << ' ' << ans[i].right << endl;
        }

    }
}
