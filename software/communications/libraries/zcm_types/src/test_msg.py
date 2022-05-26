"""ZCM type definitions
This file automatically generated by zcm.
DO NOT MODIFY BY HAND!!!!
"""

try:
    import cStringIO.StringIO as BytesIO
except ImportError:
    from io import BytesIO
import struct

class test_msg(object):
    __slots__ = ["str"]

    IS_LITTLE_ENDIAN = False;
    def __init__(self):
        self.str = ""

    def encode(self):
        buf = BytesIO()
        buf.write(test_msg._get_packed_fingerprint())
        self._encode_one(buf)
        return buf.getvalue()

    def _encode_one(self, buf):
        __str_encoded = self.str.encode('utf-8')
        buf.write(struct.pack('>I', len(__str_encoded)+1))
        buf.write(__str_encoded)
        buf.write(b"\0")

    def decode(data):
        if hasattr(data, 'read'):
            buf = data
        else:
            buf = BytesIO(data)
        if buf.read(8) != test_msg._get_packed_fingerprint():
            raise ValueError("Decode error")
        return test_msg._decode_one(buf)
    decode = staticmethod(decode)

    def _decode_one(buf):
        self = test_msg()
        __str_len = struct.unpack('>I', buf.read(4))[0]
        self.str = buf.read(__str_len)[:-1].decode('utf-8', 'replace')
        return self
    _decode_one = staticmethod(_decode_one)

    _hash = None
    def _get_hash_recursive(parents):
        if test_msg in parents: return 0
        tmphash = (0xef3e5b5c283a2def) & 0xffffffffffffffff
        tmphash  = (((tmphash<<1)&0xffffffffffffffff)  + ((tmphash>>63)&0x1)) & 0xffffffffffffffff
        return tmphash
    _get_hash_recursive = staticmethod(_get_hash_recursive)
    _packed_fingerprint = None

    def _get_packed_fingerprint():
        if test_msg._packed_fingerprint is None:
            test_msg._packed_fingerprint = struct.pack(">Q", test_msg._get_hash_recursive([]))
        return test_msg._packed_fingerprint
    _get_packed_fingerprint = staticmethod(_get_packed_fingerprint)
