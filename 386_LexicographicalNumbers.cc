class Solution {
public:

    vector<int> lexicalOrder(int n) {

        vector<int> res;
        int curr = 1;
        for(int i = 1; i <= n; i++){
            res.push_back(curr);
            if(curr * 10 <= n)
                curr = curr * 10;
            else if(curr % 10 != 9 && curr + 1 <= n)
                curr++;
            else{
                while((curr / 10) % 10 == 9)
                    curr = curr / 10;
                
                curr = curr / 10 + 1;
            }
        }
        return res;
    }
};
