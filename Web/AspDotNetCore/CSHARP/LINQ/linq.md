![alt text](image.png)
![alt text](image-1.png)

Example:
![alt text](image-2.png)

BookRepository:
![alt text](image-3.png)
![alt text](image-4.png)

Without LINQ, below is how we would query to find the cheaper books:
![alt text](image-5.png)
![alt text](image-6.png)

Different features of linq:
![alt text](image-7.png)
Different ways to write linq
![alt text](image-8.png)

Single expects one result to be present in the list but if none is present it will thorw an exception:
![alt text](image-9.png)

So we use default when we know in advance there might not be a single result matching the criteria:
![alt text](image-10.png)

Give me first book whose title matches the criteria given in the where clause:
![alt text](image-11.png)
Similary we have FirstOrDefault which works the same way as SingleOrDefault

Below is how we can skip the first two records and grab the other three:
![alt text](image-12.png)

Methods for reference:
![alt text](image-13.png)