class Solution {
public:
    double myPow(double x, int n) {
        long long exp = n;

        if (exp < 0) {
            x = 1 / x;
            exp = -exp;
        }

        double result = 1.0;

        while (exp > 0) {
            // If the current bit is 1
            if (exp % 2 == 1) {
                result *= x;
            }

            // Move to the next bit
            x *= x;
            exp /= 2;
        }

        return result;
    }
};