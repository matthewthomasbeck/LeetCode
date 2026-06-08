class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.size() != t.size()) { // if string sizes unequal...

            return false; // return false immediately
        }

        int freq[26] = {0}; // initialize frequency table to 0 with max 26 english chars

        for (int i = 0; i < s.size(); i++) { // loop through string lengths

            // in c++, characters have numerical values; a = 97, and because it is the first
            // character in the alphabet, every other character is:
            // <char> - 'a'(97) = <char's position in the alphabet>
            // this code finds the correct char's index in the table, and then increments if
            // character in string 's', and then decrements if the character in string 't'
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++) { // loop through all characters in the alphabet

            // if character count is not 0, then strings not the same
            if (freq[i] != 0) return false;
        }

        return true; // return true by default
    }
};
