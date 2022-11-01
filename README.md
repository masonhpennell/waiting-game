# Waiting Game
Mason Pennell, Timothy Pieschala
2370867 2391088
pennell@chapman.edu, pieschala@chapman.edu
CPSC 350-01
Programming Assignment 4: The Waiting Game

Imagine that the student services center (SSC), which houses the registrar, cashier, and financial aid office, has approached you with the following issues. At certain times during the day, students arrive in large numbers, each needing to visit one or more offices. If there are not enough windows open at each, the average student wait times are too long, and they receive many complaints. On the other hand, if they open too many windows, their staff will be idle for most of the time, and they will be wasting money. They want you to program a simulation that will allow them to calculate metrics on student wait times and window idle times given a specific traffic flow of students through the SSC.

CUSTOMER

  A customer has two different queues with times and offices to enter, as well as a time the student enters the first office. After each office, each queue has one value removed.

OFFICE



SERVICE CENTER

  The Service Center holds on to the students while the offices are all occupied.

WINDOW



FILE PROCESSOR

  This program reads the input file and creates a Service Center to hold all customers.

INSTRUCTIONS

1. Compile by typing "g++ -o test *.cpp".
2. Run code with "./test input.txt".