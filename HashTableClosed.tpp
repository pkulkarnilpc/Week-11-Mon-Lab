template <typename Key, typename Val>
int HashTableClosed<Key, Val>::hash(const Key& key) const {
    std::hash<Key> h;
    return h(key) % capacity;
    }
   
template <typename Key, typename Val>
HashTableClosed<Key, Val>::HashTableClosed(int cap) : table(cap), numElements(0), capacity(cap) {}

// insert key-value pair
template <typename Key, typename Val>
void HashTableClosed<Key, Val>::insert(const Key& key, const Val& value) {
    if (numElements >= capacity)
        throw string("Hash table is full");

    int index = hash(key);
    int start = index;

    do {
        if (table[index].state == EMPTY || table[index].state == DELETED) {
            table[index].key = key;
            table[index].value = value;
            table[index].state = OCCUPIED;
            numElements++;
            return;
        }

        // update if key already exists
        if (table[index].key == key && table[index].state == OCCUPIED) {
            table[index].value = value;
            return;
        }

        // linear probing
        index = (index + 1) % capacity;

    } while (index != start);

    throw string("Hash table is full");
}

// find value by key
template <typename Key, typename Val>
Val HashTableClosed<Key, Val>::find(const Key& key) const {
    // TO DO
}

// remove entry
template <typename Key, typename Val>
void HashTableClosed<Key, Val>::remove(const Key& key) {
    // TO DO
}

// number of valid elements
template <typename Key, typename Val>
int HashTableClosed<Key, Val>::size() const {
        return numElements;
}

// remove all entries
template <typename Key, typename Val>
void HashTableClosed<Key, Val>::clear() {
    // TO DO
}

// display (for debugging)
template <typename Key, typename Val>
void HashTableClosed<Key, Val>::display() const {
    cout << "Table contents:\n";
    for (int i = 0; i < capacity; i++) {
        cout << i << ": ";
        if (table[i].state == OCCUPIED)
            cout << "(" << table[i].key << ", " << table[i].value << ")";
        else if (table[i].state == DELETED)
            cout << "<deleted>";
        cout << endl;
    }
}
