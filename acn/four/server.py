import socket
from ch import ip_checksum

s=socket.socket()
s.bind(('',9999))
s.listen(1)
x,_=s.accept()
m=x.recv(1024)
msg,cs=m.rsplit(b'|',1)
print("Received:",msg)
print("Received checksum:",cs.decode())
# cs =b'0x1233'
print("Verification:",'OK' if hex(ip_checksum(msg))==cs.decode() else 'Error')
x.close() 
s.close()