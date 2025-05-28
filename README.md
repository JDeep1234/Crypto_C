# Cryptography Implementations in C



### Implemented Cryptographic Techniques

#### 1. Classical Cryptography
- [Caesar Cipher](caesar_cipher.c): Basic substitution cipher
- Demonstrates fundamental encryption principles
- [Railfence Cipher](railfence.c)

#### 2. Symmetric Key Cryptography
- [DES Algorithm](des_algorithm.c): Data Encryption Standard
- [AES Algorithm](aes_algorithm.c): Advanced Encryption Standard
- Explores block cipher mechanisms

#### 3. Asymmetric Cryptography
- [RSA Algorithm](rsa_algorithm.c): Public-key cryptosystem
- Demonstrates key generation and message encryption/decryption

#### 4. Key Exchange Protocols
- [Diffie-Hellman Key Exchange](diffie_hellman.c): Secure key negotiation
- [ElGamal Cryptographic System](elgamal_crypto.c): Public-key cryptosystem

#### 5. Security Techniques
- [Man-in-the-Middle Attack Simulation](mitm_attack.c): Demonstrates communication vulnerabilities
- [Authentication using Hashing](hashing_auth.c): Secure password storage technique

### 🛠️ Prerequisites
- GCC Compiler
- Standard C Libraries
- Math Library

### 💻 Compilation Instructions

#### Compile Individual Programs
```bash
# General Compilation Pattern
gcc -o program_name program_name.c -lm

# Example Compilations
gcc -o caesar_cipher caesar_cipher.c
gcc -o rsa_algorithm rsa_algorithm.c -lm

#For Hashing
gcc auth_hash.c -o auth_hash -lssl -lcrypto

```

#### Compile All Programs
```bash
# Using Makefile
make all

# Clean compiled binaries
make clean
```



### 🔍 Cryptographic Concepts Covered
- Encryption/Decryption
- Key Generation
- Hashing
- Public Key Infrastructure
- Secure Communication Protocols

### 📦 Project Structure
```
cryptography_lab/
├── caesar_cipher.c
├── des_algorithm.c
├── aes_algorithm.c
├── rsa_algorithm.c
├── diffie_hellman.c
├── elgamal_crypto.c
├── mitm_attack.c
├── hashing_auth.c
├── Makefile
└── README.md
```

