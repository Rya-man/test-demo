import socket, struct
from collections import defaultdict

IP_HEADER_SIZE, MTU = 20, 500

def reassemble(fragments):
    data = defaultdict(list)
    for frag in fragments:
        hdr, payload = frag[:IP_HEADER_SIZE], frag[IP_HEADER_SIZE:]
        _, _, _, pid, offset, mf, *_ = struct.unpack('!BBHHHBBH4s4s', hdr)
        data[pid].append((offset, payload))
    for pid, parts in data.items():
        parts.sort(key=lambda x: x[0])
        return b''.join(p[1] for p in parts)

def receive_packet(host, port):
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.bind((host, port))
    print(f"Listening on {host}:{port}...")
    while True:
        frags = []
        while True:
            data, addr = sock.recvfrom(MTU)
            frags.append(data)
            _, _, _, pid, _, mf, *_ = struct.unpack('!BBHHHBBH4s4s', data[:IP_HEADER_SIZE])
            if not mf:
                print(f"Reassembled packet {pid}:\n{reassemble(frags).decode()}")
                break

if __name__ == "__main__":
    receive_packet('127.0.0.1', 12345)