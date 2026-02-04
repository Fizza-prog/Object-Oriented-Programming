Object-Oriented Programming (C++) Portfolio
📋 Overview
This repository contains my complete Object-Oriented Programming (OOP) journey in C++, originally developed during my 2nd semester and now refined, expanded, and shared in my 4th semester. It includes fundamental concepts, advanced implementations, and practical projects that demonstrate the application of OOP principles.

📅 Timeline: 2nd Semester (Learning) → 4th Semester (Refinement & Sharing)

🎯 Repository Structure
text
📦 OOP-CPP-Portfolio/
│
├── 📂 ADTs/                          # Abstract Data Types
│   ├── array/                       # Custom Array Implementation
│   ├── matrix/                      # Matrix Operations
│   ├── rational numbers/            # Fraction Arithmetic
│   └── string/                      # Custom String Class
│
├── 📂 class/                        # Core Class Concepts
│   ├── advanced features/           # Advanced OOP Features
│   ├── arrays in classes/           # Arrays within Objects
│   ├── basic classes/               # Fundamental Classes
│   ├── constructors destructors/    # Special Member Functions
│   ├── copy constructor/            # Deep Copy Implementation
│   └── miscellaneous/               # Additional Examples
│
├── 📂 mini-projects/                # Practical Applications
│   ├── bank system/                 # Banking Management System
│   ├── scheduler/                   # Task Scheduling Application
│   └── tic-tac-toe/                 # Interactive Game
│
├── 📂 struct/                       # Structure Implementations
│   ├── advanced structs/            # Complex Structures
│   ├── array of structs/            # Structure Collections
│   ├── basic structs/               # Fundamental Structures
│   ├── dynamic structs/             # Heap-allocated Structures
│   ├── nested structs/              # Structures within Structures
│   ├── pointer to structs/          # Structure Pointers
│   └── struct functions/            # Functions Operating on Structures
│
└── 📄 README.md                     # This Documentation
🚀 Featured Projects
🏦 Banking Management System
A comprehensive banking application with multiple account types implementing real-world banking operations.

🔧 Key Features:

Multiple account types: Deposit, Loan, Mortgage

Polymorphic behavior with virtual functions

Custom String class for customer management

Interest calculation per account type

🎯 OOP Concepts:

Inheritance hierarchy

Polymorphism & virtual functions

Abstract classes

Encapsulation

📁 Location: mini-projects/bank system/

❌⭕ Tic-Tac-Toe Game
A complete console-based game with advanced features including sound effects and colorful UI.

🔧 Key Features:

Colorful console interface (Windows API)

Sound effects for game events

Win/draw detection logic

Input validation and error handling

Restart functionality

🎯 OOP Concepts:

Separation of concerns

Friend classes

Static methods

Enumerations

📁 Location: mini-projects/tic-tac-toe/

⏰ Task Scheduler
A task management system for organizing daily tasks with date and time tracking.

🔧 Key Features:

Dynamic array management with automatic resizing

Date and time tracking

Task organization and display

Memory-efficient design

🎯 OOP Concepts:

Composition over inheritance

Dynamic memory management

Getter/Setter methods

Resource cleanup

📁 Location: mini-projects/scheduler/

📝 Custom String Class
A complete implementation of a String class from scratch, mimicking std::string functionality.

🔧 Key Features:

Dynamic memory management

Operator overloading ([], =, ==, <<, >>)

Multiple constructors

Utility functions (resize, display, length)

🎯 OOP Concepts:

Deep copy semantics

Operator overloading

Resource Acquisition Is Initialization (RAII)

Friend functions

📁 Location: ADTs/string/

📚 Learning Progression
Foundation Phase (Basic Concepts)
📍 struct/                           # Starting with C structures
📍 class/basic classes/              # Transition to classes
📍 class/constructors destructors/   # Object lifecycle
📍 class/copy constructor/           # Memory management basics
Intermediate Phase (Advanced Concepts)
📍 ADTs/                            # Abstract Data Types
📍 class/advanced features/         # Advanced OOP features
📍 class/arrays in classes/         # Complex data in objects
Application Phase (Real-world Projects)
📍 mini-projects/                   # Practical applications
- Bank system, Scheduler, Tic-Tac-Toe
🛠️ Technologies & Tools
Technology	Purpose
C++ (OOP)	Primary programming language
Visual Studio Code-Main code editor
Visual Studio Community-Advanced debugging
Git/GitHub-Version control
Windows API-Console colors & sounds
g++ (MinGW/GCC)-Compilation
Compiler Command:

