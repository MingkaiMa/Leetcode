#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

bool wordPattern(string pattern, string str) {
    if(str.size() == 0)
        return false;


    unordered_map<char, int> Map;

    int count = 1;

    for(int i = 0; i < pattern.size(); i++)
    {
        if(Map.count(pattern[i]) > 0)
            continue;

        Map[pattern[i]] = count;
        count++;
    }

    string p1 = "";

    for(int i = 0; i < pattern.size(); i++)
    {
        p1 += to_string(Map[pattern[i]]);
    }

  //  cout << p1 << endl;





    unordered_map<string, int> Map2;
    vector<string> wordList;
    int i = 0;
    int count2 = 1;

    while(i < str.size())
    {
        cout << i << endl;
        while(str[i] == ' ')
            i++;



        int j = i;
        while(j < str.size() && str[j] != ' ')
            j++;

        //cout << j << endl;



        cout << "i: " << i << " j : " << j << endl;
        string word = str.substr(i, j - i);
        //cout << word << ", ";

        wordList.push_back(word);

        if(Map2.count(word) > 0)
        {

          ;
        }
        //cout << "count2 : " << count2 << endl;
        else
        {
            Map2[word] = count2;
            count2++;
        }

        if(j >= str.size())
            break;
        i = j;
    }

    string p2 = "";


    for(auto& word: wordList)
    {
        p2 += to_string(Map2[word]);
    }

    cout << p2 << endl;

    return p1 == p2;

}

int main()
{
    string pattern = "abba";
    wordPattern(pattern, "dog cat cat dog");
}