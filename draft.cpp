//用图数据结构表示，
//用BFS，队列实现的时候，给未遍历的每个节点赋一个位置数组
//也可以DFS寻找最短S和D的最短路径
//试一下可以用邻接矩阵形式的图结构，这样不必定义图节点，
//递归标记最短路径,
//~~1)多条最短路径仍需处理;~~
//2)非递归形式=回溯剪枝?

//note: 简单的例子能提供更高效的信息

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int N,D;
vector<pair<int,int>> coord;
int min_len=1000;
vector<int> optimal_path;

bool check(int x,int y){
    if(x==0)    return (pow(coord[y].first,2)+pow(coord[y].second,2)<=pow(D+7.5,2))?true:false;
    return (pow(coord[x].first-coord[y].first,2)+pow(coord[x].second-coord[y].second,2)<=pow(D,2))?true:false;
}

//检查非根节点是否可以到岸
bool test_plausible(int x){
    if(x==0)    return    (abs(coord[x].first-50)<=D+7.5||abs(coord[x].first+50)<=D+7.5||\
       abs(coord[x].second-50)<=D+7.5||abs(coord[x].second+50)<=D+7.5)?true:false;
    return (abs(coord[x].first-50)<=D||abs(coord[x].first+50)<=D||\
       abs(coord[x].second-50)<=D||abs(coord[x].second+50)<=D)?true:false;
}

//递归寻找最短路径,赋值给optimal_path
void shortest_path(int root,vector<int> &path,int depth,vector<int> &visit){
    //path初始化为(N+1,-1);    depth不能用引用改变，否则for循环中depth不等
    for(int i=0;i<=N;i++){
        if(i!=root&&check(root,i)&&visit[i]==0){    //i与root相连且未访问
            visit[i]=1;
            path[depth]=i;        //长度为depth+1，在后面第42行写错俩
            if(test_plausible(i)){
                //若有多条最短路径,需要单独处理,path[1]第一跳更小
                if(depth+1<min_len||((depth+1==min_len)&&\
                    (pow(coord[path[1]].first,2)+pow(coord[path[1]].second,2)\
                    <=pow(coord[optimal_path[1]].first,2)+pow(coord[optimal_path[1]].second,2)))){
                    optimal_path=path;
                    min_len=depth+1;
                    // cout<<"a new path="<<endl;
                    // for(int i=1;i<min_len;i++)
                    //     cout<<coord[optimal_path[i]].first<<" "<<coord[optimal_path[i]].second<<endl;
                }
                //这里可以剪枝——不用从i下探=执行shortest_path函数
                visit[i]=0;    //恢复现场;
             }
            else    shortest_path(i,path,depth+1,visit);
        }
    }
    visit[root]=0;    //恢复现场
    return ;
}

int main(){
    //tackle with input 
    cin>>N>>D;
    coord.assign(N+1,make_pair(0,0));
    for(int i=1;i<=N;i++)
        cin>>coord[i].first>>coord[i].second;

    // //define plausible array
    // vector<bool> plausible(N+1,0);
    // if(D>=42.5)    plausible[0]=true;
    // else     plausible[0]=false;
    // for(int i=1;i<=N;i++)
    //     plausible[i]=test_plausible(i);

    //perform dfs to search for shortest path
    vector<int> path(N+1,-1);    int depth=0;     //熟知,size+array可以表示一个栈
    vector<int> visit(N+1,0);
    visit[0]=1;        //将根节点加入队列
    path[depth]=0;
    if(test_plausible(0)){
        optimal_path=path;
        min_len=1;
    }
    else{
        shortest_path(0,path,depth+1,visit);    //保持形式一致性
    }
    if(min_len==1000){
        cout<<0<<endl;
        return 0;
    }
    cout<<min_len<<endl;
    for(int i=1;i<min_len;i++){                //根节点不用输出
        if(path[i]!=-1)
            cout<<coord[path[i]].first<<" "<<coord[path[i]].second<<endl;
        else 
            break;
    }
    return 0;
}