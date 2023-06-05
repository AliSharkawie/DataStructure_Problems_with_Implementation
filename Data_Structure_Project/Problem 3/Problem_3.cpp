#include <iostream>
using namespace std;

class Queue {

private:
    int* array;
    int size ;
    int added_elements;
    int front ;
    int rear ;

public:
    Queue(int s):size(s),front(0),rear(0),added_elements(0){
       array = new int [size];
    }
    ~Queue(){
        delete[] array;
    }
    int get_front(){
        return array[front];
    }

    void enqueue (int x)
    {
        if(!isFull()){
            array[rear]=x;
            rear = next_index(rear);
            added_elements++;
        }
        else
            cout << "full..can't add more\n";
    }
    int dequeue ()
    {
        if(!isEmpty()){
           int value = array[front];
            front = next_index(front);
            added_elements--;
            return value;
        }
        else
            cout << "\nempty.\n";
        return 0;
    }

    int isEmpty(){
        return added_elements == 0;
    }
    int isFull(){
        return added_elements == size ;
    }
    int next_index(int position){
        position++;
        if (position == size)
            position = 0;
        return position;

    }

    void Display(){

        if (isEmpty()) {
            cout << "\nempty.\n";
            return;
        }
        cout << "\n";

        for (int current = front, steps = 0; steps < added_elements; steps++)
        {

            cout << array[current] << " ";
            current = next_index(current);
        }



    }

};


class Stack{
private:
    Queue q;
    int added_elements;

public:
    Stack(int size ):q(size){
        added_elements = 0;
    }
    void push(int x){
        int size = added_elements;
        q.enqueue(x);
        while(size--)
            q.enqueue(q.dequeue());  // pull the element which is in the front of the queue
                                        // to the end of the queue.
        ++added_elements;
    }
    void pop(){
        q.dequeue();
    }
    int top(){
        return q.get_front();
    }
    void Display(){

        q.Display();
    }


};




int main()
{
    Stack stk(5);

    stk.push(5);
    stk.push(6);
    stk.push(7);
    stk.push(8);
    stk.push(9);


    stk.Display();
    cout <<"\n" << stk.top();

    stk.pop();

    stk.Display();
    cout << "\n" << stk.top();


    Stack stk1(4);
    stk1.push(1);
    stk1.push(2);
    stk1.push(3);

    cout << "\n";
    stk1.Display();
    cout << "\n" << stk1.top();

    stk1.pop();

    stk1.Display();
    cout << "\n" << stk1.top();


    return 0;
}
