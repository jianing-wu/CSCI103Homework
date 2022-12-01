/* 
maze.cpp

Author:

Short description of this file:
*/

#include <iostream>
#include "mazeio.h"
#include "queue.h"
using namespace std;


// Directions that help to find neighbors of current cell
// Up, down, left, right
const int DIRECTIONS[][2] = {{-1,0},{1,0},{0,-1},{0,1}}; 
// Number of possible directions
const int NUMDIR = 4;

// Prototype for maze_search, which you will fill in below.
int maze_search(char**, int, int);

bool maze_check(char**, int, int, Location&, Location&);


// main function to read, solve maze, and print result
int main(int argc, char* argv[]) {
   int rows, cols, result;
   char** mymaze=NULL;
   
   if(argc < 2)
   {
       cout << "Please provide a maze input file" << endl;
       return 1;
   }
   mymaze = read_maze(argv[1], &rows, &cols); // FILL THIS IN
   
   if (mymaze == NULL) {
      cout << "Error, input format incorrect" << endl;
      return 1;
   }

   // when working on Checkpoint 3, you will call maze_search here.
   // here. but for Checkpoint 1, just assume we found the path.
//    result = 1; // TO BE CHANGED
   result = maze_search(mymaze, rows, cols);

   // examine value returned by maze_search and print appropriate output
   if (result == 1) { // path found!
      print_maze(mymaze, rows, cols);
   }
   else if (result == 0) { // no path :(
      cout << "No path could be found!" << endl;
   }
   else { // result == -1
      cout << "Invalid maze." << endl;
   }

   // ADD CODE HERE to delete all memory 
   // that read_maze allocated
  for (int i = 0; i < rows; i++) {
    delete[] mymaze[i];
  }
  delete[] mymaze;

   return 0;
}

/**************************************************
 * Attempt to find shortest path and return:
 *  1 if successful
 *  0 if no path exists
 * -1 if invalid maze (not exactly one S and one F)
 *
 * If path is found fill it in with '*' characters
 *  but don't overwrite the 'S' and 'F' cells
 *************************************************/
int maze_search(char** maze, int rows, int cols) 
{
  Location S;
  Location F;
  if (!maze_check(maze, rows, cols, S, F)) {
    return -1;
  }
  bool** visited = new bool*[rows];
  for (int i = 0; i < rows; i++) {
    visited[i] = new bool[cols];
    for (int j = 0; j < cols; j++) {
      visited[i][j] = false;
    } 
  }
  
  Location** predecessors = new Location*[rows];
  for (int i = 0; i < rows; i++) {
    predecessors[i] = new Location[cols];
  }
  
  Queue q(rows*cols);
  q.add_to_back(S);
  visited[S.row][S.col] = true;
  bool isPathFound = false;
  while (!q.is_empty()) {
    Location cur = q.remove_from_front();
//     cout << "row: " << cur.row << ", col: " <<cur.col <<endl;
    if (maze[cur.row][cur.col] == 'F') {
      isPathFound = true;
      break;
    }
    for (int i = 0; i < NUMDIR; i++) {
      int neiRow = cur.row + DIRECTIONS[i][0];
      int neiCol = cur.col + DIRECTIONS[i][1];
      if (neiRow < 0 || neiRow >= rows 
          || neiCol < 0 || neiCol >= cols
          || maze[neiRow][neiCol] == '#'
          || visited[neiRow][neiCol]) {
        continue;
      }
      Location neighbor;
      neighbor.row = neiRow;
      neighbor.col = neiCol;
      q.add_to_back(neighbor);
      visited[neiRow][neiCol] = true;
      predecessors[neiRow][neiCol] = cur;
    }
  }
  for (int i = 0 ; i < rows; i ++) {
    delete [] visited[i];
  }
  delete [] visited;
  if (!isPathFound) {   
    for (int i = 0 ; i < rows; i ++) {
      delete [] predecessors[i];
    }
    delete [] predecessors;
    return 0;
  }
  
  Location cur = F;
  while (maze[cur.row][cur.col] != 'S') {
    if (maze[cur.row][cur.col] != 'F') {
      maze[cur.row][cur.col] = '*';
    }
    cur = predecessors[cur.row][cur.col];
  }
  
  for (int i = 0 ; i < rows; i ++) {
     delete [] predecessors[i];
  }
  delete [] predecessors;
   return 1; // DELETE this stub, it's just for Checkpoint 1 to compile.
}


bool maze_check(char** maze, int rows, 
                int cols, Location& S, 
                Location& F) {
  Location STemp;
  Location FTemp;
  STemp.row = -1;
  STemp.col = -1;
  FTemp.row = -1;
  FTemp.col = -1;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (maze[i][j] == 'S') {
        if (STemp.row != -1) {
          return false;
        }
        STemp.row = i;
        STemp.col = j;
      }
      
      if (maze[i][j] == 'F') {
        if (FTemp.row != -1) {
          return false;
        }
        FTemp.row = i;
        FTemp.col = j;
      }
    }
  }
  if (STemp.row == -1 || FTemp.row == -1) {
    return false;
  }
  S.row = STemp.row;
  S.col = STemp.col;
  F.row = FTemp.row;
  F.col = FTemp.col;
  return true;
}
