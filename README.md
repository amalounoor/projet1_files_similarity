# Project1:the similarity between two files
this program retun the percentage of the similarity between two files
# Programming language used
     "C++"
# similarity methode used
cos similarity
# cos similarity
definition:
     cosine similarity or cos similarity is a measure of similarity between two sequences of numbers.For defining it, the sequences are viewed as vectors in an inner product space, and the cosine similarity is defined as the cosine of the angle between them, that is, the dot product of the vectors divided by the product of their lengths.
 The formula to find the cosine similarity between two vectors:
     Cos(x, y) = x . y / ||x|| * ||y||
   where:
 -->x . y = product (dot) of the vectors ‘x’ and ‘y’.
 -->||x|| and ||y|| = length of the two vectors ‘x’ and ‘y’.
 -->||x|| * ||y|| = cross product of the two vectors ‘x’ and ‘y’.(from Wikipedia and GeeksforGeeks)
 # compilation
 g++ similarity_files.cpp
 # execution
 ./a name_file1.txt name_file2.txt
