// Time Complexity: O(m*n)
// Space Complexity: O(m*n)
// Did this code run successfully on Leetcode? Yes

//Approach: 
// 1. Create a queue and push the click position into it.
// 2. Check if the clicked position is a mine. If it is, mark it as 'X' and return the board.
// 3. For each position in the queue, check the number of mines around it using the getMines function.
// 4. If there are no mines, mark the position as 'B' and push all adjacent positions that are 'E' into the queue and change to B in board.
// 5. If there are mines, mark the position with the number of mines around it.
// 6. Continue until the queue is empty.

class Solution {
    public:
        vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
            int m = board.size();
            int n = board[0].size();
            vector<pair<int, int>> direction = {{1,0},{0,1}, {-1,0}, {0,-1}, {1,1},{1,-1}, {-1,1}, {-1, -1}};
            queue<vector<int>> q;
            char start = board[click[0]][click[1]];
            if(start == 'M'){
                board[click[0]][click[1]] = 'X';
                return board;
            }else{
                q.push({click[0], click[1]});
            }
            
            while(!q.empty()){
                vector<int> a = q.front();
                q.pop();
                int mines = getMines(board, a, direction);
                if(mines == 0){
                    board[a[0]][a[1]] = 'B';
                    for(auto& dir: direction){
                        int nX = a[0] + dir.first;
                        int nY = a[1] + dir.second;
                        if(nX >= 0 && nX < m && nY >= 0 && nY < n &&
                        board[nX][nY] == 'E'){
                            q.push({nX, nY});
                            board[nX][nY] = 'B';
                        }
                    }
                }else{
                    board[a[0]][a[1]] = (char)(mines + '0');
                }
            }
            return board;
        }
    private: 
        int getMines(vector<vector<char>>& board, vector<int>& a, vector<pair<int, int>> direction){
            int count = 0;
            int m = board.size();
            int n = board[0].size();
            for(auto& dir: direction){
                int nX = a[0] + dir.first;
                        int nY = a[1] + dir.second;
                        if(nX >= 0 && nX < m && nY >= 0 && nY < n &&
                        board[nX][nY] == 'M'){
                            count++;
                        }
            }
            return count;
        }
    };