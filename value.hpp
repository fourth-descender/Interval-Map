#ifndef VALUE_HPP
#define VALUE_HPP

#include <iostream>

class Value {
public:
    Value() = default;
    
    Value(int value) : value(value) { }

    Value(const Value& other) = default;

    Value& operator=(const Value& other) = default;

    bool operator==(const Value& other) const {
        return value == other.value;
    }

    // For printing purposes.
    friend std::ostream& operator<<(std::ostream& os, const Value& v) {
        os << v.value;
        return os;
    };

private:
    int value;
};

#endif // VALUE_HPP
