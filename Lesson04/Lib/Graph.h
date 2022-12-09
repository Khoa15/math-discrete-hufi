#pragma once
#ifndef _GRAPH_H_
#define _GRAPH_H_
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#define MAX 50
#define INF 9999
template <typename T>
class Graph{
public:
    bool isDirect;
    bool isWeight;
    int v;// So dinh
    int e;// So canh
    int G[MAX][MAX];// Matrix
    Graph();
    Graph(int x, int y) : v(x), e(y) {}

    void init(bool isWei, bool isDir);
    
    void getInput();
    void getFile(string filename);
    void show();
};

template <class T>
Graph<T>::Graph(){
    v = 0;
    e = 0;
}

template <class T>
void Graph<T>::init(bool isWei, bool isDir){
    isWeight = isWei;
    isDirect = isDir;
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            G[i][j] = (isWei == true) ? 9999 : 0;
        }
    }
}

template <class T>
void Graph<T>::getInput(){
    do{
        cout << "Nhap so dinh: ";
        cin >> v;
    }while(v < 0);
    do{
        cout << "Nhap so canh: ";
        cin >> e;
    }while(e < 0);
    int x = 0,
        y = 0,
        val = 1;
    for(int i = 0; i < e; i++){
        if(isDirect == true){
            cout << "Nhap dinh x va y(x -> y): ";
        }else cout << "Nhap dinh x va y: ";
        cin >> x >> y;
        if(isWeight == true){
            cout << "Nhap trong so: ";
            cin >> val;
        }
        G[x][y] = val;
        if(isDirect == true) G[y][x] = val;
    }
}

template <class T>
void Graph<T>::getFile(string filename){
    fstream FILE;
    FILE.open(filename, ios::in);
    FILE >> v >> e;
    int x = 0,
        y = 0,
        val = 0;
    for(int i = 0; i < e; i++){
        FILE >> x >> y;
        if(isWeight == true) FILE >> val;
        if(isDirect == true) G[y][x] = val;
        G[x][y] = val;
    }

    FILE.close();
}

template <class T>
void Graph<T>::show(){
    if(isDirect == true) cout << "Do thi co huong" << endl;
    else cout << "Do thi vo huong" << endl;

    for(int i = 0; i < v; i++){
        for(int j = 0; j < v; j++){
            cout << G[i][j] << "\t";
        }
        cout << endl;
    }
}
#endif