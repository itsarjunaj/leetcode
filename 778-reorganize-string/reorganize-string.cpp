class node{
    public:
    char data;
    int count;
    node(char d,int c){
        data=d;
        count=c;
    }
};
class compare{public:
     bool operator()(node a,node b){
        return a.count<b.count;
     }};
class Solution {
public:
    string reorganizeString(string s) {
        int freq[26]={0};
        int size=s.length();
        string ans="";
        for(int i=0;i<size;i++){
            char ch=s[i];
            freq[ch-'a']++;
        }
        priority_queue<node,vector<node>,compare> maxheap;
        for(int i=0;i<26;i++){
            if(freq[i]!=0){
                node temp(i+'a',freq[i]);
                maxheap.push(temp);
            }
        }
        while(maxheap.size()>1){
            node first=maxheap.top();
            maxheap.pop();
            node second=maxheap.top();
            maxheap.pop(); 
            ans+=first.data;
            ans+=second.data;
            first.count--;
            second.count--;
            if(first.count!=0){
                maxheap.push(first);

            }
              if(second.count!=0){
                maxheap.push(second);
                
            }}
      if(maxheap.size()==1){
        node temp=maxheap.top();
        maxheap.pop();
        if(temp.count==1)
        ans+=temp.data;
        else
           return "";
      
        }

    return ans;}
};