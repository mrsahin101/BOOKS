# BECOMING A FUNCTIONAL C++ PROGRAMMER

## Chapter 6 -> Creating Functions
- A good function is easy to describe. You shouldnt have to use more than a single sentence.
- Difference from C, C++ lets programmer to override function names. The key is each function signature must be different

## Chapter 7 -> Storing Sequences in Arrays
- To initialize array with same value : float floatArray[25] = {1.0}; puts into all 25 elements the value 1.0
- **sz** : prefix is usually used for zero-terminated string.
- cin is not safe. Buffer overflows could occur.

## Chapter 8 -> Taking a First Look at C++ Pointers
- Functions can return or take arguments as pointers.
- Heap is dynamic memory.
- To allocate objects on heap, **new** command is used. **delete** is used for deleting object from heap. It's analogous to malloc and free in C
- dynamic memory allocation can be managed or unmanaged. 