#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <linux/if_packet.h>
#include <net/ethernet.h>
#include <net/if.h>
#include <sys/ioctl.h>

#define PACKET_SIZE 1500

int main() {

int sockfd;
char buffer[PACKET_SIZE];
struct ethhdr *eth;
struct iphdr *ip;
struct udphdr *udp;
struct sockaddr_ll saddr;
struct ifreq ifr;

memset(buffer, 0, PACKET_SIZE);

/* Create raw socket */
sockfd = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
if (sockfd < 0) {
perror("Socket error");
exit(1);
}

/* Get interface index */
strncpy(ifr.ifr_name, "h1-eth0", IFNAMSIZ);
ioctl(sockfd, SIOCGIFINDEX, &ifr);

/* Ethernet header */
eth = (struct ethhdr *)buffer;
unsigned char src_mac[6] = {0x08,0x00,0x27,0x11,0x22,0x33};
unsigned char dest_mac[6] = {0x08,0x00,0x27,0xaa,0xbb,0xcc};

memcpy(eth->h_source, src_mac, 6);
memcpy(eth->h_dest, dest_mac, 6);
eth->h_proto = htons(ETH_P_IP);

/* IP header */
ip = (struct iphdr *)(buffer + sizeof(struct ethhdr));
ip->version = 4;
ip->ihl = 5;
ip->ttl = 64;
ip->protocol = IPPROTO_UDP;
ip->saddr = inet_addr("10.0.0.1");
ip->daddr = inet_addr("10.0.0.2");

/* UDP header */
udp = (struct udphdr *)(buffer + sizeof(struct ethhdr) + sizeof(struct iphdr));
udp->source = htons(4444);
udp->dest = htons(9999);
udp->len = htons(sizeof(struct udphdr) + 128);
udp->check = htons(0x1234); // WRONG checksum

/* Payload */
char *payload = buffer + sizeof(struct ethhdr)
+ sizeof(struct iphdr)
+ sizeof(struct udphdr);

char user[50];
getlogin_r(user, sizeof(user));

time_t now;
time(&now);

sprintf(payload,
"Roll: CSM24042 | User: %s | Time: %s",
user, ctime(&now));

/* Destination */
saddr.sll_ifindex = ifr.ifr_ifindex;
saddr.sll_halen = ETH_ALEN;
memcpy(saddr.sll_addr, dest_mac, 6);

/* Send packet */
sendto(sockfd, buffer,
sizeof(struct ethhdr) + sizeof(struct iphdr)
+ sizeof(struct udphdr) + 128,
0, (struct sockaddr *)&saddr, sizeof(saddr));

printf("✔ Corrupted UDP packet sent\n");

close(sockfd);
return 0;
}
