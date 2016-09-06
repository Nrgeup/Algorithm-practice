#include<iostream>

using namespace std;

int n;
int row,col;
char ans[2000000];
char temp[1000000];

//R**C**
void  p_one(){
    cout<<'R'<<row<<'C'<<col<<endl;
}

//RR**
void p_two(){
    int i,num = 0;
    while(col > 26){
        temp[num++] = (col  - 1 ) % 26 + 'A' ;
        col = (col  -  (temp[num - 1] - 'A' +1)) / 26;
    }
    temp[num++] = (col  - 1 ) % 26 + 'A' ;
    for(i = num - 1; i >= 0; i--)
        cout<<temp[i];
    cout<<row<<endl;

}


//R**C**
void one(){
    row = col = 0;
    int i = 1,ok = 0;
    for(;ans[i] != '\0';i++){
        if(ans[i] == 'C'){
                ok = 1;
            continue;
        }
        if(ok)
            col  = col * 10 + (ans[i] - '0');
        else
            row = row * 10 + (ans[i] - '0');
    }
    p_two();
    return;
}


//RR**
void two(){
   row = col = 0;
    int i = 0,ok = 0;
    for(; ans[i] != '\0'; i++){
        if(ans[i] > '9')
            col = col * 26 + (ans[i] - 'A' + 1);
        else
            row = row * 10 + (ans[i]  - '0');
    }
    p_one();
}


int main(){
    int i,type;
    cin>>n;  //R288C494
    while(n--){
        cin>>ans;
        type = 2;
        if((ans[0] == 'R') && (ans[1] <= '9') ){
            for(i = 2; ;i++){
                if(ans[i] == '\0')
                    break;
                if(ans[i] > '9' ){
                    type = 1;
                    break;
                }
            }
        }
        if(type == 1)
            one();
        else
            two();
    }
    return 0;
}
