#include<iostream>
#icnlude<cstring>
//#include<

using namespace std;


int N;
char Name[31][100],temp_name;


int getIndex(char * Name){
	for( int i = 0; i < N; i++){
		if(strcmp(Name,Name[i]) == 0){
			return i;
		}
	}
	return -1;
}

int main(){
	int index = 1,i,j,temp_i,x,y;
	while(cin>>N && N){
		for( i = 0; i < N; i++){
			cin>>Name[i];
		}	
		cin>>temp_i;
		for( i = 0; i < temp_i; i++){
			cin>>temp_name;
			x = getIndex();
		}
	}
	return 0;
}
