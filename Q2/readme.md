# Q2 – TCP Bandwidth Competition Under Congestion (Mininet Analysis)

## Objective

Network performance varies significantly under congestion due to TCP’s congestion control mechanisms. This experiment analyzes how **multiple concurrent TCP streams compete for bandwidth** over a constrained link using Mininet.

You will generate traffic using multiple parallel TCP connections and observe bandwidth sharing behavior through **Wireshark IO Graphs**.

---

## Task Description

1. Create a **Mininet topology** with:

   * Two hosts: `h1` (server) and `h2` (client)
   * A single link of **10 Mbps bandwidth**

2. Implement a **TCP server on h1** that:

   * Accepts multiple simultaneous client connections
   * Logs:

     * Size of every received chunk
     * High‑resolution timestamp (microsecond precision)

3. Implement a **TCP client on h2** that:

   * Creates **8 concurrent threads**
   * Each thread sends a **unique 2 MB buffer** simultaneously to the server

4. Capture packets and:

   * Generate a **Wireshark IO Graph** showing throughput of all 8 TCP streams
   * Submit the **pcap file** along with the graph

---

## Files Included

* `tcp_congestion.py` – Mininet topology script (10 Mbps link)
* `server.c` – Multi‑connection TCP server with timestamped logging
* `client.c` – Multi‑threaded TCP client (8 parallel streams)

---

## Mininet Topology Setup

Run the Mininet script:

```bash
sudo python3 tcp_congestion.py
```

This creates:

* `h1` and `h2`
* A single 10 Mbps link using `TCLink`

Open terminals inside Mininet:

```bash
xterm h1 h2
```

---

## Compilation

### On h1 (Server)

```bash
gcc server.c -o server
```

### On h2 (Client)

```bash
gcc client.c -o client -lpthread
```

> ⚠️ POSIX threads (`pthread`) are required for concurrent client streams.

---

## Execution

### Step 1: Start Server on h1

```bash
./server
```

The server:

* Listens for multiple TCP connections
* Logs received chunk size and timestamp (µs resolution)

### Step 2: Start Client on h2

```bash
./client
```

The client:

* Spawns **8 concurrent threads**
* Each thread sends **2 MB of unique data** simultaneously

---

## Packet Capture (Wireshark)

Start Wireshark on `h2` or the Mininet interface:

```bash
sudo wireshark &
```

Capture steps:

1. Select the interface (e.g., `h2-eth0`)
2. Start capture before running the client
3. Apply display filter:

   ```
   tcp
   ```
4. Stop capture after all transfers complete
5. Save capture as:

   ```
   tcp_congestion.pcap
   ```

---

## IO Graph Generation

In Wireshark:

1. Go to **Statistics → IO Graphs**
2. Configure:

   * Y Axis: Bits/Tick
   * Tick Interval: 0.1 sec or 1 sec
3. Use separate filters for each TCP stream (example):

   ```
   tcp.stream == 0
   tcp.stream == 1
   ...
   tcp.stream == 7
   ```
4. Plot all 8 streams together to observe bandwidth sharing

---

## Expected Observation

* Total throughput is limited to **~10 Mbps**
* Bandwidth is dynamically shared among 8 TCP streams
* Throughput fluctuates due to TCP congestion control
* Streams converge toward fair bandwidth allocation

---

## Submission Requirements

Submit the following:

* 📊 **Wireshark IO Graph screenshot** showing throughput of all 8 TCP streams
* 📁 **Packet capture file (`.pcap`)**
* 📄 This `README.md`

---

## Learning Outcomes

* Understanding TCP congestion and fairness
* Observing bandwidth competition in constrained networks
* Multi‑threaded socket programming
* Practical traffic analysis using Wireshark IO Graphs

---

## Notes

* Ensure Wireshark capture starts **before** client execution
* Run all commands inside Mininet hosts
* This experiment is strictly for **academic and educational purposes**

---

**Course:** Computer Networks Lab
**Question:** Q2 – TCP Congestion and Bandwidth Competition

