# Quiz Question(s)

**Question 1.4 — Resource Ownership and Move Semantics**  
**21 marks**

The `Records` class owns a dynamically allocated array of `long long` values.

```cpp
class Records {
    long long* m_items{};
    unsigned m_total{};

public:
    Records() = default;

    Records(const long long* items, unsigned total);
    // Already implemented.

    // Add the required special member functions.
};
```

The implemented parameterized constructor:

- Creates an independent copy of the supplied array when `total` is greater than zero.
- Creates an empty object when `total` is zero.

An empty object has `m_items == nullptr` and `m_total == 0`.

Complete the class by:

1. Implementing the destructor to release the owned array.
2. Explicitly preventing copy construction and copy assignment using deleted functions.
3. Implementing the move constructor.
4. Implementing the move assignment operator.

Your move operations must safely transfer ownership and leave the source object empty.

The move assignment operator must return a reference to the current object.

Write the complete class definition in namespace `seneca`, including the supplied members. Implement the required functions inside the class. Assume all necessary headers are included. Do not implement the parameterized constructor or write a `main()` function.

Begin your answer with:

```cpp
// Question 1.4
```

**Question 2.1 — Inheritance and Inclusion Polymorphism**  
**21 marks, estimated required time: 23 minutes.**

The following enumeration and abstract base class are supplied:

```cpp
enum class Service {
    Standard,
    Express
};

class Delivery {
    double m_distance{};

public:
    Delivery(double distance) : m_distance{distance} {
    }

    double distance() const {
        return m_distance;
    }

    virtual double charge() const = 0;

    virtual ~Delivery() = default;
};
```

**A. Derived class**

Write a class named `ParcelDelivery` that:

- Inherits publicly from `Delivery`.
- Stores a `Service` value privately.
- Receives a distance and a service value through its constructor.
- Initializes the base-class portion with the supplied distance.
- Overrides `charge()` using the following calculation:

| Service | Charge |
|---|---|
| `Service::Standard` | `4.00 + 0.50 × distance` |
| `Service::Express` | `8.00 + 0.75 × distance` |

Assume distances are non-negative and service values are valid.

**B. Polymorphic function**

Implement:

```cpp
double totalCharges(const Delivery* const deliveries[],
                    unsigned count);
```

The function must:

- Return the sum of the charges for the supplied deliveries.
- Ignore null pointers.
- Obtain each charge through the base-class interface so that the appropriate override is called.
- Return `0.0` when `count` is zero.
- Leave the deliveries unchanged and not destroy them.

When `count` is greater than zero, assume the array contains at least `count` elements.

Write the complete `ParcelDelivery` class and the `totalCharges()` function in namespace `seneca`. Implement the required member functions inside the class. Assume all necessary headers are included. Do not reproduce the supplied enumeration or base class, and do not write a `main()` function.

Begin your answer with:

```cpp
// Question 2.1
```

**Question 3.1 — Class Templates and Relationships**  
**14 marks, estimated required time: 19 minutes.**

The following classes are already implemented:

```cpp
class Label {
    unsigned m_code{};

public:
    Label(unsigned code);
    unsigned code() const;
};

class Inspector {
public:
    void record(unsigned code, double value);
};
```

A `Station<T>` contains its own label and connects to one externally owned object of type `T`.

Assume every type used for `T` provides this query:

```cpp
double value() const;
```

The following partial class template is supplied:

```cpp
template <typename T>
class Station {
    Label m_label;
    const T* m_item{};

public:
    Station(unsigned code, const T& item)
        : m_label{code}, m_item{&item} {
    }

    // Add the required member functions.
};
```

Complete the class template by implementing these public members:

**`connect`**

```cpp
void connect(const T& item);
```

Replaces the current connection with a connection to the supplied object.

**`disconnect`**

```cpp
void disconnect();
```

Removes the connection without destroying the connected object.

**`report`**

```cpp
bool report(Inspector& inspector) const;
```

