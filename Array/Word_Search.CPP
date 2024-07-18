class Solution {
public:
  
    void For_Better_Understanding(int k,int row,int col,vector<vector<bool>>& isvisited)
    {
        cout<<"k: "<<k<<" row: "<<row<<" col: "<<col<<endl;
        for(auto i:isvisited)
        {
            for(auto j:i)
            {
                cout<<j<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    bool getans(int k,int row,int col,string& word,vector<vector<bool>>& isvisited,vector<vector<char>>& board)
    {
        if(k >= word.length())
        {
            return true;
        }
        isvisited[row][col]=true;
       
        if((row-1 >= 0) && (word[k] == board[row-1][col]) && isvisited[row-1][col] ==false)
        {
            bool result=getans(k+1,row-1,col,word,isvisited,board);
            if(result)return true;
        }
        
        if(row+1 < board.size() && word[k] == board[row+1][col] && isvisited[row+1][col] ==false)
        {
            bool result=getans(k+1,row+1,col,word,isvisited,board);
            if(result)return true;
        }
        
        if(col-1 >= 0 && word[k] == board[row][col-1] && isvisited[row][col-1] ==false)
        {
            bool result=getans(k+1,row,col-1,word,isvisited,board);
            if(result)return true;
        }
        
        if(col+1 < board[0].size() && word[k] == board[row][col+1] && isvisited[row][col+1] ==false)
        {
            bool result=getans(k+1,row,col+1,word,isvisited,board);
            if(result)return true;
        }
        isvisited[row][col]=false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int totalRows=board.size();
        int totalCols=board[0].size();
        vector<vector<bool>> isvisited(totalRows,vector<bool>(totalCols,false));
        
        for(int i=0;i<totalRows;i++)
        {
            for(int j=0;j<totalCols;j++)
            {
                if(board[i][j] == word[0])
                {
                    bool result=getans(1,i,j,word,isvisited,board);
                    if(result)return true;
                }
            }
        }
        return false;
    }
};