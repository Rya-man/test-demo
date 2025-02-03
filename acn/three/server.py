
import socket
from crc import c

s=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
s.bind(('localhost',6000))
print("Server listening on 6000...")

while True:
    data,addr=s.recvfrom(1024)
    m,cs=data.decode().split(',')
    if m.lower()=='exit':
        print("Client exit, shutting down.")
        break
    g=input("Enter generator (binary): ")
    cc=c(m+cs,g)
    print("Received message(CRC):",m+cs)
    print("Received checksum:",cs)
    print(f"Data from {addr} is {'valid' if all(i=='0' for i in cc) else 'invalid'}.")

s.close()