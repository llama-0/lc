class Solution {
public:
    bool isPalindrome(int x) {
        int tmp = x;
        int res = 0;
        int base = 10;
        if (x < 0 && x > INT_MIN) {
            x = abs(x); // may be a costly operation... 
                        //and for INT_MIN returns value that is more than INT_MAX by 1 (so the overflow happens). 
                        // That's why the check of x > INT_MIN.
        }
        while (x != 0) {
            res *= base;
            res += x % base;
            x /= base;
        }
        if (res == tmp) {
            return true;
        } else {
            return false;
        }   
    }
};