# TCP Client–Server Socket Programming using Mininet

## Objective

To gain first hands-on experience with basic TCP socket programming by implementing a simple client–server model where:

* The **client** sends the message **"Hi"**
* The **server** responds with **"Hello"**

---

## Exercise Description

Write TCP client and server socket programs and execute them on two different Mininet hosts.

### Communication Flow

1. TCP Server starts and waits for a connection.
2. TCP Client connects to the server.
3. Client sends message: `Hi`
4. Server receives the message and replies with: `Hello`

---

## Tools & Technologies Used

* **Language:** C
* **Networking API:** BSD Sockets
* **Network Emulator:** Mininet
* **OS:** Ubuntu Linux
* **Compiler:** gcc
* **Packet Observation (optional):** Wireshark

---

## Network Topology

* Two hosts: `h1` and `h2`
* One switch: `s1`

```
h1 ---- s1 ---- h2
```

---

## Files Included

```
Assignment1/
├── server.c   # TCP Server program
├── client.c   # TCP Client program
└── README.md
```

---

## Steps to Execute

### 1. Start Mininet

```bash
sudo mn --topo minimal
```

### 2. Open Xterm for Both Hosts

```bash
mininet> xterm h1 h2
```

---

### 3. Compile Programs

#### On **h1** (Server):

```bash
gcc server.c -o server
```

#### On **h2** (Client):

```bash
gcc client.c -o client
```

---

### 4. Run Server and Client

#### Start Server on **h1**:

```bash
./server
```

Output:

```
Server is waiting for connection...
Client says: Hi
```

#### Run Client on **h2**:

```bash
./client
```

Output:

```
Server says: Hello
```

---

## Sample Output Screenshot

The following output demonstrates successful TCP communication between client and server using Mininet hosts:

* Server receives `Hi`
* Client receives `Hello`

*(Screenshot attached in submission)*

---

## Learning Outcomes

After completing this assignment, I learned:

1. Basics of TCP socket programming in C
2. How to use `socket()`, `bind()`, `listen()`, `accept()`, `connect()`, `send()`, and `recv()`
3. Running distributed programs using Mininet hosts
4. Compiling and executing programs in isolated network environments
5. Understanding client–server communication flow over TCP

---

## Conclusion

This experiment successfully demonstrates a simple TCP client–server interaction using Mininet. It provides practical exposure to socket programming and helps understand how TCP-based communication works in a networked environment.

---

**End of Assignment**


