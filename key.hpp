#ifndef KEY_HPP
#define KEY_HPP

#include <iostream>

class Key {
public:
    Key() = default;
    
    Key(int value) : value(value) { }

    Key(const Key& other) = default;

    Key& operator=(const Key& other) = default;

    bool operator<(const Key& other) const {
        return value < other.value;
    }

    // for printing purposes.
    friend std::ostream& operator<<(std::ostream& os, const Key& k) {
        os << k.value;
        return os;
    };

private:
    int value;
};

#endif // KEY_HPP
