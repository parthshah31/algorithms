#include "dict.hpp"
//#include <iostream>
//#include <random>
#include <sstream>
#include <assert.h>
#include <string>

template <typename T>
string ToString(T val)
{
    stringstream stream;
    stream << val;
    return stream.str();
}

template <typename T>
inline T hash(const T& key, const T& hashf)
{
    assert(sizeof(key) == sizeof(hashf)); //improper hash size
    return key | hashf;
}

template <class T>
Dictionary<T>::Dictionary(int inpSize, T* inpData[], vector<string>* inpKeys){
    this->size = inpSize;
    setHashes();
    if(inpKeys == nullptr){
        this->numKeys = 0;
        T* data[size];
        for(int i = 0; i < size; i++){
            this->keys.push_back("");
        }
        return;
    }
    int dataSize = sizeof(inpData);
    for(int i = 0; i < dataSize; i++){
        string inpKey = (*inpKeys)[i];
        if (inpKey.compare("") != 0){
            continue;
        }
        insertItem(inpKeys[i],inpData[i]);
    }
}

template <class T>
void Dictionary<T>::setHashes(void)
{
    this->hash1 = random() % size;
    this->hash2 = random() % size;
}

template <class T>
Dictionary<T> Dictionary<T>::tableDouble(Dictionary<T> inpDict){
    return dictionary(2*size, inpDict.data, inpDict.keys);
}

template <class T>
Dictionary<T> Dictionary<T>::tableHalve(Dictionary<T> inpDict){
    return dictionary(size/2, inpDict.data, inpDict.keys);
}

template <class T>
int Dictionary<T>::getKeyVal(const string& key)
{
    string keyString = ToString(key);
    int running_sum = 0;
    for(int i = 0; i < keyString.length(); i++){
        running_sum += keyString[i];
    }
    return running_sum % size;
}

template <class T>
int Dictionary<T>::search(const string& key){
    int val = getKeyVal(key);
    int index = ::hash<int>(val,hash1) % size;
    string * p = *keys[index];
    while(*p != ""){
        if(key == *p){
            return index;
        }
        index += ::hash<int>(val,hash2);
        index = index % size;
    }
    return -1;
}

template <class T>
T* Dictionary<T>::getData(const string& key){
    int index = search(key);
    assert(index != -1); //key is not in dictionary
    return *data[index];
}

template <class T>
void Dictionary<T>::insertItem(const string& key, T* inpData){
    assert(key != ""); //key is invalid; key must be nonempty string
    int index = search(key);
    assert(index == -1); //key is already in dictionary
    int val = getKeyVal(key);
    index = ::hash<int>(val,hash1) % size;
    string * p = *keys[index];
    while(*p != ""){
        index += ::hash<int>(val,hash2);
        index = index % size;
    }
    this -> data[index] = inpData;
    this -> keys[index] = key;
    if(++numKeys > size/2){
        this = tableDouble(this);
    }
}

template <class T>
void Dictionary<T>::deleteItem(const string& key){
    popItem(key);
}

template <class T>
T* Dictionary<T>::popItem(const string& key){
    assert(key != ""); //key is invalid; key must be nonempty string
    int index = search(key);
    assert(index == -1); //key is not in dictionary
    T* popData = *data[index];
    data[index] = 0;
    keys[index] = "";
    if(--numKeys < size/8 && size > 8){
        this = tableHalve(this);
    }
    return popData;
}

int main(){
    return 0;
}
