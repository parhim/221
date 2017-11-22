#include <iostream>

#include "string_bst.hpp"
#include "max_heap.hpp"
#include "text_item.hpp"
#include "util.hpp"

using namespace std;




//--- PART 1A: Implementation and testing of heap insert
void heap_insert_tests(max_heap &hp) {
	text_item temp;
	std::string word = "item";
	int random_num;
	long int seed = long(time(0));    // seed for random number generator
	srand(seed);
	
	//--- Testing insert functionality
	std::cout << "*** TESTING INSERT ***" << std::endl;
	//--- This adds 5 items to the heap with random numbers
	//    and prints out the top, but it does not fully 
	//    test the correctness of the insert function.
	for (int i = 0 ; i < 5; i++) {
		random_num = rand() % 100 + 2;//added +2 so its at least 2
		string text = word;
		text += std::to_string(i+1);
		std::cout << "adding " << text << ",  with number " << random_num << " to heap" << std::endl;
		hp.insert(text_item{text, random_num});	
		temp = hp.top();
		std::cout << "Top of heap is: " << temp << std::endl;
        hp.printHeap(0,0);
	}
	
	//--- Specific insert functionality that should be tested:
	
	// insert without any swap_ups needed
		// <INSERT TEST(S) HERE>
    for (int i = 0 ; i < 5; i++) {//here we add items the will definitely be at the bottom of the heap.
        string text = word;
        text += std::to_string(i+6);
        std::cout << "adding " << text << ",  with number " << -i << " to heap" << std::endl;
        hp.insert(text_item{text, -i});
        temp = hp.top();
        std::cout << "Top of heap is: " << temp << std::endl;
        hp.printHeap(0,0);
    }
	// insert with a swap_up / multiple swap_ups
		// <INSERT TEST(S) HERE>
    for (int i = 0 ; i < 5; i++) {
        random_num = rand() % ((100*i)+100) + 50;//greater values for testing
        string text = word;
        text += std::to_string(i+11);
        std::cout << "adding " << text << ",  with number " << random_num << " to heap" << std::endl;
        hp.insert(text_item{text, random_num});
        temp = hp.top();
        std::cout << "Top of heap is: " << temp << std::endl;
        hp.printHeap(0,0);
    }
    
    
}

//--- PART 1B: Implementation and testing of heap delete
void heap_delete_tests(max_heap &hp) {
	text_item temp;
    std::string word = "item";
	
	//--- Testing deleteMax functionality
	std::cout << "*** TESTING DELETEMAX ***" << std::endl;
	//--- This does not fully test delete_max functionality.
	if (hp.size() > 1) {
		temp = hp.delete_max();
		std::cout << "Item returned from heap delete: "<< temp << std::endl;
		temp = hp.top();
		std::cout << "Top of heap is now: " << temp << std::endl;
        hp.printHeap(0,0);
      
	}
	
	//--- Specific insert functionality that should be tested:
    // remove_max on an empty heap (should throw exception similar to top())
    // <INSERT TEST(S) HERE>
    try{
        while (!hp.empty()){
            temp = hp.delete_max();
            std::cout << "Item returned from heap delete: "<< temp << std::endl;
            temp = hp.top(); //re-ordering
            std::cout << "Top of heap is now: " << temp << std::endl;}

        }
    catch (std::logic_error&)//the error at hand
        {
            cout << "You have attempted to remove the last node in the heap! ~ this is the expected outcome" << endl;//what the program should do otherwise
        }
    hp.printHeap(0,0);
    
    
    string text = word;
    text += std::to_string(10);
    hp.insert(text_item{text, 10});
    hp.insert(text_item{text, 9});
    hp.insert(text_item{text, 14});
    hp.insert(text_item{text, 12});
    hp.insert(text_item{text, 250});
    hp.insert(text_item{text, 45});
    hp.insert(text_item{text, 2});
    hp.insert(text_item{text, -9});
    hp.printHeap(0,0);
    
    
    // remove_max works when swap_down with right child
    // <INSERT TEST(S) HERE>
    if (hp.size() > 1) {
        temp = hp.delete_max();
        std::cout << "Item returned from heap delete: "<< temp << std::endl;
        temp = hp.top();
        std::cout << "Top of heap is now: " << temp << std::endl;
        hp.printHeap(0,0);
    }
		
	// remove_max works when swap_down with left child
		// <INSERT TEST(S) HERE>
    if (hp.size() > 1) {
        temp = hp.delete_max();
        std::cout << "Item returned from heap delete: "<< temp << std::endl;
        temp = hp.top();
        std::cout << "Top of heap is now: " << temp << std::endl;
        hp.printHeap(0,0);
    }
    
				
}

