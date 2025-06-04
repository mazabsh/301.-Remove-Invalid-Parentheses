#include<iostream> 
#include<unordered_set> 
#include<queue> 
#include<vector> 

using namespace std; 

class Solution{
public: 
     vector<string> removeInvalidParentheses(string s){
       vector<string> res; 
       queue<string> q; 
       unordered_set<string> visited; 
       bool found = false; 
       q.push(s); 
       visited.insert(s); 
       while(!q.empty()){
          string curr = q.front(); 
          q.pop(); 
          if(isValid(curr)){
             res.push_back(curr); 
             found = true; 
          }
         if(found) continue; 
         for(int i=0; i<curr.size(); ++i){
            if(curr[i]!='(' && curr[i]!=')') continue; 
             string next = curr.substr(0,i) + curr.substr(i+1); 
             if(!visited.count(next)){
                 q.push(next); 
                 visited.insert(next); 
             }
         }
       }
       return res; 
     }
     bool isValid(string& curr){
        int count=0; 
        for(char c:curr){
            if(c=='(') ++count; 
            else if(c==')') {
               --count; 
               if(count<0) return false; 
            }
        }
        return count ==0; 
     }
};
int main(){
    string s = "()())()"; 
    Solution sol; 
    vector<string> res= sol.removeInvalidParentheses(s); 
    for(string p:res){
        cout<< p << endl; 
    }
    return 0; 
}
