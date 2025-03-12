#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin, s);

    set<char>unique_chars;

    for(char c : s){
        unique_chars.insert(c);
    }
    for(char c : unique_chars){
        cout << c;
    }
    return 0;
}
