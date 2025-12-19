# UDP Socket Programming – Assignment 3

## Objective

To gain hands-on experience with **UDP socket programming** by implementing a simple client–server application and understanding connectionless communication.

---

## Exercise

Redo **Assignment 2** using **UDP sockets** instead of TCP.

The application demonstrates:

* A UDP server that listens for client requests
* A UDP client that sends a request (fruit name and quantity)
* Server response with success or regret message based on availability
* Update of stock and last-sold timestamp

---

## Tools & Environment

* **Operating System:** Ubuntu (Linux)
* **Language:** C
* **Compiler:** gcc
* **Network Emulator:** Mininet
* **Terminals:** xterm

---

## Network Topology

* Two hosts: `h1` (Server), `h2` (Client)
* One switch: `s1`

Command used:

```bash
sudo mn --topo single,2 --arp
```

---

## Files Used

* `udp_server.c` – UDP server program
* `udp_client.c` – UDP client program

---

## Compilation Steps

Open xterm for both hosts:

```bash
mininet> xterm h1 h2
```

### On h1 (Server)

```bash
gcc udp_server.c -o udp_server
./udp_server
```

Expected output:

```
UDP Server running on port 8080...
Client requested: apple 3
```

### On h2 (Client)

```bash
gcc udp_client.c -o udp_client
./udp_client 10.0.0.1 8080 apple 3
```

Expected output:

```
Server: Success: apple sold. Remaining: 7
Last Sold: Sat Nov 29 12:09:19 2025
```

---

## Program Flow

1. Server starts and binds to a UDP port.
2. Client sends a request containing fruit name and quantity.
3. Server checks availability.
4. If available, quantity is reduced and timestamp updated.
5. If not available, server sends a regret message.
6. Client displays server response.

---

## Key Differences: TCP vs UDP

| Feature     | TCP                 | UDP            |
| ----------- | ------------------- | -------------- |
| Connection  | Connection-oriented | Connectionless |
| Reliability | Reliable            | Not guaranteed |
| Speed       | Slower              | Faster         |
| Use case    | File transfer       | Streaming, DNS |

---

## Output Screenshot

> Refer to the attached screenshot showing Mininet topology, server output on `h1`, and client output on `h2`.

---

## Learning Outcomes

1. Understand **UDP socket creation and communication**.
2. Learn **connectionless client–server interaction**.
3. Gain experience using **Mininet for network emulation**.
4. Understand differences between **TCP and UDP**.

---

## Conclusion

This assignment provides practical exposure to UDP socket programming and highlights how data can be exchanged efficiently without establishing a connection, making UDP suitable for lightweight and fast network applications.


```bash
  npm install my-project
  cd my-project
```
    
