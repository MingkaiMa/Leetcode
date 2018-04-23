#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;



    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {


        //corner case: don't forget

        //

        vector<vector<string>> res;

        if(wordList.size() <= 0 || beginWord.size() == 0 || endWord.size() == 0)
        {
            return {};
        }

        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return {};


        vector<string> newWordList = wordList;
        newWordList.push_back(beginWord);


        unordered_map<string, vector<string>> contextual_slots;

        for(auto& word: newWordList)
        {
            for(int i = 0; i < word.size(); i++)
            {
                cout << word.substr(0, i) + '*' + word.substr(i + 1, word.size() - i) << " : " << word << "\n";
                contextual_slots[word.substr(0, i) + '*' + word.substr(i + 1, word.size() - i)].push_back(word);
            }
        }

        cout << "here??\n";
        unordered_map<string, unordered_set<string>> closest_words;

        for(auto& slot: contextual_slots)
        {
            for(int i = 0; i < slot.second.size(); i++)
            {
                for(int j = i + 1; j < slot.second.size(); j++)
                {
                    closest_words[slot.second[i]].insert(slot.second[j]);
                    closest_words[slot.second[j]].insert(slot.second[i]);
                }
            }
        }

        cout << "here2??\n";

        for(auto& word: closest_words["ian"])
        {
            cout << word << "\n";
        }

       // return res;
        vector<string> currList = {beginWord};

        queue<vector<string>> Queue;
        Queue.push(currList);

        while(!Queue.empty())
        {
            //cout << Queue.size() << "\n";
            vector<string> word_sequence = Queue.front();
            Queue.pop();

            for(int i = 0; i < word_sequence.size(); i++)
            {
                cout << word_sequence[i] << ", ";
            }
            cout << "\n";


            string lastWord = word_sequence.back();
            cout << "last word: " << lastWord << "\n";
            for(auto& word: closest_words[lastWord])
            {
                //cout << word << "\n";
                if(word == endWord)
                {
                    cout << "----\n";
                    if(res.size() == 0 || res.back().size() > word_sequence.size())
                    {
                        cout << "----\n";
//                        vector<string> temp = word_sequence;
//                        temp.push_back(word);
                        word_sequence.push_back(word);
                        res.push_back(word_sequence);
                    }
                }

                if(res.size() == 0 && (find(word_sequence.begin(), word_sequence.end(), word) == word_sequence.end()))
                 {
//                    vector<string> temp = word_sequence;
//                    temp.push_back(word);

                    word_sequence.push_back(word);
                    Queue.push(word_sequence);
                 }

            }
        }

        return res;


    }


int main()
{

    string word1 = "cet";
    string word2 = "ism";
    vector<string> wordList = {"kid","tag","pup","ail","tun","woo","erg","luz","brr","gay","sip","kay","per","val","mes","ohs","now","boa","cet","pal","bar","die","war","hay","eco","pub","lob","rue","fry","lit","rex","jan","cot","bid","ali","pay","col","gum","ger","row","won","dan","rum","fad","tut","sag","yip","sui","ark","has","zip","fez","own","ump","dis","ads","max","jaw","out","btu","ana","gap","cry","led","abe","box","ore","pig","fie","toy","fat","cal","lie","noh","sew","ono","tam","flu","mgm","ply","awe","pry","tit","tie","yet","too","tax","jim","san","pan","map","ski","ova","wed","non","wac","nut","why","bye","lye","oct","old","fin","feb","chi","sap","owl","log","tod","dot","bow","fob","for","joe","ivy","fan","age","fax","hip","jib","mel","hus","sob","ifs","tab","ara","dab","jag","jar","arm","lot","tom","sax","tex","yum","pei","wen","wry","ire","irk","far","mew","wit","doe","gas","rte","ian","pot","ask","wag","hag","amy","nag","ron","soy","gin","don","tug","fay","vic","boo","nam","ave","buy","sop","but","orb","fen","paw","his","sub","bob","yea","oft","inn","rod","yam","pew","web","hod","hun","gyp","wei","wis","rob","gad","pie","mon","dog","bib","rub","ere","dig","era","cat","fox","bee","mod","day","apr","vie","nev","jam","pam","new","aye","ani","and","ibm","yap","can","pyx","tar","kin","fog","hum","pip","cup","dye","lyx","jog","nun","par","wan","fey","bus","oak","bad","ats","set","qom","vat","eat","pus","rev","axe","ion","six","ila","lao","mom","mas","pro","few","opt","poe","art","ash","oar","cap","lop","may","shy","rid","bat","sum","rim","fee","bmw","sky","maj","hue","thy","ava","rap","den","fla","auk","cox","ibo","hey","saw","vim","sec","ltd","you","its","tat","dew","eva","tog","ram","let","see","zit","maw","nix","ate","gig","rep","owe","ind","hog","eve","sam","zoo","any","dow","cod","bed","vet","ham","sis","hex","via","fir","nod","mao","aug","mum","hoe","bah","hal","keg","hew","zed","tow","gog","ass","dem","who","bet","gos","son","ear","spy","kit","boy","due","sen","oaf","mix","hep","fur","ada","bin","nil","mia","ewe","hit","fix","sad","rib","eye","hop","haw","wax","mid","tad","ken","wad","rye","pap","bog","gut","ito","woe","our","ado","sin","mad","ray","hon","roy","dip","hen","iva","lug","asp","hui","yak","bay","poi","yep","bun","try","lad","elm","nat","wyo","gym","dug","toe","dee","wig","sly","rip","geo","cog","pas","zen","odd","nan","lay","pod","fit","hem","joy","bum","rio","yon","dec","leg","put","sue","dim","pet","yaw","nub","bit","bur","sid","sun","oil","red","doc","moe","caw","eel","dix","cub","end","gem","off","yew","hug","pop","tub","sgt","lid","pun","ton","sol","din","yup","jab","pea","bug","gag","mil","jig","hub","low","did","tin","get","gte","sox","lei","mig","fig","lon","use","ban","flo","nov","jut","bag","mir","sty","lap","two","ins","con","ant","net","tux","ode","stu","mug","cad","nap","gun","fop","tot","sow","sal","sic","ted","wot","del","imp","cob","way","ann","tan","mci","job","wet","ism","err","him","all","pad","hah","hie","aim","ike","jed","ego","mac","baa","min","com","ill","was","cab","ago","ina","big","ilk","gal","tap","duh","ola","ran","lab","top","gob","hot","ora","tia","kip","han","met","hut","she","sac","fed","goo","tee","ell","not","act","gil","rut","ala","ape","rig","cid","god","duo","lin","aid","gel","awl","lag","elf","liz","ref","aha","fib","oho","tho","her","nor","ace","adz","fun","ned","coo","win","tao","coy","van","man","pit","guy","foe","hid","mai","sup","jay","hob","mow","jot","are","pol","arc","lax","aft","alb","len","air","pug","pox","vow","got","meg","zoe","amp","ale","bud","gee","pin","dun","pat","ten","mob"};


    vector<vector<string>> res = findLadders(word1, word2, wordList);



}