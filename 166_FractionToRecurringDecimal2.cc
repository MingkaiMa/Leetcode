class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
                

        long N = (long)numerator;
        long D = (long)denominator;
        
        cout << N / D << endl;
        
        string res;
        
        map<long, long> Map;
        
        
        long a = abs(N / D );
        cout << a << endl;
        if((N > 0 && D < 0) || (N < 0 && D > 0))
        {
            res += '-';
            res += to_string(a);
            
        }
        
        else
            res += to_string(a);

        if(N % D == 0)
            return res;
        
        res += '.';
        

        N = N % D;
        
        N = abs(N);
        D = abs(D);
        cout << "N is: "<< N << endl;
        
        int i = 0;
        
        while(Map.count(N) == 0)
        {
            Map[N] = i++;
            N = N * 10;
            res += to_string(N / D);
            N = N % D;
            if(N == 0)
                break;
        }
        
        cout << res << endl;
        cout << i << endl;
        if(N != 0)
        {
            int len = i - Map[N];
            cout << len << "\n";
            res.insert(res.size() - len, "(");
            res += ')';
        }
        
        return res;
    }
};
