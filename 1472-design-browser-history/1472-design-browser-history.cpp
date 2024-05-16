class Node {
public:
    string data;
    Node* next;
    Node* prev;  // Renamed from 'back' to 'prev' for clarity

    Node(string x) : data(x), next(nullptr), prev(nullptr) {}
};

class BrowserHistory {
    Node* currentPage;

public:
    BrowserHistory(string homepage) {
        currentPage = new Node(homepage);
    }

    void visit(string url) {
        Node* newNode = new Node(url);
        newNode->prev = currentPage;  // Set the new node's previous to current page
        if (currentPage) {
            currentPage->next = newNode;  // Set current page's next to new node
        }
        currentPage = newNode;  // Move current page to new node
    }

    string back(int steps) {
        while (steps > 0 && currentPage->prev) {
            currentPage = currentPage->prev;
            steps--;
        }
        return currentPage->data;
    }

    string forward(int steps) {
        while (steps > 0 && currentPage->next) {
            currentPage = currentPage->next;
            steps--;
        }
        return currentPage->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */