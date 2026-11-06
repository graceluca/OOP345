# Quiz 1 - Grace Currier-Moritsugu

## Quiz Question(s)

# Quiz 1 — Rule of Five

**Time:** 30 minutes

Assume the following class is fully implemented:

```cpp id="q4a1"
class Entry {
public:
    Entry(const char* value = "");
    void display() const;
};
```

The following class manages a dynamically allocated collection of `Entry` objects:

```cpp id="q4a2"
class Registry {
    Entry* m_entries;
    size_t m_count;

public:
    Registry();
    Registry(size_t count);

    // Implement the Rule of Five here
};
```

Assume that the two constructors shown above are already fully implemented and that:

- `m_entries` points to a dynamically allocated array of `Entry` objects.
- `m_count` contains the number of elements in that array.
- An empty `Registry` has `m_entries` set to `nullptr` and `m_count` set to `0`.

## Task

Implement the **Rule of Five** for the `Registry` class:

1. Destructor
2. Copy constructor
3. Copy assignment operator
4. Move constructor
5. Move assignment operator

### Requirements

Your implementation must:

- correctly release dynamically allocated memory;
- perform a **deep copy** for copy operations;
- transfer ownership of the dynamic memory for move operations;
- leave the source object in a safe empty state after a move;
- correctly handle self-assignment where applicable; and
- return the appropriate object from the assignment operators.

Write only the code required to add the Rule of Five to the `Registry` class. You do **not** need to implement `Entry`, the existing constructors, or a `main()` function.

## Original Student Answer

Filename: Quiz 1_gcurrier-moritsugu_attempt_2026-10-02-12-10-35_test.cpp

```cpp
class Entry {
public:
   Entry(const char* value = "");
   void display() const;
}


class Registry {
   Entry* m_entries;
   std::size_t m_count;
public:
   Registry();
   Registry(std::size_t count);

   ~Registry();
   Registry(const Registry& other);
   Registry& operator=(const Regitry& other);
   Registry(Registry&& other)noexcept;
   Registry& operator=(Registry&& other)noexcept;
}


Registry::~Registry() {
   if (m_entries != nullptr) {
      delete[] m_entries;
      m_entries = nullptr;
   }
}
Registry::Registry(const Registry& other) {
   m_count = 0;
   m_entries = nullptr;
   operator=(other);
}
Registry& operator=(const Registry& other) {
   if (*this != other) {
      m_count = other.m_count;
      if (m_entries != nullptr) {
         delete[] m_entries;
         m_entries = nullptr;
      }
      if (other.m_entries != nullptr) {
         m_entries = new Entry[m_count + 1];
         for (std::size_t i = 0; i < m_count; i++) {
            m_entries[i] = other.m_entries[i];
         }
      }
   }
   return *this;
}


Registry::Registry(Registry&& other)noexcept {
   m_count = 0;
   m_entries = nullptr;
   std::move(other);
}


Registry& operator=(Registry&& other)noexcept {
   if (*this != other) {
      m_count = other.m_count;
      if (m_entries != nullptr) {
         delete[] m_entries;
         m_entries = nullptr;
      }
      if (other.m_entries != nullptr) {
         m_entries = new Entry[m_count + 1];
         memcpy(other, *this, m_count);
         delete[] other.m_entries;
         other.m_entries = nullptr;
         other.m_count = 0;
      }
   }
   return *this;
}
```

## Feedback

# Quiz 1

Student: Grace Currier-Moritsugu
Seneca User ID: gcurrier-moritsugu
Assessment Version: Version 4
Points: **62**/78
Final Mark: **7.95**/10

## Marking

### Destructor

* 1/1 Signature
* 2/2 Releases dynamic memory

### Copy constructor

* 3/3 Signature
* 3/3 Initializes copy
* 4/4 Allocates array
* 4/4 Copies every element

### Copy assignment operator

* 4/4 Signature
* 1/2 Self-assignment protection
  - Compare object addresses: this != &other. The submitted *this != other compares Registry objects, but no comparison operator is provided. One point is retained for the intended guard. The same error is not deducted again in move assignment.
* 2/2 Releases current memory
* 3/3 Prepares destination
* 4/4 Allocates array
* 4/4 Copies every element
* 2/2 Returns *this

### Move constructor

* 4/4 Signature
* 1/6 Transfers ownership
  - std::move(other) alone only produces an rvalue expression. It does not assign anything or call move assignment. The pointer and count are not taken from the source. One point is awarded for avoiding allocation.
* 0/6 Empties source
  - The source pointer and count are not reset by the move constructor.

### Move assignment operator

