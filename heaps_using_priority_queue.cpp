# include <iostream>
# include <queue>
# include <cstdlib>
# include <ctime>
using namespace std;

class Point{
    int x;
    int y;
    
public:
    Point (int _x, int _y){
        x = _x;
        y = _y;
    }
    
    int getX() const {return x;}
    int getY() const {return y;}
};

class myComparator{

public:
    int operator() (const Point& p1, const Point& p2)
    {
        return p1.getX() > p2.getX();
    }
};

int main(){
    srand(time(NULL));
    int n = 5;
    
    // MAX HEAP
    priority_queue <int> max_pq;
    
    for(int i = 0; i < n; i++){
        int num = rand()%100;
        max_pq.push(num);
    }
    
    cout<<"The MAX-HEAP is: ";
    while (!max_pq.empty()){
        cout<<max_pq.top()<<" ";
        max_pq.pop();
    }
    cout<<endl;
    
    
    // MIN HEAP
    priority_queue <int, vector <int>, greater <int> > min_pq;
    
    for (int i = 0; i < n; i++){
        int num = rand()%100;
        min_pq.push(num);
    }
    
    cout<<"The MIN-HEAP is: ";
    while (!min_pq.empty()){
        cout<<min_pq.top()<<" ";
        min_pq.pop();
    }
    cout<<endl;
    
    
    // USER DEFINED HEAPS
    priority_queue <Point, vector <Point>, myComparator > user_pq;
    
    user_pq.push(Point(5,8));
    user_pq.push(Point(2,4));
    user_pq.push(Point(6,9));
    user_pq.push(Point(15,1));
    user_pq.push(Point(12,12));
    user_pq.push(Point(2,3));
    
    cout<<"The User defined Heap is: ";
    while (!user_pq.empty()){
        Point p = user_pq.top();
        user_pq.pop();
        
        cout<<"("<<p.getX()<<", "<<p.getY()<<") ";
    }
    cout<<endl;
    
    return 0;
}
