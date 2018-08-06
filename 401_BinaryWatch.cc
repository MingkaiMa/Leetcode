class Solution {
public:
    string getTime(vector<int>& list){
        vector<int> hour(list.begin(), list.begin() + 4);
        vector<int> minutes(list.begin() + 4, list.end());
        reverse(hour.begin(), hour.end());
        reverse(minutes.begin(), minutes.end());
        
        int Hour = 0;
        int Minute = 0;
        
        for(int i = 0; i < hour.size(); ++i){
            Hour += pow(2, i) * hour[i];
        }
        
        if(Hour >= 12)
            return "";
        for(int i = 0; i < minutes.size(); ++i){
            Minute += pow(2, i) * minutes[i];
        }
        
        if(Minute > 59)
            return "";
        string res = "";
        
        res += to_string(Hour);
        res += ":";
        
        if(Minute < 10){
            res += "0";
        }
        
        res += to_string(Minute);
        
        return res;
    }
    void core(int num, int cnt, int start, vector<string>& res, vector<int>& list){
        if(cnt == num){

            string putStr = getTime(list);
            if(putStr == "")
                return;

            res.push_back(getTime(list));
            return;
        }
        
        for(int i = start; i < list.size(); ++i){
            if(list[i] != 1){
                list[i] = 1;
                ++cnt;
                core(num, cnt, i + 1, res, list);
                list[i] = 0;
                --cnt;
            }
        }
        
    }
    vector<string> readBinaryWatch(int num) {
        int cnt = 0;
        vector<string> res;
        vector<int> list(10, 0);
        core(num, cnt, 0, res, list);
        return res;
    }
};
