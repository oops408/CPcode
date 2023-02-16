import hashlib
from Crypto.Cipher import DES3
import base64

class HelloWorld:
    def main(self):
        obj = HelloWorld()
        val = obj.encrypt("@$#147%$#@$%@", "AbhiMAIabhi.cash19iD7Fd3nvVqoInsGGPr2")
        print(val)

    def encrypt(self, secret, to_encrypt):
        key = hashlib.md5(secret.encode('utf-8')).digest()
        cipher = DES3.new(key, DES3.MODE_ECB)
        padded_data = self.pad(to_encrypt)
        encrypted_data = cipher.encrypt(padded_data.encode('utf-8'))
        return base64.b64encode(encrypted_data).decode('utf-8')

    def pad(self, s):
        block_size = DES3.block_size
        padding_size = block_size - len(s) % block_size
        return s + padding_size * chr(padding_size)

if __name__ == '__main__':
    HelloWorld().main()