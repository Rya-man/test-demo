#data class

import socket
import json

class Data:
    def __init__(self, packet):
        self.packet = packet
        self.checksum = self.calculate_checksum()

    def calculate_checksum(self):
        total_sum = 0
        for word in self.packet:
            total_sum += int(word, 2)  
            total_sum = (total_sum & 0xFF) + (total_sum >> 8)

        # One's complement of the total sum
        checksum = ~total_sum & 0xFF
        return f"{checksum:08b}"  # Convert checksum to an 8-bit binary string

    def verify_checksum(self):
        total_sum = int(self.checksum, 2)
        for word in self.packet:
            total_sum += int(word, 2)
            total_sum = (total_sum & 0xFF) + (total_sum >> 8)

        # If total_sum is all 1's (255 in binary), the data is considered error-free
        return total_sum == 0xFF

    def to_json(self):
        return json.dumps({"packet": self.packet, "checksum": self.checksum})
