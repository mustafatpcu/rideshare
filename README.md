### Report on Carpooling Simulation

#### Overview:

This report outlines a multithreaded carpooling simulation program written in C. The program simulates the process of organizing two teams, Team A and Team B, for carpooling. Each team consists of passengers who are seeking available spots in cars. Once a car is filled with four passengers, one passenger becomes the captain and drives the car.

#### Program Structure:

- **Main Function**:
  - The `main` function initializes the program, parses command-line arguments to determine the sizes of Team A and Team B, and checks if the input meets certain conditions for the simulation to proceed.
  - It initializes variables such as `A` (count of passengers in Team A), `B` (count of passengers in Team B), `carId` (identification number for cars), and a semaphore `Semaphore` to manage critical sections.

- **Passenger Threads**:
  - Two types of passenger threads are defined: `passengerA` and `passengerB`, corresponding to Team A and Team B, respectively.
  - Each passenger thread represents a passenger looking for available spots in cars. It increments its team's count upon finding a spot and manages the car-driving process when the car is filled with four passengers.

#### Implementation Details:

- **Semaphore Usage**:
  - The semaphore `Semaphore` is used to ensure that only one thread at a time can access critical sections of the code, such as modifying passenger counts and accessing shared variables.
  - Threads use `sem_wait` to acquire the semaphore before entering critical sections and `sem_post` to release it after completing their operations.

- **Thread Creation and Joining**:
  - The program dynamically creates threads for Team A and Team B passengers using `pthread_create`.
  - After creating all threads, the main thread waits for their completion using `pthread_join`.

- **Command-Line Arguments**:
  - The program expects two command-line arguments representing the sizes of Team A and Team B, respectively. It validates that the total number of passengers is divisible by 4 and that both team sizes are even.

- **Dynamic Memory Allocation**:
  - Dynamic memory allocation is used to create arrays of `pthread_t` structures for storing thread identifiers.

#### Instructions for Running the Program:

- Compile the program using a C compiler, such as `gcc`.
- Execute the compiled program with two command-line arguments specifying the sizes of Team A and Team B.
  - Example: `./carpool_simulation 4 8` (for a simulation with Team A having 4 members and Team B having 8 members).

#### Conclusion:

The carpooling simulation program demonstrates multithreading concepts in C, including thread creation, synchronization using semaphores, and dynamic memory allocation. It simulates the process of organizing passengers into cars, ensuring that each car has four passengers before proceeding with the driving task. The program provides a practical example of concurrency management in real-world scenarios.
