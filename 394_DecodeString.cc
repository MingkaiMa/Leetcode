#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;



string decodeString(string s) {
    if(s.size() == 0)
        return "";
    
    stack<int> IntStack;
    stack<string> StrStack;
    
    int i = 0;
    
    while(i < s.size()){

        char c = s[i];
        
        if(c == '['){
            string tmp = "";
            tmp += c;
            StrStack.push(tmp);
            ++i;
        }
        else if(c >= '0' && c <= '9'){
            int j = i;
            while(s[j] >= '0' && s[j] <= '9')
                ++j;
            string tmpNb = s.substr(i, j - i);
            IntStack.push(stoi(tmpNb));
            i = j;
            
        }
        else if(isalpha(c)){
            string tmp = "";
            tmp += c;
            StrStack.push(tmp);
            ++i;
        }
        else if(c == ']'){
            ++i;
            
            vector<string> saveList;
            string pushStr = "";
            int pushTimes = 0;
            
            while(!StrStack.empty()){
                string topElement = StrStack.top();
                if(topElement != "[")
                {
                    saveList.push_back(topElement);
                    StrStack.pop();
                }
                else{
                    StrStack.pop();
                    pushTimes = IntStack.top();
                    IntStack.pop();
                    
                    for(auto it = saveList.rbegin(); it != saveList.rend(); ++it)
                        pushStr += (*it);
                    
                    break;
                }
            }
            
            string ori = pushStr;

            cout << "pushStr is: "<< pushStr << endl;
            for(int j = 1; j < pushTimes; ++j){
                pushStr += ori;
            }
            cout << "after pushStr is: "<< pushStr << endl;
            StrStack.push(pushStr);
            
        }
    }
    
    vector<string> resList;
    while(!StrStack.empty()){
        resList.push_back(StrStack.top());
        StrStack.pop();
    }

    string res = "";
    for(auto it = resList.rbegin(); it != resList.rend(); ++it){
        res += (*it);
    }  
    return res;
    
}




int main(){
    //string s = "3[a]2[bc]";
    //string s = "3[a2[c]]";
    //string s = "2[abc]3[cd]ef";
    string s = "abce";
    cout << decodeString(s) << endl;
}
