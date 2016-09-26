/*
    bellman-ford 算法，判断有没有负环
*/
#include<cstdio>
#include<iostream>

//#define LOCAL
const int Max_Length = (1<<26);

using namespace std;

int F,N,M,W,Num;

struct node{
	int s;
	int e;
	int t;
}Edge[10000];

int Distance[10000];

int bellman_ford(){
	Distance[1] = 0;
	int i,j = 0,Time = Num * N,s,e,t;
	for(i = 2; i <= N; i++){
		Distance[i] = Max_Length;
	}

	int ok = 1;
    while(ok){
        ok = 0;
        for( i = 0; i < Num; i++){
            s = Edge[i].s;
            e = Edge[i].e;
            t = Edge[i].t;
            //cout<<"s = "<<s<<" e = "<<e<<" t = "<<t<<" Distance["<<s<<"] = "<<Distance[s]<<" Distance["<<e<<"] = "<<Distance[e]<<"\n";
            if(Distance[e] > Distance[s] + t){
                ok = 1;
                Distance[e] = Distance[s] + t;
            }
            //cout<<" Distance["<<s<<"] = "<<Distance[s]<<" Distance["<<e<<"] = "<<Distance[e]<<"\n";
            j++;
            if(j > Time)
                return 1;
        }
	}
	return 0;
}


int main(){
    //从文件读入
    #ifdef  LOCAL
    freopen ("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);
    #endif

    /* TO DO  HERE!  */
	int i,j,temp_s,temp_e,temp_t;
	cin>>F;
	while(F--){
		cin>>N>>M>>W;
		Num = 0;
		for(i = 0; i < M; i++){
			cin>>temp_s>>temp_e>>temp_t;
			Edge[Num].s = temp_s;
			Edge[Num].e = temp_e;
			Edge[Num++].t = temp_t;
			Edge[Num].s = temp_e;
			Edge[Num].e = temp_s;
			Edge[Num++].t = temp_t;
		}
		for(i = 0; i < W; i++){
			cin>>temp_s>>temp_e>>temp_t;
			Edge[Num].s = temp_s;
			Edge[Num].e = temp_e;
			Edge[Num++].t = -temp_t;
		}

        if(bellman_ford())
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;

	}
    return 0;
}
