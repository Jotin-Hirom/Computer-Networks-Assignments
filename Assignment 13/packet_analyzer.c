#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define ETHER_TYPE_IP 0x0800
#define PROTO_ICMP 1
#define PROTO_TCP 6
#define PROTO_UDP 17

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Usage: %s <pcap file>\n", argv[0]);
        return 1;
    }

    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_offline(argv[1], errbuf);

    if (!handle) {
        printf("Error opening pcap file: %s\n", errbuf);
        return 1;
    }

    struct pcap_pkthdr *header;
    const u_char *packet;
    int packet_count = 0;

    printf("\n=== PACKET HEADER ANALYSIS ===\n");

    // Unique protocol flags
    int seen_tcp = 0, seen_udp = 0, seen_icmp = 0;

    while (pcap_next_ex(handle, &header, &packet) >= 0) {
        packet_count++;

        printf("\nPacket %d\n", packet_count);
        printf("Timestamp: %ld.%06ld seconds\n", header->ts.tv_sec, header->ts.tv_usec);

        // ------------------------
        // Layer 2 – Ethernet Header
        // ------------------------
        unsigned short ethertype = ntohs(*(unsigned short *)(packet + 12));
        printf("L2: Ethernet | Ethertype: 0x%04x\n", ethertype);

        if (ethertype != ETHER_TYPE_IP) {
            printf("Not an IP packet → Skipping\n");
            continue;
        }

        // ------------------------
        // Layer 3 – IP Header
        // ------------------------
        const u_char *ip_header = packet + 14;
        unsigned char protocol = ip_header[9];

        printf("L3: IP | Protocol number: %d\n", protocol);

        // ------------------------
        // Layer 4 – TCP / UDP / ICMP
        // ------------------------
        if (protocol == PROTO_TCP) {
            printf("L4: TCP\n");
            seen_tcp = 1;
        }
        else if (protocol == PROTO_UDP) {
            printf("L4: UDP\n");
            seen_udp = 1;
        }
        else if (protocol == PROTO_ICMP) {
            printf("L4: ICMP\n");
            seen_icmp = 1;
        }
        else {
            printf("L4: Other Protocol\n");
        }

        // ------------------------
        // Time-sequence diagram
        // ------------------------
        printf("Time Diagram: ");
        int time_units = header->ts.tv_usec / 20000; // every 20ms → 1 unit
        for (int i = 0; i < time_units; i++)
            printf("-");
        printf("> [Packet %d]\n", packet_count);
    }

    printf("\n=== UNIQUE PROTOCOLS IDENTIFIED ===\n");
    if (seen_tcp)  printf("TCP detected\n");
    if (seen_udp)  printf("UDP detected\n");
    if (seen_icmp) printf("ICMP detected\n");

    printf("\nTotal Packets Processed: %d\n", packet_count);

    pcap_close(handle);
    return 0;
}

