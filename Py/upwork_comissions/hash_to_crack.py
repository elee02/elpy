import hashlib

# encoding, hashing and converting the password
def hash_password(password: str, algorithm: str = 'sha256') -> str:
    return getattr(hashlib, algorithm)(password.encode()).hexdigest()

# take in a dict to hash and check if it matches
def crack_hash(hash_to_crack: dict, algorithm: str = 'sha256') -> dict:
    password_list = ['123456', 'password', 'admin']  # This should be replaced with a real password list
    for password in password_list:
        for hash in hash_to_crack:
            if not hash_to_crack[hash] and hash_password(password, algorithm) == hash:
                hash_to_crack[hash] = password
    return hash_to_crack

# Example usage:
hash_to_crack = {hash_password('123456'): '', hash_password('password'): ''}
print(f"Hashes to crack: {hash_to_crack}")

hash_to_crack = crack_hash(hash_to_crack)
print(f"Cracked hashes: {hash_to_crack}")
