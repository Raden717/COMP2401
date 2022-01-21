#include <stdio.h>
#include <X11/Xlib.h>
#include <stdlib.h>

#include "graphSet.h"
#include "mazeDisplay.h"




// Compute the graph for the given maze and add it to the given graph set.



Graph *computeGraph(char maze[HEIGHT][WIDTH]) {



  // Create the initially-empty graph
  Graph *graph;
  graph = malloc(sizeof(Graph));
  graph->rootNode = malloc(sizeof(Node));
  int checkLoop = 0;
  // Find a graph->rootNode node, then trace out the maze recursively.  A graph->rootNode node can be
  // found by searching from top to bottom, left to right, for a non-wall maze location.
  // You MUST NOT hard-code this start location ... it must be determined by your code.
  for(int i = 1; i < 20;i++){
    for(int n = 1; n < 20;n++){

      if(maze[i][n] == '0'){
        graph->rootNode->x = n;
        graph->rootNode->y = i;
        checkLoop = 1;
        maze[i][n] = '2';
        break;
      }
    }
    if(checkLoop == 1)
      break;
  }

  void recurse(char maze[HEIGHT][WIDTH], int x, int y, Node *CurrentNode, Node *previous){

    if(previous == NULL){
      CurrentNode->up = NULL;
      CurrentNode->down = NULL;
      CurrentNode->left = NULL;
      CurrentNode->right = NULL;
    //  CurrentNode = malloc(sizeof(Node));
      //Check Up
      if(x-1 >= 1 && x-1 <= 19)
        if(maze[x-1][y] == '0'){
          CurrentNode->up = (Node*)malloc(sizeof(Node));
          CurrentNode->up->up = NULL;
          CurrentNode->up->left = NULL;
          CurrentNode->up->right = NULL;
          CurrentNode->up->down = NULL;
          CurrentNode->up->y = CurrentNode->y-1;
          CurrentNode->up->x = CurrentNode->x;
          maze[x-1][y] = '2';
          recurse(maze,x-1,y,CurrentNode->up,CurrentNode);
        //  free(CurrentNode->up);
      } else {
        CurrentNode->up = NULL;
      }
      //Check Right
      if(y+1 <= 19 && y+1 >= 1)
        if(maze[x][y+1] == '0'){
          CurrentNode->right = (Node*)malloc(sizeof(Node));
          CurrentNode->right->up = NULL;
          CurrentNode->right->left = NULL;
          CurrentNode->right->right = NULL;
          CurrentNode->right->down = NULL;
          CurrentNode->right->y = CurrentNode->y;
          CurrentNode->right->x = CurrentNode->x+1;
          maze[x][y+1] = '2';
          recurse(maze,x,y+1,CurrentNode->right,CurrentNode);
      //    free(CurrentNode->right);
        }else {
          CurrentNode->right = NULL;
        }
      //Check Down
      if(x+1 <= 19 && x+1 >= 1)
        if(maze[x+1][y] == '0'){
          CurrentNode->down = (Node*)malloc(sizeof(Node));
          CurrentNode->down->up = NULL;
          CurrentNode->down->left = NULL;
          CurrentNode->down->right = NULL;
          CurrentNode->down->down = NULL;
          CurrentNode->down->y = CurrentNode->y+1;
          CurrentNode->down->x = CurrentNode->x;
          maze[x+1][y] = '2';
          recurse(maze,x+1,y,CurrentNode->down,CurrentNode);
        //  free(CurrentNode->down);
        } else {
          CurrentNode->down = NULL;
        }
      //Check Left
      if(y-1 >= 1 && y-1 <= 19)
        if(maze[x][y-1] == '0'){
          CurrentNode->left = (Node*)malloc(sizeof(Node));
          CurrentNode->left->up = NULL;
          CurrentNode->left->left = NULL;
          CurrentNode->left->right = NULL;
          CurrentNode->left->down = NULL;
          CurrentNode->left->y = CurrentNode->y;
          CurrentNode->left->x = CurrentNode->x-1;
          maze[x][y-1] = '2';
          recurse(maze,x,y-1,CurrentNode->left,CurrentNode);
      //    free(CurrentNode->left);
        } else {
          CurrentNode->left = NULL;
        }
    } else {

      //Check Up
      if(x-1 >= 1 && x-1 <= 19){
        if(maze[x-1][y] == '0'){
          CurrentNode->up = (Node*)malloc(sizeof(Node));
          CurrentNode->up->up = NULL;
          CurrentNode->up->left = NULL;
          CurrentNode->up->right = NULL;
          CurrentNode->up->down = NULL;
          CurrentNode->up->y = CurrentNode->y-1;
          CurrentNode->up->x = CurrentNode->x;
          maze[x-1][y] = '2';
          recurse(maze,x-1,y,CurrentNode->up,CurrentNode);
        } else {
          CurrentNode->up = NULL;
        }
      }
      //Check Right
      if(y+1 <= 19 && y+1 >= 1){
        if(maze[x][y+1] == '0'){
          CurrentNode->right = (Node*)malloc(sizeof(Node));
          CurrentNode->right->up = NULL;
          CurrentNode->right->left = NULL;
          CurrentNode->right->right = NULL;
          CurrentNode->right->down = NULL;
          CurrentNode->right->y = CurrentNode->y;
          CurrentNode->right->x = CurrentNode->x+1;
          maze[x][y+1] = '2';
          recurse(maze,x,y+1,CurrentNode->right,CurrentNode);
        } else {
          CurrentNode->right = NULL;
        }
      }
      //Check Down
      if(x+1 <= 19 && x+1 >= 1){
        if(maze[x+1][y] == '0'){
          CurrentNode->down = (Node*)malloc(sizeof(Node));
          CurrentNode->down->up = NULL;
          CurrentNode->down->left = NULL;
          CurrentNode->down->right = NULL;
          CurrentNode->down->down = NULL;
          CurrentNode->down->y = CurrentNode->y+1;
          CurrentNode->down->x = CurrentNode->x;
          maze[x+1][y] = '2';
          recurse(maze,x+1,y,CurrentNode->down,CurrentNode);
        } else {
          CurrentNode->down = NULL;
        }
      }
      //Check Left
      if(y-1 >= 1 && y-1 <= 19){
        if(maze[x][y-1] == '0'){
          CurrentNode->left = (Node*)malloc(sizeof(Node));
          CurrentNode->left->up = NULL;
          CurrentNode->left->left = NULL;
          CurrentNode->left->right = NULL;
          CurrentNode->left->down = NULL;
          CurrentNode->left->y = CurrentNode->y;
          CurrentNode->left->x = CurrentNode->x-1;
          maze[x][y-1] = '2';
          recurse(maze,x,y-1,CurrentNode->left,CurrentNode);
        } else {
          CurrentNode->left = NULL;
        }
      }
    }
  }


  recurse(maze,graph->rootNode->y,graph->rootNode->x,graph->rootNode,NULL);

  // To trace out the maze recursively, you will likely want to create a recursive
  // procedure that is called by this one.   It should take parameters to indicate
  // the location in the maze to start tracing from, the maze itself and also the node
  // that led to this node (i.e., the previous one in the tree that led here).  If you
  // start with the root node, then the previous node should be NULL.
  //
  // As you go through the maze, make sure to mark off maze locations that you have
  // visited (perhaps by putting a '2' character at that location) so that you do not
  // go back to that location again and end up with infinite recursion.  So you can
  // stop the recursion when you reach a wall (i.e., a '0' character in the maze) or a
  // '2' character.  A '1' character means that it is a free space that you just arrived
  // at for the first time.   Make sure to check recursively in all directions.  In my
  // solutions (shown on the assignment), I used an ordering of up/down/left/right.  So
  // if you want solutions to look like mine, you should follow that ordering as well.
  //
  // As you traverse the maze, make sure to connect the previous node to the current one.
  // You'll have to check which direction you can from (i.e., x and y values) so that
  // you know whether it is the up/down/left or right pointer to set.

  // You need not do this recursively, but it will lkely be a lot harder to do it non-
  // recursively.
  //free(graph->rootNode);
  return graph; // Remove this line when you write your code
}



