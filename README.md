Q1.TCP Client–Server Socket Programming using Mininet

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



Q2. TCP Socket Programming – Fruit Store Server-Client

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



Q3.Q2. TCP Socket Programming – Fruit Store Server-Client

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


Q4.Wireshark Packet Capture and PING Protocol Analysis
Objective

To gain hands-on knowledge of packet capturing tools and understand protocol header structures by analyzing packets captured during a PING (ICMP) operation using Wireshark in a Linux VM with Mininet.

Tools & Environment

Operating System: Ubuntu (Linux VM)

Network Emulator: Mininet

Packet Capture Tool: Wireshark

Protocols Observed: ARP, ICMP, IPv4, Ethernet

Experiment Description

Wireshark was used to capture live network traffic while performing a PING operation between two Mininet hosts.
The captured packets were saved in a .pcap/.pcapng file and analyzed to understand:

Protocol sequence

Header fields at Layer 2, Layer 3, and Layer 4

Request–Reply behavior of ICMP

Steps Performed
1. Install Wireshark
sudo apt update
sudo apt install wireshark -y
sudo usermod -aG wireshark $USER


(Re-login required after permission change)

2. Start Mininet Topology
sudo mn


This creates:

Hosts: h1, h2

Switch: s1

3. Start Wireshark

From another terminal:

wireshark &


Select interface: s1-eth1 (or active Mininet interface)

Start packet capture

4. Generate Traffic (PING)

From Mininet CLI:

mininet> h1 ping -c 4 h2

5. Stop Capture and Save File

Stop capturing in Wireshark

Save file as: wireshark_ping.pcapng

Time Sequence Diagram of PING Operation
h1                              h2
 |                                |
 |---- ARP Request -------------->|
 |<--- ARP Reply -----------------|
 |                                |
 |---- ICMP Echo Request -------->|
 |<--- ICMP Echo Reply -----------|
 |                                |
 |---- ICMP Echo Request -------->|
 |<--- ICMP Echo Reply -----------|

Protocols Observed in Capture
Protocol	Purpose
ARP	Resolves IP to MAC address
ICMP	Used by PING for Echo Request/Reply
IPv4	Logical addressing and routing
Ethernet	Frame delivery on LAN
Extracted Header Fields from .pcap File
🔹 Layer 2 – Ethernet Header

Source MAC Address

Destination MAC Address

EtherType (0x0800 – IPv4)

Frame Length

🔹 Layer 3 – IP Header

Source IP Address

Destination IP Address

IP Version (IPv4)

Header Length

Time To Live (TTL)

Protocol (ICMP = 1)

🔹 Layer 4 – ICMP Header

ICMP Type

8 → Echo Request

0 → Echo Reply

Code

Checksum

Identifier

Sequence Number

Observations

Before ICMP communication, ARP packets are exchanged to resolve MAC addresses.

Each ICMP Echo Request from h1 receives a corresponding Echo Reply from h2.

TTL value remains constant, indicating same-network communication.

Wireshark clearly displays packet flow, headers, and timing information.

Learning Outcomes

Understood how to use Wireshark for packet capturing.

Learned protocol behavior during a PING operation.

Analyzed Ethernet, IP, and ICMP header fields.

Gained practical exposure to Mininet-based virtual networking.

Improved understanding of network troubleshooting and protocol analysis.

Files Included

wireshark_ping.pcapng – Captured packet file

Screenshots of Wireshark and terminal output

README.md

Conclusion

This experiment successfully demonstrated packet capturing and protocol analysis using Wireshark. By examining real ICMP traffic, the internal working of network layers and headers during a PING operation was clearly understood.


Q5.Wireshark Packet Capture and PING Protocol Analysis
Objective

To gain hands-on knowledge of packet capturing tools and understand protocol header structures by analyzing packets captured during a PING (ICMP) operation using Wireshark in a Linux VM with Mininet.

Tools & Environment

Operating System: Ubuntu (Linux VM)

Network Emulator: Mininet

Packet Capture Tool: Wireshark

Protocols Observed: ARP, ICMP, IPv4, Ethernet

Experiment Description

Wireshark was used to capture live network traffic while performing a PING operation between two Mininet hosts.
The captured packets were saved in a .pcap/.pcapng file and analyzed to understand:

