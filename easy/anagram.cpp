class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.size() != t.size()) { // if string sizes unequal...

            return false; // return false immediately
        }

        // in string, store character type and count
        unordered_map<char, int> stringOne, stringTwo;

        for (int i = 0; i < s.size(); i++) { // loop through strings

            stringOne[s[i]]++;
            stringTwo[t[i]]++;
        }

        return stringOne == stringTwo; // compare string chars and counts
    }
};
