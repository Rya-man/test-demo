import socket
from ch import ip_checksum

s=socket.socket()
s.connect(('localhost',9999))
m=b"Hello"
print(m)
cs=hex(ip_checksum(m))
s.send(m+b'|'+cs.encode())
s.close() 