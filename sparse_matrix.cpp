#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int row;
        int col;
        int data;
        Node* next;
};

class List{
    public:
    Node* ptrNode;
    vector <vector<int>> matrix;
};

Node* createNode(int row, int col, int data){
    Node* newNode = new Node();
    newNode -> row = row;
    newNode -> col = col;
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}

List* addInList(List* listHead, int row, int col, int data){

    Node* newNode = createNode(row, col, data);
    
    if(listHead -> ptrNode == NULL){
        listHead -> ptrNode = newNode;
        return listHead;
    }

    newNode -> next = listHead -> ptrNode;
    listHead -> ptrNode = newNode;

    return listHead;
}

List* createList(List*  listHead, vector<vector<int>> arr, Node* nodeHead){
    List* listPtr = listHead;

    if(listHead == NULL){
        listHead = new List();
        listHead -> matrix = arr;
        listHead -> ptrNode = nodeHead;
    }

    listPtr = listHead;

    for(int i=0;i < listPtr -> matrix.size();i++){
        for(int j = 0;j < listPtr -> matrix[i].size();j++){
            if(arr[i][j] != 0 ){
                listHead = addInList(listHead,i,j,arr[i][j]);
            }
        }
    }

    return listHead;
}

vector<vector<int>> reconstruct(List* sparseList){
    vector<vector<int>> reconArray;
    reconArray.assign(sparseList->matrix.size(), vector<int>(sparseList->matrix[0].size()));
    for(int i = 0;i < sparseList->matrix.size();i++){
        for(int j = 0; j<sparseList->matrix[i].size();j++){
            reconArray[i][j] = 0;
        }
    }
    Node* ptr = sparseList->ptrNode;
    while(ptr != NULL){
        reconArray[ptr->row][ptr->col] = ptr->data;
        ptr = ptr->next;
    }

    return reconArray;
}

int main(){

    List* listHead = NULL;
    Node* nodeHead = NULL;

    vector<vector<int>> arr = {
        {1,0,4,0},
        {2,0,0,0},
        {0,0,3,0},
        {0,4,3,0}
    };

    List* sparseList = createList(listHead,arr,nodeHead);
    vector <vector <int>> reconMatrix = reconstruct(sparseList);

    for(auto x: reconMatrix){
        for(auto y: x){
            cout<<y<<" ";
        }
        cout<<endl;
    }

    while (sparseList -> ptrNode != NULL ){
        cout<<sparseList -> ptrNode -> row<< sparseList -> ptrNode -> col <<sparseList -> ptrNode -> data<<" -> ";
        sparseList -> ptrNode = sparseList -> ptrNode -> next;
    }

    cout<< "NUll";

    return 0;
}