#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

bool isOneLetterDiff(const string& word1, const string& word2) {
    int diff = 0;
    for (int i = 0; i < word1.size(); i++) {
        if (word1[i] != word2[i])
            diff++;
        if (diff > 1)
            return false;
    }
    return diff == 1;
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> wordSet(wordList.begin(), wordSet.end());
    vector<vector<string>> result;
    if (wordSet.find(endWord) == wordSet.end())
        return result;

    queue<vector<string>> paths;
    paths.push({beginWord});
    int level = 1;
    int minLevel = INT_MAX;
    unordered_set<string> visited;

    while (!paths.empty()) {
        vector<string> path = paths.front();
        paths.pop();

        if (path.size() > level) {
            for (string w : visited)
                wordSet.erase(w);
            visited.clear();
            if (path.size() > minLevel)
                break;
            else
                level = path.size();
        }

        string last = path.back();
        for (int i = 0; i < last.size(); i++) {
            string newWord = last;
            for (char c = 'a'; c <= 'z'; c++) {
                newWord[i] = c;
                if (wordSet.find(newWord) != wordSet.end()) {
                    vector<string> newPath = path;
                    newPath.push_back(newWord);
                    visited.insert(newWord);
                    if (newWord == endWord) {
                        minLevel = level;
                        result.push_back(newPath);
                    } else {
                        paths.push(newPath);
                    }
                }
            }
        }
    }
    return result;
}

int main() {
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    vector<vector<string>> result = findLadders(beginWord, endWord, wordList);
    for (const auto& path : result) {
        for (const auto& word : path)
            cout << word << " ";
        cout << endl;
    }

    return 0;
}
