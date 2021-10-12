/* file   : skeleton.c */
/* author : Jeremias Lino Ferrao (j.l.ferrao@student.rug.nl) */

/* Description:
 * Structural backbone
 */

#include <stdio.h>
#include <stdlib.h>

#define Y 6
#define X 7

int gameBoard[Y][X] = {0};
int columns[Y] = {0};

void displayBoard () {

    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < X; j++) {
            printf("%-2i", gameBoard[i][j]);
        }
        printf("\n");
    }

}

// Red is 2
// Yellow is 1

void getMoves () {
    int player = 1;
    // Yellow Move
    int x;
    scanf("%i", &x);
    gameBoard[Y - columns[x] - 1][x] = player;

    // Keep track of moves
    int counter = 1;
    columns[x]++;

    char terminator;
    scanf("%c", &terminator);

    while (terminator != '#') {
        scanf("%i", &x);

        if (counter % 2 == 0) {
            player = 1;
        } else {
            player = 2;
        }

        gameBoard[Y - columns[x] - 1][x] = player;
        counter++;
        columns[x]++;

        scanf("%c", &terminator);
    }


}

int computeVictory () {

    int player;

    for (int i = 0; i < Y; i++) {

        for (int j = 0; j < X; j++) {

            if (gameBoard[i][j]) {

                // Vertical
                player = gameBoard[i][j];
                int counter = 1;
                for (int k = -3; k <= 3; k++) {
                    
                    if (k == 0) {
                        counter = 1;
                        continue;
                    }

                    if (i + k < Y && i + k >= 0) {
                        if (gameBoard[i + k][j] == player) {
                            counter++;

                            if (counter == 4) {
                                return player;
                            }
                        } else {
                            break;
                        }
                    }
                }

                // Horizontal
                counter = 1;
                for (int k = -3; k <= 3; k++) {
                    
                    if (k == 0) {
                        counter = 1;
                        continue;
                    }

                    if (j + k < X && j + k >= 0) {
                        if (gameBoard[i][j + k] == player) {
                            counter++;
                            
                            if (counter == 4) {
                                return player;
                            }
                        } else {
                            break;
                        }
                    }
                }
                
                // Diagonal
                counter = 1;
                for (int k = -3; k <= 3; k++) {
                    
                    if (k == 0) {
                        counter = 1;
                        continue;
                    }

                    if (i + k < Y && j + k < X && i + k >= 0 && j + k >= 0) {
                        if (gameBoard[i + k][j + k] == player) {
                            counter++;

                            if (counter == 4) {
                                return player;
                            }
                        } else {
                            break;
                        }
                    }
                }

                counter = 1;
                for (int k = -3; k <= 3; k++) {
                    
                    if (k == 0) {
                        counter = 1;
                        continue;
                    }

                    if (i - k < Y && j + k < X && i - k >= 0 && j + k >= 0) {
                        if (gameBoard[i - k][j + k] == player) {
                            counter++;

                            if (counter == 4) {
                                return player;
                            }
                        } else {
                            break;
                        }
                    }
                }

                counter = 1;
                for (int k = -3; k <= 3; k++) {
                    
                    if (k == 0) {
                        counter = 1;
                        continue;
                    }

                    if (i + k < Y && j - k < X && i - k >= 0 && j + k >= 0) {
                        if (gameBoard[i + k][j - k] == player) {
                            counter++;

                            if (counter == 4) {
                                return player;
                            }
                        } else {
                            break;
                        }
                    }
                }
            }
        }
    }

    // Undecided
    return 0;

}

int main (int argc, char *argv[]){
    
    getMoves();

    int winner = computeVictory();

    if (winner == 1) {
        printf("YELLOW\n");
    } else if (winner == 2) {
        printf("RED\n");
    } else {
        printf("UNDECIDED\n");
    }

	return 0;
}