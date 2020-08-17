//William Ayers

#define BOARD_WIDTH	50
#define BOARD_HEIGHT 50
#define STARTING_CELLS 200

void init_board (int[][BOARD_HEIGHT]);

int xadd (int, int);

int yadd (int, int);

int num_neighbors (int[][BOARD_HEIGHT], int, int);

void next_generation(int[][BOARD_HEIGHT], int[][BOARD_HEIGHT]);

void next_state (int[][BOARD_HEIGHT]);

void print (int[][BOARD_HEIGHT]);
