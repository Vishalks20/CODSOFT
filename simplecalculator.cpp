#include<iostream>
#import<math.h>
using namespace std;
int main() {
  double num1, num2;
  char op;
  cout << "Enter first number: ";
  cin >> num1;
  cout << "Enter second number: ";
  cin >> num2;
  cout << "Enter operator: \n";
  cout << "1.[+] - Addition\n";
  cout << "2.[-] - Subtraction\n";
  cout << "3.[*] - Multiplication\n";
  cout << "4.[/] - Division\n";
  cout << "5.[%] - Modulus\n"; // Add this line for the modulus option

  cout << "Enter your choice (1/2/3/4/5): ";
  cin >> op;

  double res;
  if (op == '1') {
    res = num1 + num2;
    cout << "Result: " << res;
  } else if (op == '2') {
    res = num1 - num2;
    cout << "Result: " << res;
  } else if (op == '3') {
    res = num1 * num2;
    cout << "Result: " << res;
  } else if (op == '4') {
    if (num2 == 0) {
      cout << "Error: Division by zero is not allowed.\n";
    } else {
      res = num1 / num2;
      cout << "Result: " << res;
    }
  } else if (op == '5') { // Add this block for the modulus
    if (num2 == 0) {
      cout << "Error: Modulus by zero is not allowed.\n";
    } else {
      res = int(num1) % int(num2); // Calculate modulus
      cout << "Result: " << res;
    }
  } 
  else {
    cout << "Invalid operator.\n";
  }
  return 0;
}