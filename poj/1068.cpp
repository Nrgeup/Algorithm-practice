#include<iostream>
#include<cstring>
//#include <fstream>

using namespace std;

 //从文件读入
 //ifstream cin("input.txt");
//ofstream cout("output.txt");

int t,i,j,n,temp1,temp2,pos;
int seq[44];
int p_seq[22];
int ok_seq[44];

int main(){
    cin>>t;
    while(t--){
        cin>>n;
        pos = 0;
        temp2 = 0;
        for( i = 0; i < n; i++){
            cin>>temp1;
            temp2 = temp1 - temp2;
            while(temp2--)
                seq[pos++] = -1;
            p_seq[i] = pos;
            seq[pos++] = 1;
            temp2 = temp1;
        }

        memset(ok_seq,0,sizeof(ok_seq));

        for(i = 0; i < n; i++){
            j = p_seq[i];
            temp1 = 1;
            for( ; j >= 0; j--){
                if(seq[j] == 1)
                    continue;
                if(ok_seq[j] == 1)
                    temp1 ++;
                else{
                    ok_seq[j] = 1;
                    cout<<temp1<<" ";
                break;
                }
            }
        }
        cout<<endl;

    }
    return 0;
}
