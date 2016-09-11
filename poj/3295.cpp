    #include <cstdio>
    #include <cstring>
    #include <iostream>
    #include <algorithm>

    #include <stack>

    #include <fstream>

using namespace std;


 //从文件读入
//ifstream cin("input.txt");
//ofstream cout("output.txt");


    char str[105];
    int p, q, r, s, t;
    int len;

    int fun() {
        stack<int> st;
        for(int i = len - 1; i >= 0; i --) {
            if(str[i] == 'p') st.push(p);
            else if(str[i] == 'q') st.push(q);
            else if(str[i] == 'r') st.push(r);
            else if(str[i] == 's') st.push(s);
            else if(str[i] == 't') st.push(t);
            else if(str[i] == 'K') {
                int t1 = st.top(); st.pop();
                int t2 = st.top(); st.pop();
                if(t1 == 1 && t2 == 1) st.push(1);
                else st.push(0);
            }
            else if(str[i] == 'A') {
                int t1 = st.top(); st.pop();
                int t2 = st.top(); st.pop();
                if(t1 == 0 && t2 == 0) st.push(0);
                else st.push(1);
            }
            else if(str[i] == 'N') {
                int t1 = st.top(); st.pop();
                st.push(!t1);
            }
            else if(str[i] == 'C') {
                int t1 = st.top(); st.pop();
                int t2 = st.top(); st.pop();
                if(t1 == 1 && t2 == 0) st.push(0);
                else st.push(1);
            }
            else if(str[i] == 'E') {
                int t1 = st.top(); st.pop();
                int t2 = st.top(); st.pop();
                if((t1 == 1 && t2 == 1) || (t1 == 0 && t2 == 0)) st.push(1);
                else st.push(0);
            }
        }
        return st.top();
    }

    int solve() {
        for(p = 0; p < 2; p ++)
            for(q = 0; q < 2; q ++)
                for(r = 0; r < 2; r ++)
                    for(s = 0; s < 2; s ++)
                        for(t = 0; t < 2; t ++) {
                            int tmp = fun();
                            if(tmp == 0) return 0;
                        }
        return 1;
    }

    int main() {
        while(scanf("%s", str) != EOF) {
            if(strcmp(str, "0") == 0) break;
            len = strlen(str);
            int flag = solve();
            if(flag) {
                printf("tautology\n");
            }
            else printf("not\n");
        }
        return 0;
    }
