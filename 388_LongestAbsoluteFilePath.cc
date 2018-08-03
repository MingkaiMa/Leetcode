class Solution {
public:
    int lengthLongestPath(string input) {

        int res = 0, n = input.size(), level = 0;
        
        unordered_map<int, int> Map{{0, 0}};
        for(int i = 0; i < n; i++){
            cout << "i is: "<< i<< endl;
            cout << "level is: " << level << endl;
            int start = i;
            while(i < n && input[i] != '\n' && input[i] != '\t')
                ++i;
            if(i >= n || input[i] == '\n'){
                string substring = input.substr(start, i - start);
                if(substring.find('.') != string::npos){
                    res = max(res, Map[level] + int(substring.length()));
                }
                else{
                    level++;
                    Map[level] = Map[level - 1] + substring.length() + 1;
                }
                
                level = 0;
            }else{
                level++;
            }
        }
        return res;
    }
};
