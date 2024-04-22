#include "bet.h"
#include <stack>
#include <sstream>
#include <cctype>

using namespace std;

// Helper function prototypessize_t BET::size(BinaryNode *t) const {
size_t BET::countNodes(BinaryNode *t) const
{
    if (t == nullptr)
        return 0;
    else
        return 1 + countNodes(t->left) + countNodes(t->right);
}

size_t BET::countLeafNodes(BinaryNode *t) const
{
    if (t == nullptr)
    {
        return 0;
    }
    if (t->left == nullptr && t->right == nullptr)
    {
        return 1;
    }
    return countLeafNodes(t->left) + countLeafNodes(t->right);
}

size_t BET::size() const
{
    return countNodes(root);
}

size_t BET::leaf_nodes() const
{
    return countLeafNodes(root);
}

// Constructor to create an empty Binary Expression Tree
BET::BET() : root(nullptr) {}

// Constructor to build Binary Expression Tree from a postfix expression
BET::BET(const string &postfix) : root(nullptr)
{
    buildFromPostfix(postfix);
}

// Copy constructor
BET::BET(const BET &other) : root(nullptr)
{
    root = clone(other.root);
}

// Destructor
BET::~BET()
{
    makeEmpty(root);
}

// Public function to build or rebuild a tree from a postfix expression
bool BET::buildFromPostfix(const string &postfix)
{
    stack<BinaryNode *> s;
    stringstream ss(postfix);
    string token;

    makeEmpty(root);

    while (ss >> token)
    {
        if (isdigit(token[0]) || isalpha(token[0]))
        { // Operand
            s.push(new BinaryNode(token, nullptr, nullptr));
        }
        else
        { // Operator
            if (s.size() < 2)
                return false;

            BinaryNode *right = s.top();
            s.pop();
            BinaryNode *left = s.top();
            s.pop();

            s.push(new BinaryNode(token, left, right));
        }
    }

    if (s.size() != 1)
        return false;

    root = s.top();
    return true;
}

// Print the infix expression
void BET::printInfixExpression() const
{
    if (root != nullptr)
    {
        printInfixExpression(root);
        cout << endl;
    }
}

// Print the infix expression by traversing the tree
void BET::printInfixExpression(BinaryNode *n) const
{

    if (n != nullptr)
    {
        bool needParens = (n->left && n->right && (n->element == "+" || n->element == "-"));
        if (needParens)
            cout << "(";
        printInfixExpression(n->left);
        cout << n->element;
        printInfixExpression(n->right);
        if (needParens)
            cout << ")";
    }
}

// Clean up the tree
void BET::makeEmpty(BinaryNode *&t)
{
    if (t != nullptr)
    {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    t = nullptr;
}

// Clone all nodes in the tree
BET::BinaryNode *BET::clone(BinaryNode *t) const
{
    if (t == nullptr)
        return nullptr;
    else
        return new BinaryNode(t->element, clone(t->left), clone(t->right));
}

// Operator= to make a deep copy of the tree
const BET &BET::operator=(const BET &other)
{
    if (this != &other)
    {
        makeEmpty(root);
        root = clone(other.root);
    }
    return *this;
}

// Size function to count nodes
size_t size(BET::BinaryNode *t)
{
    if (t == nullptr)
        return 0;
    else
        return 1 + size(t->left) + size(t->right);
}

// Leaf nodes count function
size_t leaf_nodes(BET::BinaryNode *t)
{
    if (t == nullptr)
        return 0;
    if (t->left == nullptr && t->right == nullptr)
        return 1;
    else
        return leaf_nodes(t->left) + leaf_nodes(t->right);
}

// Public function to return size

// Check if the tree is empty
bool BET::empty() const
{
    return root == nullptr;
}

// Optionally implement the printPostfixExpression if needed
void BET::printPostfixExpression(BinaryNode *n) const
{
    if (n != nullptr)
    {
        printPostfixExpression(n->left);  // Visit left subtree
        printPostfixExpression(n->right); // Visit right subtree
        std::cout << n->element << " ";   // Process the current node
    }
}

void BET::printPostfixExpression() const
{
    if (root != nullptr)
    {
        printPostfixExpression(root); // Start the recursion from the root
        std::cout << std::endl;       // After printing, move to the next line
    }
}
