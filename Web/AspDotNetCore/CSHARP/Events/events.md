![alt text](image.png)
![alt text](image-1.png)

Say we want to send text to someone after the video encoding, we need to add that functionality
![alt text](image-2.png)
Now we have added the new code in the VideoEncode class and code need to be recompiled again. 
And that means all the classes that are dependent on VideoEncoder need to be recompiled 
and deployed again.

![alt text](image-3.png)
![alt text](image-4.png)
![alt text](image-5.png)
![alt text](image-6.png)
![alt text](image-7.png)

Example
Video.cs
![alt text](image-8.png)

VideoEncoder.cs
![alt text](image-9.png)

![alt text](image-10.png)

![alt text](image-11.png)
![alt text](image-12.png)
![alt text](image-13.png)

Another version of the event to send the video going to be encoded
![alt text](image-14.png)
![alt text](image-15.png)

Built in method in csharp for event:
![alt text](image-16.png)