- If connected, calls `inspector.record()` with the station’s label code and the connected object’s value, then returns `true`.
- If disconnected, returns `false` without calling `record()`.
- Does not retain a pointer or reference to the inspector.

Preserve these relationships:

- **Composition** between the station and its label.
- **Aggregation** between the station and the connected object.
- **Association** between the station and the inspector used by `report()`.

The station must never copy or destroy the connected object. Assume that object remains alive while connected.

Write the complete class template in namespace `seneca`, including the supplied members. Implement the required member functions inside the class. Assume all necessary headers are included. Do not reproduce `Label` or `Inspector`, and do not write a `main()` function.

Do not write custom copy operations, move operations, or a destructor; the compiler-generated versions are sufficient.

Begin your answer with:

```cpp
// Question 3.1
```

**Question 4.1 — Function Pointers and Lambda Expressions**  
**14 marks, estimated required time: 25 minutes.**

**A. Function pointer**

Write a function named `countSelected` that:

- Returns an `unsigned`.
- Receives:
  - A pointer to constant `int` values.
  - An unsigned element count.
  - A pointer to a function that receives an `int` and returns a `bool`.
- Returns the number of array elements for which the supplied function returns `true`.
- Leaves the array unchanged.
- Returns zero when the element count is zero.

Assume the function pointer is valid. When the count is greater than zero, assume the array pointer refers to at least the specified number of elements.

**B. Lambda expression**

Implement:

```cpp
void showSelected(const int* values, unsigned count);
```

Inside this function:

1. Define a non-capturing lambda expression that receives an `int` and returns `true` when the value is **positive and divisible by 3**, and `false` otherwise.
2. Call `countSelected()` using that lambda.
3. Display:

   ```text
   Selected: N
   ```

   where `N` is the returned count. End the output with a newline.

Write both function definitions in namespace `seneca`. Assume all necessary headers are included. Do not write a `main()` function.

Begin your answer with:

```cpp
// Question 4.1
```

# Original Student Answer

## Midterm Test_gcurrier-moritsugu_attempt_2026-10-23-11-52-28_Question1.cpp

```cpp
// Question 1.4
namespace seneca {
class Records {
	long long* m_items{};
	unsigned m_total{};
public:
	Records() = default;
	Records(const long long* items, unsigned total);
    // Already implemented.
 
    // Add the required special member functions.
	~Records() {
		delete[] m_records;
		m_records = nullptr;
		m_total = 0;
	}
	
	Records(const Records& other) = delete;
	Records& operator=(const Records& other) = delete;
	
	Records(Records&& other) noexcept {
		m_items = other.m_items;
		m_total = other.m_total;
		delete[] other.m_items;
		other.m_items = nullptr;
		other.m_total = 0;
	}
	
	Records& operator=(Records&& other) noexcept {
		if (this != &other) {
			if (m_items != nullptr) {
				delete[] m_items;
			}
			m_items = other.m_items;
			m_total = other.m_total;
			delete[] other.m_items;
			other.m_items = nullptr;
			other.m_total = 0;
		}
		return *this;
	}
};
}
```


## Midterm Test_gcurrier-moritsugu_attempt_2026-10-23-11-52-28_Question2.cpp

```cpp
// Question 2.1
namespace seneca {

class ParcelDelivery : public Delivery {
private:
	Service m_serviceType;
public:
	ParcelDelivery(double distance, Service serviceType) 
		: Delivery(distance), m_serviceType(serviceType) {
		}
	double charge() const override {
		if (m_serviceType == Service::Standard) {
			return (4.00 + 0.50 * distance());
		}
		else {
			return (8.00 + 0.75 * distance());
		}
	}
};

double totalCharges(const Delivery* const deliveries[], unsigned count) {
	double total = 0.0;
	for (unsigned i = 0; i < count; i++) {
		if (deliveries[i] != nullptr) {
			total += deliveries[i]->charge();
		}
	}
	return total;
}
}
```


## Midterm Test_gcurrier-moritsugu_attempt_2026-10-23-11-52-28_Question3.cpp

```cpp
// Question 3.1
namespace seneca {
template <typename T>
class Station {
	Label m_label;
	const T* m_item{};
public:
	Station(unsigned code, const T& item)
		: m_label{code}, m_item{&item} {
	}
 
	// Add the required member functions.
	void connect(const T& item) {
		m_item = &item;
	}
	void disconnect() {
		m_item = nullptr;
	}
	bool report(Inspector& inspector) const {
		if (m_item != nullptr) {
			inspector->record(m_label.code(), *m_item);
			return true;
		}
		return false;
	}
};
}
```


## Midterm Test_gcurrier-moritsugu_attempt_2026-10-23-11-52-28_Question4.cpp

```cpp
// Question 4.1
namespace seneca {
unsigned countSelected(const int* values, unsigned count, bool* funcPoint(int)) {
	unsigned selected = 0;
	for (unsigned i = 0; i < count; i++) {
		if (funcPoint(values[i]) {
			selected++;
		}
	}
	return selected;
}
void showSelected(const int* values, unsigned count) {
	bool lambda(int i) {
		return (i > 0 && i % 3 == 0);
	}
	unsigned selected = countSelected(values, count, *lambda);
	std::cout << "Selected: " << selected << std::endl;
}
}
```


# Feedback

# Midterm Test

Student: Grace Currier-Moritsugu
Seneca User ID: gcurrier-moritsugu
Assessment Version: Question 1.4, Question 2.1, Question 3.1, Question 4.1
Points: **132**/139
Final Mark: **66.65**/70

## Marking

### Question 1.4
Points: **33**/35; scaled mark: **19.80**/21

#### Destructor

* 1/1 correct destructor signature
* 2/2 resource release - delete[]: 1, owned pointer m_items: 1
#### Prevent copy construction

* 4/4 Records constructor name: 1, const source: 1, reference parameter: 1, = delete: 1
#### Prevent copy assignment

* 5/5 Records& return type: 1, operator=: 1, const source: 1, reference parameter: 1, = delete: 1
#### Move constructor

* 3/3 Records constructor name: 1, Records&& parameter: 1, noexcept: 1
* 1/3 ownership transfer - acquire source pointer without allocation or element copying: 2, copy element count: 1
  - After taking the source pointer, do not delete its array. That leaves the destination with a dangling pointer. The same error in move assignment is counted here only once.
* 2/2 empty source - reset source pointer: 1, reset source count: 1
#### Move assignment operator

* 4/4 Records& return type: 1, operator=: 1, Records&& parameter: 1, noexcept: 1
* 2/2 self-move protection - compare object addresses: 1, leave object unchanged on self-move: 1
* 2/2 release previous destination resource before replacing its pointer - delete[]: 1, destination pointer m_items: 1
* 3/3 ownership transfer - acquire source pointer without allocation or element copying: 2, copy element count: 1
* 2/2 empty source - reset source pointer: 1, reset source count: 1
* 2/2 return current object - dereference this: 1, return on all normal paths including self-move: 1

### Question 2.1
Points: **42**/42; scaled mark: **21.00**/21

#### Derived class

* 3/3 class name ParcelDelivery: 1, public inheritance: 1, base class Delivery: 1
* 2/2 private data member: 1, Service type: 1
#### Constructor

* 3/3 public constructor named ParcelDelivery: 1, double distance parameter: 1, Service service parameter: 1
* 3/3 initialize base through Delivery constructor: 1, pass supplied distance: 1, initialize stored service from parameter: 1
#### Charge override

* 4/4 double return type: 1, charge() name and empty parameter list: 1, const: 1, override: 1
* 2/2 test stored service: 1, correctly qualified scoped enumerator Service::Standard: 1
* 4/4 standard charge - base fee 4.00: 1, rate 0.50: 1, obtain distance through accessible base query: 1, combine as base fee + rate * distance: 1
* 4/4 express charge - base fee 8.00: 1, rate 0.75: 1, obtain distance through accessible base query: 1, combine as base fee + rate * distance: 1
* 1/1 return the calculated charge
#### Polymorphic total function

