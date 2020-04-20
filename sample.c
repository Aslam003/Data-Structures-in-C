#include<stdio.h>
void main(){
    int X0,Y0;
    X0 = 0;
    Y0 = 0;
  char bomb_dir[4];
        scanf("%s", bomb_dir);
        if(bomb_dir == "U")
            printf("%d %d\n",X0,Y0-1);
        if(bomb_dir == "UR")
            printf("%d %d\n",X0+1,Y0-1);
        if(bomb_dir == "R")
            printf("%d %d\n",X0+1,Y0);
        if(bomb_dir == "DR")
            printf("%d %d\n",X0+1,Y0+1);
        if(bomb_dir == "D")
            printf("%d %d\n",X0,Y0+1);
        if(bomb_dir == "DL")
            printf("%d %d\n",X0-1,Y0+1);
        if(bomb_dir == "L")
            printf("%d %d\n",X0-1,Y0);
        if(bomb_dir == "UL")
            printf("%d %d\n",X0-1,Y0-1);
            printf("0 0");
        }









        #include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    // width of the building.
    int W;
    // height of the building.
    int H;
    scanf("%d%d", &W, &H);
    // maximum number of turns before game over.
    int N;
    scanf("%d", &N);
    int X0;
    int Y0;
    scanf("%d%d", &X0, &Y0);

    // game loop
    while (1) {
        // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        char bomb_dir[4];
        scanf("%s", bomb_dir);
        // Write an action using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");
        if(bomb_dir == "U")
            printf("%d %d\n",X0,Y0-1);
        else if(bomb_dir == "UR")
            printf("%d %d\n",X0+1,Y0-1);
        else if(bomb_dir == "R")
            printf("%d %d\n",X0+1,Y0);
        else if(bomb_dir == "DR")
            printf("%d %d\n",X0+1,Y0+1);
        else if(bomb_dir == "D")
            printf("%d %d\n",X0,Y0+1);
        else if(bomb_dir == "DL")
            printf("%d %d\n",X0-1,Y0+1);
        else if(bomb_dir == "L")
            printf("%d %d\n",X0-1,Y0);
        else if(bomb_dir == "UL")
            printf("%d %d\n",X0-1,Y0-1);
        }
    return 0;
}