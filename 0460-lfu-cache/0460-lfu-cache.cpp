class LFUCache {
public:
    unordered_map<int,vector<int>>mp;
    set<vector<int>>s;
    int cap,Count;
    LFUCache(int capacity) {
        cap=capacity;
        Count=0;
    }
    
    int get(int key) {
        if(cap==0)return -1;
        Count++;
        if(mp.find(key)==mp.end())return -1;
        int val=mp[key][0];
        int freq=mp[key][1];
        int Count1=mp[key][2];
        auto it=s.find({freq,Count1,key});
        s.erase(it);
        mp[key]={val,freq+1,Count};
        s.insert({freq+1,Count,key});
        return val;
        
    }
    
    void put(int key, int value) {
        if(cap==0)return;
        Count++;
        if(mp.find(key)!=mp.end()){
            int val=value;
            int freq=mp[key][1];
            int Count1=mp[key][2];
            auto it =s.find({freq,Count1,key});
            s.erase(it);
            mp[key]={val,freq+1,Count};
            s.insert({freq+1,Count,key});
        }else{
            if(s.size()>=cap){
                vector<int>it=*s.begin();
                int key1=it[2];
                cout<<key1<<endl;
                mp.erase(key1);
                s.erase(s.begin());
            }
            mp[key]={value,1,Count};
            s.insert({1,Count,key});
        }
        return;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */