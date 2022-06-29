#include <iostream>
#include <array>
#include <stdbool.h>

using namespace std ;

array< array<int, 11>, 11> arr;
int row,col;
int my_max = 0;



void show_array( array< array<int, 11>, 11> Q ){
  
    for(int i = 1; i <= 9; i++) {
      for(int j = 1; j <= 9; j++) {
        printf("%d ", Q[i][j]);
      }
      printf("\n");
  }
} // end of showit( )

void set_array( array< array<int, 11>, 11> &Q ){
  
    for(int i=1; i<=9; i++) {
    	for(int j=1; j<=9; j++) {
      		scanf("%d", &Q[i][j]);
    }
  }
  for(int j=0; j<=10; j++) {
      Q[0][j] = 0;
    }
  for(int j=0; j<=10; j++) {
      Q[10][j] = 0;
    }
  for(int j=0; j<=10; j++) {
      Q[j][0] = 0;
    }
  for(int j=0; j<=10; j++) {
      Q[j][10] = 0;
    }
} // end of setit( )

void my_sol( array< array<int, 11>, 11> Q ){
  

    for(int i=1; i<=9; i++) {
      for(int j=1; j<=9; j++) {
        if(my_max < Q[i][j]) { my_max = Q[i][j],row = i, col = j; }
      }
    }
} // end of setit( )

int main() {
    
    set_array (arr) ;
    my_sol    (arr) ;
    cout << my_max << "\n" << row << " " << col ;
    //show_array(arr) ;
    return 0;
}
