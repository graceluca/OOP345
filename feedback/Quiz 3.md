# Quiz Question(s)

### Before You Start

If Notepad++ is not open, [click here to go to MyApps](https://myapps.senecapolytechnic.ca/), open **Notepad++**, and save a file named **quiz3.cpp** on your **Desktop**.

**DO NOT copy and paste your answer into the quiz answer box.**

Write all three answers in **quiz3.cpp**. Begin each answer with its question number as a C++ comment, such as `// Question 1`.

When you are finished, save your file and attach it to your Blackboard answer using either method:

- Drag `quiz3.cpp` from your Desktop into the answer area.
- Click the attachment icon and select `quiz3.cpp`.

**Attach only one file.**

### OOP345 – Quiz 3.3

**Total: 10 marks · Suggested time: 50 minutes**

A community centre keeps a list of rooms. Each room has a label and a seating capacity. Assume the following code is provided for all three questions. Write only the requested implementations. A `main()` function is not required.

```cpp
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

struct Room {
    string label;
    int seats;
};
```

The **reference** section at the end of the quiz contains the signatures of the STL algorithms used in the questions.

### Question 1 – Check room capacities (3 marks)

Begin your answer with `// Question 1`.

Implement a **function object** named `WithinCapacity`. Its constructor receives an integer and stores it as the maximum permitted seating capacity. Assume the maximum is positive.

When called with a `Room` by constant reference, the function object must return `true` if the room has **at least one seat and no more than the stored maximum**. Otherwise, it must return `false`. The call must work with a constant `WithinCapacity` object.

Then implement the following function using `all_of` and your `WithinCapacity` object. Return `true` if every room meets the capacity rule. Return `false` if any room fails the rule. For an empty vector, return `true`.

```cpp
bool allRoomsWithinLimit(const vector<Room>& rooms, int maxSeats);
```

For example, with a maximum of `40`, rooms with capacities `1, 25, 40` give `true`. Adding a room with `0` seats or a room with `41` seats changes the result to `false`.

### Question 2 – Register rooms and handle errors (3 marks)

Begin your answer with `// Question 2`.

Implement both functions below.

```cpp
void registerRoom(vector<Room>& directory, const Room& room);

void registerGroup(vector<Room>& directory, const vector<Room>& arrivals,
                   ostream& errors);
```

**`registerRoom`**

- If the room has a positive number of seats, add it to the end of `directory`.
- If the number of seats is zero or negative, throw a `runtime_error` with the message `"Invalid seating capacity"`. The directory must remain unchanged for that room.

**`registerGroup`**

- Call `registerRoom` for each room in `arrivals`, in order. Assume `directory` and `arrivals` are separate vectors.
- If `registerRoom` throws a `runtime_error`, catch it by constant reference. Write the room label, a colon and a space, and the exception’s message to `errors`, followed by a newline.
- Continue processing the remaining rooms after each error.

For example, suppose the directory is empty and `arrivals` contains `{"Studio", 18}`, `{"Annex", 0}`, and `{"Hall", 75}`, in that order. After the call, the directory contains `Studio` followed by `Hall`, and the error stream contains this line:

```text
Annex: Invalid seating capacity
```

### Question 3 – Build a shortlist for an event (4 marks)

Begin your answer with `// Question 3`.

Implement the following function. Assume `guests` is positive and every room in `rooms` has a positive seating capacity.

```cpp
vector<Room> shortlistRooms(const vector<Room>& rooms, int guests);
```

1. Create a new `vector<Room>` for the shortlist.
2. Use `for_each` with a **lambda expression** to add every room that can seat **at least `guests` people**. Keep every qualifying room, including rooms with the same capacity.
3. Use `sort` with a **lambda expression** to arrange the shortlist by **room label in ascending order**, using the usual `string` comparison. If two rooms have the same label, place the room with **more seats first**.
4. Return the shortlist. If no rooms qualify, return an empty vector. Preserve the original order of the input vector `rooms`.

For example, suppose `guests` is `25` and `rooms` contains:

```cpp
{ {"West", 40}, {"East", 25}, {"North", 18}, {"East", 35} }
```

The returned shortlist contains:

```cpp
{ {"East", 35}, {"East", 25}, {"West", 40} }
```

### reference

The following algorithms are declared in `<algorithm>`. Each operates on the range `[first, last)`, which includes `first` and excludes `last`.

**`std::all_of` — Check whether every element satisfies a condition**

```cpp
template<class InputIt, class UnaryPredicate>
bool all_of(InputIt first, InputIt last, UnaryPredicate pred);
```

Returns `true` if the predicate is true for every element or if the range is empty. Returns `false` if any element fails the condition.

**`std::for_each` — Perform an action on each element**

```cpp
template<class InputIt, class UnaryFunction>
UnaryFunction for_each(InputIt first, InputIt last, UnaryFunction action);
```

Calls `action(element)` once for each element, in order. Returns the function object after processing the range.

**`std::sort` — Arrange elements using a comparison rule**

```cpp
template<class RandomIt, class Compare>
void sort(RandomIt first, RandomIt last, Compare comp);
```

Rearranges the elements in the supplied range. `comp(a, b)` returns `true` when `a` should come before `b`. It must return `false` when the two elements are equivalent under the comparison rule.



# Original Student Answer

### Quiz 3_gcurrier-moritsugu_attempt_2026-11-20-12-10-37_quiz3.cpp

```cpp
// Question 1

UnaryFunction WithinCapacity(const Room& room, const int capacity) {
	return (room.seats > 0 && room.seats <= capacity);
}

bool allRoomsWithinLimit(const vector<Room>& rooms, int maxSeats) {
	return std::all_of(rooms[0], rooms[rooms.count() - 1], WithinCapacity(maxSeats));
	}


// Question 2

void registerRoom(vector<Room>& directory, const Room& room) {
	if (room.seats <= 0) {
		throw runtime_error("Invalid seating capacity");
		return;
	}
	directory[directory.count()] = room;
}

void registerGroup(vector<Room>& directory, const vector<Room>& arrivals, ostream& errors) {
	for (int i = 0; i < arrivals.count(); i++) {
		try {
			registerRoom(directory, arrivals[i]);
		}
		catch {
			errors << arrivals.label << ": " << registerRoom << '\n';
			continue;
		}
	}
}

// Question 3


vector<Room> shortlistRooms(const vector<Room>& rooms, int guests) {
	vector<Room> shortlist;
	registerRoom(shortlist, std::for_each(rooms[0], rooms.count() - 1, WithinCapacity(guests));
	bool ascendingOrder(Room& a, Room& b){
		return (a.label < b.label || a.seats > b.seats);
	};
	std::sort(shortlist[0].label, shortlist[shortlist.count() - 1].label, ascendingOrder); 
	return shortlist;
}
```

# Feedback

# Quiz 3

Student: Grace Currier-Moritsugu
Seneca User ID: gcurrier-moritsugu
Assessment Version: Version 3
Points: **27**/50
Final Mark: **5.40**/10

## Marking

### Question 1 — Function object and collection algorithm
* 0/3 Constructor and state - stores a per-object maximum: 1, public constructor accepts an integer: 1, initializes the stored maximum from the argument: 1
  - WithinCapacity is written as a regular function. The required class, per-object maximum, and constructor are missing.
* 0/4 Call operator - defines a public operator(): 1, returns bool: 1, accepts a Room by const reference: 1, callable on a const WithinCapacity object: 1
  - There is no member call operator taking a const Room& and callable on a const function object.
* 4/4 Capacity rule - checks for a positive seat count: 1, compares seats against the stored upper limit: 1, includes a capacity equal to that limit: 1, requires both conditions to hold: 1
* 3/4 Collection check - uses all_of: 1, supplies the full rooms range: 1, passes a WithinCapacity object configured with maxSeats: 1, returns the algorithm's Boolean result: 1
  - The range must use rooms.begin() and rooms.end(), not indexed room objects.

### Question 2 — Validation and exception handling
* 4/4 Validation - recognizes zero and negative capacities: 1, throws an exception for an invalid room: 1, uses runtime_error: 1, supplies the exact required message: 1
* 2/3 Directory update - appends at the end of the caller's directory: 1, appends the supplied room: 1, leaves the directory unchanged for an invalid room: 1
  - The supplied room and invalid-case protection are present, but assigning at directory[directory.count()] does not grow the vector.
* 2/2 Traversal - visits every room in arrivals: 1, processes rooms in their original order: 1
* 2/2 Protected call - calls registerRoom with the destination directory and current room: 1, protects each call individually so processing continues after an error: 1
* 0/1 Exception handler - catches runtime_error by const reference: 1
  - Declare the caught exception as const runtime_error&.
* 2/3 Error reporting - writes to the supplied errors stream: 1, writes the current room label followed by a colon and a space: 1, writes the exception message from what() followed by a newline: 1
  - The label and newline are shown, but registerRoom is not the exception message. Use the caught exception's what().

### Question 3 — Selection and sorting
* 2/2 Destination - creates a separate vector of Room objects: 1, starts the shortlist empty: 1
* 1/2 Traversal - uses for_each: 1, supplies the full range of the input rooms vector: 1
  - for_each is named, but the endpoints are not iterators covering the rooms vector.
* 0/4 Selection lambda - passes a lambda as the action: 1, accepts the current room: 1, captures guests so the required capacity is available: 1, captures the shortlist so additions affect the destination vector: 1
  - The required selection lambda is missing.
* 0/2 Capacity threshold - accepts rooms above the required capacity and excludes those below it: 1, also accepts a room with exactly enough seats: 1
  - WithinCapacity uses an upper limit. The shortlist needs rooms with seats greater than or equal to guests.
* 0/2 Selected rooms - appends the complete qualifying room: 1, retains every qualifying occurrence including rooms with equal capacities: 1
  - Passing the result of for_each to registerRoom does not append each qualifying room.
* 1/3 Sorting setup - uses sort: 1, supplies the full shortlist range: 1, supplies a comparison lambda that accepts two rooms: 1
  - sort is used, but it needs the shortlist iterator range and a comparison lambda receiving two rooms.
* 3/3 Tie handling - uses seat count to break ties between equal labels: 1, places the larger capacity first: 1, returns false when both labels and capacities are equal: 1
* 0/1 Primary ordering - places different labels in ascending string order: 1
  - The OR condition can place a larger label first because it has more seats. Compare labels first; compare seats only when labels match.
* 1/1 Result - returns the completed shortlist, including an empty vector when no rooms qualify: 1

Points: **27**/50
Final Mark: **5.40**/10

## Feedback

Grace, your capacity check, invalid-room exception, and per-room registration loop show useful understanding. Practise writing a function object as a class. Use begin() and end() for algorithm ranges. The shortlist needs rooms large enough for the guests, with each full room appended. Sort by label first and use seats only to break a label tie.


# Rubric

```cpp
//# 10

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

// Provided in the question
struct Room {
   string label;
   int seats;
};

// Question 1

//+ WithinCapacity function object
class WithinCapacity {
   int m_maxSeats;
public:
   WithinCapacity(int maxSeats) : m_maxSeats(maxSeats) {}
   //- 3 Constructor and state - stores a per-object maximum: 1, public constructor accepts an integer: 1, initializes the stored maximum from the argument: 1

   //+
   bool operator()(const Room& room) const {
      //- 4 Call operator - defines a public operator(): 1, returns bool: 1, accepts a Room by const reference: 1, callable on a const WithinCapacity object: 1

      //+
      return room.seats > 0 && room.seats <= m_maxSeats;
      //- 4 Capacity rule - checks for a positive seat count: 1, compares seats against the stored upper limit: 1, includes a capacity equal to that limit: 1, requires both conditions to hold: 1
   }
};

//+ Check all room capacities
bool allRoomsWithinLimit(const vector<Room>& rooms, int maxSeats) {
   return all_of(rooms.begin(), rooms.end(), WithinCapacity(maxSeats));
   //- 4 Collection check - uses all_of: 1, supplies the full rooms range: 1, passes a WithinCapacity object configured with maxSeats: 1, returns the algorithm's Boolean result: 1
}

// Question 2

//+ Register one room
void registerRoom(vector<Room>& directory, const Room& room) {
   if (room.seats <= 0) {
      throw runtime_error("Invalid seating capacity");
   }
   //- 4 Validation - recognizes zero and negative capacities: 1, throws an exception for an invalid room: 1, uses runtime_error: 1, supplies the exact required message: 1

   //+
   directory.push_back(room);
   //- 3 Directory update - appends at the end of the caller's directory: 1, appends the supplied room: 1, leaves the directory unchanged for an invalid room: 1
}

//+ Register a group of rooms
void registerGroup(vector<Room>& directory, const vector<Room>& arrivals,
                   ostream& errors) {
   for (const Room& room : arrivals) {
      //- 2 Traversal - visits every room in arrivals: 1, processes rooms in their original order: 1

      //+
      try {
         registerRoom(directory, room);
      }
      //- 2 Protected call - calls registerRoom with the destination directory and current room: 1, protects each call individually so processing continues after an error: 1

      //+
      catch (const runtime_error& err) {
         //- 1 Exception handler - catches runtime_error by const reference: 1

         //+
         errors << room.label << ": " << err.what() << '\n';
         //- 3 Error reporting - writes to the supplied errors stream: 1, writes the current room label followed by a colon and a space: 1, writes the exception message from what() followed by a newline: 1
      }
   }
}

// Question 3

//+ Build the room shortlist
vector<Room> shortlistRooms(const vector<Room>& rooms, int guests) {
   vector<Room> shortlist;
   //- 2 Destination - creates a separate vector of Room objects: 1, starts the shortlist empty: 1

   //+
   for_each(rooms.begin(), rooms.end(),
       //- 2 Traversal - uses for_each: 1, supplies the full range of the input rooms vector: 1

       //+
       [guests, &shortlist](const Room& room) {
         //- 4 Selection lambda - passes a lambda as the action: 1, accepts the current room: 1, captures guests so the required capacity is available: 1, captures the shortlist so additions affect the destination vector: 1

         //+
         if (room.seats >= guests) {
            //- 2 Capacity threshold - accepts rooms above the required capacity and excludes those below it: 1, also accepts a room with exactly enough seats: 1

            //+
            shortlist.push_back(room);
            //- 2 Selected rooms - appends the complete qualifying room: 1, retains every qualifying occurrence including rooms with equal capacities: 1
         }
       });

   //+ Sort the shortlist
   sort(shortlist.begin(), shortlist.end(),
       [](const Room& left, const Room& right) {
         //- 3 Sorting setup - uses sort: 1, supplies the full shortlist range: 1, supplies a comparison lambda that accepts two rooms: 1

         //+
         if (left.label == right.label) {
            return left.seats > right.seats;
         }
         //- 3 Tie handling - uses seat count to break ties between equal labels: 1, places the larger capacity first: 1, returns false when both labels and capacities are equal: 1

         //+
         return left.label < right.label;
         //- 1 Primary ordering - places different labels in ascending string order: 1
       });

   //+
   return shortlist;
   //- 1 Result - returns the completed shortlist, including an empty vector when no rooms qualify: 1
}
```
