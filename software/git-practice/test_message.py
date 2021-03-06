"""LCM type definitions
This file automatically generated by lcm.
DO NOT MODIFY BY HAND!!!!
"""

try:
    import cStringIO.StringIO as BytesIO
except ImportError:
    from io import BytesIO
import struct

class test_message(object):
    __slots__ = ["name", "value"]

    __typenames__ = ["string", "string"]

    __dimensions__ = [None, None]

    def __init__(self):
        self.name = ""
        self.value = ""

    def encode(self):
        buf = BytesIO()
        buf.write(test_message._get_packed_fingerprint())
        self._encode_one(buf)
        return buf.getvalue()

    def _encode_one(self, buf):
        __name_encoded = self.name.encode('utf-8')
        buf.write(struct.pack('>I', len(__name_encoded)+1))
        buf.write(__name_encoded)
        buf.write(b"\0")
        __value_encoded = self.value.encode('utf-8')
        buf.write(struct.pack('>I', len(__value_encoded)+1))
        buf.write(__value_encoded)
        buf.write(b"\0")

    def decode(data):
        if hasattr(data, 'read'):
            buf = data
        else:
            buf = BytesIO(data)
        if buf.read(8) != test_message._get_packed_fingerprint():
            raise ValueError("Decode error")
        return test_message._decode_one(buf)
    decode = staticmethod(decode)

    def _decode_one(buf):
        self = test_message()
        __name_len = struct.unpack('>I', buf.read(4))[0]
        self.name = buf.read(__name_len)[:-1].decode('utf-8', 'replace')
        __value_len = struct.unpack('>I', buf.read(4))[0]
        self.value = buf.read(__value_len)[:-1].decode('utf-8', 'replace')
        return self
    _decode_one = staticmethod(_decode_one)

    _hash = None
    def _get_hash_recursive(parents):
        if test_message in parents: return 0
        tmphash = (0x754cd9dfeacb958f) & 0xffffffffffffffff
        tmphash  = (((tmphash<<1)&0xffffffffffffffff) + (tmphash>>63)) & 0xffffffffffffffff
        return tmphash
    _get_hash_recursive = staticmethod(_get_hash_recursive)
    _packed_fingerprint = None

    def _get_packed_fingerprint():
        if test_message._packed_fingerprint is None:
            test_message._packed_fingerprint = struct.pack(">Q", test_message._get_hash_recursive([]))
        return test_message._packed_fingerprint
    _get_packed_fingerprint = staticmethod(_get_packed_fingerprint)

