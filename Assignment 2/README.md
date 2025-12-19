# TCP Socket Programming – Fruit Store Server-Client

## Objective

To gain hands-on experience with **TCP Socket Programming** by implementing a simple client–server application that supports multiple clients and maintains shared server-side state.

---

## Problem Statement

Implement a TCP-based client–server system where:

1. The **server maintains fruit records** in the format:

   * `fruit-name`
   * `quantity`
   * `last-sold (server timestamp)`

2. **Multiple clients** can connect to the server and purchase fruits.

3. Fruit quantity is **updated after every successful transaction**.

4. If the requested quantity is **not available**, the server sends a **regret message**.

5. The server maintains and displays a list of **unique customers** identified by `<IP, Port>`.

6. The **total number of unique customers** is sent to the client after every transaction.

---

## Tools & Technologies Used

* **Language**: C
* **Socket Type**: TCP (`SOCK_STREAM`)
* **Network Emulator**: Mininet
* **OS**: Ubuntu Linux
* **Compiler**: GCC
* **Packet Analysis (optional)**: Wireshark

---

## Network Topology

* **1 Server Host**: `h1`
* **2 Client Hosts**: `h2`, `h3`
* **1 Switch**: `s1`

Topology created using Mininet:

```
h1 ---- s1 ---- h2
         |
         └---- h3
```

---

## Files Description

| File Name        | Description                                                  |
| ---------------- | ------------------------------------------------------------ |
| `fruit_server.c` | TCP server program maintaining fruit stock and customer list |
| `fruit_client.c` | TCP client program for purchasing fruits                     |
| `README.md`      | Documentation of the assignment                              |

---

## Steps to Execute

### 1. Create Mininet Topology

```bash
sudo mn --topo single,3
```

This creates 3 hosts (`h1`, `h2`, `h3`) connected to a single switch.

Open terminals for each host:

```bash
mininet> xterm h1 h2 h3
```

---

### 2. Compile the Server (on h1)

```bash
gcc fruit_server.c -o fruit_server -lpthread
```

### 3. Run the Server (on h1)

```bash
./fruit_server
```

The server runs in an infinite loop to handle multiple clients.

---

### 4. Compile the Client (on h2 / h3)

```bash
gcc fruit_client.c -o fruit_client
```

### 5. Run the Client (on h2 or h3)

```bash
./fruit_client
```

---

## Sample Client Interaction

### Case 1: Fruit Not Available

```
Enter fruit name: Apple
Enter quantity: 90

---- Server Response ----
ERROR: Fruit not found.
```

### Case 2: Successful Transaction

```
Enter fruit name: apple
Enter quantity: 10

---- Server Response ----
SUCCESS: 10 apple sold.
Remaining stock: 35
Last sold time updated.
Unique customers: 3
```

---

## Server Features Implemented

* Maintains **shared fruit inventory**
* Updates **quantity and timestamp** after every sale
* Rejects invalid or unavailable requests
* Tracks **unique customers using IP and port**
* Displays **total unique customers** after each transaction
* Supports **multiple clients sequentially** using `accept()`

---

## Learning Outcomes

* Understanding of **TCP client–server communication**
* Handling **multiple client connections** via sockets
* Maintaining **shared server-side data**
* Using **Mininet** for network emulation
* Practical experience with **socket APIs**: `socket()`, `bind()`, `listen()`, `accept()`, `connect()`

---

## Conclusion

This assignment demonstrates a real-world TCP socket application where multiple clients interact with a centralized server, reinforcing concepts of networking, concurrency handling, and state management in C.

---

**Author:** MCA Student
**Course:** Computer Networks / Socket Programming Assignment


