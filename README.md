# Vehicle Management System

A console-based Vehicle Management System built in C++ that demonstrates core Object-Oriented Programming principles. The system allows users to manage records for Cars, Bikes, and Trucks along with their respective owner information.

## Features

- Display all vehicle records by type
- Search vehicles by registration number
- Add new vehicle entries
- Delete existing vehicle entries
- Edit vehicle information
- Manage owner information linked to vehicles

## OOP Concepts Applied

- **Abstraction** — `Vehicle` is an abstract base class with a pure virtual function `vehicleType()`
- **Inheritance** — `Car`, `Bike`, and `Truck` inherit common attributes and behavior from `Vehicle`
- **Polymorphism** — `displayInfo()` and `inputInfo()` are overridden in each derived class for type-specific behavior
- **Encapsulation** — All data members are private, accessible only through public member functions
- **Constructor Overloading** — Each class supports both default and parameterized constructors
- **Virtual Destructor** — Ensures proper memory cleanup when deleting derived objects through a base pointer

## Tech Stack

- Language: C++
- Paradigm: Object-Oriented Programming

## Project Structure

- `main.cpp` — Contains all class definitions and implementations including Vehicle, Car, Bike, Truck, and Owner
