#include<iostream>
#include<bits/stdc++.h>
using namespace std;

pair<int,int> findString(vector <vector<string>> stringArr,string key){
    pair<int,int> result{1,-1};
    vector<string> flattenedArr;
    for(auto row : stringArr){
        flattenedArr.insert(flattenedArr.end(),row.begin(),row.end());
    }
    
    auto it = find(flattenedArr.begin(),flattenedArr.end(),key);

    if(it != flattenedArr.end()){
        int index = distance(flattenedArr.begin(),it);
        int rows = stringArr.size();
        int cols = stringArr[0].size();
        result.first = index / cols;
        result.second = index % cols;
        // return 
    }

    return result;
}

main(){
    vector<vector<string>> stringArr = {
        {"a","b","c"},
        {"p","q","r"},
        {"e","f","g"},
        {"m","n","o"}
    };
    string key = "n";
    pair <int,int> index = findString(stringArr,key);
    cout<<index.first<<" "<<index.second;
    return 0;
}

