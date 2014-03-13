1. We believe that all of our code is working properly.

2. We have a hash table in the library that is a direct map of 
   items in binary trees. We hash each item by subtracting 'a' from
   the character type of the item. For example: a FictionBook hash value
   is 'f' - 'a' or 5. We also implement hash tables in our factories.
   These hash tables utilize the same hashing algorithm. For example:
   a return command would have the hash value of 'r' - 'a'. 

3. Our manager reads in the book data with buildItems.
   Then the manager:

   main() -> manager.run() -> buildItems(infile)
   -> itemFact.createIt() -> item.setData(infile)
   
   Then they are placed into the correct BinTree using the hash table.

4. Our manager reads in the command data with buildCommands. 
   Then the manager:

   main() -> manager.run() -> buildCommands(infile)
   -> commandFact.createIt() -> command.setData(infile)
   
   After they are placed in the queue, processCommands pops them off
   and runs them.

5. We believe our factories could be improved slightly. Currently,
   CreateIt() accepts an int to determine what type of object should
   be built by the factory. We think it would be better to pass the
   file stream itself into the factory. If for some reason the input
   file format changed, this would allow us to update the system by
   only modifying the factory.
   
6. We are glad we thought of using a stack to handle the return book
   command error checking.

