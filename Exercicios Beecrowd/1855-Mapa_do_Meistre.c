#include <stdio.h>

int isArrow(char c) {
  return c == '>' || c == 'v' || c == '<' || c == '^';
}

int setDirection(char c) {
  if (c == '>') return 1;
  if (c == 'v') return 2;
  if (c == '<') return 3;
  
  return 4;
}

int setX(int x, int d) {
  if (d == 2) return ++x;
  if (d == 4) return --x;

  return x;
}

int setY(int y, int d) {
  if (d == 1) return ++y;
  if (d == 3) return --y;
  
  return y;
}

int main() {
  int x, y;

  scanf("%d %d", &x, &y);
  getchar();

  char map[x][y];
  int walk[x][y];

  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      walk[i][j] = 0;
    }
  }

  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      scanf("%c", &map[i][j]);
    }
    getchar();
  }

  int i = 0, j = 0, direction, win = 0;
  while (walk[i][j] == 0 && !win) {
    char c = map[i][j];

    if (isArrow(c)) {
      walk[i][j] = 1;
      direction = setDirection(c);
    }

    if (c == '*') {
        win = 1;
        break;
    }

    int aux_i = setX(i, direction);
    int aux_j = setY(j, direction);

    if (aux_i == x || aux_i < 0 || aux_j == y || aux_j < 0) break;
    
    i = aux_i;
    j = aux_j;
  }

  if (win){
    printf("*\n");
  }else{
    printf("!\n");
  } 
}