# Assignment 9: TCP File Upload and Download

## Objective
To implement file upload and download between two different hosts using **TCP socket programming** and to calculate the **file transfer time** on both client and server sides.

---

## Problem Statement
Write a TCP client–server program where:
- The **client downloads a file** from the server.
- The **client uploads a file** to the server.
- File transfer time is calculated using the `time.h` library.
- Programs are executed on **two different Mininet hosts** using `xterm`.

---

## Tools & Technologies Used
- Language: **C**
- Protocol: **TCP**
- Libraries:
  - `stdio.h`
  - `stdlib.h`
  - `string.h`
  - `unistd.h`
  - `arpa/inet.h`
  - `time.h`
- Environment: **Linux (Ubuntu)**
- Network Emulator: **Mininet**

---

## Directory Structure
Two separate directories are created:

Assignment9/
│
├── server/
│ ├── server.c
│ └── server_file.txt
│
└── client/
├── client.c
└── client_file.txt


---

## Steps to Execute

### 1. Start Mininet
```bash
sudo mn

2. Open Xterm for Hosts
mininet> xterm h1 h2


h1 → Server

h2 → Client

3. Compile Programs
On Server (h1)
cd server
gcc server.c -o server

On Client (h2)
cd client
gcc client.c -o client

4. Run Server
./server


Server starts listening on a TCP port and waits for client requests.

5. Client Downloads File from Server
./client


Output (Client):

Connects to server

Downloads file

Displays download time

Output (Server):

Client connected

File sent

Transfer time displayed

6. Client Uploads File to Server

After download completes, client uploads its file to server directory.

Output (Client):

Upload started

Upload finished

Upload time displayed

Output (Server):

File received

Stored in server directory

Receive time displayed

Sample Output
Server Side
Server listening on port 8080
Client connected for DOWNLOAD
DOWNLOAD finished
Time taken to SEND = 0.00001 seconds

Client connected for UPLOAD
Received 0 bytes into 'received_from_client.txt'
Time taken to RECEIVE = 0.00001 seconds
UPLOAD finished

Client Side
Connected to server for DOWNLOAD
Downloaded 0 bytes into 'downloaded_from_server.txt'
Time taken to DOWNLOAD = 0.00002 seconds

Connected to server for UPLOAD
UPLOAD finished

Learning Outcomes

Understanding TCP socket programming

File transfer using send() and recv()

Using time.h to calculate transfer duration

Running distributed programs using Mininet

Client–server communication across different hosts

Conclusion

This assignment successfully demonstrates reliable file transfer using TCP. Both upload and download operations were performed between two Mininet hosts, and transfer time was measured on both client and server sides.

Author

Mohsin Iqubal
MCA – Computer Networks Lab
Assignment 9

