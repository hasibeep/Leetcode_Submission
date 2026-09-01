#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        if (m == 0) return -1;
        int n = classroom[0].size();

        int sr = -1, sc = -1;
        int litterCount = 0;
        
        // Assign a unique ID (0 to litterCount - 1) to each litter cell
        vector<vector<int>> litterId(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                } else if (classroom[i][j] == 'L') {
                    litterId[i][j] = litterCount++;
                }
            }
        }

        // If there is no litter to clean, 0 moves are required.
        if (litterCount == 0) return 0;

        int fullMask = (1 << litterCount) - 1;

        // BFS State: {row, col, remaining_energy, litter_collected_mask, moves_taken}
        struct State {
            int r, c;
            int e;
            int mask;
            int moves;
        };

        queue<State> q;
        q.push({sr, sc, energy, 0, 0});

        // maxEnergy[r][c][mask] stores the maximum energy we've had at (r, c) with a specific `mask`.
        // This drops the 4th dimension (massive memory save) and prunes suboptimal looping paths.
        vector<vector<vector<int>>> maxEnergy(
            m, 
            vector<vector<int>>(
                n, 
                vector<int>(1 << litterCount, -1)
            )
        );

        maxEnergy[sr][sc][0] = energy;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            State cur = q.front();
            q.pop();

            // If we have collected all the litter, return the moves taken
            if (cur.mask == fullMask) {
                return cur.moves;
            }
            
            // If energy is 0 and we didn't just land on an 'R' (which would have reset it), we cannot move further.
            if (cur.e == 0) continue;

            for (int d = 0; d < 4; d++) {
                int nr = cur.r + dr[d];
                int nc = cur.c + dc[d];

                // Check grid bounds
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;

                // Check for obstacles ('X' is the wall)
                if (classroom[nr][nc] == 'X') continue;

                int nE = cur.e - 1;
                int nMask = cur.mask;

                // If we land on a Litter cell, update the bitmask
                if (classroom[nr][nc] == 'L') {
                    nMask |= (1 << litterId[nr][nc]);
                } 
                // If we land on a Reset cell ('R'), restore energy to full capacity
                else if (classroom[nr][nc] == 'R') {
                    nE = energy; 
                }

                // If this move leaves us with more energy than any previous visit to this exact state, explore it
                if (nE > maxEnergy[nr][nc][nMask]) {
                    maxEnergy[nr][nc][nMask] = nE;

                    q.push({
                        nr, 
                        nc, 
                        nE, 
                        nMask, 
                        cur.moves + 1
                    });
                }
            }
        }

        // If the queue is exhausted and we haven't found a path, it's impossible.
        return -1;
    }
};