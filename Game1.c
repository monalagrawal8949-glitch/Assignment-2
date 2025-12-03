#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

int highScore = 0;

/* Load High Score */
void loadHighScore() 
{
    FILE *f = fopen("highscore.txt", "r");
    if (f == NULL) {
        highScore = 0;
        return;
    }
    fscanf(f, "%d", &highScore);
    fclose(f);
}

/* Save High Score */
void saveHighScore(int score) 
{
    FILE *f = fopen("highscore.txt", "w");
    if (!f) return;
    fprintf(f, "%d", score);
    fclose(f);
}

/* Game Function */
void playGame()
{
    srand(time(0));

    int x = 1;                  
    int step = 0;                
    int obstaclePos = rand() % 3;
    int score = 0;
    int speed = 150;
    int lives = 3;

    while (1)
    {
        // INPUT
        if (_kbhit())
        {
            char ch = getch();
            if (ch == 75 && x > 0) x--;        // left
            else if (ch == 77 && x < 2) x++;   // right
        }

        // DRAW
        system("cls");
        printf("|--- --- ---|\n");

        for (int i = 0; i < 10; i++)
        {
            if (i == step)
            {
                if (obstaclePos == 0) printf("| %c         |\n", 1);
                else if (obstaclePos == 1) printf("|     %c     |\n", 1);
                else printf("|        %c  |\n", 1);
            }
            else
            {
                printf("|           |\n");
            }
        }

        // PLAYER
        if (x == 0) printf("| %c         |\n", 6);
        else if (x == 1) printf("|     %c     |\n", 6);
        else printf("|        %c  |\n", 6);

        // STATS
        printf("\nScore: %d", score);
        printf("\nLives: %d", lives);
        printf("\nHigh Score: %d\n", highScore);

        // COLLISION
        if (step == 10 && x == obstaclePos)
        {
            lives--;
            printf("\nYou got hit! Lives left: %d\n", lives);
            Sleep(600);

            if (lives == 0)
            {
                // Update high score
                if (score > highScore)
                {
                    highScore = score;
                    saveHighScore(highScore);
                }

                printf("\nGAME OVER!\n");
                printf("Your Final Score: %d\n", score);
                printf("High Score: %d\n", highScore);
                break;
            }

            // Reset obstacle after losing life
            step = 0;
            obstaclePos = rand() % 3;
        }

        Sleep(speed);

        // Move obstacle
        step++;

        // Obstacle passed
        if (step > 10)
        {
            step = 0;
            obstaclePos = rand() % 3;

            score++;

            // Increase difficulty
            if (score % 5 == 0 && speed > 40)
                speed -= 10;
        }
    }
}

/* MAIN */
int main()
{
    char choice;

    loadHighScore();

    while (1)
    {
        system("cls");
        printf("\n==== SIMPLE LANE GAME ====\n");
        printf("Controls: Left Arrow ← , Right Arrow →\n");
        printf("Press any key to start...\n");
        getch();

        playGame();

        printf("\nDo you want to play again? (y/n): ");
        fflush(stdin);
        scanf("%c", &choice);

        if (choice == 'n' || choice == 'N')
        {
            printf("\nThanks for playing!\n");
            break;
        }
    }

    return 0;
}