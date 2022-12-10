#include <iostream>

using namespace std;

int main(){
    int n = 7;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            cout << j << "\t";
        }
        cout << endl;
    }


    return 0;
}