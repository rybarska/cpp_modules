Overview
This repository contains solutions to the C++ Modules 00 through 09 from the 42 school curriculum. These modules are designed to teach and reinforce the fundamentals of object-oriented programming, class design, inheritance, and other advanced C++ concepts. Each module builds upon the knowledge gained in previous ones, progressively increasing in complexity and depth.

Module Descriptions

C++ Module 00

Topics Covered:
Classes, Member functions, Stdio streams, Initialization lists, Static and const members, Basic syntax and foundational concepts

C++ Module 01

Topics Covered:
Memory allocation, Pointers to members, References, Switch statements

C++ Module 02

Topics Covered:
Ad-hoc polymorphism, Operator overloading, Orthodox Canonical Class Form

C++ Module 03

Topics Covered:
Multiple inheritance (including diamond-shaped inheritance pattern), Polymorphism, Method overriding, Scope resolution, Constructor chaining

C++ Module 04

Topics Covered:
Subtype polymorphism, Abstract classes, Interfaces, Understanding the difference between concrete and abstract types

C++ Module 05

Topics Covered:
Exceptions, Exception handling mechanisms (try, catch, throw), Nested try-catch blocks, Proper use of exceptions in robust programs

C++ Module 06

Topics Covered:
C++ casts (static_cast, dynamic_cast, const_cast, reinterpret_cast), Safe type conversions, Runtime type identification (RTTI), Proper use of type casting in modern C++

C++ Module 07

Topics Covered:
Function templates, Class templates

C++ Module 08

Topics Covered:
Containers, Iterators, Algorithms from the C++ Standard Template Library (STL)

Usage:
Each exercise comes with its own Makefile. Simply run the following commands in each exercise directory:

```bash
make
./prog
```

=============================

C++ Module 09

Topics Covered:
Advanced use of STL containers and algorithms through real-world inspired projects

Exercise 00 - BitcoinExchange:
Read and validate historical financial data using containers and date parsing.

Usage:

```bash
make
./btc input.csv
```
Exercise 01 - Reverse Polish Notation:
Stack-based arithmetic parser for postfix expressions.

Usage:

```bash
make
./RPN <num> <num> <operator> [... more nums and operators]
```

Exercise 02 - PmergeMe:
Implementation of the Ford-Johnson merge-insert sort algorithm using multiple STL containers and performance measurement.

Usage:

```bash
make
./PmergeMe "<num> <num> <num> ..."
``` 
