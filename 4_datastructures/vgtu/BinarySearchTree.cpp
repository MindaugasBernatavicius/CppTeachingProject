#include <iostream>
#include <vector>

using namespace std;

class BiNode {
    public:
        string data;
        int count = 1;
        BiNode *leftChild = nullptr;
        BiNode *rightChild = nullptr;
        BiNode(string data) : data(data) {}
        ~BiNode() {}
};

class BinarySearchTree {
    private:
        BiNode *head = nullptr;
        BiNode *insert(BiNode *head, const string &data) {
            if (head == nullptr)
                head = new BiNode(data);
            else if (head->data.compare(data) < 0) // head's data "bigger", go right
                head->rightChild = insert(head->rightChild, data);
            else if (head->data.compare(data) > 0) // head's data "smaller", go left
                head->leftChild = insert(head->leftChild, data);
            else if (head->data == data)
                head->count++; // handle dubs, by using same keys with count
            return head;
        }
        void printPreOrder(BiNode *head) { // NLR
            if (head == nullptr) return;
            cout << head->data << " (" << head->count << ")" << endl;
            printPreOrder(head->leftChild);
            printPreOrder(head->rightChild);
        }
        void printInOrder(BiNode *head, ostream &os) const { // LNR
            if (head == nullptr) return;
            printInOrder(head->leftChild, os);
            os << head->data << " (" << head->count << ")" << endl;
            printInOrder(head->rightChild, os);
        }
        void printPostOrder(BiNode *head) { // LRN
            if (head == nullptr) return;
            printPostOrder(head->leftChild);
            printPostOrder(head->rightChild);
            cout << head->data << " (" << head->count << ")" << endl;
        }
        bool find(BiNode *node, string key) {
            if (node == nullptr) return false;
            if (node->data == key) return true;
            bool res = find(node->leftChild, key);
            if (res) return true;
            res = find(node->rightChild, key);
            return res;
        }
        BiNode *deleteNode(BiNode *node, string key) {
            if (node == nullptr)
                return node;
            if (key < node->data)
                node->leftChild = deleteNode(node->leftChild, key);
            else if (key > node->data)
                node->rightChild = deleteNode(node->rightChild, key);
            else {
                if (node->count > 1) { // if duplicate, decrement and return
                    node->count--;
                    return node;
                } else if (node->leftChild == nullptr) { // node with only one child or no child
                    BiNode *temp = node->rightChild;
                    delete node;
                    return temp;
                } else if (node->rightChild == nullptr) {
                    BiNode *temp = node->leftChild;
                    delete node;
                    return temp;
                }
                // for cases with two children, find minimum of right subtree
                BiNode *temp = this->minNode(node->rightChild);
                node->data = temp->data;
                node->rightChild = deleteNode(node->rightChild, temp->data);
            }
            return node;
        }
        BiNode *minNode(BiNode *node) {
            BiNode *current = node;
            while (current->leftChild != nullptr)
                current = current->leftChild;
            return current;
        }
    public:
        BinarySearchTree() = default;
        explicit BinarySearchTree(vector<string> vect) {
            for (auto const &value: vect) this->insert(value);
        }
        explicit BinarySearchTree(string data) {
            this->head = new BiNode(data);
        }
        ~BinarySearchTree() {
            destroy(this->head);
        }
        void insert(string data) {
            this->head = this->insert(this->head, data);
        }
        bool find(string key) {
            if (this->head == nullptr) return false;
            return this->find(this->head, key);
        }
        void deleteNode(string data) {
            this->deleteNode(this->head, data);
        }
        void update(string curVal, string newVal) {
            deleteNode(this->head, curVal);
            insert(this->head, newVal);
        }
        BiNode *destroy(BiNode *node) { // completely wipe the nodes information
            if (node == nullptr) return nullptr;
            node->rightChild = destroy(node->rightChild);
            node->leftChild = destroy(node->leftChild);
            delete node;
            return node; // TODO :: is it ok to return node after calling delete?
        }
        void printPreOrder() {
            this->printPreOrder(this->head);
        }
        void printInOrder(ostream &os) const {
            this->printInOrder(this->head, os);
        }
        void printPostOrder() {
            this->printPostOrder(this->head);
        }
        friend ostream &operator<<(ostream &os, const BinarySearchTree &bst);
};

ostream &operator<<(ostream &os, const BinarySearchTree &bst) {
    bst.printInOrder(os);
    return os;
}

void run2ndExample() {
    // // 1. Create an empty tree
    // // Original: F, B, A, D, C, E, G, I, H
	// BinarySearchTree bst;
	// bst.insert("F");
	// bst.insert("B");
	// bst.insert("A");
	// bst.insert("D");
	// bst.insert("C");
	// bst.insert("E");
	// bst.insert("G");
	// bst.insert("I");
	// bst.insert("H");

    // // 2. Create a tree with one node
	// BinarySearchTree bst("BBB");
	// // 4. Add element to the tree
	// bst.insert("AAA");
	// bst.insert("AAA");
	// bst.insert("AAA");
	// bst.insert("DDD");
	// bst.insert("CCC");
	// bst.insert("CCC");

    // 3. Create tree from a vector<T>
    vector<string> vector{"F", "B", "A", "D", "C", "E", "A"};
    BinarySearchTree bst(vector);

    // 5. Find element
    cout << std::boolalpha << "C is present in the tree: " << bst.find("C") << endl;
    cout << std::boolalpha << "X is present in the tree: " << bst.find("X") << endl;

    // 6. Update element
	// bst.update("C", "X");

    cout << "--------- printInOrder() --------" << endl;
    cout << bst;

    // 7. Remove element from the tree
    cout << "--------- deleteNode() --------" << endl;
    bst.deleteNode("A");

    // 8. In-order traversal.
    cout << "--------- printInOrder() --------" << endl;
    cout << bst;

    bst.insert("A");

    cout << "--------- printInOrder() --------" << endl;
    cout << bst;

    cout << "--------- deleteNode() --------" << endl;
    bst.deleteNode("A");

    cout << "--------- printInOrder() --------" << endl;
    cout << bst;

    bst.update("A", "X");

    // 9. Pre-order traversal
    cout << "--------- printPreOrder() --------" << endl;
    bst.printPreOrder();

    // 10. Post-order traveral
    cout << "--------- printPostOrder() --------" << endl;
    bst.printPostOrder();

    // Breadth First or Level Order Traversal
    // cout << "--------- printBreadthFirst() --------" << endl;
    // bst.printBreadthFirst();
}

int main() {
// 	run1stExample();
    run2ndExample();
}