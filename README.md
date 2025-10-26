# Hashtable Closed hashing 

## Directions

You are going to implement the hash table data structure using the closed hashing as the CRP. 

There are 6 methods that you need to implement to complete the data structure:

- `HashTableClosed(int)` - Already provided.
- `~HashTableClosed()`- Already provided.
- `Val find(const Key&) const`
- `void insert(const Key&, const Val&)` - Already provided.
- `void remove(const Key&)`
- `int size() const`- Already provided.
- `void clear()` 

A working `main` function is already provided. Use this to test your hash table implementation.

## Notes

- All elements in the hash table are stored as `Record` instances, as per the search problem definition
    + If you need access an individual record's key or value, use `.k` or `.v` on it, respectively
- We are assuming that there are no duplicate keys in the hash table
- `find` and `remove` need to throw errors if they're unable to complete their tasks, like this:
    ```C++
    throw string("message goes here");
    ```