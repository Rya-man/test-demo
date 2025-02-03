import socket, struct

IP_HEADER_SIZE = 20

def fragment(data, mtu, pid=12345):
    offset, frags = 0, []
    while offset < len(data):
        size = min(mtu - IP_HEADER_SIZE, len(data) - offset)
        mf = 1 if offset + size < len(data) else 0
        hdr = struct.pack('!BBHHHBBH4s4s', 69, 0, size + IP_HEADER_SIZE, pid, offset // 8, mf, 0, 0, b'0.0.0.0', b'0.0.0.0')
        frags.append(hdr + data[offset:offset + size])
        offset += size
    return frags

def send_packet(data, mtu, host, port):
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    for frag in fragment(data, mtu):
        sock.sendto(frag, (host, port))
        print(f"Sent fragment with size {len(frag)} bytes")
    sock.close()

if __name__ == "__main__":
    mtu = int(input('Enter MTU: '))
    message = b"Hello, this is a large packet!" * 50
    send_packet(message, mtu, '127.0.0.1', 12345)
