import socket
s=socket.socket()
s.connect(('localhost',9989))
s.send(input("Enter file name ").encode())
data=s.recv(999999).decode()
print(data)
s.close() 