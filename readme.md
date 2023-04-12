# Minitalk

The purpose of this project is to code a small data exchange program using UNIX signals.

# Initial installation

```
git clone https://github.com/magnitopic/minitalk.git
cd minitalk
git submodule init
git submodule update
```

# Compilation and execution

## Mandatory

Compile

```bash
make
```

Execute the server

```bash
./server
```

Execute the client

**_Remember_** to replace the `serverPID` with the PID the server gives you.

```bash
./client "serverPID" "Hello World!"
```

## Bonus

Compile

```bash
make bonus
```

Execute the server

```bash
./server_bonus
```

Execute the client

**_Remember_** to replace the `serverPID` with the PID the server gives you.

```bash
./client_bonus "serverPID" "Hello World!👋"
```

# Mandatory vs Bonus

The difference between the mandatory and the bonus is that bonus makes sure the message gets sent to the server.

You can check it for yourself by sending a message with the mandatory version but with a different PID to the server's, it will always say the message was successfully sent, even when the server hasn't received it.

Try the same with the bonus version and it will tell you the message was not received successfully.
