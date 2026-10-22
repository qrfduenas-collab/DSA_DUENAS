 #include <iostream>

//static array, what do we need?
const size_t maxCap = 100;
int stack[maxCap];
int top = -1, i, newData;
//always -1 is the top of the stack if it is empty

//functions
void push();
void pop();
void Top();
bool isEmpty();
bool isFull();
void display();

int main() {
   int choice;
   std::cout << "Enter the number of max elements for the new stack: ";
   std::cin >> i;
   push();

   while(true) {
       std::cout << "\nstack operations" << std::endl;
       std::cout << "1. PUSH  2. POP  3. TOP  4. isEmpty  5. DISPLAY" << std::endl;
       std::cout << "Enter choice: ";
       std::cin >> choice;
       
       switch(choice) {
           case 1: push();
           break;
           case 2: pop();
           break;
           case 3: Top();
           break;
           case 4:
               if(isEmpty()) std::cout << "Stack is empty" << std::endl;
               else std::cout << "Stack is not empty" << std::endl;
           break;
           case 5: display();
           break;
           default:
               std::cout << "Invalid choice! Please try again." << std::endl;
           break;
       }
   }

   return 0;
}

bool isEmpty() {
   //create a condition to check whether the top element is equal to -1
   if (top == -1) return true;
   return false;
}

bool isFull() {
   //check if we reached the maximum capacity of the array
   if (top >= (int)maxCap - 1) return true;
   return false;
}

void push() {
   //check if full -> if yes return an error
   if (isFull()) {
       std::cout << "stack overflow" << std::endl;
       return;
   }

   std::cout << "New Value to add into the stack: ";
   std::cin >> newData;

   //increment the top(index by 1) then assign the new data;
   stack[++top] = newData;
}

void Top() {
   //check if the stack is empty
   if (isEmpty()) {
       std::cout << "stack underflow" << std::endl;
       return;
   }

   std::cout << "The element on the top of the stack is " << stack[top] << std::endl;
}

void pop() {
   //check if the stack is empty
   if (isEmpty()) {
       std::cout << "stack underflow" << std::endl;
       return;
   }

   //display the top value and decrement top
   std::cout << "popping: " << stack[top--] << std::endl;
}

// Function to display all elements in the stack
void display() {
   if (isEmpty()) {
       std::cout << "Stack is empty, nothing to display." << std::endl;
       return;
   }

   std::cout << "Elements in stack (top to bottom): ";
   for (int j = top; j >= 0; j--) {
       std::cout << stack[j] << " ";
   }
   std::cout << std::endl;
}