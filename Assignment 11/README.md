# Assignment: TCP SYN Flood using RAW Sockets (Academic Lab)

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
