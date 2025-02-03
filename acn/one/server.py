import socket,os
s=socket.socket()
s.bind(('',9989))
s.listen(1)
c,addr=s.accept()
f=c.recv(1024).decode()
if os.path.isfile(f):
    with open(f) as x:
        c.sendall(x.read().encode())
else:
    c.send(b'File not found')
c.close()
s.close()

