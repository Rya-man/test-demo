import socket
s=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
s.bind(('',9999))
data,addr=s.recvfrom(1024)
s.sendto(data.upper(),addr)
 