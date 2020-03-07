#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    string s;
    s.clear();
    while (cin >> s && s[0] != '.')
    {
        bool flag = 1;
        for (int i = 1; i <= int(s.size()); i++) //i is for repeat string length
        {
            flag = 1;
            if(s.size()%i!=0)   continue;  //remove this line will get TLE
            for (int k = 0; k < int(s.size()) ;) //k run through the whole string everytime
            {
                for (int j = 0; j < i; j++, k++) //j is for s[0] to s[i-1]
                {
                    if (s[j] != s[k])
                    {
                        flag = 0;
                        break;
                    }
                }
                if (flag == 0)
                    break;
            }
            if (flag == 1)
            {
                cout << s.size() / i << "\n";
                break;
            }
        }
        s.clear();
    }
    return 0;
}
