import socket
from scapy.all import ARP, Ether, srp

def scan_network(target_ip):
    arp = ARP(pdst=target_ip)
    ether = Ether(dst="ff:ff:ff:ff:ff:ff")
    packet = ether/arp

    results = srp(packet, timeout = 3, verbose = 0) [0]

    devices = []

    for sent, received in results:
        try:
            hostname = socket.gethostbyaddr(received.psrc)[0]
        except socket.herror:
            hostname = "Unknown"
        devices.append({'ip': received.psrc, 'mac': received.hwsrc, 'hostname': hostname})
    return devices

network = "172.20.4.207/24"
devices = scan_network(network)


print("Found Devices: ")
for device in devices:
    print(f"IP ADDRESS: {device['ip']}, MAC ADDRESS: {device['mac']} HOSTNAME: {device['hostname']}")

