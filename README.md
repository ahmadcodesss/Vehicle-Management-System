# Vehicle Management System

A console-based C++ application for managing vehicle and owner records 
built around core Object-Oriented Programming principles.

## About

The system uses an abstract base class `Vehicle` with pure virtual 
functions to enforce a common interface across three derived classes — 
Car, Bike, and Truck. Inheritance allows each subclass to extend base 
attributes with type-specific fields. Runtime polymorphism is achieved 
through virtual functions, encapsulation is enforced by keeping all 
attributes private, and constructor chaining delegates initialization 
from derived classes to the base class.

Owner records are linked to vehicles through a shared registration 
number, enabling cross-referencing between two separate data structures.

## Tech Stack

- **Language:** C++
- **Concepts:** Abstraction, Inheritance, Polymorphism, Encapsulation, Virtual Destructors

## Features

- Add, search, edit and delete vehicle records
- Separate categories for Cars, Bikes and Trucks
- Owner records linked to vehicles via registration number
- Menu-driven console interface
