#include<iostream>
#include<string>
#include<cstring>


using namespace std;

class node
 {
 public:
 	node* last;
	node* next;
	string data;
	node(){
		last =NULL;
		next  = NULL;
		data = "";
	}
 };

int main(){
    string comment,url;
    node* root = new node;
    root->data = "http://www.acm.org/";
    node* pos = root;
    while(cin>>comment && comment != "QUIT"){
        if(comment == "FORWARD"){
            if(pos->next == NULL){
                cout<<"Ignored"<<endl;
            }
            else{
                pos = pos->next;
                cout<<pos->data<<endl;
            }
        }
        if(comment == "BACK"){
        	if(pos->last == NULL){
                cout<<"Ignored"<<endl;
            	}
            	else{
               	pos = pos->last;
               	cout<<pos->data<<endl;
            	}
        }
        if(comment ==  "VISIT"){
                cin>>url;
                cout<<url<<endl;
                pos->next = new node;
                pos->next->last = pos;
                pos = pos->next;
                pos->data = url;
        }
    }
    return 0;
}
