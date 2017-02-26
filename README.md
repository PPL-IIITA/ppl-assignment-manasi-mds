# ppl-assignment-manasi-mds
##CREATED BY Manasi Mohandas- (ICM2015501) SECTION - 'B'

##How to run

###To create library (lib_ppl.a) execute-
>```
g++ -c addboy.cpp
g++ -c addgift.cpp
g++ -c addgirl.cpp
g++ -c boyhapp.cpp
g++ -c couplehapp.cpp
g++ -c girlhapp.cpp
g++ -c q2indep.cpp
g++ -c q2nec.cpp
g++ -c readboygirlq1.cpp
ar rvs lib_ppl.a addboy.o addgift.o addgirl.o boyhapp.o couplehapp.o girlhapp.o q2indep.o q2nec.o readboygirlq1.o
```


###Steps
To generate random input:
>```
g++ addboy.cpp
./a.out
g++ addgirl.cpp
./a.out
g++ addgift.cpp
./a.out
```
###To run question 1 :
```
>g++ q1.cpp lib_ppl.a
>./a.out
```
##To generate coupleinput for question 2:
```
>g++ q2indep.cpp lib_ppl.a
>./a.out
```

###To run question 2:
```
>g++ q2.cpp lib_ppl.a
>./a.out
```

###To view couple file:
```
>Open coupledetails.txt
```

###To view gift exchange and K-most happiest and compatible couples:
```
>Open gifttransfer.txt
```
###Documentation of the project can be found in:
```
>doc/html/index.html