* 5/5 double return type: 1, function name totalCharges: 1, array of pointers to const Delivery: 1, const pointer elements: 1, unsigned count parameter: 1
* 2/2 floating-point accumulator: 1, initialize to zero so an empty array produces 0.0: 1
* 3/3 begin at index zero: 1, continue while index is less than count: 1, advance through each element: 1
* 2/2 check current pointer before dereferencing: 1, skip null entries while continuing with remaining entries: 1
* 3/3 invoke charge() through the base-class pointer for virtual dispatch: 2, accumulate the returned charge: 1
* 1/1 return the accumulated total

### Question 3.1
Points: **27**/28; scaled mark: **13.50**/14

#### Connect

* 4/4 public member named connect: 1, void return type: 1, template type T as a reference parameter: 1, const parameter: 1
* 3/3 connection - obtain supplied object's address: 1, store address in m_item: 1, connect directly without copying or destroying an object: 1
#### Disconnect

* 2/2 public member named disconnect with no parameters: 1, void return type: 1
* 3/3 disconnection - reset stored connection: 1, use nullptr or equivalent null pointer value: 1, leave externally owned object alive: 1
#### Report

* 5/5 public member named report: 1, bool return type: 1, Inspector parameter type: 1, non-const reference parameter: 1, const member function: 1
* 1/1 establish a false result for a disconnected station
* 2/2 check connection before accessing the object: 1, skip recording when disconnected: 1
* 4/5 call record on supplied inspector: 1, obtain owned label's code: 1, obtain connected object's value through its pointer: 1, pass code then value: 1, use inspector without retaining its address or reference: 1
  - Pass m_item->value(), not the connected object itself, as the second argument.
* 1/1 establish a true result after recording
* 2/2 return the result: 1, provide a return on both connected and disconnected paths: 1

### Question 4.1
Points: **30**/34; scaled mark: **12.35**/14

#### Array-processing function

* 6/7 unsigned return type: 1, function name countSelected: 1, pointer to const int: 2, unsigned count parameter: 1, function-pointer parameter receiving int and returning bool: 2
  - Use a pointer to a function returning bool: bool (*funcPoint)(int).
* 2/2 unsigned counter: 1, initialize to zero so an empty array produces zero: 1
* 3/3 begin at index zero: 1, continue while index is less than count: 1, advance through each element: 1
* 3/3 call supplied function through its pointer: 1, pass current array element: 1, use returned bool to decide whether to count the element: 1
* 1/1 increment the counter once for each selected element
* 1/1 return the accumulated count
#### Display function

* 4/4 void return type: 1, function name showSelected: 1, pointer to const int: 1, unsigned count parameter: 1
#### Lambda expression

* 1/3 define and store a lambda: 1, empty capture list: 1, int parameter: 1
  - This is a named function definition, not a non-capturing lambda. Use an empty capture list.
* 4/4 test strictly positive value: 1, test divisibility by 3: 1, combine conditions with logical AND: 1, return the bool result: 1
#### Process and display

* 2/3 call countSelected: 1, pass supplied array and count: 1, pass the defined lambda as the selection function: 1
  - Pass the required lambda to countSelected().
* 3/3 output exact label Selected: followed by a space: 1, output returned count: 1, end with a newline: 1

Points: **132**/139
Final Mark: **66.65**/70

## Feedback

Grace Currier-Moritsugu, your inheritance, total function, and connection management are strong. A move transfers ownership; it must not delete the transferred array. Review the difference between an object and the value returned by its query. Practise function-pointer declarations and the syntax for a non-capturing lambda.

# Rubric

## Question 1.4

