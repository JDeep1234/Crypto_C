# Cryptography Implementations in C

## Overview
This repository contains implementations of various cryptographic algorithms and techniques in C programming language.

## Algorithms Implemented

### 1. Traditional Ciphers
- Caesar Cipher
- Simple substitution cipher
- Demonstrates basic encryption and decryption techniques

### 2. DES (Data Encryption Standard)
- Symmetric key block cipher
- Placeholder implementation showing encryption structure
- Demonstrates round-based encryption process

### 3. AES (Advanced Encryption Standard)
- Modern symmetric encryption algorithm
- Placeholder showing encryption stages
- Supports 128-bit block size

### 4. RSA Algorithm
- Asymmetric encryption algorithm
- Key generation
- Encryption and decryption of messages
- Demonstrates modular arithmetic principles

### 5. Diffie-Hellman Key Exchange
- Secure key exchange protocol
- Allows two parties to generate shared secret
- Demonstrates public key cryptography

### 6. ElGamal Cryptographic System
- Public-key cryptosystem
- Encryption and decryption of messages
- Based on discrete logarithm problem

### 7. Man-in-the-Middle (MITM) Attack Simulation
- Demonstrates potential vulnerabilities in key exchange
- Shows how an attacker can intercept and manipulate communication

### 8. Authentication using Hashing
- Secure password storage technique
- Uses one-way hash function
- Demonstrates basic authentication mechanism

## Compilation
Compile each program using GCC:
```bash
gcc -o program_name program_name.c -lm
```

## Security Notes
- These are educational implementations
- Not recommended for production use
- Use established cryptographic libraries for real-world applications

## Dependencies
- Standard C libraries
- Math library (-lm)

## Contributing
Contributions, improvements, and bug fixes are welcome!

## License
MIT License
