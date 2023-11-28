#ifndef INTERVAL_MAP_HPP
#define INTERVAL_MAP_HPP

#include <map>
#include <iostream>
#include "key.hpp"
#include "value.hpp"

template<typename K, typename V>

class interval_map {
    private:
        std::map<K, V> m_map;
        V m_valBegin;
    public:
        interval_map(V const& val)
            : m_valBegin(val)
            {};

        // look-up value at key.
        V const& operator[](K const& key) const {
            auto it = m_map.upper_bound(key);
            return (it == m_map.begin()) ? m_valBegin : (--it)->second;
        };

        // gets the value left of key.
        V const& lSearch(K const& key) const {
            auto it = m_map.upper_bound(key);

            if (it == m_map.begin()) {
                return m_valBegin;
            };

            // key is equal to it->first, move further left.
            if ((!(key < (--it)->first) && !(it->first < key))) {
                if (it == m_map.begin()) {
                    return m_valBegin;
                }
                --it;
            } 

            return it->second;
        };

        void assign(K const& KeyBegin, K const& KeyEnd, V const& value) {
            if (!(KeyBegin < KeyEnd)) {
                return;
            }

            // leftVal is the value at the left end of the interval.
            auto itBegin = m_map.lower_bound(KeyBegin);
            V const leftVal = lSearch(KeyBegin);

            // rightVal is the value at the right end of the interval.
            // note that the regular lookup operator can be used as
            // the intervals inside the map are half open intervals,
            // where the right end is not included.
            auto itEnd = m_map.upper_bound(KeyEnd);
            V const rightVal = (*this)[KeyEnd];

            m_map.erase(itBegin, itEnd);

            // ensures left canonicity.
            if (!(leftVal == value)) {
                m_map.emplace(std::make_pair(KeyBegin, value));
            }

            // ensures right canonicity.
            if (rightVal == value) {
                return;
            }

            m_map.emplace(std::make_pair(KeyEnd, rightVal));
        }

        // For testing purposes.
        void print_map() {
            bool first = true;
            std::cout << "{";
            for (auto it =m_map.begin(); it != m_map.end(); ++it) {
                if (!first) {
                    std::cout << ", ";
                }

                std::cout << "(" << it->first << ", " << it->second << ")";
                first = false;
            }
            std::cout << "}";
            std::cout << std::endl;
        };
};

#endif // INTERVAL_MAP_HPP