# Banking Management System

A client-server banking application built in C using UNIX system calls.

## Features

The system supports four roles with secure login and role-based access:

### Customer

- View account balance, deposit, withdraw, transfer funds
- Apply for loans, view transaction history
- Change password, submit feedback

### Employee

- Add new customers and accounts
- Modify customer details
- Approve/reject assigned loan applications
- View customer transactions (passbook feature)

### Manager

- Activate/deactivate customer accounts
- Assign loan applications to employees
- Review customer feedback
- View all loans in the system

### Admin

- Add new bank employees
- Modify customer/employee details
- Promote employees to manager or demote back

## Technical Details

- **Networking:** TCP sockets with `fork()` for concurrent multi-client support
- **Storage:** Flat binary files with fixed-size struct records
- **Concurrency:** POSIX file locks (`fcntl`) and System V semaphores
- **Security:** Password hashing with `crypt()`

## How to Run

```bash
# Create records directory
mkdir -p records

# Compile
gcc server.c -o server -lcrypt
gcc client.c -o client

# Terminal 1: Start server
./server

# Terminal 2: Connect client
./client
```

## First-Time Setup

1. Login as **Admin** (ID: `Admin123`, Password: `admin@123`)
2. Create employees via "Add New Bank Employee"
3. Login as **Employee** to create customer accounts
4. Login as **Customer** to use banking features
5. To use **Manager** role, promote an employee via Admin's "Manage User Roles"

## Project Structure

```
Banking-Management-System/
├── server.c                # Server: socket setup, accept loop, fork per client
├── client.c                # Client: connects to server, handles I/O
├── functions/
│   ├── common.h            # Login handlers, record lookup utilities
│   ├── admin.h             # Admin operations
│   ├── customer.h          # Customer operations
│   ├── employee.h          # Employee operations
│   ├── manager.h           # Manager operations
│   ├── server-constants.h  # File paths and constants
│   └── admin-credentials.h # Admin login credentials
├── record-struct/
│   ├── account.h           # Account structure
│   ├── customer.h          # Customer structure
│   ├── employee.h          # Employee structure
│   ├── transaction.h       # Transaction structure
│   ├── loan_struct.h       # Loan structure
│   └── feedback.h          # Feedback structure
├── records/                # Runtime data files (auto-created)
├── BMS_Class_Diagram.pdf   # Class diagram
└── README.md
```
