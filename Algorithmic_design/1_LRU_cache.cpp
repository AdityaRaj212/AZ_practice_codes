#include<bits/stdc++.h>
using namespace std;

class LRUcache{
    list<int> order;
    unordered_map<int, pair<int, list<int>::iterator>> cache; // key -> (val, it)
    int maxSize = 0;

    void touch(int id){
        auto it = cache.find(id);
        int key = it->first;
        order.erase(it->second.second);
        order.push_front(key);
        it->second.second = order.begin();
    }

    public:

    LRUcache(int capacity){
        maxSize = capacity;
        order.clear();
        cache.clear();
    }

    int get(int key){
        if(cache.find(key)==cache.end()){
            return -1;
        }else{
            touch(key);
            return cache[key].first;
        }
    }

    void put(int key, int val){
        if(cache.find(key)==cache.end()){
            if(cache.size()==maxSize){
                int del = order.back();
                cache.erase(del);
                order.pop_back();
            }
            order.push_front(key);
        }else{
            touch(key);
        }
        cache[key] = make_pair(val, order.begin());
    }
};

signed main(){
    
    return 0;
}