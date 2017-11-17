#!/bin/bash

host_ip="166.104.243.43"
port="4000"
guest_ip="192.168.122.143"
passwd="1234"

# host_ip="192.168.0.5" 		# host IP
# port="4000" 			# UDP port	
# guest_ip="192.168.122.232" 	# vmone's IP
# passwd="1"			# password for host super user

# virt_host_ip="$(echo $passwd | sudo -S iptables -L | grep -Eo '192.168.122.[0-9]{1,3}' | head -1)/24"
# echo $virt_host_ip

virt_host_ip="192.168.122.0/24"

echo $passwd | sudo -S iptables -t nat -A PREROUTING -p udp -d $host_ip --dport $port -j DNAT --to-destination $guest_ip:$port
echo $passwd | sudo -S iptables -I FORWARD -m state -d $virt_host_ip --state NEW,RELATED,ESTABLISHED -j ACCEPT

