class Solution {
public:
    int findNthDigit(int n) {
        if(n <= 9)
            return n;
        
        long long upToNow = 9;
        long long nbDigits = 2;
        
        while(1){
            upToNow = 9 * pow(10, nbDigits - 1) * nbDigits + upToNow;
        
            if(n == upToNow)
                return 9;
            
            if(n < upToNow)
                break;
            
            ++nbDigits;
        }
        
        //cout << "upToNow: " << upToNow << endl;
        
        string strNb = "";
        for(int i = 0; i < nbDigits; ++i){
            strNb += "9";
        }
        
        int endNb = stoi(strNb);
        
        //cout << "endNb: " << endNb << endl;;
        
        long long diff = upToNow - n;
        long long diffQ = diff % nbDigits;
        diff = diff / nbDigits;
        
        //cout << "diff:  " << diff << endl;
       // cout << "diffQ: " << diffQ << endl;
        long long targetNb = endNb - diff;
        //cout << "Target: " << targetNb << endl;

        
        long long m = diffQ;
        while(m){
            targetNb = targetNb / 10;
            --m;
        }
        
        return targetNb % 10;
        
        //return 1;
        
    }
};
