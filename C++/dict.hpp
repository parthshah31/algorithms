#ifndef DICT_H
#define DICT_H
#include <string>
#include <vector>

using namespace std;

template <class T>
class Dictionary{
    int size;
    int numKeys;
    int hash1;
    int hash2;
    vector<string> keys;
    T* data[];
    
public:
    Dictionary(int inpSize = 8, T* inpData[] = nullptr, vector<string>* inpKeys = nullptr);
    void setHashes(void);
    Dictionary<T> tableDouble(Dictionary<T> inpDict);
    Dictionary<T> tableHalve(Dictionary<T> inpDict);
    int getKeyVal(const string& key);
    int search(const string& key);
    T* getData(const string& key);
    void insertItem(const string& key, T* inpData);
    void deleteItem(const string& key);
    T* popItem(const string& key);
};

#endif