#include<cstdio>
#include<map>
#include<cstring>
using namespace std;

class Node{
public:
    char next[6];
    char val;
};

int main(){
    char h1[6],h2[6];
    int N;
    map<char*,Node>    dict;
    scanf("%s %s %d",h1,h2,&N);
    for(int i=0;i<N;i++){
        char front[6];
        Node *nnode=new Node;
        scanf("%s %c %s",front,&(nnode->val),nnode->next);
        dict[front]=(*nnode);
    }
    char tra1[6],tra2[6];
    strcpy(tra1,h1);
    strcpy(tra2,h2);
    char common_prefix[6];
    int sign=0;
    while(strcmp(tra1,"-1")!=0||strcmp(tra2,"-1")!=0){
        if(dict[tra1].val==dict[tra2].val){
            if(sign==0){
                sign=1;
                strcpy(common_prefix,tra1);
            }
        }
        else sign=0;
        if(strcmp(dict[tra1].next,"-1")==0)    strcpy(tra1,h2);
        else    strcmp(tra1,dict[tra1].next);
        if(strcmp(dict[tra2].next,"-1")==0)    strcpy(tra2,h1);
        else    strcmp(tra2,dict[tra2].next);
    }
    printf("%s",common_prefix);
}