#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
using namespace std;

int n = 10000;

int main(){
    bool is_p[n+1];
    for(int i=0;i<=n;i++) is_p[i] = true;
    for(int i=2;i*i<=n;i++){
        if(is_p[i]){
            for(int j=i*i; j<=n; j+= i){
                is_p[j] = false;
            }
        }
    }
    ofstream file;
    file.open("code.txt");
    for(int i=0; i<= n; i++){
        string odp;
        if(is_p[i]){
            odp = "TAK";
        }else{
            odp = "NIE";
        }
        string t = "    if(a == " + to_string(i) + "){\n        printf(" + odp + " backen);\n    } \n";
        file << t;
    }
    
    file.close();

    return 0;
}