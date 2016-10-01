#include<iostream>
#include<cstdio>
#include<cstring>
//#include<

using namespace std;

//#define LOCAL

int N;
char Name[32][200],temp_name[200];
float MAP[32][32];


int getIndex(char * name){
	for( int i = 0; i < N; i++){
		if(strcmp(name,Name[i]) == 0){
			return i;
		}
	}
	return -1;
}

void floyd(){
    int i,j,k;
    float temp;
    for ( k = 0; k < N; k++){
        for( i = 0; i < N; i++){
            for( j = 0; j < N; j++){
                temp = MAP[i][k] * MAP[k][j];
                if(MAP[i][j] < temp)
                    MAP[i][j] = temp;
            }
        }
    }
}

int main(){

    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    #endif // LOCAL

	int index = 1,i,j,temp_i,x,y,ok;
	float val;
	while(cin>>N && N){
        for( i =0; i < N; i++){
            for( j = 0; j < N; j++){
                if(i == j)
                    MAP[i][j] = 1;
                else
                    MAP[i][j] = 0;
            }
        }
		for( i = 0; i < N; i++){
			cin>>Name[i];
		}
		cin>>temp_i;

		for( i = 0; i < temp_i; i++){
			cin>>temp_name;
			x = getIndex(temp_name);
            cin>>val;
            cin>>temp_name;
			y = getIndex(temp_name);
			MAP[x][y] = val;
		}
        floyd();
        ok = 0;
        cout<<"Case "<<index++<<": ";
        for(i = 0; i < N; i++)
            if(MAP[i][i] > 1){
                ok = 1;
                break;
            }
        if(ok)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;

	}
	return 0;
}
