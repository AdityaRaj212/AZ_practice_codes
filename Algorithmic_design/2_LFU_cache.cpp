#include<bits/stdc++.h>
using namespace std;

class LFUcache{
    int size, capacity, lfu;
    unordered_map<int, list<int>> keys;
    unordered_map<int, pair<int, int>> values; // key -> (value, freq)
    unordered_map<int, list<int>::iterator> iters;

    void update(int key){
        int freq = values[key].second;
        auto iter = iters[key];
        values[key].second++;
        keys[freq].erase(iter);
        keys[freq+1].push_back(key);
        iters[key] = --keys[freq+1].end();
        if(keys[lfu].empty()){
            lfu++;
        }
    }

    public:

    LFUcache(int capacity){
        size = 0;
        this->capacity = capacity;
        lfu = 0;
    }

    int get(int key){
        if(values.find(key)==values.end()){
            return -1;
        }
        update(key);
        return values[key].first;
    }

    void put(int key, int val){
        if(!capacity){
            return;
        }

        if(values.find(key)!=values.end()){
            values[key].first = val;
            update(key);
        }else{
            if(size==capacity){
                int del = keys[lfu].front();
                keys[lfu].pop_front();
                values.erase(del);
                iters.erase(del);
            }else{
                size++;
            }

            values[key] = {val, 1};
            keys[1].push_back(key);
            iters[key] = --keys[1].end();
            lfu = 1;
        }
    }
};

signed main(){
    
    return 0;
}