bash
g++ -o output filename.cpp -std=c++11
🎓 Key OOP Concepts Covered
1. Core Principles
Encapsulation: Data hiding with access specifiers

Inheritance: Creating class hierarchies

Polymorphism: Runtime binding with virtual functions

Abstraction: Abstract classes and interfaces

2. Advanced Features
Operator overloading

Friend functions and classes

Copy constructors (deep vs shallow)

Static members and functions

Const correctness

3. Memory Management
Dynamic memory allocation (new/delete)

RAII (Resource Acquisition Is Initialization)

Memory leak prevention

Smart pointers introduction

4. Design Patterns
Separation of concerns

Manager classes (UI, Sound)

Factory pattern (Account types)

Singleton pattern (SoundManager)

🚦 How to Use This Repository
For Students:
Start with basics: struct/basic structs/ → class/basic classes/

Practice concepts: Each folder contains working examples

Study projects: Analyze mini-projects/ for real-world applications

Compare evolution: See code improvements from basic to advanced

For Developers:
Code reference: Well-documented implementations

Design patterns: Practical OOP design examples

Best practices: Memory management and error handling

Compilation Guide:
bash
# Navigate to project folder
cd "mini-projects/tic-tac-toe"

# Compile all files
g++ *.cpp -o tictactoe -std=c++11

# Run the program
./tictactoe
🌟 Special Features
🎵 Audio-Visual Experience (Tic-Tac-Toe)
cpp
// Windows-based sound system
SoundManager::playSound(SoundManager::WIN);
// Colorful console output
UIManager::setColor(10); // Green for X
🏦 Real-world Modeling (Banking)
cpp
// Polymorphic account handling
Account* acc = new LoanAccount("Customer", 10000, 7.5);
acc->calcInterest(12); // Calls LoanAccount's implementation
📅 Practical Utility (Scheduler)
cpp
// Dynamic task management
Scheduler schedule;
schedule.addTask(Task("Meeting", Date(15,2,2024), Time(14,30)));
📈 Learning Outcomes
Technical Skills:
✅ Mastery of C++ OOP syntax and semantics

✅ Advanced memory management techniques

✅ Design and implementation of class hierarchies

✅ Real-world problem solving with OOP

Software Engineering:
✅ Code organization and modular design

✅ Documentation and commenting practices

✅ Version control with Git/GitHub

✅ Debugging and testing strategies

Project Development:
✅ From concept to complete application

✅ User interface design (even in console)

✅ Feature planning and implementation

✅ Code refactoring and optimization

🤝 Contribution & Usage
For Educational Purposes:
Feel free to use code for learning

Study the implementations

Modify and experiment

Share with attribution

Guidelines:
Give credit if using significant portions

Report issues for improvements

Star the repository if helpful

Fork for your own versions

📫 Contact & Attribution
👨‍🎓 Student Information:

Name: Fizza

University: Punjab University College of Information Technology

Program: BS-Software Engineering

Email: fizzahassaan84@gmail.com

📅 Academic Timeline:

Course: Object-Oriented Programming

Semester Taken: 2nd Semester

Repository Created: 4th Semeste

Status: Actively maintained

📄 License
This repository is for educational purposes. All code is available for learning and reference. Please provide attribution if used in academic or professional settings.

🙏 Acknowledgments
University Faculty: For foundational OOP teaching

Online Resources: C++ documentation and tutorials

Self-Motivation: For revisiting and improving past work

GitHub Community: For inspiration and collaboration

"This repository documents my journey from learning basic OOP concepts to building complete applications. It represents not just what I learned, but how I apply that knowledge to solve real problems."

<div align="center">
⭐ If you find this repository helpful, please give it a star!

https://img.shields.io/github/stars/Fizza-prog/Object-Oriented-Programming?style=social

</div>
