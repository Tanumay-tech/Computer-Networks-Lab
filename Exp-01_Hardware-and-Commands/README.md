# Experiment 1: Basic Hardware Components & Networking Commands

## Hardware Components
* **NIC (Network Interface Card):** Hardware component enabling device connectivity to a network.
* **Switch:** Layer 2 device connecting devices within a LAN using MAC addresses.
* **Router:** Layer 3 device connecting multiple distinct networks using IP addresses.
* **UTP Cable (CAT6):** Media containing 4 twisted pairs of copper wire to reduce crosstalk.

## Essential CLI Commands
* `ping <host>`: Tests end-to-end IP reachability and round-trip time.
* `tracert <host>` / `traceroute <host>`: Displays route hops to a remote destination.
* `ipconfig` / `ifconfig`: Displays local interface IP, subnet mask, and default gateway.
* `netstat -an`: Lists all active socket connections and listening ports.
* `nslookup <domain>`: Queries DNS servers for IP address mapping.
* `arp -a`: Displays local ARP cache mapping IP addresses to MAC addresses.