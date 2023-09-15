# Philosophers 🍴😴🤔

## Introduction
- This project is a classic exercise in concurrent programming and synchronization. It simulates a scenario where a group of philosophers sit around a table and perform **three activities: sleeping, thinking and eating.**
- **The goal of this project** is to implement a solution that allows the philosophers to alternate between thinking, sleeping and eating, while avoiding any conflicts that might arise due to shared resources, like forks, because they will only have one fork per philo and cannot share it with the colleague next door.

## GRADE PROJECT ✅
- 100/125 📋
- [**Subject**](https://github.com/nunovaladao/42_Philosophers_lev3/blob/main/extras/en.subject.pdf) 

## Installation
To get started with Philosophers, follow the steps below:
1. Clone the repository via
```bash
git clone https://github.com/nunovaladao/42_Philosophers_lev3.git
```

2. Move into the repository directory:
```bash
cd 42_Philosophers_lev3
```

3. Build the project using the provided Makefile:
```bash
make
```

4. Run Philosophers:
```bash
./philo <nb_philos> <time_to_die> <time_to_eat> <time_to_sleep>
```

5. You can add a lastest argument:
```bash
./philo <nb_philos> <time_to_die> <time_to_eat> <time_to_sleep> <number_of_times_each_philosopher_must_eat>
```

## Implementation
In this project, I use the following synchronization mechanisms to ensure safe concurrent execution:

**`Threads:`** Each philosopher is implemented as a separate thread, allowing them to run concurrently.

**`Init Forks:`** When I initialize the philosophers I immediately assign the forks to each of them and when the last philosopher arrives I assign him with fork 0 to close the table circle.

**`Mutexes:`** Mutexes are used to protect shared resources (forks in this case) from concurrent access. Each philosopher must acquire both the left and right fork using mutex locks before eating. And mutexes also serve to protect variables, so that they are not accessed by other threads without being supposed to.


## Conclusion
The Philosphers project has provided a valuable learning experience in the realm of concurrent programming and synchronization. Through this project, i gained a deeper understanding of several key concepts and techniques:

1. **`Thread Management:`** I learned how to create and manage threads, understanding the basics of thread creation, execution, and termination. This skill is vital for building responsive and efficient software.

2. **`Mutexes:`** I become acquainted with mutexes as a synchronization mechanism. Mutexes help ensure that critical sections of code or shared resources are accessed by only one thread at a time, preventing race conditions and data corruption.

3. **`Debbuging Challenges:`** The project has exposed me to common concurrency challenges, including race conditions and deadlocks. I now understand the importance of proper synchronization to avoid these issues and ensure the correctness and reliability of concurrent programs.

4. **`Practical Problem-Solving:`** This project has allowed me to apply my knowledge of threads and mutexes to a practical scenario, emphasizing the real-world significance of concurrent programming in modern software development.

5. **`Critical Thinking:`** I honed my critical thinking skills by designing and implementing a solution that balances the competing needs of individual philosophers while ensuring overall system integrity.

The Philosphers project serves as an excellent foundation for more complex concurrent programming tasks and helps prepare me for challenges in developing multi-threaded applications that are responsive, efficient, and reliable.

## Useful links

- https://medium.com/swlh/the-dining-philosophers-problem-bbdb92e6b788
- https://www.youtube.com/watch?v=UGQsvVKwe90&t=3s
- https://www.youtube.com/watch?v=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2

## Note:

- [**Coding Norm**](https://github.com/nunovaladao/42_Philosophers_lev3/blob/main/extras/en_norm.pdf) - All students must follow the 42 code writing standards. This standard is applied to many projects in the course.
- 42's projects are made and designed to work on the school's computers, so it is possible that when testing it, it may give an unexpected error.
##
Nuno Valadão | nsoares-@student.42porto.com