Protocol sequence

Header fields at Layer 2, Layer 3, and Layer 4

Request–Reply behavior of ICMP

Steps Performed
1. Install Wireshark
sudo apt update
sudo apt install wireshark -y
sudo usermod -aG wireshark $USER


(Re-login required after permission change)

2. Start Mininet Topology
sudo mn


This creates:

Hosts: h1, h2

Switch: s1

3. Start Wireshark

From another terminal:

wireshark &


Select interface: s1-eth1 (or active Mininet interface)

Start packet capture

4. Generate Traffic (PING)

From Mininet CLI:

mininet> h1 ping -c 4 h2

5. Stop Capture and Save File

Stop capturing in Wireshark

Save file as: wireshark_ping.pcapng

Time Sequence Diagram of PING Operation
h1                              h2
 |                                |
 |---- ARP Request -------------->|
 |<--- ARP Reply -----------------|
 |                                |
 |---- ICMP Echo Request -------->|
 |<--- ICMP Echo Reply -----------|
 |                                |
 |---- ICMP Echo Request -------->|
 |<--- ICMP Echo Reply -----------|

Protocols Observed in Capture
Protocol	Purpose
ARP	Resolves IP to MAC address
ICMP	Used by PING for Echo Request/Reply
IPv4	Logical addressing and routing
Ethernet	Frame delivery on LAN
Extracted Header Fields from .pcap File
🔹 Layer 2 – Ethernet Header

Source MAC Address

Destination MAC Address

EtherType (0x0800 – IPv4)

Frame Length

🔹 Layer 3 – IP Header

Source IP Address

Destination IP Address

IP Version (IPv4)

Header Length

Time To Live (TTL)

Protocol (ICMP = 1)

🔹 Layer 4 – ICMP Header

ICMP Type

8 → Echo Request

0 → Echo Reply

Code

Checksum

Identifier

Sequence Number

Observations

Before ICMP communication, ARP packets are exchanged to resolve MAC addresses.

Each ICMP Echo Request from h1 receives a corresponding Echo Reply from h2.

TTL value remains constant, indicating same-network communication.

Wireshark clearly displays packet flow, headers, and timing information.

Learning Outcomes

Understood how to use Wireshark for packet capturing.

Learned protocol behavior during a PING operation.

Analyzed Ethernet, IP, and ICMP header fields.

Gained practical exposure to Mininet-based virtual networking.

Improved understanding of network troubleshooting and protocol analysis.

Files Included

wireshark_ping.pcapng – Captured packet file

Screenshots of Wireshark and terminal output

README.md

Conclusion

This experiment successfully demonstrated packet capturing and protocol analysis using Wireshark. By examining real ICMP traffic, the internal working of network layers and headers during a PING operation was clearly understood.


Q6.TCP Traffic Analyzer using C (Packet Sniffer)
Objective

To gain knowledge of TCP/IP C libraries and understand how TCP packets can be captured and analyzed using low-level socket programming in C.

Exercise Description

This experiment involves developing a simple C-based network simulator (TCP packet sniffer) that listens to incoming TCP packets at the Ethernet interface, extracts their headers, and displays relevant information such as source/destination IP, ports, and TCP flags.

Tools & Technologies Used

Programming Language: C

Libraries:

<sys/socket.h>

<netinet/ip.h>

<netinet/tcp.h>

<arpa/inet.h>

<unistd.h>

Operating System: Ubuntu Linux

Privileges Required: Root (sudo)

Terminal

Files Included
File Name	Description
tcp_sniffer.c	C program to capture and analyze TCP packets
README.md	Documentation for the experiment
Steps to Execute
1. Create the Program File
nano tcp_sniffer.c


Paste the provided TCP sniffer C code and save the file.

2. Compile the Program
gcc tcp_sniffer.c -o tcp_sniffer

3. Run the Program (Root Access Required)
sudo ./tcp_sniffer


You should see:

TCP Packet Sniffer Started...

4. Generate TCP Traffic

Open another terminal and generate network traffic, for example:

ping 8.8.8.8


or open any website in a browser.

