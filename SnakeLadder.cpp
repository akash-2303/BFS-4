// Time Complexity: O(m*n)
// Space Complexity: O(m*n)
// Did this code run successfully on Leetcode? Yes

//Approach:
// 1. Make a flat array of size n*n and fill it with the values from the board.
// 2. Use a queue to perform BFS on the flat array, starting from index 0.
// 3. For each index, check the next 6 indices (1 to 6) and push them into the queue if they are not visited.
// 4. If the index is a snake or ladder, push the destination index into the queue instead.
// 5. Mark the index as visited by setting it to -2.
// 6. Continue until the queue is empty or the destination index is reached.

class Solution {
    public:
        int snakesAndLadders(vector<vector<int>>& board) {
            int n = board.size();
            vector<int> flat(n * n);
            int i = n - 1, j = 0; //starting square
            bool dir = true;
            int idx = 0;// index of flattened array
            while(idx < n*n){
                //is not snake or ladder
                if(board[i][j] == -1){
                    flat[idx] = -1;
                }else{
                    flat[idx] = board[i][j] - 1;
                }
                if(dir == true){
                    j++;
                    if(j == n){
                        dir = false;
                        i--;
                        j--;
                    }
                }else{
                    j--;
                    if(j == -1){
                        dir = true;
                        i--;
                        j++;
                    }
                }
                idx++;
            }
            queue<int> q;
            q.push(0);
            flat[0] = -2;
            int jumps = 0;
    
            while(!q.empty()){
                int size = q.size();
                for(int i = 0; i < size; i++){
                    int curr = q.front();
                    q.pop();
                    if(curr >= n*n - 1){
                        return jumps;
                    }
                    for(int j = 1; j <= 6; j++){
                        int neighbor = curr + j;
                        if(neighbor < n*n && flat[neighbor] != -2){
                            if(flat[neighbor] > -1){
                                q.push(flat[neighbor]);
                            }else{
                                q.push(neighbor);
                            }
                            flat[neighbor] = -2;
                        }
                    
                    }
                }
                jumps++;
            }
            return -1;
        }
    };