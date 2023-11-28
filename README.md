# IntervalMap

IntervalMap is a C++ implementation of an interval map data structure. It allows you to associate values with intervals and perform efficient lookups based on a key within those intervals.

## Building the Project

To build the project, you can use the provided Makefile. The project uses CMake for building and Catch2 for testing. Make sure you have CMake installed on your system.

### Build Instructions

```bash
make
```
This will create a build directory, generate the build files using CMake, and build the IntervalMap executable.

### Running Tests
```bash
make test
```
This command builds and runs the tests using the Catch2 framework.

### Cleaning up
```bash
make clean
```
This command cleans up the build directory and removes any generated files.

## Usage

The main component of this project is the interval_map class defined in `interval_map.hpp`. You can include this header file in your project and use the `interval_map` class to create and manipulate interval maps.

### Example
```cpp
#include "interval_map.hpp"

int main() {
    // Example usage of the interval_map class
    interval_map<int, std::string> myIntervalMap("default_value");

    // Assigning a value to the interval [1, 5)
    myIntervalMap.assign(1, 5, "assigned_value");

    // Accessing the value at key 3
    std::cout << "Value at key 3: " << myIntervalMap[3] << std::endl;

    return 0;
}
```

## Time Complexity

The assign operation in the interval_map class has a time complexity of $O(\log N + M)$, where $N$ is the number of intervals in the map, and $M$ is the number of intervals affected by the assignment. The complexity is influenced by both the search and the removal of intervals within the map.

## Space Complexity

The space complexity of the `interval_map` class is primarily determined by the size of the underlying `std::map` (`m_map`). Assuming the number of intervals is $N$, the space complexity is $O(N)$. Each interval is represented as a key-value pair in the map.

Additionally, the `m_valBegin` variable, which stores the value associated with intervals that extend to negative infinity, contributes to the overall space complexity. However, its impact is constant, so it does not change the asymptotic space complexity.

In summary, the space complexity of the `interval_map` class is $O(N)$, where N is the number of intervals in the map.
