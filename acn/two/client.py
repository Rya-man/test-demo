import socket
s=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
s.sendto(input().encode(),('localhost',9999))
print(s.recv(1024).decode())
