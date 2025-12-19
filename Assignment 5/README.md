Wireshark Packet Capture and PING Protocol Analysis
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

