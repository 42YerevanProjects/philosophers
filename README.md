# philosophers

42 project about inter-process communication. A program that can monitor multiple instances of itself, either processes or threads, using semaphores or mutexes.

### Concept

Philosophers (represented by parts of a program) sit around a table, with a big plate of spaghetti at its center. They each have a fork, but they need two forks to eat ; so they need to borrow their neighbor's fork to eat.

Of course, if they borrow a neighbor's fork, the neighbor can't use the fork. The processes / threads must communicate, to know the state of the forks (and of the other philosophers) at all times. There must also be a parent process that monitors everything.

### Philo and Philo_bonus 

**philo** does this using **threads** as philosophers, and **mutexes** as forks.

**philo_bonus** forks itself, making philosophers **processes**. Its forks are **semaphores**. It uses threads too, but only for monitoring.

<p align="center">
  <img src="https://i.imgur.com/OFhqnqw.png" width="100%" />
</p>

### How to use it

Using ``make`` in the philo directory will create the ``philo`` executable. Same for philo_bonus.

You run it specifying, in order :
* The number of philosophers
* The time in milliseconds until a philosopher dies from starvation
* The time in milliseconds it takes for a philosopher to eat
* The time in milliseconds it takes for a philosopher to sleep
* (Optional) The number of meals before the program stops

```
./philo 6 400 200 100 5
```

Here, the program will create 6 philosophers, who will die if they go without eating for 400 milliseconds. It takes them 200 milliseconds to eat, and 100 milliseconds to sleep. The program will stop after each philosopher has had 5 meals (or if any one of them dies prematurely).

### Output

The program outputs every action with a timestamp (in milliseconds) and the philosopher's number. For example, if Philosopher 2 starts eating 412 milliseconds after the beginning of the program, it will output :

```
412 #2 is eating
```

### Additional information

For more information you can read the philosophers.pdf. My code does not have memory leaks and it passes all the tests. Although The case with 4 410 200 200 is a special case for my philo. Before using my code for 42 school please double check the Norms.
