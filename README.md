# Online-Store-Management-System-Using-OOP-cpp
This C++ code implements a simple online store management system with two classes: Item and seller. The system allows sellers to add, sell, display, and search for items by their serial ID. Users can interact with the system through a menu-driven interface in the console.

#Item Class
The Item class represents a store item with attributes such as price, quantity, ID, and name. Key features include:

- Encapsulation: Private attributes (price, quantity, ID, name, and IDNUM) are encapsulated within the class, and access is controlled through public member functions.

- Constructors: The class has a default constructor, a parameterized constructor, and a copy constructor. The default constructor initializes default values, the parameterized constructor creates an object with specified parameters, and the copy constructor performs a deep copy of an existing object.

- Operator Overloading: The class overloads operators for input (>>), output (<<), equality (==), addition (+=), and subtraction (-=). This allows for convenient user interaction and manipulation of item objects.

- Static Member: The static member IDNUM serves as the serial ID number for items and increments with each new item creation.

#Seller Class
The seller class represents a seller managing a collection of items. Key features include:

- Encapsulation: Private attributes (items, maxitems, email, and name) are encapsulated within the class, and access is controlled through public member functions.

- Parametrized Constructor: The constructor takes seller information and initializes an array of Item objects with a specified maximum capacity (maxitems).

- Operator Overloading: The class overloads the output operator (<<) to display seller information.

- Item Management: Public member functions allow sellers to add items to the store, sell items, find items by ID, and display all items.

- Dynamic Memory: The class utilizes dynamic memory allocation for the array of Item objects.

- Destructor: A destructor is implemented to release the dynamically allocated memory.

#User Interaction (main function)
The main function serves as the user interface, prompting users to input their information and interact with the online store system through a menu. The menu options include printing seller information, adding items, selling items, displaying items, finding items by ID, and exiting the program.
