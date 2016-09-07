#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
//#include <fstream>

using namespace std;

int origin[26];
int  encrypte[26];

 //从文件读入
//ifstream cin("input.txt");
//ofstream cout("output.txt");

int cmp ( const void *a , const void *b ){
     return *(int *)a - *(int *)b;
}

int main(){
    int i;
    memset(origin, 0, sizeof(origin));
    memset(encrypte, 0, sizeof(encrypte));
    char str[256];
    cin.getline(str,256);
    for(i = 0; str[i] != '\0'; i++)
        origin[str[i] - 'A'] ++;
    cin.getline(str,256);
    for(i = 0; str[i] != '\0'; i++)
        encrypte[str[i] - 'A'] ++;

    qsort(origin, 26, sizeof(int), cmp);
    qsort(encrypte, 26, sizeof(int), cmp);

    int ok = 1;
    for(i = 0; i < 26; i++){
        if(origin[i] != encrypte[i]){
            ok = 0;
            break;
        }
    }
    if(ok){
        cout<<"YES\n";
    }
    else
        cout<<"NO\n";
    return 0;
}
