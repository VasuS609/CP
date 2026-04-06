#include <vector>
#include <unordered_set>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // 1. Store obstacles in a set for O(1) lookup
        // We use a string "x y" as the key
        unordered_set<string> obstacleSet;
        for (const auto& obs : obstacles) {
            obstacleSet.insert(to_string(obs[0]) + " " + to_string(obs[1]));
        }

        // 2. Define directions: North, East, South, West
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        
        int x = 0, y = 0, d = 0; // Start at origin, facing North (index 0)
        int maxDistSq = 0;

        for (int cmd : commands) {
            if (cmd == -1) {
                // Turn right
                d = (d + 1) % 4;
            } else if (cmd == -2) {
                // Turn left
                d = (d + 3) % 4;
            } else {
                // Move forward cmd steps
                for (int i = 0; i < cmd; i++) {
                    int nextX = x + dx[d];
                    int nextY = y + dy[d];
                    
                    // Check if next step is an obstacle
                    if (obstacleSet.find(to_string(nextX) + " " + to_string(nextY)) == obstacleSet.end()) {
                        x = nextX;
                        y = nextY;
                        // Update max distance squared
                        maxDistSq = max(maxDistSq, x * x + y * y);
                    } else {
                        // Hit an obstacle, stop moving for this command
                        break;
                    }
                }
            }
        }
        
        return maxDistSq;
    }
};