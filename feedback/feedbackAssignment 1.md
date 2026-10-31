# Assignment 1 — Grace Currier-Moritsugu (gcurrier-moritsugu)

I reviewed your Assignment 1 submission. I found that the citations contain the required ownership statements.

I retained the externally validated 6/10 working-submission credit and reviewed the remaining 4/10 for code quality. I made no additional compilation, output, memory-leak or lateness deductions.

I located all five required modules and found the Dictionary interface in `assignments/a1/dictionary.h`, lines 46–70; the numbered source evidence is retained in my marking record.

My code-quality deductions are:

- Naming: 0.2 points (2% of the full assignment). I found single-letter uppercase parameter names D and L for source objects. Use descriptive camelCase names such as source or other. Evidence: `assignments/a1/dictionary.cpp`, lines 115–125; `assignments/a1/dictionary.cpp`, lines 140–150; `assignments/a1/logger.cpp`, lines 32–38.
- Logic: 0.5 points (5% of the full assignment). I found the capacity doubled on every addEvent call, even when spare slots remain. This grows unused storage exponentially. Grow only when the event count reaches capacity, then append into the existing array. Evidence: `assignments/a1/logger.cpp`, lines 49–58.
- Logic: 0.2 points (2% of the full assignment). I found irrelevant stream/timing includes in Settings and stream-formatting includes in TimeMonitor. Keep only dependencies used by each module. Evidence: `assignments/a1/settings.h`, lines 21–22; `assignments/a1/settings.cpp`, lines 20–22; `assignments/a1/timeMonitor.cpp`, lines 20–23.
- Logic: 0.2 points (2% of the full assignment). I found the copy operations allocating one extra unused Word object. Allocate exactly the source count; Word arrays do not need a string terminator. Evidence: `assignments/a1/dictionary.cpp`, lines 117–120; `assignments/a1/dictionary.cpp`, lines 131–134.

My result: raw **8.9/10**; original Blackboard multiplier **1.00**; final Blackboard grade **8.9/10**.

Calculation: max(0, 10 − 1.1 quality − 0 borrowing) × 1.00. I rounded only the final Blackboard value to one decimal place.
