#include <ncurses.h>
#include <math.h>   // for floor()
#include <cstdlib>  // for rand()

#define CELL_CHAR   "*"
#define SCALE       60
#define RED_PAIR    1

float position[2] = {0.5, 1};

float point1[2] = {0, 1};
float point2[2] = {1, 1};
float point3[2] = {0.5, 1 - 0.866025};

// size of character is 14px 28px

void placePoint(float  x, float y)
{
    int window_x = floor(x * SCALE * 2);
    int window_y = floor(y * SCALE);

    move(window_y, window_x);
    printw(CELL_CHAR);
}

void Sierpinski(int iterations)
{
    for (int i = 0; i < iterations; i++)
    {
        placePoint(position[0], position[1]);

        switch((rand() % 3) + 1) {
            case 1:
                position[0] = (position[0] + point1[0])/2;
                position[1] = (position[1] + point1[1])/2;
                break;
            case 2:
                position[0] = (position[0] + point2[0])/2;
                position[1] = (position[1] + point2[1])/2;
                break;
            case 3:
                position[0] = (position[0] + point3[0])/2;
                position[1] = (position[1] + point3[1])/2;
                break;
        } 
    }
}

int main()
{
    initscr();
    
    start_color();
    init_pair(RED_PAIR, COLOR_RED, COLOR_BLACK);
 
    Sierpinski(100000);
    
    attron(COLOR_PAIR(RED_PAIR) );
    placePoint(point1[0], point1[1]);
    placePoint(point2[0], point2[1]);
    placePoint(point3[0], point3[1]);
    attroff(COLOR_PAIR(RED_PAIR) );

    refresh();
    getch();
    endwin();

    return 0;
}    
