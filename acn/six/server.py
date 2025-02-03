import socket
from ch import c
s=socket.socket(socket.AF_INET,socket.SOCK_RAW,socket.IPPROTO_ICMP)
while True:
    p,_=s.recvfrom(1024)
    if p[20]==8:
        print("Received:",p[28:])
        print("Checksum:", "OK" if c(p[20:])==0 else "Fail")
