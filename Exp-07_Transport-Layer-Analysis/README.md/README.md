```markdown
# Experiment 7: Packet Analysis of TCP & UDP Protocols

## Objectives
* Capture, inspect, and compare Transport Layer protocols (TCP and UDP) using Wireshark.

## Protocol Comparison

| Feature | TCP (Transmission Control Protocol) | UDP (User Datagram Protocol) |
| :--- | :--- | :--- |
| **Connection Type** | Connection-Oriented (3-Way Handshake) | Connectionless |
| **Header Size** | 20 to 60 Bytes (Variable) | 8 Bytes (Fixed) |
| **Reliability** | Guaranteed delivery via ACKs & Retransmissions | Best-effort delivery |
| **Header Fields** | Src/Dst Port, Seq No, Ack No, Window, Flags | Src/Dst Port, Length, Checksum |

## Wireshark Filters
* `tcp` : Displays TCP segment traffic showing 3-way handshake (`SYN`, `SYN-ACK`, `ACK`).
* `udp` : Displays UDP datagram traffic showing lightweight single-packet DNS/media requests.