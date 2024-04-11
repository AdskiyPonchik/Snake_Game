#include <iostream>
#include <stdio.h>

const int WIDTH = 20;
const int HEIGHT = 9;
const int MAX_LEN_SNAKE = (WIDTH - 3) * (HEIGHT - 2);
const int UP = 0;
const int DOWN = 1;
const int LEFT = 2;
const int RIGHT = 3;
int snake_dir = UP;
bool isRunning = true;

void SetCursorPosition(int XPos, int YPos) {
    printf("\033[%d;%dH", YPos + 1, XPos + 1);
}

char map[] =
        "####################\n"
        "#                  #\n"
        "#                  #\n"
        "#                  #\n"
        "#                  #\n"
        "#                  #\n"
        "#                  #\n"
        "#                  #\n"
        "####################\n";

char snake = 'O';
int snake_x[MAX_LEN_SNAKE] = {0};
int snake_y[MAX_LEN_SNAKE] = {0};
int snake_len = 1;

int main() {
    snake_x[0] = WIDTH / 2;
    snake_y[0] = HEIGHT / 2;
    double time = clock();
    while (isRunning) {
        if ((clock() - time) / CLOCKS_PER_SEC >= 0.3) {
            time = clock();
            for (int i = snake_len - 2; i >= 0; i--) {
                snake_x[i + 1] = snake_x[i];
                snake_y[i + 1] = snake_y[i];
            }
            switch (snake_dir) {
                case UP:
                    --snake_y[0];
                    break;
                case DOWN:
                    ++snake_y[0];
                    break;
                case RIGHT:
                    ++snake_x[0];
                    break;
                case LEFT:
                    --snake_x[0];
                    break;
            }
            if (snake_x[0] == 0 || snake_y == 0 || snake_x[0] == WIDTH - 2 || snake_y[0] == HEIGHT - 1) {
                isRunning = false;
            }
            SetCursorPosition(0, 0);
            std::cout << "Length: " << snake_len << std::endl;
            for (int i = 0; i < snake_len; ++i) {
                map[snake_y[i] * WIDTH + snake_x[i]] = snake;
            }
            std::cout << map;
            for (int i = 0; i < snake_len; ++i) {
                map[snake_y[i] * WIDTH + snake_x[i]] = ' ';
            }
        }
    }
    SetCursorPosition(1, HEIGHT/2);
    std::cout << "Your score is " << snake_len << std::endl;
    SetCursorPosition(WIDTH, HEIGHT);
}

