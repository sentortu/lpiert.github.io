#!/usr/bin/env bash
PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin:~/bin
export PATH
iptables -I INPUT -m state --state NEW -m tcp -p tcp --dport 1194 -j ACCEPT
iptables -I INPUT -m state --state NEW -m udp -p udp --dport 1194 -j ACCEPT
iptables -I INPUT -m state --state NEW -m tcp -p tcp --dport 2895 -j ACCEPT
iptables -I INPUT -m state --state NEW -m udp -p udp --dport 2895 -j ACCEPT
reboot
