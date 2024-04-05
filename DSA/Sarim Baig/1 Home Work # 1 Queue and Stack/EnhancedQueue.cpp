//Problem 1
template <typename T>
class EnhancedQueue{
    private:
        //Only the following members are allowed
        T * eqptr;
        int front;
        int rear;
        int n, cap;//n is physical size cap is logical size
        //you can add utility methods here
        public:
        EnhancedQueue();
        void enqueueAtFront(T & obj);
        void dequeueAtFront();
        void enqueueAtRear(T & obj);
        void dequeueAtRear();
        T peekFront();
        T peekRear();
        int size();
        bool empty();
};
EnhancedQueue::EnhancedQueue(){
    eqptr=nullptr;
    front=rear=-1;
    n=cap=0;
}
void EnhancedQueue:: enqueueAtRear(const T& obj){
		//is the queue full (physically)
		if(n+1==cap){
			//array is full, so grow it
			T * temp = new T[cap*2];
			//copy data from the older array
			int k=0, i=next(front);
			while(k<size){
				temp[k++]=arr[i];
				i=next(i);
				
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

void EnhancedQueue:: enqueueAtFront(const T& obj){
		//is the queue full (physically)
		if(n+1==cap){
			//array is full, so grow it
			T * temp = new T[cap*2];
			//copy data from the older array
			int k=0, i=next(front);
			while(k<size){
				temp[k++]=arr[i];
				i=next(i);
				
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
			rear=1	;
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

void EnhancedQueuevoid::dequeueAtFront(){
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


void EnhancedQueuevoid::dequeueAtRear(){
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
			//front=next(front);
			rear--;
			size--;
			delete [] arr;
			arr=temp;
		}else{
			//front=next(front);
			rear--;
			size--;
		}
	}