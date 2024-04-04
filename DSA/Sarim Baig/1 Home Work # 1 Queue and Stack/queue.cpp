//Microsoft (R) C/C++ Optimizing Compiler Version 19.00.23506 for x64

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <list>
#include <stack>
#include <cmath>
#include <algorithm>
using namespace std;

template <typename T>
class queue{//class template for circular queue
private:
	T * arr;//pointer to be allocated
	int cap;//physical size
	int size;//logical size
	int front, rear;
	
	int next(int i){//utility function
		return (i+1)%cap;//cap
	} 

public:
	//next time
	
	queue(int icap=0){
		if(icap>0){
			arr=new T[icap+1];
			cap=icap;
		}else{//default behaviour
			arr=nullptr;
			cap=0;
		}
		size=0;
		front=rear=0;//dead cell //////////////////////////We can make it working cell
	}

	void enqueue(const T& obj){
		//is the queue full (physically)
		if(size+1==cap){
			//array is full, so grow it
			T * temp = new T[cap*2];
			//copy data from the older array
			int k=0, i=next(front);
			while(k<size){
				temp[k+1]=arr[i];
				i=next(i);
				k++;
			}
			//how to change front and rear values?
			front=0;//dead cell
			rear=size;//rear is pointing at the last element
			rear++;
			temp[rear]=obj;
			cap*=2;
			size++;
			delete [] arr;
			arr=temp;
		}else if(cap==0){
			//what should we do?
			arr=new T[2];
			front=0;
			rear=1;
			arr[1]=obj;
			size=1;
			cap=2;
		}
		else{
			//there is a slot available
			rear=next(rear);
			arr[rear]=obj;
			size++;
		}
	}

	void dequeue(){
		if(empty())
			return;
		
		if((size+1)==cap/2)
		{
			 //array is half empty, so shrink it
			T * temp = new T[cap/2];
			//copy data from the older array
			int k=0, i=next(front);
			while(k<size){
				temp[k+1]=arr[i];
				i=next(i);
				k++;
			}
			//how to change front and rear values?
			front=0;//dead cell
			rear=size;
			
			cap/=2;
			front=next(front);
			size--;
			delete [] arr;
			arr=temp;
		}else{
			front=next(front);
			size--;
		}
	}


	void printQueue(){
		//testing purposes
		for(int i=front+1;i<=rear;i++){
			cout<<arr[i]<<" ";
		}
	}
	
	const T & peek(){//read only reference
		return arr[next(front)];
	}


	bool empty(){
		return size==0;
	}

	int getSize(){
		return size;
	}
	//destructor
	~queue(){
		delete [] arr;
	}

	//add the follwing methods
	//Copy Constructor
	
	queue(const queue & obj){
		if(this==&obj){
			return;
		}
		cap=obj.cap;
		arr=new T[cap];
		front=obj.front;
		rear=obj.rear;
		size=obj.size;
		int i=next(front);
		while(i<=rear){
			arr[i]=obj.arr[i];
			i=next(i);
		}
		
		return *this;
	}
	//Assignment operator
	
	void operator=(const queue& obj) 
    { 
        if(this==&obj){
			return;
		} 
		cap=obj.cap;
		arr=new T[cap];
		front=obj.front;
		rear=obj.rear;
		size=obj.size;
		int i=next(front);
		while(i<=rear){
			arr[i]=obj.arr[i];
			i=next(i);
		}
		return *this;
    } 

};

int main(){
	queue<int> q1(2);//make a queue with cap=250
	q1.enqueue(22);
	q1.enqueue(33);
	q1.enqueue(44);
	q1.enqueue(55);
	q1.enqueue(66);
	
	queue<int> q2;
	q2=q1;
	q2.printQueue();
	
}


//q1.printQueue();
	// while(!q1.empty()){
	// 	int value = q1.peek();
	// 	cout<<value<<endl;
		
	// 	q1.dequeue();
	// }






// stack<int> s;

	// int x=0;
	// x=3;
	// x++;

	// while(x<10){
	// 	x++;
	// }


	//ADT: Abstract Data Type
	
	
	//size is the number of elements enqueued










