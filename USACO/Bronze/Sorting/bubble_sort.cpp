#include <vector>
#include <iostream>
using namespace std;

void countSwaps(vector<int> a) {
    int swaps = 0;
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - 1; ++j ) {
            if (a[j] > a[j + 1]) {
                int temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
                swaps++;
            }
        }
    }
    cout << "Array is sorted in " << swaps << " swaps.\n" 
    << "First Element: " << a[0] << '\n' << "Last Element: "<< a[n - 1] << '\n';
}


int main() {
    return 0;
}