```cpp
//# 21
// Question1.4

namespace seneca {

   class Records {
      long long* m_items{};
      unsigned m_total{};

   public:
      Records() = default;

      Records(const long long* items, unsigned total);
      // Assumed implemented.

      //+ Destructor
      ~Records() {
         //- 1 correct destructor signature

             //+
         delete[] m_items;
         //- 2 resource release - delete[]: 1, owned pointer m_items: 1
      }

      //+ Prevent copy construction
      Records(const Records&) = delete;
      //- 4 Records constructor name: 1, const source: 1, reference parameter: 1, = delete: 1

      //+ Prevent copy assignment
      Records& operator=(const Records&) = delete;
      //- 5 Records& return type: 1, operator=: 1, const source: 1, reference parameter: 1, = delete: 1

      //+ Move constructor
      Records(Records&& source) noexcept {
         //- 3 Records constructor name: 1, Records&& parameter: 1, noexcept: 1

             //+
         m_items = source.m_items;
         m_total = source.m_total;
         //- 3 ownership transfer - acquire source pointer without allocation or element copying: 2, copy element count: 1

         //+
         source.m_items = nullptr;
         source.m_total = 0;
         //- 2 empty source - reset source pointer: 1, reset source count: 1
      }

      //+ Move assignment operator
      Records& operator=(Records&& source) noexcept {
         //- 4 Records& return type: 1, operator=: 1, Records&& parameter: 1, noexcept: 1

             //+
         if (this != &source) {
            //- 2 self-move protection - compare object addresses: 1, leave object unchanged on self-move: 1

                //+
            delete[] m_items;
            //- 2 release previous destination resource before replacing its pointer - delete[]: 1, destination pointer m_items: 1

            //+
            m_items = source.m_items;
            m_total = source.m_total;
            //- 3 ownership transfer - acquire source pointer without allocation or element copying: 2, copy element count: 1

            //+
            source.m_items = nullptr;
            source.m_total = 0;
            //- 2 empty source - reset source pointer: 1, reset source count: 1
         }

         //+
         return *this;
         //- 2 return current object - dereference this: 1, return on all normal paths including self-move: 1
      }
   };

}
```


## Question 2.1

```cpp
//# 21
// Question2.1

namespace seneca {

   //+ Derived class
   class ParcelDelivery : public Delivery {
      //- 3 class name ParcelDelivery: 1, public inheritance: 1, base class Delivery: 1

          //+
      Service m_service;
      //- 2 private data member: 1, Service type: 1

   public:
      //+ Constructor
      ParcelDelivery(double distance, Service service)
         //- 3 public constructor named ParcelDelivery: 1, double distance parameter: 1, Service service parameter: 1

             //+
         : Delivery{ distance }, m_service{ service } {
         //- 3 initialize base through Delivery constructor: 1, pass supplied distance: 1, initialize stored service from parameter: 1
      }

      //+ Charge override
      double charge() const override {
         //- 4 double return type: 1, charge() name and empty parameter list: 1, const: 1, override: 1

             //+
         double amount{};
         if (m_service == Service::Standard) {
            //- 2 test stored service: 1, correctly qualified scoped enumerator Service::Standard: 1

                //+
            amount = 4.00 + 0.50 * distance();
            //- 4 standard charge - base fee 4.00: 1, rate 0.50: 1, obtain distance through accessible base query: 1, combine as base fee + rate * distance: 1

         }
         else {
            //+
            amount = 8.00 + 0.75 * distance();
            //- 4 express charge - base fee 8.00: 1, rate 0.75: 1, obtain distance through accessible base query: 1, combine as base fee + rate * distance: 1
         }

         //+
         return amount;
         //- 1 return the calculated charge
      }
   };

   //+ Polymorphic total function
   double totalCharges(const Delivery* const deliveries[],
                       unsigned count) {
      //- 5 double return type: 1, function name totalCharges: 1, array of pointers to const Delivery: 1, const pointer elements: 1, unsigned count parameter: 1

          //+
      double total = 0.0;
      //- 2 floating-point accumulator: 1, initialize to zero so an empty array produces 0.0: 1

      //+
      for (unsigned i = 0; i < count; ++i) {
         //- 3 begin at index zero: 1, continue while index is less than count: 1, advance through each element: 1

             //+
         if (deliveries[i] != nullptr) {
            //- 2 check current pointer before dereferencing: 1, skip null entries while continuing with remaining entries: 1

                //+
            total += deliveries[i]->charge();
            //- 3 invoke charge() through the base-class pointer for virtual dispatch: 2, accumulate the returned charge: 1
         }
      }

      //+
      return total;
      //- 1 return the accumulated total
   }

}
```


