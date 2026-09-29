class Solution {
public:
    void dfs(vector<vector<char>>& board, string& word,bool& ans,int i , int j , int x , int n , int m )
    {
        if(i<0 || j <0 || i>=n || j>=m) return ;
        if(board[i][j]==word[x])
        {
            if(x==word.length()-1){
            ans=true;
            return;
            }
            auto tmp = board[i][j];
            board[i][j]='*'; 
            dfs(board,word,ans,i+1,j,x+1,n,m);
            dfs(board,word,ans,i,j+1,x+1,n,m);
            dfs(board,word,ans,i-1,j,x+1,n,m);
            dfs(board,word,ans,i,j-1,x+1,n,m);
            board[i][j]=tmp;
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool res=false;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]==word[0])
                {
                    dfs(board,word,res,i,j,0,board.size(),board[0].size());
                    if(res) return true;
                }
            }
        }
        return res;
    }
};
