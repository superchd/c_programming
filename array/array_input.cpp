#include <iostream>
#include <array>

using namespace std ;

array< array<int, 5>, 5> stlarray ;

void show_array(  array< array<int, 5>, 5> Q ){ // self-explanatory
    int i,j,k ;
    i = j = 0 ;
    for( auto U : Q ){
        for( auto v : U ) {
            printf("\n i,j=%2d,%2d, val=%3d", i, j, v) ;
            j++ ;
        }
        i++; j=0 ;
    }
} // end of showit( )

void set_array( array< array<int, 5>, 5> &Q ){
    int i;
    for( auto &U : Q ){
        for( auto &v : U ) {
            cin >> i; 
        }
    }
} // end of showit( )

int main() {

    set_array ( stlarray ) ;
    show_array( stlarray ) ;

}
