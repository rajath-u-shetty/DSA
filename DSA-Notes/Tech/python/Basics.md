Byte Lock suns fastex
- ﻿﻿pyc → compiled python
- ﻿- pycache_.
* Source Change & Python Version hello_ chai. Cpython - 312. pc 
* Works only tox impoxted files
* not for top level files


Python Virtual Machine PVM
→ Code loop to iterate byte Code
→ Run time Engine
→ Also Known as python interpreter

Byte Code is Not machine Code
→ Python specific inteapretation
-> cypython is the standard implementation, there are others like Iron Python,jython,PyPy

```python
from importlib import reload
reload(hello_chai)

// chai aur python
// Lemon tea
```
* if we declare variables or functions after they are imported in a file, then they must be reloaded to fetch the new data from that file
*

![[Screenshot 2025-03-31 at 12.48.39 PM.png]]

### immutable
![[Screenshot 2025-03-31 at 12.51.35 PM.png]]

* when we declare a varibale with immutable type. a new object is created in the memory. and its reference is stored in the variable
* we can change the entire value as python will create a new obj and assign its reference to the variable.
* but we cannot  modify the existing value

### mutable
* here we can modify the existing value of the reference obj in the memory.


# Object Types / Data Types

- Number : 1234, 3.1415, 3+4j, 0b111, Decimal(), Fraction()
- String : 'spam', "Bob's", b'a\x01c', u'sp\xc4m'
- List : [1, [2, 'three'], 4.5], list(range(10))
- Tuple : (1, 'spam', 4, 'U'), tuple('spam'), namedtuple
- Dictionary : {'food': 'spam', 'taste': 'yum'}, dict(hours=10)
- Set : set('abc'), {'a', 'b', 'c'}

- File : open('eggs.txt'), open(r'C:\ham.bin', 'wb')
- Boolean : True, False
- None : None
- Funtions, modules, classes

- Advance: Decorators, Generators, Iterators, MetaProgramming

## int & strings

* python does not have any data type.
* the reference in the memory is the one that has a type. if the reference stroes a int then the type of object reference becomes int.
* python due to optimization tskes some time for garbage collection of numbers ans strings
* type in python comes from the storage objects and not from variables.
```python
a = 3 // this will be removed by garbage collector
a = "hello"
```

#### calculation & reassigning values
![[Screenshot 2025-03-31 at 3.57.58 PM.png]]

* when it completes calclulating 5+2. it will create a new reference in the memory as then assign the new reference to a.

## list

```python
l1 = [1,2,3]
l2 = l1;
//here both of them share the same reference object in the memory ans changing the data using one variable affects the other also.

2.
l1 = [1,2,3]
l2 = [1,2,3] // this create 2 seperate objects in the memory

3.
l1 = [1,2,3]
l2 = l1[:] // uses slice operator to create a new copy of l1 into l2. both have difference reference in the memory

4.
m = [1,2,3]
n = [1,2,3]
m == n // True
//bcz both share have same values

5. m is n //false bcz different memory references

```

### comparison
```python
m = [1,2,3]
n = [1,2,3]
m == n // True
//bcz both share same
```

## differnt types of print
repr() : use for clear representation and debugging and mainly use by developer. 
str() : represent as readable for human.
print() : internally it use str() to get object and print it.