import hashlib

def encrypt(text):
    return hashlib.sha256(text.encode()).hexdigest()
