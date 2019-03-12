class Solution {
public:
    int reverse(int x) {
        bool ans=true;
        long long xx=x;
        long long result=0;
        if (xx<0){
            ans=false;
            xx=0-xx;
        }
        while (xx>0){
            result=result*10+xx%10;
            xx=xx/10;
        }
        if (ans==false) result=-result;
        if (result>INT_MAX || result<-INT_MAX) return 0;
        return result;
    }
};