# Customer Order Management System

## Project Description

This project implements a Customer Order Management System using C++. The system reads data from input files to manage customer orders, stations, and the assembly line process. It involves handling customer orders, filling items, and displaying order statuses.

<img src="./workstation.jpg" alt="Assembly Line Process" width="400"/>

## Features

- **Customer Orders**: Manage customer orders, including the items ordered, and their fill status.
- **Stations**: Manage station information, including item details, serial numbers, and quantities.
- **Order Filling**: Fill items in customer orders based on station availability.

## File Structure

- [main.cpp](main/main.cpp): Entry point of the program.
- [CustomerOrder.cpp](main/CustomerOrder.cpp): Manages individual customer orders, including item names, serial numbers, and fill status.
- [CustomerOrder.h](main/CustomerOrder.h): Header file for the `CustomerOrder` class.
- [LineManager.cpp](main/LineManager.cpp): Manages the assembly line process, including stations and ensuring order fulfillment.
- [LineManager.h](main/LineManager.h): Header file for the `LineManager` class.
- [Station.cpp](main/Station.cpp): Manages individual stations, including methods for updating quantities, retrieving serial numbers, and checking item availability.
- [Station.h](main/Station.h): Header file for the `Station` class.
- [Utilities.cpp](main/Utilities.cpp): Handles parsing strings, extracting tokens, and managing field widths across the project.
- [Utilities.h](main/Utilities.h): Header file for `utility` functions.
- [Workstation.cpp](main/Workstation.cpp): Manages specific workstations or processing units in the assembly line, handling tasks or items assigned to each workstation.
- [Workstation.h](main/Workstation.h): Header file for the `Workstation` class.

## Compiling

#### Prerequisites

C++17 compatible compiler

#### Building

```bash
g++ -Wall -std=c++17 -g -o main main.cpp Utilities.cpp Station.cpp CustomerOrder.cpp Workstation.cpp LineManager.cpp
```

#### Running

```bash
./main Stations1.txt Stations2.txt CustomerOrders.txt AssemblyLine.txt
```

## Sample Output

You can find the example output of the program in [sample_output.txt](main/./sample_output.txt).

#### Sample Text Files

- [Stations1.txt](main/Stations1.txt): Contains station data.
- [Stations2.txt](main/Stations2.txt): Additional station data.
- [CustomerOrders.txt](main/CustomerOrders.txt): Customer orders to be filled.
- [AssemblyLine.txt](main/AssemblyLine.txt): Assembly line details.
