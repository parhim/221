/*--- max_heap.cpp -----------------------------------------------
  This file implements hax_heap.hpp member functions.
-------------------------------------------------------------------------*/

#include "max_heap.hpp"
#include <stdexcept>

max_heap::max_heap(int n){
	data = new text_item[n];
	numItems = 0;
	max_capacity = n;
}

max_heap::~max_heap()
{ 
	delete [] data;
}

bool max_heap::empty() const {
	return (numItems == 0);
}
bool max_heap::full() const {
	return (numItems == max_capacity);
}

int max_heap::size() const {
	return numItems;
}	

text_item& max_heap::top() {
	if (empty()) {
		throw std::logic_error("Heap is empty, can't access top!");
	}
	return data[0];
}


//--- You must comple the following functions:



void max_heap::printHeap(int node=0, int d=0) {
    //prints the heap out
    if(node >= numItems) return;
    printHeap(2*node+2,d+1);
    for (int i = 0;i<d;i++){
        std::cout<<"     ";
    }
    std::cout<<data[node].freq<<std::endl;
    printHeap(2*node+1,d+1);
    
}

text_item max_heap::delete_max() {
	if (empty()) {
		throw std::logic_error("Cannot delete, heap is empty!");
	} else {
        text_item *temp = new text_item;
        *temp = data[0];
        data[0] = data[numItems-1];
        numItems--;
        swap_down(0);
        
        //we assume that we need to return the text_item being deleted
        
        return *temp;
	}
}

void max_heap::swap_down(int i) {
	// ADD CODE HERE
    if (i==numItems || (i*2+1)>numItems) return;
    text_item tar = data[i];//node to be swapped
    
    text_item child1 =data[i*2+1];//it's children
    text_item child2 =data[i*2+2];
    //comparing frequencies
    if (tar.freq>=child1.freq&&(tar.freq>=child2.freq||i*2+2>=numItems)) return;    text_item* temp = new text_item;
    text_item* max = NULL;//this will be whichever child has a greater frequency
    int maxpos = -1;//the position of the child with the greater frequency
    
    if (tar.freq<child1.freq||tar.freq<child2.freq){
        if (child1.freq>=child2.freq && tar.freq<child1.freq){
            max = &child1;//sets max
            maxpos = (i*2+1);//and its position
        } else if (child1.freq<child2.freq && tar.freq<child2.freq){
            max = &child2;
            maxpos = (i*2+2);
        } else {
            max=NULL;
            maxpos=-1;
        }
    }
    if (max==NULL||maxpos<0) {//in case max wasn't set
        return;
    }
    *temp=data[i];
    data[i]=*max;
    
    data[maxpos]=*temp;
    delete temp;
    swap_down(maxpos);
    
    
}

void max_heap::insert(const text_item & item) {
	if (full()) {
		throw std::logic_error("Cannot insert, heap array is full!");
	} else {
        data[numItems]=item;//the next available position in the heap is numItems
        swap_up(numItems);
        numItems++;
	}
}

void max_heap::swap_up(int i) {
    
    if (i==0) return;
    text_item* tar = new text_item;
    *tar = data[i];
    text_item* par = new text_item;
    *par = data[(i-1)/2];//parent of the item to be swapped up
    if (tar->freq>par->freq){
        data[(i-1)/2]=*tar;
        data[i]=*par;
        swap_up((i-1)/2);//recursive call
    }
    delete tar;
    delete par;
    return;
    
}
