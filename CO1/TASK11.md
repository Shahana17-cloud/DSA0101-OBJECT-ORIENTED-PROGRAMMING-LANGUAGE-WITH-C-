# TASK 11 — Recommend and Defend the Final Design (4 Marks)

## Recommendation
Retain the object-oriented design, but modify it to centralize fare policy and support validation, testing and configuration. A complete redesign is not necessary because fare calculation and card validation already have clear responsibilities.

## Recommended types and classes
- Store all money in integer paise using `long long`.
- Use `enum class Zone` for valid zones.
- Use `constexpr` for compile-time constants.
- Use `SmartCard` to keep the balance private and expose `canTravel()` and `deduct()`.
- Use a fare-policy component to calculate base fares, surcharge and discounts.
- Validate input and reject invalid zones, times and negative recharge values.

## How a fare revision is made
Keep fare values in one fare table or configuration source rather than repeating numbers in several functions. Update the relevant fare policy and rerun tests for every zone, peak boundary, concession and minimum-balance boundary.

## Limitations
- A single-process educational program does not handle simultaneous gate transactions or persistent card storage.
- The example concession rate is an assumption unless the official rate is supplied.
- The original three-zone implementation does not automatically support weekend discounts, monthly passes or the airport zone.
- Large-scale deployment needs transaction safety, audit logging, concurrency control and secure card validation.

## Configuration-file alternative
Loading `z` fare values from a configuration file adds O(z) startup time and O(z) memory for the fare table. It can avoid recompilation for ordinary fare revisions, but the file must be validated and versioned. A compiled constant table starts faster and is simpler, but a fare change requires rebuilding and redeploying the application.

## Conclusion
A centralized, testable OOP design using exact integer money and validated transactions is the best fit. The recommendation should be confirmed by running the boundary and network-total tests and recording their actual results.
