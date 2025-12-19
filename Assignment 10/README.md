Assignment 10: Packet Generation Using RAW Sockets
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

