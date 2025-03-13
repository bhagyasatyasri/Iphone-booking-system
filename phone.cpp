#include <iostream>
#include <string>
using namespace std;
// Base class template representing a product
template <typename T>
class Product {
public:
string name;
T price;
// Function to display basic information about the product
virtual void display() {
cout << "Model: " << name << endl;
cout << "Price: Rs." << price << endl;
}
// Virtual overloaded function to display additional
information with a discount
virtual void display(double discount) {
cout << "Model: " << name << endl;
cout << "Price: Rs." << price << endl;
cout << "Discount: " << discount << "%" << endl;
cout << "Discounted Price: Rs." << price - (price * discount
/ 100.0) << endl;
}
};
// Derived class representing an iPhone
class IPhone : public Product<double> {
public:
IPhone(const string& model, double price) {
name = "iPhone " + model;
this->price = price;
}
// Overridden function to display iPhone-specific information
void display() override {
cout << "Company: Apple" << "\n"; // Display only the
company name
Product::display(); // Call the base class display function
for common information
}
// Overridden function to display additional information with
a discount
void display(double discount) override {
cout << "Company: Apple" << "\n"; // Display only the
company name
Product::display(discount); // Call the base class display
function with a discount
}
};
int main() {
string choseniphone;
double chosenPrice;
// Display available iPhone models
cout << "Available iPhone Models:\n";
cout << "1. iPhone 15 Pro Max - Rs.1,79,900\n";
cout << "2. iPhone 15 Plus - Rs.99,900\n";
cout << "3. iPhone 15 - Rs.89,900\n";
// Read user input for iPhone model
cout << "\nEnter the number of the iPhone model you want to
buy: ";
int modelChoice;
cin >> modelChoice;
// Validate user input
while (modelChoice < 1 || modelChoice > 3) {
cout << "Invalid choice. Please enter a number between 1
and 3: ";
cin >> modelChoice;
}
// Set the chosenModel and chosenPrice based on user
input
switch (modelChoice) {
case 1:
choseniphone = "15 Pro Max";
chosenPrice = 179900;
break;
case 2:
choseniphone = "15 Plus";
chosenPrice = 99900;
break;
case 3:
choseniphone = "15";
chosenPrice = 89900;
break;
default:
std::cout << "Invalid choice. Exiting...\n";
return 1;
}
// Create an iPhone object using the template
IPhone myiPhone(choseniphone, chosenPrice);
// Display information about the purchased iPhone using the
overridden functions
cout << "\nCongratulations! You have purchased the
following iPhone:\n";
myiPhone.display(); // Calls the overridden display function
in IPhone class
myiPhone.display(10.0); // Calls the overloaded display
function in IPhone class with a discount
return 0;
}