// This procedure must clean up graph by removing all nodes in which the previous and
// next nodes have the same x or y value as it.
void cleanUpGraph(Node *n, Node *previousNode) {
  if(previousNode == NULL){
    if(n->up != NULL)
      cleanUpGraph(n->up,n);
    if(n->right != NULL)
      cleanUpGraph(n->right,n);
    if(n->down != NULL)
      cleanUpGraph(n->down,n);
    if(n->left != NULL)
      cleanUpGraph(n->left,n);

    } else {

      int outcount = 0;

      if(n->up != NULL){
        outcount++;
      }
      if(n->right != NULL){
        outcount++;
      }
      if(n->down != NULL){
        outcount++;
      }
      if(n->left != NULL){
        outcount++;
      }

      //Figuring out which is the out connection if its only 1
      if(outcount == 1){
        int outcount2 = 0;
        if(n->y < previousNode->y && n->up != NULL){
          outcount2++;
          previousNode->up = n->up;
          free(n);
          cleanUpGraph(previousNode->up,previousNode);
        }
        else if(n->x > previousNode->x && n->right != NULL){
          outcount2++;
          previousNode->right = n->right;
          free(n);
          cleanUpGraph(previousNode->right,previousNode);
        }
        else if(n->y > previousNode->y && n->down != NULL){
          outcount2++;
          previousNode->down = n->down;
          free(n);
          cleanUpGraph(previousNode->down,previousNode);
        }
        else if(n->x < previousNode->x && n->left != NULL){
          outcount2++;
          previousNode->left = n->left;
          free(n);
          cleanUpGraph(previousNode->left,previousNode);
        }


        if(outcount2 == 0){
          if(n->up != NULL){
            cleanUpGraph(n->up,n);
          }
          if(n->right != NULL){
            cleanUpGraph(n->right,n);
          }
          if(n->down != NULL){
            cleanUpGraph(n->down,n);
          }
          if(n->left != NULL){
            cleanUpGraph(n->left,n);
          }
        }

      } else {

        if(n->up != NULL){
          cleanUpGraph(n->up,n);
        }
        if(n->right != NULL){
          cleanUpGraph(n->right,n);
        }
        if(n->down != NULL){
          cleanUpGraph(n->down,n);
        }
        if(n->left != NULL){
          cleanUpGraph(n->left,n);
        }
      }
  }
}








