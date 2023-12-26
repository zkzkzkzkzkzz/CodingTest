#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        int len1 = s.length();
        int len2 = t.length();

        if (len1 != len2)
        {
            return false;
        }

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
};


int main()
{
    Solution sol;

    string s1 = "anagram";
    string s2 = "nagaram";

    sol.isAnagram(s1, s2);

    return 0;
}