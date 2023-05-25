class Solution{
public:
    vector<int> prefixCount(int N, int Q, string li[], string query[])
    {
         unordered_map<string,int> map;
        // int n=li.size();
        for(int i=0;i<N;i++){
            int m=li[i].size();
            string s="";
            for(int j=0;j<m;j++){
                s+=li[i][j];
                map[s]++;
            }
        }
        vector<int> ans;
        for(int i=0;i<Q;i++){
            ans.push_back(map[query[i]]);
        }
        return ans;
    }
};