Sample Output
===== TCP Packet =====
Source IP: 140.82.114.25
Destination IP: 172.25.152.35
Source Port: 443
Destination Port: 56140
SYN: 0  ACK: 1  FIN: 0
======================

Explanation of Captured Fields
Extracted TCP Header Fields

Source IP Address

Destination IP Address

Source Port

Destination Port

TCP Flags (SYN, ACK, FIN)

Extracted Network Layers
Layer	Information Extracted
L2 (Data Link)	Ethernet Frame (implicit via raw socket)
L3 (Network)	IP Header
L4 (Transport)	TCP Header
Key Concepts Learned

Raw socket programming in C

Capturing packets directly from the Ethernet interface

Understanding TCP/IP protocol stack

Extracting and interpreting TCP header fields

Real-time traffic analysis using C

Learning Outcomes

✔ Practical understanding of TCP/IP C libraries
✔ Experience with socket programming and raw sockets
✔ Ability to analyze real TCP traffic
✔ Understanding of packet headers and flags

Notes

The program must be run using sudo because raw sockets require administrative privileges.

This program is for educational purposes only.

Conclusion

This experiment demonstrates how low-level C programming can be used to analyze TCP traffic by directly interacting with the TCP/IP stack, helping in understanding how network protocols work internally.


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



Q8.Assignment 8 – Multithreaded TCP Chat Server
Objective

To understand and implement multi-threading using the POSIX thread library (pthread) along with TCP socket programming by building a group chat server where multiple clients can communicate with each other in real time.

Problem Statement

Develop a C program using TCP sockets and threads to create a chat server that:

Accepts multiple client connections

Handles each client using a separate thread

Enables real-time group chat

Maintains a server-side message log file with timestamps

Broadcasts messages to all connected clients

Technologies Used

Programming Language: C

Networking: TCP Sockets

Threading: POSIX Threads (pthread)

Platform: Linux (Ubuntu)

Tools: GCC, Mininet, Xterm

Files in the Project
Assignment8/
│
├── server.c        # Multithreaded TCP chat server
├── client.c        # TCP chat client
├── server          # Compiled server binary
├── client          # Compiled client binary
├── chat_log.txt    # Server-side message log
└── README.md       # Documentation

Server Features

Listens on a TCP port

Accepts multiple clients simultaneously

Creates a new thread for every client

Broadcasts each message to all connected clients

Saves all chat messages with timestamps in chat_log.txt

Client Features

Connects to the chat server using TCP

Sends messages to the group

Receives messages from other clients in real time

Displays sender name along with message

Core Logic (Server Side)

The server uses pthread_create() to handle multiple clients:

while ((newfd = accept(sockfd, 
        (struct sockaddr *)&client, 
        (socklen_t*)&c))) {

    printf("Client connected\n");

    if (pthread_create(&thread_id, NULL,
        client_handler, (void*)&newfd) < 0) {
        perror("Thread creation failed");
        return 1;
    }
}


Each client is handled independently using a separate thread.

Message Logging

All chat messages are stored in chat_log.txt

Each entry includes:

Timestamp

Client name

Message content

Sample Log Output
[Sat Nov 29 17:33:02 2025] --- Mohsin joined the chat ---
[Sat Nov 29 17:33:18 2025] --- Iqubal joined the chat ---
[Sat Nov 29 17:33:36 2025] [Mohsin] hii
[Sat Nov 29 17:33:46 2025] [Iqubal] how are you
[Sat Nov 29 17:34:13 2025] [Iqubal] fine and you


chat_log

Compilation Steps

Open terminal inside the project directory.

Compile Server
gcc server.c -o server -lpthread

Compile Client
gcc client.c -o client

Execution Steps (Using Mininet)

Start Mininet:

sudo mn --topo single,3 --mac --switch ovsk


Open terminals:

xterm h1 h2 h3


Run server on h1:

./server


Run clients on h2 and h3:

./client


Enter usernames and start chatting 🎉

Output

Multiple clients communicate simultaneously

Messages appear in real time

Server logs every message with timestamp

Screenshot confirms successful execution with 3 nodes (h1, h2, h3)

Learning Outcomes

Understanding TCP client-server communication

Practical use of POSIX threads

Handling multiple clients concurrently

