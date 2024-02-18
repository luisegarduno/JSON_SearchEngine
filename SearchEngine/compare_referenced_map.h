#ifndef COMPARE_REFERENCED_MAP_H
#define COMPARE_REFERENCED_MAP_H

#include <set>
#include <string>
#include <algorithm>

using std::pair;
using std::string;
using std::multiset;
using std::reference_wrapper; // Class template that wraps a reference in a copyable

/* Implementation base on:
 * http://www.cplusplus.com/forum/beginner/168761/
 */

struct Compare_Referenced_Map{
    template <typename T>
    bool operator() (const T& left, const T& right) const{
        return left.second.get() > right.second.get();
    }
};

template <typename T>
std::multiset<std::pair<std::reference_wrapper<const std::string>, std::reference_wrapper<const int>>, Compare_Referenced_Map>
sortMap(const T& map) {
    std::multiset<std::pair<std::reference_wrapper<const std::string>, std::reference_wrapper<const int>>, Compare_Referenced_Map> newMultiSet;

    // Iterate over key-value pairs in the map
    for (const auto& pair : map) {
        // Insert pair into the multiset, using references to avoid unnecessary copies
        newMultiSet.emplace(std::ref(pair.first), std::ref(pair.second));
    }

    return newMultiSet;
}

#endif // COMPAREREFERENCEMAP_H
