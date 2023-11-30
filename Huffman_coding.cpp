#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// tree node
struct Node {
    char data;
    int frequency;
    Node* left;
    Node* right;

    //Initilizer list
    Node(char data, int frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}
};

struct CompareNodes {
    bool operator()(Node* left, Node* right) {
        return left->frequency > right->frequency;
    }
};

void generateCodes(Node* root, string code, unordered_map<char, string>& huffmanCodes) {
    // ete yntaciq node-y armate avaertel funkcian
    if (root == nullptr)
        return;

    // ete yntaciq node-y tereve, avelacnel ayn hufmani koderi mapum
    if (!root->left && !root->right) {
        huffmanCodes[root->data] = code;
    }

    // rekursivoren navarkel huffman carov, hashvarkel kodery ev grancel hufmani kodeeri mapum
    generateCodes(root->left, code + "0", huffmanCodes);
    generateCodes(root->right, code + "1", huffmanCodes);
}

void buildHuffmanTree(string text) {
    // simvol ev hachaxakanutyun
    unordered_map<char, int> frequencyMap;

    // voroshum enq textum simvolneri qanaky
    for (char c : text) {
        frequencyMap[c]++;
    }
    // Node*-neri arajnahertutyan hert
    priority_queue<Node*, vector<Node*>, CompareNodes> minHeap;

    // Create new Node objects for each character and its frequency,
    // then push these nodes into the minHeap
    for (auto& pair : frequencyMap) {
        minHeap.push(new Node(pair.first, pair.second));
    }

    // algi himnakan logikan
    // amenacacr hajax-erov tareri hajax-ery gumarel irar
    while (minHeap.size() != 1) {
        // vercnum enq minHeap-i verjin 2 amenacacr hajax-y unecox tarery
        Node* left = minHeap.top();
        minHeap.pop();

        Node* right = minHeap.top();
        minHeap.pop();

        int sumFreq = left->frequency + right->frequency;
        // stexcel 2 noderi miacumic arajacac nor node hatuk simvolov
        Node* newNode = new Node('$', sumFreq);
        newNode->left = left;
        newNode->right = right;
        // nor tary avelacnum enq minHeapin
        minHeap.push(newNode);
    }

    // hufmani koderi map
    unordered_map<char, string> huffmanCodes;
    // generacnel hufmani koder jur simvoli hamar ev pahel hufmani koder mapum
    generateCodes(minHeap.top(), "", huffmanCodes);

    // tpel hufmani koder
    cout << "Huffman Codes:\n";
    for (auto& pair : huffmanCodes) {
        cout << pair.first << " : " << pair.second << endl;
    }
}

int main() {
    string input = "HelloWorld!";
    buildHuffmanTree(input);

    return 0;
}