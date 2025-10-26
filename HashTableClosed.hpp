#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <functional>
using namespace std;

/**
 * @brief A generic closed-hashing (linear probing) hash table implementation.
 * 
 * Supports basic operations:
 *   - insert(key, value)
 *   - find(key)
 *   - remove(key)
 *   - clear()
 *   - size()
 * 
 * Collisions are resolved using linear probing.
 * Empty and deleted slots are tracked for proper insertion and deletion.
 */
template <typename Key, typename Value>
class HashTableClosed {
private:
    enum State { EMPTY, OCCUPIED, DELETED };

    struct Entry {
        Key key;
        Value value;
        State state = EMPTY;
    };

    vector<Entry> table;
    int numElements;
    int capacity;

    int hash(const Key& key) const;
    
public:
    // Constructors
    HashTableClosed(int cap = 11);

    // Core operations
    virtual void insert(const Key& key, const Value& value);
    virtual Value find(const Key& key) const;
    virtual void remove(const Key& key);
    virtual void clear();

    // Utility
    virtual int size() const;
    virtual void display() const;
};

// Include the implementation file
#include "HashTableClosed.tpp"
