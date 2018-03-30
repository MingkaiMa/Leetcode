class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        
        
        if(words.size() <= 0)
        {
            vector<string> ss;
            return ss;
        }
        
        int array[words.size()];
        for(int i = 0; i < words.size(); i++)
        {
            array[i] = words[i].size();
        }
                
        vector<string> r;
        
        
        int i = 0;
        
        while(i < words.size())
        {
            
            if(i == words.size() - 1)
            {
                string s = words[i];
                for(int p = 0; p < (maxWidth - words[i].size()); p++)
                    s += " ";
                
                r.push_back(s);
                i++;
                continue;
            }
            
            
            int sum = 0;
            int k = 0;
            cout << "i upper is: " << i << "\n";
            for(int j = i; j < words.size(); j++)
            {
                if(j == i)
                {
                    sum += array[j];
                }
                else
                {
                    sum += array[j] + 1;
                }
                
                if(sum == maxWidth)
                {
                    k = j;
                    break;
                }
                
                
                if(sum > maxWidth)
                {
                    k = j - 1;
                    break;
                }
                
                
                if(j == words.size() - 1)
                {
                    cout << "Fuck?\n";
                    string s = "";
                    for(int yy = i; yy < j; yy++)
                    {
                        s += words[yy];
                        s += " ";
                    }
                    
                    s += words[j];
                    int sLen = s.size();
                    for(int qq = 0; qq < (maxWidth - sLen); qq++)
                        s += " ";
                    
                    r.push_back(s);
                    return r;
                    
                }
                
                
            }
            
            cout << "k is: " << k << "\n";
            sum = 0;
            for(int j = i; j <= k; j++)
                sum += array[j];
            
            cout << "sum is :" << sum << "\n";
            
            int slotNb = k - i;
            
            cout << "slot nb is:" << slotNb << "\n";
            int emptyNb = maxWidth - sum;
            vector<int> spaceNb;
            
            if(slotNb == 0)
            {
                
                if(words[k].size() < maxWidth)
                {
                    string s= words[k];
                    for(int rr = 0; rr < maxWidth - words[k].size(); rr++)
                        s += " ";
                    
                    r.push_back(s);
                    i++;
                    continue;
                }
                
                
                string s = words[k];
                r.push_back(s);
                i++;
                continue;
            }
            
            cout << "empty nb : " << emptyNb << "\n";
            while(emptyNb % slotNb != 0)
            {
                spaceNb.push_back(emptyNb / slotNb);
                emptyNb = emptyNb - emptyNb / slotNb;
                slotNb -= 1;
            }
            
            for(int jj = 0; jj < slotNb; jj++)
                spaceNb.push_back(emptyNb / slotNb);
            
            reverse(spaceNb.begin(), spaceNb.end());
            
            for(int uu = 0; uu < spaceNb.size(); uu++)
                cout << spaceNb[uu] << ", ";
            cout << "\n";
            
            
            string temp = "";
            int emptyCount = 0;
            for(int kk = i; kk <= k; kk++)
            {
                temp += words[kk];
                if(kk != k)
                {
                    int u = 0;
                    while(u < spaceNb[emptyCount])
                    {
                        temp += " ";
                        u++;
                    }
                    emptyCount++;
                }
            }
            
            //cout << "temp is: " << temp << "\n";
            r.push_back(temp);
            
            i = k + 1;
            cout << "i is: " << i << "\n";
        }
        
        
        
        return r;
    }
};
