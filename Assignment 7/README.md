# Assignment 7: UDP Based Scientific Calculator (Client–Server)

## Objective
To understand **client–server communication using UDP packets** and analyze the **reliability of UDP** by detecting packet loss using **Wireshark** in a **Mininet environment**.

---

## Problem Statement
Develop a UDP-based client–server application where:
- The **client** sends one or two numbers along with a **scientific calculator operation**
- The **server** evaluates the operation using `math.h`
- The **server** sends the result back to the client
- Packet loss (if any) is detected using **UDP sequence numbers**
- Traffic is captured and analyzed using **Wireshark**

---

## Tools & Technologies Used
- **Language**: C  
- **Libraries**:  
  - `stdio.h`  
  - `stdlib.h`  
  - `string.h`  
  - `unistd.h`  
  - `arpa/inet.h`  
  - `math.h`  
- **Networking**: UDP Sockets  
- **Emulator**: Mininet  
- **Packet Analyzer**: Wireshark  
- **OS**: Ubuntu Linux  

---

## Supported Operations
The server supports the following scientific calculator operations:

| Operation | Description |
|---------|------------|
| `sin x` | Sine of x |
| `cos x` | Cosine of x |
| `tan x` | Tangent of x |
| `log x` | Logarithm (base 10) |
| `sqrt x` | Square root |
| `inv x` | Inverse (1/x) |
| `x + y` | Addition |
| `x - y` | Subtraction |
| `x * y` | Multiplication |
| `x / y` | Division |
| `pow x y` | Power (x^y) |

---

## Network Topology
- Two Mininet hosts:
  - **h1** → UDP Server
  - **h2** → UDP Client
- One virtual switch
- Communication via UDP on port **5555**

---

## File Structure
Assignment7/
├── server.c
├── client.c
└── README.md


---

## Compilation
Open Mininet and compile the programs:

```bash
gcc server.c -o server -lm
gcc client.c -o client

Execution Steps
Step 1: Start Mininet
sudo mn

Step 2: Open Terminals
mininet> xterm h1 h2

Step 3: Run Server on h1
./server


Server output:

Displays incoming packets

Shows request operation

Sends computed result

Maintains packet statistics

Step 4: Run Client on h2
./client


Client output:

Sends calculator expressions

Receives evaluated result

Maintains sent/received packet count

Example:

Enter operation: log 8
Server Result: 2.079442

UDP Packet Loss Detection

Each UDP packet carries a sequence number

Client and server maintain:

Packets sent

Packets received

Lost packets (if sequence mismatch occurs)

Sample Statistics Output
Stats: Sent=5, Received=5, Lost=0


This confirms no packet loss during the transaction.

Wireshark Analysis
Steps:

Run Wireshark on Mininet host interface

Start capture before running client

Apply filter:

udp.port == 5555


Observe:

UDP request packets

UDP response packets

No retransmissions (UDP behavior)

Observation:

All packets are delivered successfully

UDP does not guarantee delivery, but no loss occurred in this controlled setup

Output Screenshot

(Refer to the attached terminal screenshot showing client–server communication and statistics.)

Learning Outcomes

Understanding UDP socket programming

Handling scientific calculations over network

Observing unreliable nature of UDP

Detecting packet loss using sequence numbers

Analyzing UDP traffic using Wireshark

Practical exposure to Mininet-based networking

Conclusion

This experiment demonstrates how UDP-based client–server communication works for real-time applications like calculators. Although UDP does not ensure reliability, packet loss can be detected and monitored at the application level. Wireshark analysis confirms successful data exchange between hosts.

Author

Mohsin Iqubal
MCA – Computer Networks Lab

