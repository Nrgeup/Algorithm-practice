#include<cstdio>
#include<cmath>
#include<cstring>

//#define LOCAL

using namespace std;

char str[1000];


int main(){
    //从文件读入
    #ifdef  LOCAL
    freopen ("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);
    #endif

    /* TO DO  HERE!  */
    int sum=0,temp;
    char type;
    while(scanf("%s",&str)!=EOF){
        if(strcmp(str,"#")==0){
            break;
        }
        if(strcmp(str,"0")==0){
            printf("%d\n",sum);
            sum = 0;
            continue;
        }
        scanf("%s %d %c",&str,&temp,&type);
        if(type == 'F'){
            sum += temp*2;
        }
        if(type == 'B'){
            sum += ceil(temp*1.5);
        }
        if(type == 'Y'){
            if(temp <= 500)
                sum += 500;
            else
                sum += temp;
        }
    }

    return 0;
}
