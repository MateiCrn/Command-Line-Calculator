# C++ Command-Line Calculator with History

This project implements a functional pocket calculator in C++ using Object-Oriented Programming (OOP). Beyond basic arithmetic, the application features a dynamic memory system that tracks and stores the last 10 operations performed.

> **Note:** This project was developed as a university assignment. While this documentation is in English, the codebase (class names and variables) uses Romanian terminology to align with the original academic requirements.
## Core Features

* **Arithmetic Suite:** Supports addition, subtraction, multiplication, and division.
* **Advanced Operations:** Includes power functions, square root, reciprocal (1/x), and negation.
* **Automatic History Management:** Stores the last 10 results and their associated expressions as strings.
* **State Control:** Functions to display history, clear memory, reset the current value, or reload a previous result for further calculation.

## Technical Concepts Applied

* **Memory Management:** Implementation of the "Rule of Three" (Copy Constructor and Assignment Operator) to handle dynamically allocated arrays.
* **Operator Overloading:** Custom implementations for +, -, *, /, !, and [] to provide intuitive interaction with the Calculator class.
* **Data Structures:** Efficient handling of dynamic vectors for operation history.
* **Encapsulation:** Proper use of access modifiers to protect the internal state of the calculator.

## Project Structure

The class is designed for modularity and is tested within a main execution flow that simulates real-world user interactions with a standard calculator.

