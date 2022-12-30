#include <iostream>
#include "LinkedList.cpp"
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

//CONSTANTS

int ARR_SIZE = 256;

Node<string>* findNewIndex(Node<string>* start_node, Node<string>* node){
  Node<string>* curr = start_node;
	while(curr != nullptr and (curr->counter < node->counter)){
		curr = curr->prev;
	}
	return curr;
}

void printNode(Node<string>* node){
	cout << "Node: "<< node->data << endl;
	cout << "prev: ";
	if (node->prev != nullptr)
		cout << node->prev->data;
	else
		cout << "Nullpointer";
	cout << " Next: ";
	if (node->next != nullptr)
		cout << node->next->data;
	else
		cout << "Nullpointer";
	cout << endl;
}


int main(int argc, char* argv[]){

    if (argc > 3) //checks amount of args
    {
        throw std::invalid_argument("Usage: ./hello <INPUT FILE> <OUTPUT FILE>"); //throws error
    }

		ifstream input;
		ofstream output;

		input.open(argv[1]);
		output.open(argv[2]);



		LinkedList<string>* arr_of_lists[ARR_SIZE];
		for (int i = 0; i< ARR_SIZE; i++) {
			arr_of_lists[i] = nullptr;
		}

		string foo;

		//take all the words, and assign them to their respective index
		//   within the array of linked lists
		while (getline(input, foo)){
			int i = foo.length();
			if (i < 0){
				continue;
			}
			if (arr_of_lists[i] == nullptr){ // if index is empty
				//add new node
				arr_of_lists[i] = new LinkedList<string>();
				arr_of_lists[i]->insert_front(foo);
				//cout << arr_of_lists[i]->front()->data;
			}
			else{
				Node<string>* catch_item = arr_of_lists[i]->firstRef(foo); //
					//printNode(catch_item);
				if (catch_item != nullptr){//if there is already a Node with the word in it,
					catch_item->counter++;   // add to it;

					arr_of_lists[i]->pop_lol(catch_item);//then, remove said Node from list, while keeping its old ptrs;
                    //arr_of_lists[i]->print();

                    if (arr_of_lists[i]->front() == nullptr){//if, with it gone, the list is empty, then re-insert said item;
						arr_of_lists[i]->insert_front(catch_item);//this works
					}else{//else, find the newest position that it can be in
						Node<string>* new_index = findNewIndex(catch_item->prev, catch_item);

						if(new_index == nullptr){
						    arr_of_lists[i]->insert_front(catch_item);
						}
						else{
							arr_of_lists[i]->insertFromNext(new_index, catch_item);
						}
					}
				}
				else{
					arr_of_lists[i]->insert_back(foo);
				}
			}
			//cout << "_______" << endl;
		}

		for (int i = 0; i< ARR_SIZE; i++){
		    if(arr_of_lists[i] != nullptr){
		        cout<< i;
		        arr_of_lists[i]->print();
		    }


		}



		input.close();
		output.close();


}

