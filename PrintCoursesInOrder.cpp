/*
  Code to support construction of a Binary Search Tree consisting of Nodes to order Courses
*/

struct Course {
    string courseNum;
    string courseName;
    vector<string> prerequisites;
    
    Course() {
        courseNum = "";
        courseName = "";
    }
    Course(string number, string name, vector<string> prereqs) {
        this->courseNum = number;
        this->courseName = name;
        this->prerequisites = prereqs;
    }
};

struct Node {
    Course course;
    Node* left;
    Node* right;
    Node() {
        left = nullptr;
        right = nullptr;
    }
    Node(Course course) {
        this->course = course;
    }
};

class BinarySearchTree {
private:
    Node* root;
    void insertNodeRecurse(Node* node, Course course);
    void removeNodeRecurse(Node* node);
    void inOrderRecurse(Node* node);
public:
    BinarySearchTree();
    virtual ~BinarySearchTree();
    void Insert(Course course);
    Course Search(string number);
    void InOrder();
};


/*
  Code to print a list of courses in alphanumeric order
*/

void BinarySearchTree::InOrder() {
    inOrderRecurse(root);
}

void BinarySearchTree::inOrderRecurse(Node *node) {
    if (node != nullptr) {
        inOrderRecurse(node->left);
        
        cout << node->course.courseNum << ", " << node->course.courseName << endl;
        
        inOrderRecurse(node->right);
    }
}
