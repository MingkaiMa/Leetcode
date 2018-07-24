class Solution {
public:
    int getSum(int a, int b) {
        int sum = a ^ b;
        int carry = (a & b) << 1;
        while(carry) {
            int x = sum;
            int y = carry;
            sum = x ^ y;
            carry = (x & y) << 1;
        }
        return sum;
    }
};
