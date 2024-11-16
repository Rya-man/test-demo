#Server.py

import socket
from data import *

# Server setup
def start_server():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(('localhost', 65432))
    server_socket.listen(1)
    print("Server listening on port 65432...")

    while True:
        conn, addr = server_socket.accept()
        print(f"Connected by {addr}")

        # Sample data packet (binary strings)
        packet = ["10101001", "00111001"]
        data_obj = Data(packet)
        
        #used to send an erroneous checksum
        # data_obj.checksum="00010001" 

        message = data_obj.to_json()

        # Send data to client
        conn.sendall(message.encode('utf-8'))
        print(f"Sent data: {message}")

        conn.close()
        break

start_server()
