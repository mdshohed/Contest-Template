#include <stdio.h>
#include <stdlib.h>

#define MAX_TURTLES 3

// Define the directions
typedef enum {RIGHT, DOWN, LEFT, UP} Direction;

// Structure for each turtle's state
typedef struct {
    int row, col;
    Direction direction;
} Turtle;


// Function prototypes
void initializeCanvas(char **canvas, int rows, int cols);
void turnRight(Turtle *turtle);
void turnLeft(Turtle *turtle);
void move(Turtle *turtle, int rows, int cols);
void togglePixel(Turtle *turtle, char **canvas);
void printCanvas(char **canvas, int rows, int cols);

int main() { 
    int rows, cols;
    char command;

    // Read the canvas dimensions
    scanf("%d %d", &rows, &cols);

    // Allocate memory for the canvas
    char **canvas = (char **)malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++) {
        canvas[i] = (char *)malloc(cols * sizeof(char));
    }
    initializeCanvas(canvas, rows, cols);

    // Initialize the first turtle
    Turtle turtles[MAX_TURTLES];
    int turtleCount = 1;
    turtles[0].row = 0;
    turtles[0].col = 0;
    turtles[0].direction = RIGHT;

    // Process each command from input
    while (scanf(" %c", &command) == 1) {
        switch (command) {
            case 'r':
                for (int i = 0; i < turtleCount; i++) {
                    turnRight(&turtles[i]);
                }
                break;
            case 'l':
                for (int i = 0; i < turtleCount; i++) {
                    turnLeft(&turtles[i]);
                }
                break;
            case 'm':
                for (int i = 0; i < turtleCount; i++) {
                    move(&turtles[i], rows, cols);
                }
                break;
            case 'o':
                for (int i = 0; i < turtleCount; i++) {
                    togglePixel(&turtles[i], canvas);
                }
                break;
            case 'f':
                if (turtleCount < MAX_TURTLES) {
                    turtles[turtleCount].row = 0;
                    turtles[turtleCount].col = 0;
                    turtles[turtleCount].direction = RIGHT;
                    turtleCount++;
                }
                break;
            case 'x':
                printCanvas(canvas, rows, cols);
                break; 
        }
    }

    // Free allocated memory for the canvas
    for (int i = 0; i < rows; i++) {
        free(canvas[i]);
    }
    free(canvas);
    return 0;
}

// Initialize the canvas with dots
void initializeCanvas(char **canvas, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            canvas[i][j] = '.';
        }
    }
}

// Turn the turtle right
void turnRight(Turtle *turtle) {
    turtle->direction = (Direction)((turtle->direction + 1) % 4);
}

// Turn the turtle left
void turnLeft(Turtle *turtle) {
    turtle->direction = (Direction)((turtle->direction + 3) % 4);
}

// Move the turtle in the current direction, with wrap-around
void move(Turtle *turtle, int rows, int cols) {
    switch (turtle->direction) {
        case RIGHT:
            turtle->col = (turtle->col + 1) % cols;
            break;
        case DOWN:
            turtle->row = (turtle->row + 1) % rows;
            break;
        case LEFT:
            turtle->col = (turtle->col - 1 + cols) % cols;
            break;
        case UP:
            turtle->row = (turtle->row - 1 + rows) % rows;
            break;
    }
}

// Toggle a pixel on or off at the turtle's position
void togglePixel(Turtle *turtle, char **canvas) {
    if (canvas[turtle->row][turtle->col] == '.') {
        canvas[turtle->row][turtle->col] = 'o';
    } else {
        canvas[turtle->row][turtle->col] = '.';
    }
}

// Print the canvas
void printCanvas(char **canvas, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            putchar(canvas[i][j]);
        }
        putchar('\n');
    }
}
