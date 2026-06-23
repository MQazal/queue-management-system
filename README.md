# 🎟️ Queue Management System

A console-based **Queue Management System** built in **C++** using **OOP**, designed to simulate real-world ticketing flows found in banks, clinics, and service centers.

---

## ✨ Features

- **Issue Tickets** — generates tickets with unique ID (prefix + order number), timestamp, waiting client count, and expected serve time
- **Serve Next Client** — dequeues the front client and tracks served count
- **Who's Next** — peeks at the next client without dequeuing
- **Print Queue LTR / RTL** — visualizes the queue left-to-right or right-to-left (uses a `stack` internally for reversal)
- **Print All Tickets** — displays full info for every ticket in the queue
- **Line Info Dashboard** — shows prefix, total tickets, served clients, waiting clients, and average serve time

---

## 🏗️ Architecture

The system is built around two classes:

### `clsQueueLine` (public)
Manages a named service line with a prefix and average serve time.

```cpp
clsQueueLine cashierLine("Cashier", "C", 5); // 5 min avg serve time
cashierLine.IssueTicket();   // Issues C1
cashierLine.IssueTicket();   // Issues C2
cashierLine.WhoIsNext();     // "C1"
cashierLine.ServeNextClient(); // Serves C1
cashierLine.PrintInfo();     // Dashboard
```

### `clsTicket` (private, nested)
Encapsulates ticket data — ID, timestamp, waiting count, and expected serve time calculation:

```
Expected Serve Time = AverageServeTime × WaitingClients
```

---

## 📐 Data Structures Used

| Structure | Usage |
|---|---|
| `std::queue<clsTicket>` | Main FIFO line for serving clients |
| `std::stack<clsTicket>` | Temporary reversal for RTL printing |

---

## 🖥️ Sample Output

```
            ----------------------
                 C1

            23/06/2026 10:45:00
            Waiting Clients: 2
            Serve time in
            10 Minutes.
            ----------------------

            ________________________________
            |                              |
            |   Cashier Line Info          |
            |______________________________|
            | Prefix :       C             |
            | Total Tickets: 3             |
            | Served Clients:1             |
            | Waiting Clients:2            |
            | Avg Serve Time:5             |
            |______________________________|
```

---

## 🛠️ Requirements

- C++11 or later
- `clsDate.h` from the [Libraries](https://github.com/MQazal/Libraries) repo (for timestamp)
