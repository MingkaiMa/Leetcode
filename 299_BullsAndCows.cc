#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;


string getHint(string secret, string guess) {

    unordered_map<char, vector<int>> Map;
    int bull = 0;
    int cow = 0;

    for(int i = 0; i < guess.size(); i++)
    {
        if(guess[i] == secret[i])
        {
            bull++;
            continue;
        }


        Map[guess[i]].push_back(i);
    }


    // Map is:

//    Map['1'].pop_back();
//
//
//    if(Map.count('1') > 0)
//        cout << "1 exists\n";

    unordered_map<char, vector<int>>::iterator it;
    for(it = Map.begin(); it != Map.end(); it++)
    {
        char c = it->first;
        vector<int> l = it->second;

        cout << "key is: " << c << endl;
        for(auto& i: l)
            cout << i << ", ";
        cout << endl;
    }




    for(int i = 0; i < secret.size(); i++)
    {
        if(secret[i] == guess[i])
            continue;


        if(Map.count(secret[i]) <= 0)
            continue;

        vector<int> list = Map[secret[i]];

        cout << "i : " << i << " number: " << secret[i] << endl;
        for(auto& i: list)
            cout << i << ", ";

        cout << endl;


        if(!list.empty())
        {
            cow++;
            list.pop_back();
            Map[secret[i]] = list;
        }


    }

    string res = to_string(bull) + "A" + to_string(cow) + "B";
    return res;
}

int main()
{
    string secret = "1122";
    string guess =  "0001";
    cout << getHint(secret, guess) << endl;
}