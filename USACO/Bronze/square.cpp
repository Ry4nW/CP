#include <iostream>
#include <array>
#include <vector>

using namespace std;
int largest ( const array<int, 4> arr )  
{  
    int i ;   
    // Initialize maximum element  
    int max = arr [ 0 ] ;   
    // Traverse array elements  
    // from second and compare  
    // every element with current max  
    for ( i = 1 ; i < arr.size(); i++ ) {
        if ( arr [ i ] > max )  
            max = arr [ i ] ;  
    }
    return max ;  
}  

int smallest ( const array<int, 4> arr )  
{  
    int i ;   
    // Initialize maximum element  
    int max = INT64_MAX ;   
    // Traverse array elements  
    // from second and compare  
    // every element with current max  
    for ( i = 1 ; i < arr.size(); i++ ) {
        if ( arr [ i ] < max )  
            max = arr [ i ] ;  
    }
    return max ;  
}  

int main() {
    int x1, y1, x2, y2;
    int a1, b1, a2, b2;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> a1 >> b1 >> a2 >> b2;
    array<int, 4> xVals { x1, a1, x2, a2 };
    array<int, 4> yVals { y1, b1, y2, b2 };
    int maxLen = max(abs(largest(yVals) - smallest(yVals)), abs(biggest(xVals) -smaller(xVals)));
    
    cout <<  << '\n';
    return 0;
}



