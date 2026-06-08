class Solution {
public:
    bool isPalindrome(string s) {

        // clean string

        string cleaned = ""; // make cleaned string

        for (char c : s) { // loop through chars c in string s
            if (isalnum(c)) {
                cleaned += tolower(c);
            }
        }

        // check if palindrome

        int length = cleaned.size(); // get size once to avoid overcalculation

        if (length > 1) { // if s multiple characters...

            for (int i = 0; i < length; i++) { // loop through string s 

                int reverse = length - 1 - i; // get reverse position

                // if inverse char not the same
                if (cleaned[i] != cleaned[reverse]) return false;
            }

            return true; // return true if palindrome
        }

        else return true; // if s one character return true
    }
};
