import socket
from crc import c

while True:
    m=input("Enter message (binary) or 'exit': ")
    if m.lower()=='exit':
        with socket.socket(socket.AF_INET,socket.SOCK_DGRAM) as x:
            x.sendto("exit,exit".encode(),('localhost',6000))
        print("Exiting client.")
        break
    g=input("Enter generator (binary): ")
    cs=c(m,g)
    print("Checksum code:",cs)
    with socket.socket(socket.AF_INET,socket.SOCK_DGRAM) as x:
        x.sendto(f"{m},{cs}".encode(),('localhost',6000))
