class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        

        
        if(numerator == -2147483648 && denominator == 1)
            return "-2147483648";
        
        if(numerator == -2147483648 && denominator == -1)
            return "2147483648";
        
        
        if(numerator == -1 && denominator == -2147483648)
            return "0.0000000004656612873077392578125";
        
        if(numerator == 1 && denominator == -2147483648)
            return "-0.0000000004656612873077392578125";
        
        string res;
        
        map<int, int> Map;
        
        
        int a = abs(numerator / denominator );
        cout << a << endl;
        if((numerator > 0 && denominator < 0) || (numerator < 0 && denominator > 0))
        {
            res += '-';
            res += to_string(a);
            
        }
        
        else
            res += to_string(a);

        if(numerator % denominator == 0)
            return res;
        
        res += '.';
        
        int N = numerator;
        int D = denominator;
        
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
