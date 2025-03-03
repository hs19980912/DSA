Knight and Bishop Minimum Moves Problem 🏇♟️

📌 Problem Statement

You are given an N × N chessboard where a knight starts at position (kStartX, kStartY) and needs to reach the target position (targetX, targetY). However, there is a bishop placed at (bishopX, bishopY), which may obstruct the knight’s movement. 
Bishop does not move, but if knight comes at its original position, bishop is killed. 

The objective is to determine the minimum number of moves required for the knight to reach the target position. The knight follows its standard movement pattern, moving in eight possible L-shaped directions. Additionally:
	•	The bishop blocks certain squares based on its movement (it can attack diagonally).
	•	The knight can capture the bishop by landing on its position, removing it from the board.
	•	The knight cannot pass through squares where the bishop can attack unless it captures the bishop first.

🛠 Constraints & Rules
	1.	Knight Movement:
	•	Moves in an “L” shape: (±2, ±1) or (±1, ±2).
	•	Can move through obstacles except when blocked by the bishop.
	2.	Bishop Rules:
	•	Attacks diagonally in all four directions.
	•	Blocks the knight from passing through its attack range.
	•	If the knight lands on the bishop’s position, the bishop is captured and removed.
	3.	Grid Constraints:
	•	0 ≤ kStartX, kStartY, targetX, targetY, bishopX, bishopY < N
	•	Board size N × N (typically N = 16).

🔹 Approach & Solution
	1.	Use BFS (Breadth-First Search):
	•	The knight moves in levels, ensuring the shortest path.
	•	A visited matrix is used to prevent revisiting squares.
	2.	Handling the Bishop’s Blockage:
	•	A function isBishopPosition(x, y) checks if a position falls within the bishop’s attack range.
	•	If the bishop is alive, the knight cannot pass through blocked squares.
	•	If the knight reaches (bishopX, bishopY), the bishop is captured (isBishopDead = true).
	3.	Processing Moves:
	•	Start from (kStartX, kStartY), explore all 8 knight moves.
	•	Avoid bishop-controlled squares unless capturing the bishop.
	•	Continue BFS until reaching (targetX, targetY).

🔹 Example Walkthrough

📝 Input

N = 16;
kStartX = 4, kStartY = 5;
targetX = 12, targetY = 8;
bishopX = 9, bishopY = 4;

🚀 Execution
	1.	BFS starts at (4,5) with count = 0.
	2.	Moves are checked, avoiding bishop attacks.
	3.	If required, the knight captures the bishop.
	4.	The target (12,8) is reached in minimum moves.

🎯 Output

Minimum Steps: 6

✅ The knight reaches the target in 6 moves.

⏳ Time Complexity
	•	O(N²) in the worst case due to BFS traversal.
	•	O(1) extra space for tracking visited cells.
	

Code:

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int kStartX = 4, kStartY = 5;
int targetX = 12, targetY = 8;
int bishopX = 9, bishopY = 4;
bool isBishopDead = false;
int n = 16; // n x n matrix

vector<vector<bool>> visited;
vector<int> delX = {2, -2, 1, -1, 2, -2, 1, -1};
vector<int> delY = {1, 1,  2,  2, -1, -1, -2, -2}; 

bool isBishopPosition(int curX, int curY) {
    if (isBishopDead) return false;
    return (abs(curX - bishopX) == abs(curY - bishopY));
}

bool isValid(int curX, int curY) {
    return (curX >= 0 && curX < n && curY >= 0 && curY < n);
}

int minSteps() {
    visited.resize(n, vector<bool>(n, false)); // Fixed bool type
    int count = 0;
    queue<pair<int, int>> q;
    q.push({kStartX, kStartY});
    visited[kStartX][kStartY] = true;

    while (!q.empty()) {
        int curLen = q.size();
        while (curLen-- > 0) {
            pair<int, int> curPos = q.front();
            q.pop();

            int curX = curPos.first, curY = curPos.second;

            if (curX == targetX && curY == targetY) {
                return count; // Answer found
            }

            int newX, newY;
            for (int i = 0; i < 8; ++i) {
                newX = curX + delX[i];
                newY = curY + delY[i];

                if (isValid(newX, newY) 
                    && isBishopPosition(newX, newY) == false
                    && visited[newX][newY] == false) {

                    if (newX == bishopX && newY == bishopY) {
                        // Bishop is captured
                        isBishopDead = true;
                    }

                    q.push({newX, newY});
                    visited[newX][newY] = true;
                }
            }
        }
        count += 1;
    }

    return -1; // If no path found
}

int main() {
    cout << "Minimum Steps: " << minSteps() << endl;
    return 0;
}