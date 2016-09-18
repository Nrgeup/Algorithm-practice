#include<cstdio>

//#define LOCAL

using namespace std;

/*
y=-x+2.5; 0 <= x < 5
y=2-1.5(x-3)(x-3); 5 <= x < 10
y=x/2-1.5; 10 <= x < 20
*/

float  func(float x){
    float y;
    if(x >= 0 && x < 5){
        y = 2.5 - x;
    }
    if(x >= 5 && x < 10)
        y =  (2 - 1.5 * (x - 3)* (x - 3) );
    if( x >= 10 && x  < 20)
        y = x/2 - 1.5;
    return y;
}

int main(){
    //从文件读入
    #ifdef  LOCAL
    freopen ("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);
    #endif

    /* TO DO  HERE!  */

    float N;
    while(scanf("%f",&N) != EOF){
        printf("%.3f\n",func(N));
    }
    return 0;
}