## Question 3.1

```cpp
//# 14
// Question3.1

namespace seneca {

   template <typename T>
   class Station {
      Label m_label;
      const T* m_item{};

   public:
      Station(unsigned code, const T& item)
         : m_label{ code }, m_item{ &item } {}

      //+ Connect
      void connect(const T& item) {
         //- 4 public member named connect: 1, void return type: 1, template type T as a reference parameter: 1, const parameter: 1

             //+
         m_item = &item;
         //- 3 connection - obtain supplied object's address: 1, store address in m_item: 1, connect directly without copying or destroying an object: 1
      }

      //+ Disconnect
      void disconnect() {
         //- 2 public member named disconnect with no parameters: 1, void return type: 1

             //+
         m_item = nullptr;
         //- 3 disconnection - reset stored connection: 1, use nullptr or equivalent null pointer value: 1, leave externally owned object alive: 1
      }

      //+ Report
      bool report(Inspector& inspector) const {
         //- 5 public member named report: 1, bool return type: 1, Inspector parameter type: 1, non-const reference parameter: 1, const member function: 1

             //+
         bool recorded = false;
         //- 1 establish a false result for a disconnected station

         //+
         if (m_item != nullptr) {
            //- 2 check connection before accessing the object: 1, skip recording when disconnected: 1

                //+
            inspector.record(m_label.code(), m_item->value());
            //- 5 call record on supplied inspector: 1, obtain owned label's code: 1, obtain connected object's value through its pointer: 1, pass code then value: 1, use inspector without retaining its address or reference: 1

            //+
            recorded = true;
            //- 1 establish a true result after recording
         }

         //+
         return recorded;
         //- 2 return the result: 1, provide a return on both connected and disconnected paths: 1
      }
   };

}
```


## Question 4.1

```cpp
//# 14
// Question4.1

namespace seneca {

   //+ Array-processing function
   unsigned countSelected(const int* values, unsigned count,
                          bool (*select)(int)) {
      //- 7 unsigned return type: 1, function name countSelected: 1, pointer to const int: 2, unsigned count parameter: 1, function-pointer parameter receiving int and returning bool: 2

          //+
      unsigned selected = 0;
      //- 2 unsigned counter: 1, initialize to zero so an empty array produces zero: 1

      //+
      for (unsigned i = 0; i < count; ++i) {
         //- 3 begin at index zero: 1, continue while index is less than count: 1, advance through each element: 1

             //+
         if (select(values[i])) {
            //- 3 call supplied function through its pointer: 1, pass current array element: 1, use returned bool to decide whether to count the element: 1

                //+
            ++selected;
            //- 1 increment the counter once for each selected element
         }
      }

      //+
      return selected;
      //- 1 return the accumulated count
   }

   //+ Display function
   void showSelected(const int* values, unsigned count) {
      //- 4 void return type: 1, function name showSelected: 1, pointer to const int: 1, unsigned count parameter: 1

          //+ Lambda expression
      auto positiveMultiple = [](int value) {
         //- 3 define and store a lambda: 1, empty capture list: 1, int parameter: 1

             //+
         return value > 0 && value % 3 == 0;
         //- 4 test strictly positive value: 1, test divisibility by 3: 1, combine conditions with logical AND: 1, return the bool result: 1
         };

      //+ Process and display
      unsigned result = countSelected(values, count, positiveMultiple);
      //- 3 call countSelected: 1, pass supplied array and count: 1, pass the defined lambda as the selection function: 1

      //+
      std::cout << "Selected: " << result << '\n';
      //- 3 output exact label Selected: followed by a space: 1, output returned count: 1, end with a newline: 1
   }

}
```

