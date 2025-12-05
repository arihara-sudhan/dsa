import heapq
from collections import defaultdict, Counter

class Node:
    def __init__(self, char=None, freq=0):
        self.char = char
        self.freq = freq
        self.left = None
        self.right = None
    # FOR PRIORITY QUEUE
    def __lt__(self, other):
        return self.freq < other.freq

# BUILD HUFFMAN TREE
def build_huffman_tree(text):
    freq = Counter(text)
    heap = [Node(char, f) for char, f in freq.items()]
    heapq.heapify(heap)
    while len(heap) > 1:
        node1 = heapq.heappop(heap)
        node2 = heapq.heappop(heap)
        merged = Node(freq=node1.freq + node2.freq)
        merged.left = node1
        merged.right = node2
        heapq.heappush(heap, merged)
    return heap[0]  #ROOT

# GENERATE HUFFMAN CODES
def generate_codes(node, prefix="", code_map=None):
    if code_map is None:
        code_map = {}
    if node.char is not None:
        code_map[node.char] = prefix
    else:
        generate_codes(node.left, prefix + "0", code_map)
        generate_codes(node.right, prefix + "1", code_map)
    return code_map

# ENCODE
def huffman_encode(text):
    root = build_huffman_tree(text)
    codes = generate_codes(root)
    encoded_text = "".join(codes[c] for c in text)
    return encoded_text, codes

# DECODE
def huffman_decode(encoded_text, codes):
    reverse_codes = {v: k for k, v in codes.items()}
    decoded = ""
    temp = ""
    for bit in encoded_text:
        temp += bit
        if temp in reverse_codes:
            decoded += reverse_codes[temp]
            temp = ""
    return decoded

text = "ARIHARASUDHAN"
encoded_text, codes = huffman_encode(text)
print("Huffman Codes:", codes)
print("Encoded:", encoded_text)
decoded_text = huffman_decode(encoded_text, codes)
print("Decoded:", decoded_text)
