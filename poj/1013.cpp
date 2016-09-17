#include<cstdio>
#include<cstring>

//#define LOCAL

using namespace std;

int n;

int data[12];
int flag[12];

void pro(int pos, int val){
    if(val == 0 || data[pos] == -1){
        data[pos] = val;
        return;
    }
    if((data[pos] == 1 && val == 2) || (data[pos] == 2 && val == 1)){
        data[pos] = 0;
    }
}

int main(){
    //从文件读入
    #ifdef  LOCAL
    freopen ("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);
    #endif

    /* TO DO  HERE!  */
    int i,k;
    scanf("%d",&n);
    char str1[12],str2[12],str3[12];
    while(n--){
        memset(data,-1,sizeof(data));
        for(k = 1; k <= 3; k ++){
            scanf("%s %s %s", &str1,&str2,&str3);
            if(strcmp(str3,"even")==0){
                for(i = 0;str1[i]!='\0'; i ++)
                    pro(str1[i] - 'A',0);
                for(i = 0;str2[i]!='\0'; i ++)
                    pro(str2[i] - 'A',0);
                continue;
            }
            memset(flag,0,sizeof(flag));
            if(strcmp(str3,"up")==0){
                for(i = 0;str1[i]!='\0'; i ++){
                    pro(str1[i] - 'A',2);
                    flag[str1[i] - 'A'] = 1;
                }
                for(i = 0;str2[i]!='\0'; i ++){
                    pro(str2[i] - 'A',1);
                    flag[str2[i] - 'A'] = 1;
                }
            }
             if(strcmp(str3,"down")==0){
                for(i = 0;str1[i]!='\0'; i ++){
                    pro(str1[i] - 'A',1);
                    flag[str1[i] - 'A'] = 1;
                }
                for(i = 0;str2[i]!='\0'; i ++){
                    pro(str2[i] - 'A',2);
                    flag[str2[i] - 'A'] = 1;
                }
            }

            for( i = 0 ; i < 12; i ++){
                if(flag[i] == 0)
                    pro(i,0);
            }
        }

        for(i = 0; i < 12; i ++){
            if(data[i] == 1){
                printf("%c is the counterfeit coin and it is light.\n",i + 'A');
                break;
            }
            if(data[i] == 2){
                printf("%c is the counterfeit coin and it is heavy.\n",i + 'A');
                break;
            }
        }

    }
    return 0;
}
