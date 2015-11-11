#include <string>
#include <vector>
#include <iostream>
using namespace std;

void computeNext(string& s, vector<int>& vec);
int stringMatch(string&, string&);//KMP

int main(int argc, char **argv)
{
    string s1, s2;
    cout << "Enter 2 strings:" << endl;
    cin >> s1 >> s2;
    cout << "string1 = " << s1;
    cout << "\nstring2 = " << s2 << endl;
    cout << "The substring starts at " << stringMatch(s1, s2) << endl;
    return 0;
}

void computeNext(string &s, vector<int>& vec)
{
    vec.push_back(-1);
    vec.push_back(0);
    for(string::size_type i = 2; i < s.size(); ++i)
    {
        int j = vec.at(i - 1);
        while(j >= 0 && s.at(i - 1) != s.at(j))
        {
            j = vec.at(j);
        }
        vec.push_back(j + 1);
    }
/*    for(vector<int>::size_type i = 0; i != vec.size(); ++i)
        cout << vec.at(i);
    cout << "\nfinished\n";
*/

}

int stringMatch(string& str, string& sub)
{
    vector<int> next;
    computeNext(sub, next);
    int start = 0;
    int i, j;
    i = j = 0;
    while(i != static_cast<int>(str.size()))
    {
        if(str.at(i) == sub.at(j))
        {
            ++i;
            ++j;
        }
        else
        {
            j = next.at(j);
            if(j == -1)
            {
                j = 0;
                ++i;
            }
        }
        if(j == static_cast<int>(sub.size()))
        {
            start = i - static_cast<int>(sub.size());
            break;
        }

    }
    return start;
}
