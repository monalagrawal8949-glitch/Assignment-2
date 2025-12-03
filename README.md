🎮 Simple Lane Game (C Language)

A console-based 3-lane game built in C, featuring:
✔ Player movement
✔ Falling obstacles
✔ Lives system
✔ Score tracking
✔ Auto-saved high score
✔ Dynamic difficulty

This project uses only simple terminal graphics and works on Windows Console.

📌 Features
🔹 3-Lane Gameplay

Player moves left and right using arrow keys.

Obstacle falls from a random lane.

🔹 Lives System

Player starts with 3 lives.

Collision reduces a life.

Game ends when all lives are lost.

🔹 Score System

Score increases each time the obstacle completes a fall.

Difficulty increases every 5 points by reducing the delay.

🔹 High Score Save/Load

Highest score is saved in highscore.txt.

Each startup loads the previously saved high score.

Automatically updates when a new high score is achieved.

🔹 Difficulty Curve

Speed decreases over time (game becomes faster).

Balanced difficulty for fun and smooth gameplay.

📂 File Structure
simple_lane_game.c
highscore.txt   (auto-created)
README.md

🖥️ Controls
Action	Key
Move Left	← (Left Arrow)
Move Right	→ (Right Arrow)
Start Game	Any key
Replay	y / n
⚙️ How It Works (Logic Flow)
1. Player Input
if (_kbhit()) {
    char ch = getch();
    if (ch == 75) x--;  // Left
    else if (ch == 77) x++; // Right
}

2. Obstacle Movement

Obstacle moves one row per frame.

When it reaches the bottom, score increases.

3. Collision Detection
if (step == 10 && x == obstaclePos)
    lives--;

4. High Score System
Load:
FILE *f = fopen("highscore.txt", "r");
fscanf(f, "%d", &highScore);

Save:
fprintf(f, "%d", score);

5. Difficulty Increase
if (score % 5 == 0 && speed > 40)
    speed -= 10;

🚀 How to Compile & Run
Using GCC (Windows / MinGW):
gcc simple_lane_game.c -o game
game

Turbo C++ (DOSBox)

Direct compile & run

Fully compatible with <conio.h>

📊 Example Output (Simplified)
|--- --- ---|
|     X     |
|           |
|           |
...
|     O     |

Score: 7
Lives: 2
High Score: 12

🏁 Game Over Screen
GAME OVER!
Your Final Score: 23
High Score: 45
