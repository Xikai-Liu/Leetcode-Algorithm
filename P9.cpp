class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;
        if (x<10) return true;
        long long now=0,old=x;
        while (old!=0){
            now=now*10+old%10;
            old=old/10;
        }
        if (now==x) return true;
        return false;
    }
};