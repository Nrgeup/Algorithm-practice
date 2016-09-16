#include<cstdio>
#include<algorithm>
#include<cstring>
//#define LOCAL

using namespace std;

int k1,k2,k3;
char str[88];
int pos[88];
char str1[88],str2[88],str3[88];
int n1,n2,n3;

int main(){
    //从文件读入
    #ifdef  LOCAL
    freopen ("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);
    #endif

    /* TO DO  HERE!  */
    int i;
    while(scanf("%d %d %d",&k1,&k2,&k3) != EOF && !(k1==0 && k2 == 0 && k3 == 0)){
        scanf("%s",&str);
        n1 = n2 = n3 = 0;
        for(i = 0; i < strlen(str); i ++){
            if(str[i] >= 'a' && str[i] <= 'i'){
                pos[i] = n1;
                str1[n1++] = str[i];
            }
            if(str[i] >= 'j' && str[i] <= 'r'){
                pos[i] = n2;
                str2[n2++] = str[i];
            }
            if((str[i] >= 's' && str[i] <= 'z') ||str[i] == '_' ){
                pos[i] = n3;
                str3[n3++] = str[i];
            }
        }
        //  0 1 2 3 4 5 6 7        8    0 + 8 - 1 % 8
        for(i = 0; i < strlen(str); i ++){
            if(str[i] >= 'a' && str[i] <= 'i'){
                str[i] = str1[(pos[i] + n1 - (k1%n1)) % n1];
            }
            if(str[i] >= 'j' && str[i] <= 'r'){
                str[i] = str2[(pos[i] + n2 - (k2%n2)) % n2];
            }
            if((str[i] >= 's' && str[i] <= 'z') ||str[i] == '_' ){
                str[i] = str3[(pos[i] + n3 - (k3%n3)) % n3];
            }
        }

        printf("%s\n",str);
    }
    return 0;
}
