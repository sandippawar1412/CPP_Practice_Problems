/*
Reverse the String
Problem Description

Given a string A of size N.

Return the string A after reversing the string word by word.

NOTE:

A sequence of non-space characters constitutes a word.
Your reversed string should not contain leading or trailing spaces, even if it is present in the input string.
If there are multiple spaces between words, reduce them to a single space in the reversed string.
*/

/*
references:
1.Trim
https://www.techiedelight.com/trim-string-cpp-remove-leading-trailing-spaces/

2.Unique
https://stackoverflow.com/questions/8362094/replace-multiple-spaces-with-one-space-in-a-string
*/

#include<bits/stdc++.h>
using namespace std;

const string WHITESPACE = " \n\r\t\f\v";
string ltrim(const string &s)
{
    size_t start = s.find_first_not_of(WHITESPACE);
    return start == string::npos ? "" : s.substr(start);
}

string rtrim(const string &s)
{
    size_t end = s.find_last_not_of(WHITESPACE);
    return end == string::npos ? "" : s.substr(0, end + 1);
}

string trim(const string &s)
{
    return rtrim(ltrim(s));
}

bool comparator(char ch1, char ch2)
{
    return (ch1 == ch2 && ch1 == ' ');
}

string reverseWords(string A)
{
    // string s = trim(A);

    string s = A;
    auto new_end = unique(s.begin(), s.end(), comparator);
    s.erase(new_end, s.end());
    /* instead of this we can also use trim */
    if (s[0] == ' ')
        s.erase(s.begin());
    if (s.back() == ' ')
        s.erase(s.end() - 1);

    reverse(s.begin(), s.end());
    int i = 0;
    while (i < s.length())
    {
        auto spaceOrEndPos = s.find(' ', i);
        if (spaceOrEndPos == string::npos)
        {
            reverse(s.begin() + i, s.end());
            break;
        }
        reverse(s.begin() + i, s.begin() + spaceOrEndPos);
        i = spaceOrEndPos + 1;
    }

    return s;
}

int main()
{
    string s = " This program is to  reverse words  in  string   ";
    cout << setw(10) << "Original: " << s << endl;
    cout << setw(10) << "Reversed: " << reverseWords(s) << endl;

    return 0;
}
