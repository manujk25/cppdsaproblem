// #include <bits/stdc++.h> 
// void addSolution(vector<vector<int>> &ans,vector<vector<int>> &board,int n){
// 	vector<int> temp;
// 	for(int i=0;i<n;i++){
// 		for(int j=0;j<n;j++){
// 			temp.push_back(board[i][j]);
// 		}
// 	}
// 	ans.push_back(temp);
// }
// bool isSafe(int row,int col,vector<vector<int>> &board,int n){
// 	int x=row;
// 	int y=col;

// 	//check for same row
// 	while(col>=0){
// 		if(board[x][y] == 1){
// 			return false;
// 		}
// 		y--;
// 	}
// 	x=row;
// 	y=col;
// 	//check for Diagonal
// 	while(x>=0 && y>=0){
// 		if(board[x][y] == 1){
// 			return false;
// 		}
// 		x--;
// 		y--;
// 	}

// 	x=row;
// 	y=col;
// 	//check for Diagonal
// 	while(x<n && y>=0){
// 		if(board[x][y] == 1){
// 			return false;
// 		}
// 		x++;
// 		y--;
// 	}
// 	return true;
// }

// void solve(int col,vector<vector<int>> &ans,vector<vector<int>> &board,int n){
// 	//base case
// 	if(col == n){
// 		addSolution(ans,board,n);
// 		return ;
// 	}
// 	//solve 1 case  rest case Recursive will Handle.
// 	for(int row=0;row<n;row++){
// 		if(isSafe(row,col,board,n)){
// 			//if placing Queen is Safe 
// 			board[row][col]=1;
// 			solve(col+1,ans,board,n);
// 			//backtrack 
// 			board[row][col] = 0;

// 		}
// 	}
// }
// vector<vector<int>> nQueens(int n)
// {
// 	vector<vector<int>> board(n,vector<int>(n,0));
// 	vector<vector<int>> ans;

// 	solve(0,ans,board,n);
// 	return ans;
	
// }

#include <bits/stdc++.h> 
unordered_map<int,bool> mppRow, mppUD, mppLD;

void markTrue(int row, int col){
	mppRow[row] = true;
    mppLD[row+col] = true;
    mppUD[row-col] = true;
}

void markFalse(int row, int col){
	mppRow[row] = false;
    mppLD[row+col] = false;
    mppUD[row-col] = false;
}

bool safeUtil(int row, int col, vector<vector<int>> &board, int n){
	
	
	if(mppRow[row] || mppLD[row+col] || mppUD[row-col]) 
    	return false;
		
	return true;
}

void addUtil(vector<vector<int>> &ans, vector<vector<int>> &board, int n){
	vector<int> dummy;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			dummy.push_back(board[i][j]);
		}
	}
	ans.push_back(dummy);
}

void solve(int col,vector<vector<int>> &ans, vector<vector<int>> &board, int n ){
	//base case for returning
	if(col == n){
		addUtil(ans, board, n);
		return;
	}

	//processing
	for(int row=0; row<n; row++){
		if(safeUtil(row,col,board,n)){
			board[row][col] = 1;
			markTrue(row, col);
			//next call for next column
			solve(col + 1, ans, board, n);
			//backtracking
			board[row][col] = 0;
			markFalse(row, col);
		}
	}
}

vector<vector<int>> nQueens(int n)
{
	vector<vector<int>> board(n, vector<int>(n,0));
	vector<vector<int>> ans;

	solve(0, ans, board, n);
	return ans;
	
}
