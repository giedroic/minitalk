# Minitalk

A simple client–server communication program written in C using UNIX signals.

## Overview

**Minitalk** is a lightweight inter-process communication project where:

- The **server** waits for incoming messages via signals.
- The **client** sends messages to the server using `SIGUSR1` and `SIGUSR2` signals.
- The **client_bonus** version supports message confirmation and Unicode characters.

This showcases low-level IPC using only signals—no sockets or external libraries.

---

## Features

- **Signal-based messaging**: Communicate using only `SIGUSR1` and `SIGUSR2`.
- **Efficient bitwise protocol**: Messages are sent bit by bit via signals.
- **Supports multiple clients**: The server can handle consecutive messages without restarting.
- **Simple and fast**: Designed to be responsive and lightweight.
- **Bonus Features**:
  - Message confirmation upon successful receipt by the server.
  - Full Unicode character support.

---

## Project Structure

```
minitalk/
├── include/        # Header files (e.g., minitalk.h)
├── libft/          # Custom library for utility functions
├── src/
│   ├── client.c        # Client implementation
│   ├── client_bonus.c  # Client with confirmation and Unicode support
│   └── server.c        # Server implementation
└── Makefile            # Build configuration
```

---

## Getting Started

### Prerequisites

- A UNIX-like environment (Linux/macOS).
- A C compiler (e.g., `gcc`).
- Basic knowledge of signals (`SIGUSR1`, `SIGUSR2`) and process IDs (PIDs).

### Installation

1. **Clone the repository**

   ```bash
   git clone https://github.com/giedroic/minitalk.git
   cd minitalk
   ```

2. **Build the project**

   ```bash
   make
   ```

   This will compile both the `server` and `client` executables.

---

## Usage

1. **Start the server**

   ```bash
   ./server
   ```

   The server will display its PID. Keep this terminal open.

2. **Send a message from the client**

   ```bash
   ./client <server_pid> "Your message here"
   ```

   Example:

   ```bash
   ./client 12345 "Hello, Minitalk!"
   ```

3. **Use the bonus client** for message confirmation and Unicode support

   ```bash
   ./client_bonus <server_pid> "Your message with Unicode 👍"
   ```

4. The server terminal will reconstruct and print the message, and the bonus client will print confirmation upon successful receipt.

---

## How It Works

### Communication Protocol

- Each character is sent bit by bit:
  - `0` is signaled via `SIGUSR1`
  - `1` is signaled via `SIGUSR2`

- The server collects bits, rebuilding characters once 8 bits are received.
- Bonus client waits for server acknowledgment after the full message.

### Reliability & Flow

- Clients pass the server’s PID as an argument.
- The server prints its PID on startup and can handle multiple messages consecutively.
- Bonus client prints a confirmation message once the server has received the full message.
- Unicode characters are supported for both sending and receiving.

---

## Example Session

```bash
# Terminal 1:
$ ./server
Server PID: 23456

# Terminal 2:
$ ./client_bonus 23456 "Hello 🌍!"
```

Server output:
```
Hello 🌍!
```

Client output:
```
Message successfully received by server.
```

---
