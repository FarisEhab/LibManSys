// //
// // Created by MacBook on 26/12/2024.
// //
// #include "Library.h"
//
// void Library::run() {
//     int choice;
//     bool success = false;
//     do {
//         std::cout << "1. Sign Up \n2. Log In \n3. Exit" << std::endl;
//         std::cin >> choice;
//         std::string username, password;
//         bool isStaff = false;
//         switch (choice) {
//             case 1:
//                 std::cout << "Enter username: ";
//                 std::cin >> username;
//                 std::cout << "Enter password: ";
//                 std::cin >> password;
//                 std::cout << "Are you a staff member? (1 for Yes, 0 for No): ";
//                 std::cin >> isStaff;
//                 if (authManager.signUp(username, password)) {
//                     success = true;
//                 }
//                 break;
//             case 2:
//                 std::cout << "Enter username: ";
//                 std::cin >> username;
//                 std::cout << "Enter password: ";
//                 std::cin >> password;
//                 if (authManager.logIn(username, password)) {
//                     success = true;
//                     // Check if the user is a Reader or Staff
//                     if (authManager.isStaff(username)) {
//                         std::cout << "Logged in as Staff" << std::endl;
//                         // Staff operations
//                         int staffChoice;
//                         do {
//                             std::cout << "1. Add Book \n2. Remove Book \n3. Update Book \n4. Log Out" << std::endl;
//                             std::cin >> staffChoice;
//                             switch (staffChoice) {
//                                 case 1:
//                                     // Add book logic
//                                     break;
//                                 case 2:
//                                     // Remove book logic
//                                     break;
//                                 case 3:
//                                     // Update book logic
//                                     break;
//                                 case 4:
//                                     std::cout << "Logging out..." << std::endl;
//                                     success = false;
//                                     break;
//                                 default:
//                                     std::cout << "Invalid choice... Please try again" << std::endl;
//                             }
//                         } while (staffChoice != 4);
//                     } else {
//                         std::cout << "Logged in as Reader" << std::endl;
//                         // Reader operations
//                         int readerChoice;
//                         do {
//                             std::cout << "1. Borrow Book \n2. Log Out" << std::endl;
//                             std::cin >> readerChoice;
//                             switch (readerChoice) {
//                                 case 1:
//                                     // Borrow book logic
//                                     break;
//                                 case 2:
//                                     std::cout << "Logging out..." << std::endl;
//                                     success = false;
//                                     break;
//                                 default:
//                                     std::cout << "Invalid choice... Please try again" << std::endl;
//                             }
//                         } while (readerChoice != 2);
//                     }
//                 }
//                 break;
//             case 3:
//                 std::cout << "Exiting..." << std::endl;
//                 break;
//             default:
//                 std::cout << "Invalid choice... Please try again" << std::endl;
//         }
//     } while (choice != 3 && !success);
// }