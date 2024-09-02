#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>
using namespace std;

int transformWord(string beginWord, string endWord, unordered_set<string> wordList)
{
    if(wordList.find(endWord) == wordList.end())
		return -1;
    queue<pair<string, int> > q;
    q.push(make_pair(beginWord, 0));
    wordList.erase(beginWord);
    while(!q.empty()) 
	{
        auto [word, step] = q.front(); q.pop();
        if(word == endWord)
			return step;
        for(size_t i = 0; i < word.length(); ++i)
		{
            string temp = word;
            for(char c = 'a'; c <= 'z'; ++c)
			{
                temp[i] = c;
                if(wordList.find(temp) != wordList.end())
				{
                    q.push(make_pair(temp, step + 1));
                    wordList.erase(temp);
                }
            }
        }
    }
    return -1;
}

int main() 
{
    int T;
    cin >> T;
    while(T--)
	{
        string beginWord, endWord;
        int N;
        cin >> beginWord >> endWord >> N;
        
        unordered_set<string> wordList;
        for(int i = 0; i < N; ++i)
		{
            string word;
            cin >> word;
            wordList.insert(word);
        }
        cout << transformWord(beginWord, endWord, wordList) << '\n';
    }
    return 1;
}
