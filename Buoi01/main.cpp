#if __linux
#include <bits/stdc++.h>
#elif WIN32
#include <iostream>
#include <string>
#endif
#include "Lib/Graph.h"
using namespace std;
void Menu(){
    cout << "==Bai 2==" << endl
        << "==Bai 3==" << endl
        << "==Bai 4==" << endl
        << "==Bai 5==" << endl
        << "==Bai 6==" << endl
        << "==Bai 7==" << endl
        << "==Bai 8==" << endl
        << "==bai 9==" << endl;
}

struct VerNode{
    int vertex_start, vertex_end;
    VerNode* pNext;
    VerNode() : vertex_start(0), vertex_end(0), pNext(NULL){}
};

Graph<int> Bai2(string inp_mtk);
Graph<int> Bai3(string inp_dsc);
Graph<int> Bai4(string dsk);
void Bai5(Graph<int> g);
void Bai6(Graph<int> g);
void Bai7(Graph<int> g);
void Bai8(Graph<int> g);
void Bai9(Graph<int> g);

int main(){
    int option;
    string inp_mtk = "input_mtk.txt",
            inp_dsc = "input_dsc.txt",
            inp_dsk = "input_dsk.txt";
    Graph<int> g;
    do{
        Menu();
        cin >> option;
        cout << "Your option: " << option << endl;
        switch (option)
        {
        case 2:
            g = Bai2(inp_mtk);
            break;
        case 3:
            g = Bai3(inp_dsc);
            break;
        case 4:
            g = Bai4(inp_dsk);
            break;
        case 5:
            Bai5(g);
            break;
        case 6:
            Bai6(g);
            break;
        case 7:
            Bai7(g);
            break;
        case 8:
            Bai8(g);
            break;
        case 9:
            Bai9(g);
            break;
        default:
            break;
        }
    }while(option != 0);


    return 0;
}

Graph<int> Bai2(string inp_mtk){
    fstream file;
    Graph<int> gra;
    file.open(inp_mtk, ios::in);
    if(file.fail()){
        cout << "Error!";
        return gra;
    }
    file >> gra.isDirect >> gra.v;
    gra.init(false, gra.isDirect);

    for(int i = 0; i < gra.v; i++){
        for(int j =0; j < gra.v;j++){
            file >> gra.G[i][j];
        }
    }
    file.close();
    return gra;
}

Graph<int> Bai3(string inp_dsc){
    Graph<int> gra;
    fstream file;
    file.open(inp_dsc, ios::in);
    if(file.fail()){
        cout << "Error";
        return gra;
    }
    int x = 0, y = 0;
    file >> gra.isDirect >> gra.v >> gra.e;
    for(int i = 0; i < gra.e; i++){
        file >> x >> y;
        gra.G[x][y] = 1;
        if(gra.isDirect == true) gra.G[y][x] = 1;
    }
    file.close();
    return gra;
}

Graph<int> Bai4(string dsk){
    Graph<int> gra;
    fstream file;
    file.open(dsk, ios::in);
    if(file.fail()){
        cout << "Error";
        return gra;
    }
    int x = 0, y = 0;
    file >> gra.isDirect >> gra.v;
    
    string line;
    while(getline(file, line)){
        stringstream stream(line);
        stream >> x;
        while(true){
            stream >> y;
            if(!stream) break;
            gra.G[x][y] = 1;
            if(gra.isDirect == true) gra.G[y][x] = 1;
        }
    }
    file.close();
    return gra;
}

void Bai5(Graph<int> g){
    cout << "So dinh: " << g.v << endl;
    if(g.isDirect == true){
        cout << "Do thi co huong " << endl;
    }else cout << "Do thi vo huong" << endl;
    if(g.isWeight == true){
        cout << "Do thi co trong so" << endl;
    }

    for(int i = 0; i < g.v; i++){
        for(int j = 0; j < g.v; j++){
            cout << g.G[i][j] << "\t";
        }
        cout << endl;
    }
}

void Bai6(Graph<int> gra){
    fstream file;
    file.open("write.txt", ios::out);
    if(file.fail()){
        cout << "Error!";
        return;
    }
    file << gra.isDirect << endl << gra.v << endl;
    for(int i = 0; i < gra.v; i++){
        for(int j = 0; j < gra.v; j++){
            file << gra.G[i][j] << "\t";
        }
        file << endl;
    }
    file.close();
}

void Bai7(Graph<int> gra){
    fstream file;
    file.open("write.txt", ios::out);
    if(file.fail()){
        cout << "Error!";
        return;
    }

    file << gra.isDirect << endl << gra.v << endl << gra.e << endl;
    for(int i = 0; i < gra.v;i++){
        for(int j = 0; j < gra.v;j++){
            if(gra.G[i][j] == 1) file << i << "\t" << j << endl;
        }
        // file << endl;
    }

    file.close();
}

void Bai8(Graph<int> gra){
    fstream file;
    file.open("write.txt", ios::out);
    if(file.fail()){
        cout << "Error!";
        return;
    }

    file << gra.isDirect << endl << gra.v << endl << gra.e << endl;
    for(int i = 0; i < gra.v;i++){
        bool flag = false;
        for(int j = 0; j < gra.v;j++){
            if(gra.G[i][j] == true && flag == false){
                file << i << "\t";
                flag = true;
            }
            if(gra.G[i][j]) file << j << "\t";
        }
        if(flag == true)file << endl;
    }

    file.close();
}

void Bai9(Graph<int> gra){
    int y = 0;
    cout << "Tim cac dinh ke cua v, nhap dinh v: ";
    cin >> y;
    // VerNode* head = new VerNode();

    // for(int i = 0; i < gra.v; i++){
    //     if(gra.G[y][i] == true){
    //         VerNode* p = new VerNode(gra.G[y][i]);
    //         cout << gra.G[y][i] << "\t";
    //     }
    // }
}