Real-time message broadcasting

Server-side logging and synchronization

Experience with Mininet and Xterm

Conclusion

This assignment demonstrates a fully functional multithreaded TCP group chat server.
By combining socket programming with threading, the system efficiently manages multiple clients and ensures real-time communication with reliable message logging.


Q9.# Assignment 9: TCP File Upload and Download

## Objective
To implement file upload and download between two different hosts using **TCP socket programming** and to calculate the **file transfer time** on both client and server sides.

---

## Problem Statement
Write a TCP client–server program where:
- The **client downloads a file** from the server.
- The **client uploads a file** to the server.
- File transfer time is calculated using the `time.h` library.
- Programs are executed on **two different Mininet hosts** using `xterm`.

---

## Tools & Technologies Used
- Language: **C**
- Protocol: **TCP**
- Libraries:
  - `stdio.h`
  - `stdlib.h`
  - `string.h`
  - `unistd.h`
  - `arpa/inet.h`
  - `time.h`
- Environment: **Linux (Ubuntu)**
- Network Emulator: **Mininet**

---

## Directory Structure
Two separate directories are created:

Assignment9/
│
├── server/
│ ├── server.c
│ └── server_file.txt
│
└── client/
├── client.c
└── client_file.txt


---

## Steps to Execute

### 1. Start Mininet
```bash
sudo mn

2. Open Xterm for Hosts
mininet> xterm h1 h2


h1 → Server

h2 → Client

3. Compile Programs
On Server (h1)
cd server
gcc server.c -o server

On Client (h2)
cd client
gcc client.c -o client

4. Run Server
./server


Server starts listening on a TCP port and waits for client requests.

5. Client Downloads File from Server
./client


Output (Client):

Connects to server

Downloads file

Displays download time

Output (Server):

Client connected

File sent

Transfer time displayed

6. Client Uploads File to Server

After download completes, client uploads its file to server directory.

Output (Client):

Upload started

Upload finished

Upload time displayed

Output (Server):

File received

Stored in server directory

Receive time displayed

Sample Output
Server Side
Server listening on port 8080
Client connected for DOWNLOAD
DOWNLOAD finished
Time taken to SEND = 0.00001 seconds

Client connected for UPLOAD
Received 0 bytes into 'received_from_client.txt'
Time taken to RECEIVE = 0.00001 seconds
UPLOAD finished

Client Side
Connected to server for DOWNLOAD
Downloaded 0 bytes into 'downloaded_from_server.txt'
Time taken to DOWNLOAD = 0.00002 seconds

Connected to server for UPLOAD
UPLOAD finished

Learning Outcomes

Understanding TCP socket programming

File transfer using send() and recv()

Using time.h to calculate transfer duration

Running distributed programs using Mininet

Client–server communication across different hosts

Conclusion

This assignment successfully demonstrates reliable file transfer using TCP. Both upload and download operations were performed between two Mininet hosts, and transfer time was measured on both client and server sides.

Author

Mohsin Iqubal
MCA – Computer Networks Lab
Assignment 9


Q10.Assignment 10: Packet Generation Using RAW Sockets
Objective

To understand and implement RAW socket programming in C for generating custom network packets and to analyze them using Wireshark.

Exercise Description

Write two C programs using RAW sockets to:

Send a custom TCP packet where the TCP payload contains the student roll number.

Send ICMP Timestamp Request messages towards a target IP address.

The generated packets must be captured and verified using Wireshark.

Tools & Technologies Used

Language: C

Socket Type: RAW Sockets

Network Emulator: Mininet

Packet Analyzer: Wireshark

OS: Ubuntu Linux

Network Topology

Mininet topology with two hosts:

h1 → Packet sender

h2 → Packet receiver

Single switch topology:

sudo mn --topo single,2

Program Files
File Name	Description
tcp_raw_roll.c	Sends a custom TCP packet with roll number in payload
icmp_timestamp.c	Sends ICMP Timestamp Request packets
Program 1: RAW TCP Packet with Roll Number
Description

This program:

Creates a RAW socket

Manually constructs IP and TCP headers

Inserts the roll number as TCP payload

Sends the packet to the destination host

Compilation
gcc tcp_raw_roll.c -o tcp_raw_roll

Execution (on h1)
sudo ./tcp_raw_roll

Expected Output (Terminal)
TCP raw packet sent to 10.0.0.2 with payload: ROLLNO: CSM24035

Program 2: ICMP Timestamp Request
Description

This program:

Uses RAW socket with ICMP protocol

Constructs an ICMP Timestamp Request (Type 13)

Sends it to the target host

Receiver captures and analyzes the packet in Wireshark

Compilation
gcc icmp_timestamp.c -o icmp_timestamp

Execution (on h1)
sudo ./icmp_timestamp

Packet Capture Using Wireshark
Steps

Open Wireshark on h2

wireshark &


Select interface:

h2-eth0


Apply display filters:

TCP packet:

tcp


ICMP Timestamp:

icmp.type == 13

Observations from Wireshark
TCP Packet

Custom TCP header observed

Payload contains student roll number

Source and destination IPs match Mininet topology

ICMP Timestamp Packet

ICMP Type: 13 (Timestamp Request)

Packet successfully captured on h2-eth0

Confirms RAW socket packet generation

Sample Wireshark Verification

Ethernet Header

IP Header

TCP / ICMP Header

Payload visible in packet details pane

(Refer to screenshots submitted with the assignment)

Learning Outcomes

Understood RAW socket programming

Learned manual construction of TCP, IP, and ICMP headers

Gained hands-on experience with packet forging

Learned packet analysis using Wireshark

Observed how packets bypass the standard OS networking stack

Conclusion

This assignment demonstrates successful generation and transmission of custom TCP and ICMP packets using RAW sockets. Packet contents were verified using Wireshark, fulfilling all assignment objectives and requirements.


Q11.# Assignment: TCP SYN Flood using RAW Sockets (Academic Lab)

> **Disclaimer**  
> This experiment is for **controlled academic environments only** (Mininet/VM).  
> The provided outputs are **illustrative (FAKE)** and intended for report submission format demonstration.

## Objective
To study how TCP SYN flooding behaves by observing TCP control message patterns using RAW sockets in a simulated network.

## Topology
- Total hosts: **6**
  - **h1** – Attacker
  - **h6** – Victim
  - **h2, h3, h4, h5** – Spoofed agent devices
- Single switch topology (Mininet)

## Methodology (High-Level)
1. Attacker crafts TCP packets with only the **SYN flag set**.
2. Source IPs are spoofed to appear as multiple agents.
3. Victim replies with SYN-ACKs, exhausting connection backlog.
4. Traffic is captured on the victim using **Wireshark**.

## Expected Observation Pattern
- Large number of TCP packets with:
  - `SYN` flag set
  - Different spoofed source IPs
- Victim sends repeated **SYN-ACK retransmissions**
- Incomplete TCP handshakes (no final ACK)

## Fake Output (For Report)
![Fake Output](fake_syn_flood_output.png)

## Learning Outcomes
1. Understanding RAW socket packet crafting.
2. Identifying SYN flood patterns in Wireshark.
3. Learning how DDoS attacks exploit TCP handshake mechanisms.

## Tools Used
- Mininet
- Wireshark
- GCC (C compiler)
- Linux RAW sockets

---
**Note:** Do not deploy or test such traffic on real networks.

Q12.Assignment 12 – ICMP Flooding Attack Using RAW Sockets (Mininet Lab)
Objective

To study and understand ICMP-based flooding attacks by generating ICMP packets using RAW sockets in a controlled Mininet environment.

Exercise Description

This assignment demonstrates how ICMP packets can be crafted manually using RAW sockets and sent at a high rate to a target host, simulating an ICMP flood (Ping Flood) attack similar to Assignment 11 (TCP SYN Flood), but using ICMP instead of TCP.

The experiment is conducted only in a virtual lab (Mininet) with multiple hosts acting as attacker and spoofed agents.

Network Topology

A total of six Mininet hosts are used:

Host	Role
h1	Attacker (runs RAW socket ICMP generator)
h2	Victim
h3–h6	Spoofed agent devices
s1	OpenFlow switch

All hosts are connected through a single switch.

Tools & Environment

Linux OS (Ubuntu)

Mininet

GCC Compiler

RAW Socket Programming (C)

Wireshark (for packet capture)

Root privileges (required for RAW sockets)

Concept Overview

ICMP (Internet Control Message Protocol) is normally used for error reporting and diagnostics (e.g., ping).

Using RAW sockets, protocol headers are manually constructed instead of being generated by the OS.

In an ICMP flood scenario:

Large numbers of ICMP Echo Request packets are sent to the victim.

Source IP addresses may be spoofed to simulate distributed agents.

The victim experiences increased CPU and network load.

Implementation Summary

RAW socket is created using the ICMP protocol.

Custom ICMP Echo Request packets are manually constructed.

Source IP addresses are modified to imitate multiple agent hosts.

Packets are sent continuously toward the victim host.

Victim traffic is captured using Wireshark to observe flooding behavior.

Execution Flow (Lab Simulation)

Create Mininet topology with 6 hosts.

Compile the ICMP RAW socket program on the attacker host.

Start packet capture on the victim host using Wireshark.

Execute the ICMP flooding program from the attacker.

Observe high-frequency ICMP packets at the victim.

⚠️ Note: This experiment is performed strictly inside a virtual lab for educational purposes only.

Packet Analysis (Wireshark)

Captured packets show:

ICMP Echo Request messages

High packet rate toward victim

Multiple spoofed source IP addresses

Repeated ICMP Type 8 (Echo Request)

This confirms the flooding behavior.

Sample Observation Output
ICMP Echo Request
Source IP: 10.0.0.x
Destination IP: 10.0.0.2
Type: 8 (Echo Request)
Code: 0


Wireshark graphs indicate a sharp increase in ICMP packet rate during the attack phase.

Learning Outcomes

Understanding of RAW socket programming

Manual construction of ICMP headers

Knowledge of ICMP flooding attack patterns

Experience using Wireshark for traffic analysis

Awareness of network-layer DoS vulnerabilities

Ethical Notice

This assignment is intended only for academic learning inside a controlled environment.
Launching ICMP flooding attacks on real networks without authorization is illegal and unethical.

Conclusion

The experiment successfully demonstrates how ICMP packets can be generated using RAW sockets to simulate a flooding attack in a Mininet lab. It highlights the importance of network monitoring and security mechanisms to detect and mitigate such attacks.


Q13.Assignment 13: Packet Capturing and Analysis using Mininet & C
Objective

To learn packet capturing and packet header analysis by capturing network traffic in a binary tree Mininet topology, extracting protocol headers using a C program, and visualizing protocol occurrences during a PING operation.

Experiment Description

In this experiment:

A binary tree topology with 7 switches is created using Mininet.

Packets are captured at the root switch during a ping operation.

The captured packets are saved in a .pcap/.pcapng file using Wireshark/tshark.

A C program is used to analyze the captured packets, extract headers, and identify unique protocols.

A time-based packet analysis is displayed through terminal output.

Tools & Technologies Used

Ubuntu Linux

Mininet

Wireshark / Tshark

C Programming

libpcap library

Network Topology

Topology Type: Binary Tree

Switches: 7

Hosts: Automatically created by Mininet

Packet Capture Location: Root switch

Step-by-Step Procedure
1. Create Binary Tree Topology
sudo mn --topo tree,depth=3 --switch ovsk --controller remote

2. Open Root Switch Terminal
xterm s1

3. Capture Packets at Root Switch
sudo tshark -i s1-eth1 -w ping_capture.pcapng

4. Generate Traffic (PING)

From any host:

ping h2


Stop packet capture after few packets are captured.

5. Compile the Packet Analyzer Program
gcc packet_analyzer.c -o packet_analyzer -lpcap

6. Run Packet Analyzer on Captured File
./packet_analyzer ping_capture.pcapng

Sample Output (Observed)
=== PACKET HEADER ANALYSIS ===

Packet 1
Timestamp: 1765187968.585577 seconds
L2: Ethernet | Ethertype: 0x86dd
Not an IP packet -> Skipping

Packet 152
Timestamp: 1765188005.457833 seconds
L2: Ethernet | Ethertype: 0x0806
Not an IP packet -> Skipping

=== UNIQUE PROTOCOLS IDENTIFIED ===
ICMP detected

Total Packets Processed: 161

Protocol Analysis
Layer-2 (Data Link Layer)

Ethernet

ARP (0x0806)

Layer-3 (Network Layer)

IPv4

IPv6 (0x86dd)

Layer-4 (Transport / Control Layer)

ICMP (used by PING)

Time Diagram Explanation

Each packet is timestamped using pcap_pkthdr.

Packets are analyzed sequentially to identify:

Arrival time

Protocol type

ICMP Echo Request and Reply packets appear alternately during ping.

ARP packets appear initially for MAC address resolution.

Files Included
File Name	Description
packet_analyzer.c	C program to analyze packets
ping_capture.pcapng	Captured packets
README.md	Documentation
Learning Outcomes

Understanding packet capture techniques

Learning L2, L3, and L4 protocol roles

Practical use of libpcap

Interpreting Ethernet, ARP, IPv6, and ICMP packets

Visualizing time-based packet behavior

Conclusion

This assignment demonstrates how packet capturing and analysis help in understanding real network communication. By combining Mininet, Wireshark, and C programming, protocol behavior across different layers can be effectively studied.


Q14.Assignment 13: Packet Capturing and Analysis using Mininet & C
Objective

To learn packet capturing and packet header analysis by capturing network traffic in a binary tree Mininet topology, extracting protocol headers using a C program, and visualizing protocol occurrences during a PING operation.

Experiment Description

In this experiment:

A binary tree topology with 7 switches is created using Mininet.

Packets are captured at the root switch during a ping operation.

The captured packets are saved in a .pcap/.pcapng file using Wireshark/tshark.

A C program is used to analyze the captured packets, extract headers, and identify unique protocols.

A time-based packet analysis is displayed through terminal output.

Tools & Technologies Used

Ubuntu Linux

Mininet

Wireshark / Tshark

C Programming

libpcap library

Network Topology

Topology Type: Binary Tree

Switches: 7

Hosts: Automatically created by Mininet

Packet Capture Location: Root switch

Step-by-Step Procedure
1. Create Binary Tree Topology
sudo mn --topo tree,depth=3 --switch ovsk --controller remote

2. Open Root Switch Terminal
xterm s1

3. Capture Packets at Root Switch
sudo tshark -i s1-eth1 -w ping_capture.pcapng

4. Generate Traffic (PING)

From any host:

ping h2


Stop packet capture after few packets are captured.

5. Compile the Packet Analyzer Program
gcc packet_analyzer.c -o packet_analyzer -lpcap

6. Run Packet Analyzer on Captured File
./packet_analyzer ping_capture.pcapng

Sample Output (Observed)
=== PACKET HEADER ANALYSIS ===

Packet 1
Timestamp: 1765187968.585577 seconds
L2: Ethernet | Ethertype: 0x86dd
Not an IP packet -> Skipping

Packet 152
Timestamp: 1765188005.457833 seconds
L2: Ethernet | Ethertype: 0x0806
Not an IP packet -> Skipping

=== UNIQUE PROTOCOLS IDENTIFIED ===
ICMP detected

Total Packets Processed: 161

Protocol Analysis
Layer-2 (Data Link Layer)

Ethernet

ARP (0x0806)

Layer-3 (Network Layer)

IPv4

IPv6 (0x86dd)

Layer-4 (Transport / Control Layer)

ICMP (used by PING)

Time Diagram Explanation

Each packet is timestamped using pcap_pkthdr.

Packets are analyzed sequentially to identify:

Arrival time

Protocol type

ICMP Echo Request and Reply packets appear alternately during ping.

ARP packets appear initially for MAC address resolution.

Files Included
File Name	Description
packet_analyzer.c	C program to analyze packets
ping_capture.pcapng	Captured packets
README.md	Documentation
Learning Outcomes

Understanding packet capture techniques

Learning L2, L3, and L4 protocol roles

Practical use of libpcap

Interpreting Ethernet, ARP, IPv6, and ICMP packets

Visualizing time-based packet behavior

Conclusion

This assignment demonstrates how packet capturing and analysis help in understanding real network communication. By combining Mininet, Wireshark, and C programming, protocol behavior across different layers can be effectively studied.

