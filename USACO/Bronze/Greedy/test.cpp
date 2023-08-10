#include <iostream>
#include <iterator>
#include <vector>

int main(int argc, char** argv) {
    std::vector<int> dest{1, 2, 3, 4, 5};
    std::vector<int> src{6, 7, 8, 9, 10};

    // Move elements from src to dest.
    // src is left in undefined but safe-to-destruct state.
    dest.insert(dest.end(), std::make_move_iterator(src.begin()),
                std::make_move_iterator(src.end()));

    // Print out concatenated vector.
    std::copy(dest.begin(), dest.end(), std::ostream_iterator<int>(std::cout, "\n"));

    return 0;
}