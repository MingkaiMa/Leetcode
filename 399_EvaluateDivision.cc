class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, int> m;
        int cnt = 0;
        
        for(auto& p: equations){
            if(m.count(p.first) == 0)
            {
                m[p.first] = cnt;
                cnt++;
            }
            if(m.count(p.second) == 0)
            {
                m[p.second] = cnt;
                cnt++;
            }
        }
        
        // for(auto& p: m){
        //     cout << p.first << " : " << p.second << endl;
        // }
        
        int len = m.size();
        double** matrix = new double*[len];
        for(int i = 0; i < len; ++i){
            matrix[i] = new double[len];
        }
        
        for(int i = 0; i < len; ++i){
            for(int j = 0; j < len; ++j){
                if(i == j){
                    matrix[i][j] = 1.0;
                }
                else{
                    matrix[i][j] = -1.0;
                }
                //cout << matrix[i][j] << ", ";
            }
            //cout << endl;
        }
        
        
        unordered_map<int, string> reverse_m;
        for(auto& p: m){
            reverse_m[p.second] = p.first;
        }
        
        // for(auto& p: reverse_m){
        //     cout << p.first << ": " << p.second;
        // }
        // cout << endl;
        



        for(int i = 0; i < equations.size(); ++i){
            matrix[m[equations[i].first]][m[equations[i].second]] = values[i];
            matrix[m[equations[i].second]][m[equations[i].first]] = 1 / values[i];
        }
        
        
        // cout << "888\n";
        // for(int i = 0; i < len; ++i){
        //     for(int j = 0; j < len; ++j){
        //         //matrix[i][j] = 0;
        //         cout << matrix[i][j] << ", ";
        //     }
        //     cout << endl;
        // }
        
        vector<double> res;
        
        for(auto& q: queries){
            string s1 = q.first;
            string s2 = q.second;
            if(m.count(s1) == 0 || m.count(s2) == 0)
                res.push_back(-1);
            
            else if(matrix[m[s1]][m[s2]] != -1.0)
                res.push_back(matrix[m[s1]][m[s2]]);
            else
                res.push_back(core(matrix, m[s1], m[s2], len));
        }        
        return res;
        
    }

    double core(double** matrix, int source, int dest, int len){

        queue<vector<int>> Queue;

        vector<int> findPath = {};
        Queue.push({source});
        while(!Queue.empty()){
            vector<int> currPath = Queue.front();
            Queue.pop();
            int lastPoint = currPath.back();
            if(lastPoint == dest){
                findPath = currPath;
                break;
            }
            for(int j = 0; j < len; ++j){
                if(j == lastPoint)
                    continue;

                if(matrix[lastPoint][j] != -1.0){
                    if(find(currPath.begin(), currPath.end(), j) == currPath.end()){
                        vector<int> tmpPath = currPath;
                        tmpPath.push_back(j);
                        Queue.push(tmpPath);
                    }
                }
            }   
        }

        if(findPath.size() == 0)
            return -1.0;

        double res = 1;

        for(int i = 1; i < findPath.size(); ++i){
            res *= matrix[findPath[i - 1]][findPath[i]];
        }

        return res;
    }
};
