#!bin/bash
firewall-cmd --zone=public --add-port=1194/tcp --permanent
firewall-cmd --zone=public --add-port=1194/udp --permanent
firewall-cmd --zone=public --add-port=2895/tcp --permanent
firewall-cmd --zone=public --add-port=2895/udp --permanent
-A INPUT -p tcp -m state --state NEW -m tcp --dport 1194 -j ACCEPT
-A INPUT -p tcp -m state --state NEW -m tcp --dport 2895 -j ACCEPT
firewall-cmd --reload
firewall-cmd --query-port=2895/tcp
firewall-cmd --query-port=2895/udp
reboot
