TCP Traffic Analyzer using C (Packet Sniffer)
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

