#ifndef loan_RECORD
#define loan_RECORD


struct loan {
    int loanID;              // Unique loan ID
    int customerID;          // ID of the customer requesting the loan
    long int amount;         // loan amount requested
    int approved;            // Approval status: 0 -> Waiting, 1 -> Approved, -1 -> Rejected
    int  EmployeeID;         // Employee assigned
};

#endif