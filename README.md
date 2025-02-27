# File-Based_User_Authentication_System


Here's a C++ project task for you:  

### **Project: File-Based User Authentication System**  

#### **Objective:**  
Create a simple user authentication system that allows users to register, log in, and manage their accounts using file storage.  

#### **Requirements:**  
1. **User Registration:**  
   - Ask for a username, email, and password.  
   - Ensure the email ends with "@gmail.com" and the password is at least 8 characters long.  
   - Store the credentials in a file (`users.txt`) securely (consider hashing passwords).  
   - Ensure that the username is unique.  

2. **User Login:**  
   - Ask for the username and password.  
   - Verify the credentials against the stored data.  

3. **Password Reset (Optional for a challenge):**  
   - Allow users to reset their password by providing their email and answering a security question.  

4. **File Handling:**  
   - Use file I/O to store and retrieve user data.  
   - Prevent duplicate entries and ensure data integrity.  

#### **Bonus Challenges:**  
- Implement password hashing using a simple hashing algorithm (like SHA-256 from OpenSSL).  
- Use a class-based approach with encapsulation for handling user data.  
- Add an option to delete a user account.  

#### **Expected Output Example:**  
```
Welcome to the User Authentication System  
1. Register  
2. Login  
3. Forgot Password  
4. Exit  
Enter your choice: 1  
Enter Username: rahib  
Enter Email: rahib@gmail.com  
Enter Password: ********  
User Registered Successfully!  
```  

Would you like a code structure to start with? 🚀