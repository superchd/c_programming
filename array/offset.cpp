#include <iostream>
#include <array>
#include <stdbool.h>

using namespace std ;

array< array<int, 7>, 7> arr;

bool standard( array< array<int, 7>, 7> Q, int i, int j){
  
	if(Q[i][j] < Q[i-1][j] && Q[i][j] < Q[i+1][j] && Q[i][j] < Q[i][j-1] && Q[i][j] < Q[i][j+1])
	      return true;
	else {return false;}
}

void show_array( array< array<int, 7>, 7> Q ){
  
    for(int i=0; i<=6; i++) {
      for(int j=0; j<=6; j++) {
        printf("%d ", Q[i][j]);
      }
      printf("\n");
  }
} // end of showit( )

void set_array( array< array<int, 7>, 7> &Q ){
  
    for(int i=1; i<=5; i++) {
    for(int j=1; j<=5; j++) {
      scanf("%d", &Q[i][j]);
    }
  }
  for(int j=0; j<=6; j++) {
      Q[0][j] = 10;
    }
  for(int j=0; j<=6; j++) {
      Q[6][j] = 10;
    }
  for(int j=0; j<=6; j++) {
      Q[j][0] = 10;
    }
  for(int j=0; j<=6; j++) {
      Q[j][6] = 10;
    }
} // end of setit( )

void my_sol( array< array<int, 7>, 7> &Q ){
  
    for(int i=1; i<=5; i++) {
      for(int j=1; j<=5; j++) {
        if(standard(Q, i, j)) { cout << "* "; }
        else                   { cout << Q[i][j] << " " ;}
      }
      cout << "\n";
    }
} // end of setit( )

int main() {
    
    set_array (arr) ;
    my_sol    (arr) ;
    //show_array(arr) ;
    return 0;
}