* 5/5 Signature
* 2/2 Self-move protection
* 3/3 Releases current resource
* 2/6 Transfers ownership
  - The source count is copied, earning 2 points. The code allocates a new array and calls memcpy instead of taking other.m_entries. memcpy(other, *this, m_count) does not transfer the array pointer.
* 6/6 Empties source
* 2/2 Returns *this

Points: **62**/78
Final Mark: **7.95**/10

## Feedback

Grace, your destructor and copy operations show good understanding of releasing memory and copying each element. Compare object addresses to protect against self-assignment. Calling std::move alone does not move anything. A move operation must take the source pointer and count, then clear both source members. Do not allocate a new array or use memcpy for ownership transfer. Practise writing the two move operations and tracing which object owns the array.

## Rubric

```cpp
//# 10

#include <cstddef>
using namespace std;

class Entry {
public:
   Entry(const char* value = "");
   void display() const;
};

class Registry {
   Entry* m_entries;
   size_t m_count;

public:
   Registry();              // assumed implemented
   Registry(size_t count);  // assumed implemented

   //+ Destructor
   ~Registry() {
      //- 1 signature - destructor: 1

          //+
      delete[] m_entries;
      //- 2 releases dynamic memory - delete[]: 1, m_entries: 1
   }

   //+ Copy constructor
   Registry(const Registry& other) {
      //- 3 signature - Registry: 1, const: 1, Registry&: 1

          //+
      m_entries = nullptr;
      m_count = other.m_count;
      //- 3 initializes copy - m_entries to nullptr: 1, m_count: 1, other.m_count: 1

      //+
      if (m_count > 0) {
         m_entries = new Entry[m_count];
      }
      //- 4 allocation - condition: 1, m_entries: 1, new Entry[]: 1, m_count: 1

      //+
      for (size_t i = 0; i < m_count; i++) {
         m_entries[i] = other.m_entries[i];
      }
      //- 4 deep copy - loop through elements: 2, destination element: 1, source element: 1
   }

   //+ Copy assignment operator
   Registry& operator=(const Registry& other) {
      //- 4 signature - Registry& return type: 1, operator=: 1, const: 1, Registry& parameter: 1

          //+
      if (this != &other) {
         //- 2 self-assignment protection - this: 1, &other comparison: 1

             //+
         delete[] m_entries;
         //- 2 releases current memory - delete[]: 1, m_entries: 1

         //+
         m_entries = nullptr;
         m_count = other.m_count;
         //- 3 prepares destination - nullptr: 1, m_count: 1, other.m_count: 1

         //+
         if (m_count > 0) {
            m_entries = new Entry[m_count];
         }
         //- 4 allocation - condition: 1, m_entries: 1, new Entry[]: 1, m_count: 1

         //+
         for (size_t i = 0; i < m_count; i++) {
            m_entries[i] = other.m_entries[i];
         }
         //- 4 deep copy - loop through elements: 2, destination element: 1, source element: 1
      }

      //+
      return *this;
      //- 2 return - return: 1, *this: 1
   }

   //+ Move constructor
   Registry(Registry&& other) {
      //- 4 signature - Registry: 1, Registry&&: 2, source parameter: 1

          //+
      m_entries = other.m_entries;
      m_count = other.m_count;
      //- 6 transfers ownership - destination pointer: 1, source pointer: 1, destination count: 1, source count: 1, no allocation: 1, ownership transfer: 1

      //+
      other.m_entries = nullptr;
      other.m_count = 0;
      //- 6 empties source - source pointer: 1, nullptr: 1, source count: 1, zero: 1, prevents shared ownership: 1, safe empty state: 1
   }

   //+ Move assignment operator
   Registry& operator=(Registry&& other) {
      //- 5 signature - Registry& return type: 1, operator=: 1, Registry&&: 2, source parameter: 1

          //+
      if (this != &other) {
         //- 2 self-move protection - this: 1, &other comparison: 1

             //+
         delete[] m_entries;
         //- 3 releases current resource - delete[]: 1, m_entries: 1, release before transfer: 1

         //+
         m_entries = other.m_entries;
         m_count = other.m_count;
         //- 6 transfers ownership - destination pointer: 1, source pointer: 1, destination count: 1, source count: 1, no allocation: 1, ownership transfer: 1

         //+
         other.m_entries = nullptr;
         other.m_count = 0;
         //- 6 empties source - source pointer: 1, nullptr: 1, source count: 1, zero: 1, prevents shared ownership: 1, safe empty state: 1
      }

      //+
      return *this;
      //- 2 return - return: 1, *this: 1
   }
};
```
