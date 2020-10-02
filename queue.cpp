#subscribed by Varsha Tanti


#include <iostream>

using namespace std;

template <class T=int>
class Node
{
	public:
		T data;
		Node<T> *next;
		//Constructor 1
		Node(T);
		~Node();
};
template <class T>
Node<T>::Node(T x)
{
	data=x;
	next=NULL;
}
template <class T>
Node<T>::~Node()
{
	//destructor defined
}

template <class T=int>
class Queue{
	public : Node<T> *f,*r;
	private :
		int isEmpty()
		{
			if(f==NULL)
				return 1;
			else 
				return 0;
		}
	public:
		//Constructor
		Queue()
		{
			f=NULL;
			r=NULL;
		}
		//CopyConstructor
		Queue(Queue<T> &q)
		{
			f=q.f;
			r=q.r;
		}
		//Destructor
		~Queue()
		{
			Node<T> *k = f;
			while(f!=NULL)
			{
				f=f->next;
				delete []k;
				k = f;
			}
			delete []f;
		}
		void enqueue(T y)
		{
			Node<T> *temp = new Node<T>(y);
			if(r==NULL)
				f = r = temp;
			else
			{
				r->next = temp;
				r = temp;
			}
			
			cout << "Value enqueued successfully" << endl;
		}
		void dequeue()
		{
			if(isEmpty())
				cout << "empty queue!!!" << endl;
			else
			{
				cout << "Value dequeued : " << f->data << endl;
				f = f->next;
				if(f==NULL)
					r=NULL;
			}
		}
		void display() const
		{
			if(f==NULL)
			{
				cout << "Empty queue " <<endl;
				return;
			}
			Node<T> *temp= f;
			cout << "Printing queue : " << endl;
			while(temp != NULL){
				cout << temp->data << endl;
				temp= temp->next;
			}
			delete []temp;
		}
};

int main()
{
	Queue<float> k;
	Queue<float>m(k);
	Queue<> q;
	k.enqueue(2.5);
	m.enqueue(9);
	q.enqueue(88);
	

}
