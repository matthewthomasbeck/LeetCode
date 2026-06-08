class Solution {
public:
    bool isPalindrome(string s) {

        // define l and r

        int l = 0; // starting from the left at index 0
        int r = s.size() - 1; // starting from the right at furthest position

        // walk to the middle

        while (l < r) { // walk to the middle

            // skip non alphanumeric characters by adjusting r and l pos

            // while not at middle and char at pos l not alphanumeric
            while (l < r && !isalnum(s[l])) {
                l++; // increment l to advance l pointer to valid char
            }

            // while not at middle and char at pos r is not alphanumeric
            while (l < r && !isalnum(s[r])) {
                r--; // decrement r to retreat r pointer to valid char
            }

            // check if palindrome with adjusted r and l pointers

            // if char at pos r not the same as char at pos l, not palindrome
            if (tolower(s[r]) != tolower(s[l])) return false;

            l++; // increment l
            r--; // decrement r
        }

        return true; // return is palindrome
    }
};
