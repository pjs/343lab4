1. Describe the state of your program, exactly what works and what does not work. 
2. List your hash table(s): briefly what they are used for and file found in. (Include any factories that are essentially hash tables.) 
3. Describe which file and which function you read the book data, high level function call, 
i.e., how/where it gets into your book collections. 
4. Describe which file and which function you read the command data, high level function call, 
            i.e., how/where you perform the commands/transactions. 
5. Describe any dirty little secrets (e.g., switch used, or if-else-if, etc.) 
            If you feel they do not violate the open-closed design principle, explain. 
6. Describe anything you are particularly proud of ... 

1. We believe that all of our code is working properly. 

2. We have hash table in the library, this is a direct maping of 
item binary trees. We has eachitem by subtracting 'a' from the 
first character of the item. For ex.FictionBook hash value is 'f'
 - 'a' or 5. We also implement hash tables in our factories. 
These hash table utilize the same hashing algorythm. For example 
a return command would have thehash value of 'r' - 'a'. 

3. Our manager reads in the book data with buildItems. Then the manager

main() -> manager.run() -> buildItems(infile) -> itemFact.create()
-> item.setData(infile)

4. Our manager reads in the command data with buildCommands. Then the manager

main() -> manager.run() -> buildCommands(infile) -> commandFact.create()
-> command.setData(infile)

5. We believe that we violate the open-clased design principle a few times.
For example, we have 2 setData functions and each of our item files. One
To set the data for the commands and one to set the data for the library.
We think we could have created a separate parent class, where the children
classes would do all of the reading in the files for this. We think
that this may have been a better way to do it. 
We also believe our print method violates this open closed principle, 
because we pass in a bool, true means you print w/o the availabilty.

