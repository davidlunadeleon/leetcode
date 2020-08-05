// Source: https://leetcode.com/problems/implement-trie-prefix-tree/
// Date: 05.08.2020
// Solution by: David Luna
// Runtime: 208ms
// Memory usage: 36.1 MB

/*
	Note: This solution contains memory leaks that I plan to solve later.
	For the time being, I would not use it as a correct solution of the
	problem.
*/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// Leetcode solution starts

class Trie {
  public:
	Trie() { trieMap = new unordered_map<char, Trie>(); }
	~Trie() { delete trieMap; }

	void insert(string word) {
		word += '*';
		unordered_map<char, Trie> *currMap = trieMap;
		for (uint64_t i = 0; i < word.size(); i++) {
			char c = word[i];
			if ((*currMap).find(c) == (*currMap).end()) {
				(*currMap).insert(pair<char, Trie>(c, Trie()));
			}
			currMap = (*currMap)[c].getTrieMap();
		}
	}

	bool search(string word) {
		word += '*';
		return startsWith(word);
	}

	bool startsWith(string prefix) {
		unordered_map<char, Trie> *currMap = trieMap;
		for (uint64_t i = 0; i < prefix.size(); i++) {
			char c = prefix[i];
			if ((*currMap).find(c) == (*currMap).end()) {
				return false;
			}
			currMap = (*currMap)[c].getTrieMap();
		}
		return true;
	}

  protected:
	unordered_map<char, Trie> *getTrieMap() { return trieMap; }

  private:
	unordered_map<char, Trie> *trieMap;
};

// Leetcode solution ends

template <typename T> void makeVectorT(vector<T> &vect) {
	int numElements;
	cin >> numElements;
	for (int i = 0; i < numElements; i++) {
		T temp;
		cin >> temp;
		vect.push_back(temp);
	}
}

void makeTest() {
	Trie *trie;
	int numOperations;
	vector<bool> ans, correctAns;
	trie = new Trie();
	cin >> numOperations;
	for (int i = 0; i < numOperations; i++) {
		char c;
		string s;
		cin >> c;
		switch (c) {
		case 'i':
			cin >> s;
			trie->insert(s);
			break;
		case 's':
			cin >> s;
			ans.push_back(trie->search(s));
			break;
		case 'w':
			cin >> s;
			ans.push_back(trie->startsWith(s));
			break;
		default:
			break;
		}
	}
	makeVectorT(correctAns);
	cout << (ans == correctAns ? "pass\n" : "fail\n");
	delete trie;
}

int main() {
	int numTests;
	// Introduce the number of tests to make.
	cin >> numTests;
	for (int i = 0; i < numTests; i++) {
		makeTest();
	}
	return 0;
}