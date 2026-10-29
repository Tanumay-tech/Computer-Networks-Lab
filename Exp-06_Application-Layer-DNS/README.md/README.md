# Experiment 6: Analysis of Application Layer Packet (DNS) using DNS cmd & Wireshark

## Objectives
* Perform domain name system lookups using CLI utility commands (`nslookup`).
* Capture and analyze DNS queries and responses using Wireshark packet analyzer.

## Key Concepts & Observations
* **DNS Protocol:** Operates at the Application Layer, translating human-readable domain names into IP addresses. Uses **UDP Port 53**.
* **Commands Executed:**
  ```powershell
  nslookup google.com
  nslookup -type=ns bing.com

  Wireshark Header Analysis:

Query Header: Identifies transaction ID, flags (Standard query 0x0000), and domain query name.

Response Header: Contains Answer RRs (Resource Records), TTL (Time to Live), and authoritative server details.