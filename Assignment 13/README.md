Assignment 13: Packet Capturing and Analysis using Mininet & C
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

