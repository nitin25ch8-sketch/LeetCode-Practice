class Solution {
public:
    int findNthDigit(int n) 
    {
        long long digit = 9;   // count of numbers in current block
        int first = 1;         // first number of current block
        int length = 1;        // digit length of numbers in block

        // Step 1: Find correct digit block
        while(n > digit * length)
        {
            n -= digit * length;
            length++;
            first *= 10;
            digit *= 10;
        }

        // Step 2: Find actual number containing nth digit
        first = first + (n - 1) / length;

        // Step 3: Extract digit
        string str = to_string(first);
        return str[(n - 1) % length] - '0';
    }
};