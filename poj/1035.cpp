/****************************************************************************\
 *题意：输入一部字典，输入若干单词
 *    1、  若某个单词能在字典中找到，则输出corret
 *    2、  若某个单词能通过 变换 或 删除 或 添加一个字符后，在字典中找得到，则输出这些单词，输出顺序根据  输入的那部字典的字典序
 *    3、  若某个单词无论操作与否都无法在字典中找得到，则输出空
 *
 *思路： 暴力法

\****************************************************************************/
#include<cstdio>   //尽量使用scanf和printf输入输出
#include<algorithm>
#include<cstring>

//#define LOCAL

using namespace std;

const int str_len_max = 16;
const int str_size_max = 10001;

struct str_msg{
    char s[str_len_max];
    int len;
}S[str_size_max];
int num_lib = 0;
char input_str[str_len_max];

void Replace(int index){
    int diff = 0, i, max_length = S[index].len;
    for(i = 0; i < max_length; i++){
        if(S[index].s[i] != input_str[i])
            diff++;
        if(diff > 1)
            return;
    }
    printf(" %s", S[index].s);
}

void Del(int index){
    int diff = 0, i, j, max_length = S[index].len + 1;
    for(i = 0, j = 0; i < max_length; i++, j++){
        if(S[index].s[j] != input_str[i]){
            diff++; j--;
        }
        if(diff > 1)
            return;
    }
    printf(" %s", S[index].s);
}

void Insert(int index){
    int diff = 0, i, j, max_length = S[index].len - 1;
    for(i = 0, j = 0; i < max_length; i++, j++){
        if(S[index].s[j] != input_str[i]){
            diff++; i--;
        }
        if(diff > 1)
            return;
    }
    printf(" %s", S[index].s);
}

int main(){
    //从文件读入
    #ifdef  LOCAL
    freopen ("input.txt","r",stdin);
    //freopen ("output.txt","w",stdout);
    #endif

    /* TO DO  HERE!  */

    int flag, i, len_input_str;

    while(scanf("%s", &S[num_lib].s) && strcmp(S[num_lib].s, "#") != 0){
        S[num_lib].len = strlen(S[num_lib].s);
        //printf("%s\n",S[num_lib].s);
        num_lib++;
    }
    while(scanf("%s", &input_str) && strcmp(input_str, "#") != 0){
        //printf("%s\n", input_str);
        flag = 0;
        for(i = 0; i < num_lib; i++){
            if(strcmp(S[i].s, input_str) == 0){
                printf("%s is correct\n", input_str);
                flag = 1;
                break;
            }
        }
        if(!flag){
            len_input_str = strlen(input_str);
            printf("%s:", input_str);
            for(i = 0; i < num_lib; i++){
                if(len_input_str == S[i].len){
                    Replace(i);
                }
                if(len_input_str == S[i].len + 1){
                    Del(i);
                }
                if(len_input_str == S[i].len - 1){
                    Insert(i);
                }
            }
            printf("\n");
        }
    }

    return 0;
}
