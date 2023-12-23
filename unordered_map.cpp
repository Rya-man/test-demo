#include <iostream>
#include <list>
#include <vector>

// Define a struct for key-value pairs
template<typename K, typename V>
struct KeyValuePair {
    K key;
    V value;
    KeyValuePair(const K& k, const V& v) : key(k), value(v) {}
};

// Define a simple hash function (for demonstration)
size_t SimpleHash(const int& key) {
    return key % 10; // Modulo operation to get bucket index
}

// Custom unordered_map implementation
template<typename K, typename V>
class CustomUnorderedMap {
private:
    std::vector<std::list<KeyValuePair<K, V>>> buckets; // Vector of lists as buckets
    size_t size;

public:
    CustomUnorderedMap(size_t initialSize) : size(initialSize) {
        buckets.resize(size);
    }

    // Insert key-value pair
    void insert(const K& key, const V& value) {
        size_t bucketIndex = SimpleHash(key);
        buckets[bucketIndex].emplace_back(key, value);
    }

    // Search for a key and return value
    V& operator[](const K& key) {
        size_t bucketIndex = SimpleHash(key);
        for (auto& pair : buckets[bucketIndex]) {
            if (pair.key == key) {
                return pair.value;
            }
        }
        throw std::out_of_range("Key not found");
    }

    // Display the map (for demonstration)
    void displayMap() {
        for (size_t i = 0; i < size; ++i) {
            std::cout << "Bucket " << i << ": ";
            for (auto& pair : buckets[i]) {
                std::cout << "(" << pair.key << ", " << pair.value << ") ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    CustomUnorderedMap<int, std::string> myMap(10);

    myMap.insert(5, "Apple");
    myMap.insert(15, "Banana");
    myMap.insert(25, "Orange");

    myMap.displayMap();

    std::cout << "Value for key 15: " << myMap[15] << std::endl;

    return 0;
}
