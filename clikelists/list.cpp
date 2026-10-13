
#include <iostream>
#include <cstdint>


struct Node {
	Node() = default;
	Node(const int32_t v) noexcept : value(v) {};
	Node(const Node& node) = delete;
	Node(Node&& node) = default; 
	~Node() = default;
	Node& operator=(const Node& node) = delete;
	Node& operator=(Node&& node) = default;

	Node* next = nullptr;

	int32_t value = 0;
};


Node* remove_from_list(Node* const root, const int idx) 
{
	int previdx = idx-1;
	if (previdx == -1) {
		Node* new_root = root->next;
		delete root;
		return new_root;
	}
	Node* head = root;
	while (previdx--) {
		head = head->next;
	}
	if (head->next) {
		Node* new_next = head->next->next;
		delete head->next;
		head->next = new_next;	
	}
	return root;
}

Node* make_list_from_stdin() 
{	
	Node* head = nullptr;
	Node* root = nullptr;
	int32_t value = 0;
	while (std::cin >> value && value != 0) {
		if (head == nullptr) {
			head = new Node(value);
			root = head;
		} else {	
			head->next = new Node(value);
			head = head->next;				
		}
	}
	return root;
}

Node* make_list_from_arr(const int* arr, const int len) {
	Node* root = nullptr;
	Node* head = nullptr;
	for (int i = 0; i < len; i++) {
		if (root) {
			head->next = new Node(arr[i]);
			head = head->next;
		} else {
			head = new Node(arr[i]);
			root = head;
		}
	}	
	return root;
}

void print_list(const Node* root) 
{
	while (root) {	
		std::cout << root->value << " ";
		root = root->next;
	}
	std::cout << '\n';
}

int main() 
{
	int arr[5] = {0,1,2,3,4};
	Node* root = make_list_from_arr(arr, 5);
	Node* secroot = new Node(std::move(*root));

	print_list(secroot);	

	secroot = remove_from_list(secroot, 0);

	print_list(secroot);

	return 0;
}
