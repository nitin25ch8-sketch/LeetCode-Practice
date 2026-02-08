class Solution {
public:
 long reverseDigits(int n) {
    long revNum = 0;
    while (n > 0) {
        revNum = revNum * 10 + n % 10;
        n = n / 10;
    }
    return revNum;
}
    bool isPalindrome(int n) {
       long rev= reverseDigits(n);
     if (n<0){
            return false;
        }
    else if(n==rev){
        return true;
    }
    else{
        return false;
    }
    }
};