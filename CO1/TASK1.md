# TASK 1 — Understand the Problem and Identify the Objects (4 Marks)

## Problem Analysis
The Namma Metro Smart-Card Fare System calculates fares according to the farthest zone travelled: Inner Zone ₹10, Middle Zone ₹20, and Outer Zone ₹30. A 20% surcharge applies during peak hours (8:00–10:00 AM and 5:00–8:00 PM). Students and senior citizens receive a concession. A journey is allowed only when at least ₹50 remains on the card after the fare is deducted.

The system must calculate fares accurately, validate journeys, protect card balances, and support future extensions such as a fourth zone, weekend discounts, and monthly passes.

## Objects, Data and Behaviour

| Object | Data (Attributes) | Behaviour (Methods) |
|---|---|---|
| `SmartCard` | Card ID, balance | Check balance, deduct fare, recharge |
| `Passenger` | Name, passenger type | Identify passenger category, determine concession |
| `Journey` | Zone, travel time | Check peak hours, validate and process journey |
| `Zone` | Zone identifier | Identify applicable fare zone |
| `FareTable` | Base fares, surcharge rate | Calculate fare and apply concession |
| `FareSystem` | Fare rules, minimum balance | Validate and process transactions |

Each object represents a distinct responsibility. `SmartCard` owns and protects the balance, while `FareTable` centralizes fare calculations. This avoids repeating fare logic throughout the program and makes the system easier to test and maintain.

## Procedural vs Object-Oriented Programming

| Procedural Programming | Object-Oriented Programming |
|---|---|
| Uses functions and shared variables. | Uses classes and objects. |
| Data and functions are separate. | Data and related methods are grouped together. |
| Shared data may be changed by many functions. | Encapsulation restricts access to sensitive data. |
| Fare rules can become duplicated. | A central fare component reduces duplication. |
| New features may require edits in many functions. | Well-designed classes make extensions easier. |

Both approaches can perform fare calculation in O(1) time per journey. OOP is preferable here because the system contains distinct entities and changing fare rules.

## Four OOP Principles
- **Encapsulation:** Keep the card balance private and modify it only through methods such as `deductFare()`.
- **Abstraction:** A caller uses `calculateFare()` without needing to know every internal calculation.
- **Inheritance:** `StudentPassenger` and `SeniorPassenger` could inherit from a base `Passenger` class.
- **Polymorphism:** A virtual `getDiscount()` method could apply different policies for different passenger categories.

Inheritance and polymorphism are useful when passenger types have distinct behaviour. For a small system, a passenger-type field and a centralized fare policy may be simpler.

## Rules for a Valid Journey
1. The card must be valid.
2. The zone and travel time must be valid.
3. The fare must be based on the applicable zone.
4. The peak surcharge applies only during the specified intervals.
5. Eligible passengers receive the configured concession.
6. At least ₹50 must remain after fare deduction.
7. Money calculations must avoid floating-point rounding errors.
8. The card balance is deducted only after validation succeeds.

## Complexity Analysis
Fare calculation, peak-hour checking and balance validation each take O(1) time. Processing one journey is therefore O(1) time and O(1) auxiliary space. Processing N journeys takes O(N) total time.

## Design Evaluation
The original design should be modified rather than completely redesigned. Keep the classes and constant-time processing, centralize fare policies, and add configurable support for a fourth zone, weekend discounts and monthly passes. Test peak-hour boundaries, concessions, invalid zones and the ₹50 minimum-balance rule.

## Conclusion
An object-oriented design with encapsulation, centralized fare calculation and clear validation rules provides a maintainable foundation for the Namma Metro Smart-Card Fare System.
