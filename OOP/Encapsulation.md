# Encapsulation and Data Hiding

## Summary

Encapsulation is a broader concept that involves bundling data and methods together into a class, while data hiding is a specific aspect of encapsulation that focuses on restricting direct access to internal data. Encapsulation provides the means to achieve data hiding and other benefits such as abstraction and modularity in object-oriented programming.

## Example

```cpp
class BankAccount {
private:
    string accountNumber;
    double balance;
public:
    void deposit(double amount) {
        balance += amount;
    }
    void withdraw(double amount) {
        balance -= amount;
    }
    double getBalance() {
        return balance;
    }
};
```

In this example, the class has two private data members, `accountNumber` and `balance`, and three public methods, `deposit`, `withdraw`, and `getBalance`. The `deposit` and `withdraw` methods modify the `balance` data member, while the `getBalance` method returns the value of `balance`.

By making the data members private and the methods public, we have encapsulated the data and provided a well-defined interface for interacting with the bank account. Clients of the `BankAccount` class can only access the data and methods that are explicitly made public and cannot modify the `accountNumber` or `balance` data members directly.