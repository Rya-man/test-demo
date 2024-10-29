#client.py
import socket
import json
from data import *

def start_client():
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect(('localhost', 65432))

    # Receive data from server
    data = client_socket.recv(1024).decode('utf-8')
    received_data = json.loads(data)

    # Recreate Data object with received packet and checksum
    packet = received_data["packet"]
    checksum = received_data["checksum"]
    data_obj = Data(packet)
    data_obj.checksum = checksum  # Set checksum from server

    # Verify checksum
    if data_obj.verify_checksum():
        print("Data received with no errors.")
    else:
        print("Error detected in received data.")

    client_socket.close()

start_client()
