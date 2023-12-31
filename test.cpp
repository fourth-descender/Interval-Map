#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include "interval_map.hpp"
#include "key.hpp"
#include "value.hpp"

// Test basic functionality of interval_map
TEST_CASE("Interval Map Tests", "[interval_map]") {
    SECTION("Default Constructor") {
        interval_map<int, std::string> myMap("default");

        REQUIRE(myMap[5] == "default");
        REQUIRE(myMap[10] == "default");
    }

    SECTION("Assign Functionality") {
        interval_map<int, std::string> myMap("default");

        myMap.assign(0, 5, "A");
        myMap.assign(5, 10, "B");
        myMap.assign(10, 15, "C");

        REQUIRE(myMap[-1] == "default");
        REQUIRE(myMap[2] == "A");
        REQUIRE(myMap[7] == "B");
        REQUIRE(myMap[12] == "C");
        REQUIRE(myMap[17] == "default");
    }

    SECTION("Overlapping Intervals") {
        interval_map<int, std::string> myMap("default");

        myMap.assign(0, 5, "A");
        myMap.assign(3, 8, "B");

        REQUIRE(myMap[-1] == "default");
        REQUIRE(myMap[0] == "A");
        REQUIRE(myMap[1] == "A");
        REQUIRE(myMap[3] == "B");
        REQUIRE(myMap[5] == "B");
        REQUIRE(myMap[8] == "default");
        REQUIRE(myMap[9] == "default");
    }

    SECTION("Canonicity") {
        interval_map<int, std::string> myMap("default");

        myMap.assign(0, 5, "A");
        myMap.assign(0, 2, "default");
        myMap.assign(5, 12, "B");
        myMap.assign(2, 9, "B");
        myMap.assign(5, 12, "B");
        myMap.assign(7, 9, "default");
        myMap.assign(9, 12, "default");
        myMap.assign(2, 9, "default");

        // Expected result:
        interval_map<int, std::string> otherMap("default");

        REQUIRE(myMap == otherMap);
    }

    SECTION("Custom Key and Value Types") {
        interval_map<Key, Value> myMap(Value(0));

        myMap.assign(Key(0), Key(5), Value(1));
        myMap.assign(Key(5), Key(10), Value(2));
        myMap.assign(Key(10), Key(15), Value(3));

        REQUIRE(myMap[Key(-1)] == Value(0));
        REQUIRE(myMap[Key(2)] == Value(1));
        REQUIRE(myMap[Key(7)] == Value(2));
        REQUIRE(myMap[Key(12)] == Value(3));
        REQUIRE(myMap[Key(17)] == Value(0));
    }
}
