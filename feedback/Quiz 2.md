# Quiz Question(s)

# Generic Equipment Rack Management

**Duration:** 25 minutes  
**Total Marks:** 10

A workshop uses racks to hold different types of equipment. Each rack has a fixed maximum capacity and is assigned to an inspector.

Assume the following classes are fully implemented:

```cpp
class Equipment {
   string m_code;
   double m_weight;
public:
   Equipment();
   Equipment(const string& code, double weight);
   double weight() const;
};

class Inspector {
   string m_name;
public:
   Inspector(const string& name);
   const string& name() const;
};
```

## Your Task

Implement a class template named `Rack` that meets the following requirements:

1. The template must accept a type parameter `T` representing the type of equipment stored, and an integer template parameter `SIZE` representing the maximum number of equipment items.
2. Each rack must contain its own fixed-size array of `SIZE` items of type `T`. The items belong to the rack and have the same lifetime as the rack.
3. The rack must keep track of the number of items currently stored, initially zero.
4. Each rack is assigned to an existing `Inspector` object. The inspector must not be copied or owned by the rack, and must remain accessible throughout the rack's lifetime.
5. The constructor must receive an `Inspector` object and establish the required relationship.
6. Implement `bool place(const T& equipment)` to add an item to the end of the stored items if space is available. Return `true` if the item is added and `false` if the rack is full.
7. Implement `const T& operator[](int index) const` to return the item at the specified index. Assume the index is always valid.
8. Implement `int count() const` to return the number of items currently stored.
9. Implement `const Inspector& inspector() const` to return the inspector assigned to the rack.

## Instructions

- Write the complete definition of the `Rack` class template.
- All member functions must be implemented inside the class.
- Do not write a `main()` function.
- Do not include any header files.
- Assume all required headers and namespace declarations are already provided.
- You may assume that `T` is default-constructible and copy-assignable, and that `SIZE` is greater than zero.

# Original Student Answer

## Quiz 2_gcurrier-moritsugu_attempt_2026-10-16-11-16-31_test.cpp

```cpp
template <typename T, int SIZE>
class Rack {
	T* m_contents[SIZE];
	int m_numOfContents{};
public:
	friend Inspector m_inspector;
	Rack() = default;
	Rack(Inspector& I) : Rack() {
		m_inspector = I;
	}
	bool place(const T& equipment) {
		bool canPlace = m_numOfContents < SIZE;
		if (canPlace) {
			m_contents[++m_numOfContents] = equipment;
		}
		return canPlace;
	}
	const T& operator[](int index) const {
		return m_contents[index];
	}
	int count() const {
		return m_numOfContents;
	}
	const Inspector& inspector() const {
		return m_inspector;
	}
};
 
```

# Feedback

# Quiz 2

Student: Grace Currier-Moritsugu
Seneca User ID: gcurrier-moritsugu
Assessment Version: Version 4
Points: **23**/30
Final Mark: **7.67**/10

## Marking

### Class Template
* 6/6 Template declaration

### Composition
* 2/4 Owned storage
  - T* m_contents[SIZE] is an array of pointers, not an owned array of T objects. The rack must contain its equipment objects directly. Related pointer type errors in place and operator[] are counted here only.
* 2/2 Item counter

### Aggregation
* 2/6 Inspector relationship
  - friend does not declare an object data member. The Inspector needs to be retained through a reference or non-owning pointer. An Inspector value member would copy and own the inspector, which the question forbids.

### Constructor
* 3/3 Constructor

### Place Function
* 2/2 Signature
* 3/4 Place logic
  - Incrementing the count before using it as an index skips position zero and eventually accesses position SIZE. Store at the current count and increase it afterward. Capacity checking, counting an insertion, and the return result receive credit.

### Accessors
* 1/1 Subscript operator
* 1/1 Count accessor
* 1/1 Inspector accessor

Points: **23**/30
Final Mark: **7.67**/10

## Feedback

Grace, your template, capacity check, return result, and accessor structure are clear. Review the difference between an array of objects and an array of pointers. The inspector must be linked by reference or a non-owning pointer; friend does not create that relationship. Use the current count as the insertion index before increasing it.

# Rubric

```cpp

//# 10

//+ Class Template
template <typename T, int SIZE>
//- 6 Template declaration - template keyword: 1, typename: 1, T: 1, int: 1, SIZE: 1, correct template parameter syntax: 1

class Rack {
   //+ Composition
   T m_equipment[SIZE];
   //- 4 Owned storage - array member: 1, element type T: 1, array size SIZE: 1, direct storage as a member (not externally owned): 1

   //+
   int m_count{};
   //- 2 Item counter - integer member: 1, initialized to zero: 1

   //+ Aggregation
   const Inspector& m_inspector;
   //- 6 Inspector relationship - Inspector type: 1, member declaration: 1, reference instead of owned object or pointer: 3, const qualification: 1

public:
   //+ Constructor
   Rack(const Inspector& inspector)
      : m_inspector(inspector) {}
   //- 3 Constructor - correct constructor signature: 1, accepting Inspector by const reference: 1, initializing m_inspector with the supplied inspector: 1

   //+ Place Function
   bool place(const T& equipment) {
      //- 2 Signature - bool return type: 1, const T& parameter: 1

         //+
      bool success = false;
      if (m_count < SIZE) {
         m_equipment[m_count++] = equipment;
         success = true;
      }
      return success;
      //- 4 Place logic - capacity check: 1, storing at the next available position: 1, incrementing count after insertion: 1, correct success/failure return: 1
   }

   //+ Accessors
   const T& operator[](int index) const {
      return m_equipment[index];
   }
   //- 1 Subscript operator - correct const-qualified accessor returning the indexed item by const reference: 1

   //+
   int count() const {
      return m_count;
   }
   //- 1 Count accessor - returns the stored item count without modifying the object: 1

   //+
   const Inspector& inspector() const {
      return m_inspector;
   }
   //- 1 Inspector accessor - returns the associated inspector by const reference without copying it: 1
};

```
