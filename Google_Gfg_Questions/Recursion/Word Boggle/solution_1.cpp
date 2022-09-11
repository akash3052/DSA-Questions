// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> delx = { 0, 0, 1, -1, 1, 1, -1, -1};
    vector<int> dely = { 1, -1, 0, 0, -1, 1, 1, -1};
    
    bool isvalid(int i, int j, int row, int col){
        if(i<0 || j<0 || i>=row || j>=col)
            return false;
        return true;
    }
    
    void initVisited(vector<vector<int>> &visited, int row, int col){
    	for(int i=0; i<row; i++){
    		for(int j=0; j<col; j++){
    			visited[i][j] = 0;
    		}
    	}
    }
    
    void dfs(int i, int j, string word, int index, vector<vector<char>> &board, int row, int col,
                bool &wordPresent, vector<vector<int>> &visited){
        cout<<"\n\nword: "<<word<<", i:"<<i<<", j:"<<j<<", index:"<<index<<", wordPresent:"<<wordPresent<<endl;
    	if(index >= word.size()){
    		wordPresent = true;
    		return;
    	}
    	if(!isvalid(i, j, row, col))
    		return;
    	cout<<"After validation -> word: "<<word<<", i:"<<i<<", j:"<<j<<", index:"<<index<<endl;
    	visited[i][j] = true;
    	cout<<"board[i][j]:"<<board[i][j]<<", word[index]:"<<word[index]<<endl;
    	if( board[i][j] == word[index]){
    		for(int k=0; k<8; k++){
        		int newi = i + delx[k];
        		int newj = j + dely[k];
        		cout<<"newi:"<<newi<<", newj:"<<newj<<endl;
        		if(isvalid(newi, newj, row, col)){
        		    if(!visited[newi][newj]){
        			dfs(newi, newj, word, index+1, board, row, col, wordPresent, visited);
        		    }
        		}
            }	
    	}
    }
    
    bool isWordPresent(string dictWord, vector<vector<char>> &board, int row, int col, 
                        vector<vector<int>> &visited){
        int index = 0, i, j;
        initVisited(visited, row, col);
        bool firstLetterPresent = false;
        cout<<"*************************start of new word *************"<<endl;
        for(i=0; i< row; i++){
            for(j=0; j<col;j++){
        		if(board[i][j] == dictWord[index]){
        		   
        		    cout<<"\nindex: "<<index<<", i:"<<i<<", j:"<<j<<", board[i][j]:"<<
        		    board[i][j]<<", dictword:"<<dictWord<<endl;
        		    firstLetterPresent = true;
        		    break;
        		}
            }
            if(firstLetterPresent)
                break;
        }
        if(firstLetterPresent){
            bool wordPresent = false;
        	dfs(i, j, dictWord, index, board, row, col, wordPresent, visited);
        	cout<<"akash ********** dictWord: "<<dictWord<<", wordPresent:"<<wordPresent<<endl;
        	if(wordPresent)
        		return true;
        	else
        	    return false;
        }
        return false;
    }
    
    vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
    	vector<string> res;
    	int row = board.size();
    	int col = board[0].size();
    	vector<vector<int>> visited(row,vector<int>(col));
    	for(auto dictWord : dictionary){
           if(isWordPresent(dictWord, board, row, col, visited)){
               cout<<"wordBoggle : ****** dictword: "<<dictWord<<endl;
                res.push_back(dictWord);
           }
        }
        return res;
    }

};
    

int main() {
    vector<vector<char> > board = {{'G','I','Z'},{'U','E','K'},{'Q','S','E'}};
    vector<string> dictionary = {"GEEKS","FOR","QUIZ","GO"};
    Solution obj;
    vector<string> res = obj.wordBoggle(board, dictionary);
    cout<<"\n\n\n final result : ";
    for(auto x:res)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}


// doubt -> considering 'I' and 'E' equal and entering into for loop. Don't know why

// word: GEEKS, i:0, j:1, index:1, wordPresent:0
// After validation -> word: GEEKS, i:0, j:1, index:1
// board[i][j]:I, word[index]:E
// newi:0, newj:-1
// newi:1, newj:0
