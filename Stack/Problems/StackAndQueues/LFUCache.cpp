#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LFUCache {
public:
  int capacity;
  int minFrequency = 0;
  int currentSize = 0;

  unordered_map<int, list<int>> frequencyList;
  unordered_map<int, list<int>::iterator> keyNode;
  unordered_map<int, pair<int, int>> frequency;

  LFUCache(int capacity_) {
    capacity = capacity_;
    minFrequency = 0;
    currentSize = 0;
  }

  int get(int key) {
    if (keyNode.find(key) == keyNode.end()) {
      return -1;
    }
    int keyFreq = frequency[key].first;
    frequencyList[keyFreq].erase(keyNode[key]);
    frequency[key].first++;
    frequencyList[frequency[key].first].push_front(key);
    keyNode[key] = frequencyList[frequency[key].first].begin();
    if (frequencyList[minFrequency].size() == 0) {
      minFrequency++;
    }
    return frequency[key].second;
  }
  void put(int key, int val) {
    if (capacity <= 0)
      return;
    if (keyNode.find(key) != keyNode.end()) {
      frequency[key].second = val;
      get(key);
      return;
    }
    // New element
    if (currentSize == capacity) {
      int minFreqBack = frequencyList[minFrequency].back();
      keyNode.erase(minFreqBack);
      frequency.erase(key);
      frequencyList[minFrequency].pop_back();
      currentSize--;
    }
    currentSize++;
    minFrequency = 1;
    frequencyList[minFrequency].push_front(key);
    keyNode[key] = frequencyList[minFrequency].begin();
    frequency[key].first = 1, frequency[key].second = val;
  }
};
