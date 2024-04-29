# Memory Management System

This project implements a simple memory management system in C++ using two allocation strategies: First Fit and Best Fit. The system allows users to allocate memory to programs, delete programs, and view the list of programs and the memory pool.

## Features

- **Memory Allocation**: The system supports two memory allocation strategies: First Fit and Best Fit. Users can choose the strategy based on their requirements.
- **Program Management**: Users can allocate memory to programs and delete programs from the memory.
- **Program Information**: Users can view the list of programs currently allocated in the memory along with their IDs and allocated memory size.
- **Memory Pool**: Users can view the current state of the memory pool, including available memory blocks.

## Usage

To use the Memory Management System, follow these steps:

1. Compile the source code files using a C++ compiler (e.g., g++).

    ```bash
    g++ main.cpp -o memory_management_system
    ```

2. Run the compiled executable.

    ```bash
    ./memory_management_system
    ```

3. Follow the on-screen instructions to interact with the memory management system.

## Implementation Details

The project is implemented using object-oriented programming concepts in C++. It consists of the following classes:

- **`block`**: Represents a memory block with a start byte ID and total bytes.
- **`program`**: Represents a program with an ID and a list of memory blocks allocated to it.
- **`List`**: Implements a generic singly linked list to store memory blocks and programs.
- **`MemoryManagementSystem`**: Implements the memory management system with functions to allocate memory to programs, delete programs, and manage the memory pool.

## Contributing

Contributions to improve the memory management system are welcome! If you have any suggestions or find any issues, please open an issue or submit a pull request.

## License

This project is licensed under the MIT License.


