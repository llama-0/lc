// vector<int> to int converter
int converter(vector<int> v) {
    long res = 0;
    for (auto d : v) {
        res = res * 10 + d; // when neg int digit is passed here it act as it is: -a = -a * 10 + (-b).
        if (res < INT_MIN || res > INT_MAX) { // check for overflows
            return 0;
        }
    }
    return res;
}

int pos(int x) {
    int base = 10;
    vector<int> res;
        while (x) {
            res.push_back(x % base);
            x /= base;
        }
    int result = converter(res);
    if (result > INT_MAX) {
        return 0;
    } else {
        return result;
    }
}

int neg(int x) {
    int base = 10;
    vector<int> res;
    while (x) {
        res.push_back(x % base); // ex. from -123 here we push -3, -2, -1. How to deal with minuses see converter() function.
        x /= base;
    }
    int result = converter(res);
    if (result < INT_MIN) {
        return 0;
    } else {
        return result;
    }
}

class Solution {
public:
    int reverse(int x) {
        if (x >= 0) {
            return pos(x);
        } else {
            return neg(x);
        }
    }
};