// This is where it all begins
int main() {
  char mazes[5][HEIGHT][WIDTH] = {
    {"111111111111111111111",
     "100000001000100000001",
     "101111111010111011111",
     "100000000010000010001",
     "101110111111101110111",
     "100010001000000000001",
     "111011111111111110111",
     "101010001000100000001",
     "101110111011101011101",
     "100010000000001010001",
     "101010111011111111111",
     "101000001000100000001",
     "101111111110101111101",
     "100010100000100000101",
     "111110101110101111101",
     "100010001000000010101",
     "101010111111111010111",
     "101010001000000010001",
     "101111111010111011101",
     "100000000010001000001",
     "111111111111111111111"},

    {"111111111111111111111",
     "100000000000000000001",
     "101111111111111111111",
     "100000000000000000001",
     "101111111111111111111",
     "100000000000000000001",
     "111111111111111111101",
     "100000000000000000001",
     "101111111111111111111",
     "100000000000000000001",
     "111111111111111111101",
     "100000000000000000001",
     "101111111111111111111",
     "101111111111111111101",
     "101111111111111111101",
     "101000100010001000101",
     "101010101010101010101",
     "101010101010101010101",
     "101010101010101010101",
     "100010001000100010001",
     "111111111111111111111"},

    {"111111111111111111111",
     "100000000000000000001",
     "101010101010101010101",
     "100000000000000000001",
     "101110111011101110111",
     "100000000000000000001",
     "101111101111101111101",
     "100000000000000000001",
     "101111111001111111101",
     "100000000000000000001",
     "101111111111111111101",
     "100111111111111111001",
     "100011111111111110001",
     "100001111111111100001",
     "100000111111111000001",
     "100000011111110000001",
     "100000001111100000001",
     "100000000111000000001",
     "100000000010000000001",
     "100000000000000000001",
     "111111111111111111111"},

    {"111111111111111111111",
     "111111111111111111111",
     "111111111111111111111",
     "111111111111111111111",
     "111111111111111111111",
     "111111111111111111111",
     "111111111111111111111",
     "111111111111111111111",
     "111111111111111111111",
     "111111111111111111111",
     "111111111110111111111",
     "111111111111111111111",
     "111111111111111111111",
     "111111111111111111111",
     "111111111111111111111",
     "111111111111111111111",
     "111111111111111111111",
     "111111111111111111111",
     "111111111111111111111",
     "111111111111111111111",
     "111111111111111111111"},

    {"111111111111111111111",
     "111100000000000000001",
     "111000000000000000001",
     "100000000000000000001",
     "100000000000000000001",
     "100000000000000000001",
     "100000000000000000001",
     "100000000000000000001",
     "100000000000000000001",
     "100000000000000000001",
     "100000000000000000001",
     "100000000000000000001",
     "100000000000000000001",
     "100000000000000000001",
     "100000000000000000001",
     "100000000000000000001",
     "100000000000000000001",
     "100000000000000000001",
     "100000000000000000001",
     "100000000000000000001",
     "111111111111111111111"}};

  // Open a display window
  openDisplayWindow();



  // Allocate a GraphSet to store the graphs for each maze
  GraphSet *gSet;
  gSet = malloc(sizeof(GraphSet));
  // Compute the graphs for each maze and add them to a Graph Set
  for (int i=0; i<5; i++) {
    Graph *g = computeGraph(mazes[i]);
    if(i == 0){
      gSet->firstGraph = g;
      gSet->lastGraph = g;
    } else {
    gSet->lastGraph->nextGraph = g;
    gSet->lastGraph = g;
    }

    //free(g->rootNode);S
    // Add g to gSet properly
    // ...
  }

  // Show the graphs
  Graph *g = gSet->firstGraph; // ... set this to the first graph in gSet ...
  //free(gSet);
  for (int i=0; i<5; i++) {
    drawMaze(mazes[i]);  // Draw the maze
    drawGraph(g->rootNode);    // Draw the graph

    getchar();  // Wait for user to press enter

    cleanUpGraph(g->rootNode, NULL);   // Clean up the graph
    drawMaze(mazes[i]);
    drawGraph(g->rootNode);

    // ... get the next graph in the set ...

    if(i < 4){
      g = g->nextGraph;
    } else {
      g = gSet->firstGraph;
    }
    // ... INSERT A LINE OF CODE HERE ...

    getchar();  // Wait again for the user to press ENTER before going on to the next maze
  }

  void recurse2(Node *n){
    if(n->up != NULL){
      recurse2(n->up);
    }
    if(n->right != NULL){
      recurse2(n->right);
    }
    if(n->down != NULL){
      recurse2(n->down);
    }
    if(n->left != NULL){
      recurse2(n->left);
    }
    free(n);
  }
  for(int i = 0; i < 5; i++){
    recurse2(g->rootNode);
    if(i < 4){
      g = g->nextGraph;
    } else {
      g = gSet->firstGraph;
    }
  }
  for(int i = 0; i < 5; i++){
    if(i < 4)
      gSet->firstGraph = g->nextGraph;
    free(g);
    g = gSet->firstGraph;
  }

  free(gSet);
  //  free(gSet);
    // Close the display window
  closeDisplayWindow();
}