//--- PART 2: Implementation and testing of BST word_frequency
void tree_tester(string_bst const &tree) {
	std::cout << std::endl << "BEGINNING TESTS FOR PART 2" << std::endl;
	
	//--- Testing word_frequency functionality
	//--- This does not fully test word_frequency functionality.
	if (tree.size() > 1) {
		string to_find = "where";
		int num_times = tree.word_frequency(to_find);
		std::cout << "Found: "<< to_find << 
			" in the input file " << num_times 
			<< " time(s)." << std::endl;
	}
	
	//--- Specific word_frequency functionality that should be tested:
	
	// can search through both left and right subtrees if not found at current node
		// <INSERT TEST(S) HERE>
    if (tree.size() > 1) {
        tree.display();
        cout<< "the root of the tree is:" << tree.get_root() << endl;
        string to_find = "apple";
        int exp = 2;
        int real = tree.word_frequency(to_find);
        if (real!=exp){std::cout<<"something went wrong"<<endl;
        } else {std::cout<<"works properly"<<endl;}
        to_find = "zebra";//zebra will be at the end of our dictionary
        exp = 2;
        real = tree.word_frequency(to_find);
        if (real!=exp){std::cout<<"something went wrong"<<endl;}
        else{std::cout<<"works properly"<<endl;}
        
    }
    
    
		
	// returns 0 if word is not found
		// <INSERT TEST(S) HERE>
    if (tree.size() > 1) {
        string to_find = "bloop";
        int num_times = tree.word_frequency(to_find);
        std::cout << "Found: "<< to_find <<
        " in the input file " << num_times
        << " time(s)." << std::endl;
    }
			
}

//--- PART 3: Implementation and testing of word frequency analysis
void overall_most_freq(max_heap hp) {
	std::cout << "*** Top 5 most frequent words: ***" << std::endl;
    text_item* del = new text_item[5];//an array for deleted items to be inserted back into the heap
	
    int sz = hp.size();
    for (int i = 0;i<5&&i<sz;i++){
        del[i] = hp.delete_max();
        std::cout<<i+1<<" : "<< del[i].word << " - used "<<del[i].freq<<" times"<< std::endl;
    }
    //We are aware that we don't really need to insert those back in because its a heap copy but we believe it's still better to keep an unchanged heap.
    for (int i = 0;i<5&&i<sz;i++){
        hp.insert(del[i]);
    }
    delete [] del;

}

void at_least_length(max_heap hp, size_t num_letters) {
	cout << "*** Top 5 most frequent words with at least " 
		<< num_letters << " letters ***" << std::endl;
    int sz = hp.size();
    int c = 0;//counts how many words met the criteria
    int c1 = 0;//counts how many items have been removed from the heap
    text_item* del = new text_item[sz];//an array of the heap size for deleted items
    for (int i = 0;i<sz;i++){
        c1++;
        del[i] = hp.delete_max();
        if (del[i].word.size()>=num_letters){
            c++;
            std::cout<<c<<" : "<< del[i].word << " - used "<<del[i].freq<<" times"<< std::endl;
            
        }
        if (c>4) break;//if we already have the top 5 we dont loop anymore
    }
    //We are aware that we don't really need to insert those back in because its a heap copy but we believe it's still better to keep an unchanged heap.
    for (int i = 0;i<c1;i++){
        hp.insert(del[i]);//insterts the items back into the heap
    }
    delete [] del;

    ////////USE delete max and insert back right away if not///...
	//--- Add code to print out the 5 most common
	//--- words of length at least <num_letters>
	
}

void starts_with(max_heap hp, char starts_with_letter) {
	cout << "*** Top 5 most frequent words that begin with " 
		<< starts_with_letter << " ***" << std::endl;
    int sz = hp.size();
    int c = 0;//same as before
    int c1 = 0;
    text_item* del = new text_item[sz];
    for (int i = 0;i<sz;i++){
        c1++;
        del[i] = hp.delete_max();
        if (del[i].word.front()==starts_with_letter){//the criteria is different
            c++;
            std::cout<<c<<" : "<< del[i].word << " - used "<<del[i].freq<<" times"<< std::endl;
            
        }
        if (c>4) break;
    }
    for (int i = 0;i<c1;i++){
        hp.insert(del[i]);
    }
    delete [] del;
}

void heap_tester() {	
	text_item temp;
	int heap_size = 1000; //feel free to create heaps of other sizes when testing
	//cout << "How many items should be added to heap? ";
	//cin >> heap_size;
	max_heap hp(heap_size);
	std::cout << "Created heap of size " << heap_size << std::endl;
		
	//--- Testing heap size and top
	std::cout << "Current number of items in heap is: " << hp.size() << std::endl;
	try {
		temp = hp.top(); //should throw and exception without items in heap
		std::cout << "Top of heap is: " << temp << std::endl;	
	} catch (std::logic_error e) {
		std::cout << e.what() << std::endl;
	}
	// PART 1A:
	std::cout << std::endl << "BEGINNING TESTS FOR PART 1A" << std::endl;
	heap_insert_tests(hp);
	// PART 1B:
	std::cout << std::endl << "BEGINNING TESTS FOR PART 1B" << std::endl;
	heap_delete_tests(hp);
}

void text_analysis_tester(string_bst &tree) {
	std::cout << std::endl << "BEGINNING TESTS FOR PART 3" << std::endl;
	overall_most_freq(copy_to_heap(tree));
	std::cout << std::endl;
	at_least_length(copy_to_heap(tree), 6); // change the 8 to test other string-lengths
	std::cout << std::endl;
	starts_with(copy_to_heap(tree), 'a'); // change the 'c' to test words that starts_with_letter
											// with different characters
}

int main(int argc, char* argv[]) {
	
	//--- Part 1: max_heap implementation
	heap_tester(); 
	
	//--- Part 2: string_bst implementation
	string_bst tree;
	load_bst("sample3.txt", tree); // create a bst from an input file.
	tree_tester(tree);			//sample2.txt contains a much bigger file
	
	//--- Part 3: word frequency analysis of text files
	text_analysis_tester(tree);

}
