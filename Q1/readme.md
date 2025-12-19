# Q1 – Forged UDP Packet with Incorrect Checksum (Raw Socket Programming)

## Objective

Standard OS networking stacks automatically generate and validate protocol headers. In this task, the goal is to **bypass the OS networking stack** and **manually forge a packet** with intentional errors in order to observe how lower network layers respond to corrupted data.

This experiment demonstrates raw socket programming, manual header construction, checksum manipulation, and packet analysis using Wireshark.

---

## Task Description

Create a **C program using raw sockets** that performs the following:

1. **Manually construct protocol headers**:

   * Ethernet Header
   * IPv4 Header
   * UDP Header

2. **Intentionally compute an incorrect UDP checksum** and insert it into the UDP header.

3. **Payload requirements**:

   * Your **Roll Number**
   * Current **system username**
   * Current **system time**

4. **Network topology**:

   * Two hosts: `h1` and `h2`
   * One switch connecting both hosts

5. **Execution**:

   * Run the raw socket program on `h1`
   * Send the forged packet to `h2`

6. **Packet analysis**:

   * Capture packets on `h2` using **Wireshark**
   * Verify that Wireshark reports:

     * `UDP Checksum: Incorrect`
     * Your Roll Number visible in the UDP payload

---

## Topology Setup (Mininet)

```bash
sudo mn --topo single,2 --mac --switch ovsk --controller none
```

This creates:

* `h1` and `h2`
* A single Open vSwitch connecting both hosts

Open terminals for both hosts:

```bash
xterm h1 h2
```

---

## Compilation

Since raw sockets require elevated privileges, compile and run the program as follows:

```bash
gcc bad_udp.c -o forge
```

> ⚠️ Ensure the program is compiled on **h1** inside Mininet or on the host with proper interface access.

---

## Execution

Run the program on **h1**:

```bash
sudo ./forge
```

The program:

* Crafts Ethernet, IP, and UDP headers manually
* Inserts an **invalid UDP checksum**
* Sends the packet directly to `h2` using a raw socket

---

## Packet Capture (Wireshark)

On **h2**, start Wireshark:

```bash
sudo wireshark &
```

Steps:

1. Select the appropriate interface (e.g., `h2-eth0`)
2. Start capturing packets
3. Apply a display filter:

   ```
   udp
   ```
4. Select the received packet
5. Expand the **UDP section** in the Packet Details pane

---

## Expected Observation

In the Wireshark **Packet Details** pane, you should clearly see:

* **UDP Checksum: Incorrect** (highlighted warning)
* Payload containing:

  * Your **Roll Number**
  * **Username** of the system
  * **Timestamp** of packet generation

---

## Submission Requirements

Submit the following:

* 📸 **Screenshot of Wireshark Packet Details pane** showing:

  * `UDP Checksum: [Incorrect]`
  * Your Roll Number in the UDP payload

Ensure the screenshot is clear and readable.

---

## Learning Outcomes

* Understanding raw socket programming in Linux
* Manual construction of Ethernet, IP, and UDP headers
* Checksum calculation and error injection
* Observing protocol behavior under corruption
* Practical packet analysis using Wireshark

---

## Notes

* Raw sockets require **root privileges**.
* Incorrect checksum packets may be dropped by some network stacks unless captured at the link layer.
* This experiment is intended strictly for **academic and educational purposes**.

---

**Course:** Computer Networks Lab
**Question:** Q1 – Forged Packet with Incorrect UDP Checksum

