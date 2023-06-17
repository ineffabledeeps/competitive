#include<iostream>
#include<vector>
using namespace std;

pair <int,int> findStr(vector <vector<string>> strArr,string key){
    pair <int,int> result = {-1,-1};

    for(int i=0;i<strArr.size();i++){
        for(int j=0;j<strArr[0].size();j++){
            if(strArr[i][j] == key){
                result.first = i;
                result.second = j;
                return result;
            }
        }
    }
    return result;
}

int main(){
    vector<vector<string>> strArr = {
        { "a", "h", "b" },
        { "c", "d", "e" },
        { "g", "t", "r" }
    };

    string key = "e";

    pair <int,int> index = findStr(strArr,key);
    cout<<index.first<<" "<<index.second;
    return 0;
}