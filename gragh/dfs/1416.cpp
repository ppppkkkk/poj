#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <cstdlib>
/*
你需要发明一台碎纸机，能够将已知内容的纸条上的数字进行分割，同时你会知道一个目标值，
你需要编写碎纸机的程序，让碎纸机将纸条分割后的数字的和最接近且不能大于目标值，
例如目标值为50，纸条为12346，碎纸机会将纸条切成4份，分别为1、2、34、6，它们的和为43，最接近目标值，而1 + 23 + 4 + 6=34或 12 + 34 + 6=52的组合均是无效的。

*/


using namespace std;
int target;
string shredding;
class Node{
public:
    int mtimes1;
    string s1;
};
map<int, Node > M;

void dfs(int s1, const string &s2, string res){
    // 剪枝
    if (s1 > target)
        return;
    if (s2.length()==0){
        // 之前没有
        if (M.find(s1)==M.end()){
            Node node;
            node.mtimes1 = 1, node.s1 = res;
            M[s1] = node;
        } else{
            M[s1].mtimes1++;
        }
        return;
    }
    for (int i = 1; i <= s2.length(); ++i) {
        string s = s2.substr(0, i);
        dfs(s1+atoi(s.c_str()), s2.substr(i), res+" "+s);
    }
}

int main(){
    while (cin>>target>>shredding&&target){
        //如果不用切取
        if (target == atoi(shredding.c_str())){
            cout<<target<<" "<<target<<endl;
            continue;
        }
        M.clear();
        // other cases;
        for (int i = 1; i <= shredding.length() ; ++i) {
            string s = shredding.substr(0, i);
            // 前面的哪个数字固定，后面的继续分
            dfs(atoi(s.c_str()), shredding.substr(i), s);
        }
        if (M.size() == 0)
            cout<<"error"<<endl;
        else if (M.rbegin()->second.mtimes1>=2){
            cout<<"rejected"<<endl;
        } else{
            cout<<M.rbegin()->first<<" ";
            cout<<M.rbegin()->second.s1<<endl;
        }
    }
}
