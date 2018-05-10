class Solution {
public:
    int reverse(int x) {
        long res = 0;
        int base = 10;
        while (x != 0) {
            res *= base;
            res += x % base;
            x /= base;
        }
        if (res > INT_MAX || res < INT_MIN) {
            return 0;
        } else {
            return (int)res;
        }
    }
};