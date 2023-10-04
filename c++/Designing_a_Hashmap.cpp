#include <iostream>
#include <unordered_map>
#include<bits/stdc++.h>

class MyHashMap {
private:
    std::unordered_map<int, int> data;

public:
    MyHashMap() {
        // Constructor, no initialization needed
    }

    void put(int key, int value) {
        data[key] = value;
    }

    int get(int key) {
        if (data.find(key) != data.end()) {
            return data[key];
        } else {
            return -1; // Key not found
        }
    }

    void remove(int key) {
        data.erase(key);
    }
};

int main() {
    MyHashMap* obj = new MyHashMap();

    // Insert key-value pairs
    obj->put(1, 100);
    obj->put(2, 200);
    obj->put(3, 300);

    // Retrieve values by keys
    int value1 = obj->get(1); // Should return 100
    int value2 = obj->get(2); // Should return 200
    int value3 = obj->get(4); // Should return -1 (key not found)

    std::cout << "Value of key 1: " << value1 << std::endl;
    std::cout << "Value of key 2: " << value2 << std::endl;
    std::cout << "Value of key 4: " << value3 << std::endl;

    // Remove a key-value pair
    obj->remove(2);

    // Attempt to retrieve the removed key
    int value4 = obj->get(2); // Should return -1 (key not found after removal)

    std::cout << "Value of key 2 after removal: " << value4 << std::endl;

    delete obj; // Clean up the dynamically allocated object

    return 0;
}
