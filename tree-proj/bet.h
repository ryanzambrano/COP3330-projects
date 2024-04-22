#ifndef BET_H
#define BET_H

#include <string>
#include <iostream>

class BET
{
public:
    struct BinaryNode
    {
        std::string element;
        BinaryNode *left;
        BinaryNode *right;

        BinaryNode(const std::string &theElement, BinaryNode *lt, BinaryNode *rt)
            : element(theElement), left(lt), right(rt) {}
    };

private:
    BinaryNode *root;

    void printInfixExpression(BinaryNode *n) const;
    void makeEmpty(BinaryNode *&t);
    BinaryNode *clone(BinaryNode *t) const;

    size_t countNodes(BinaryNode *t) const;
    size_t countLeafNodes(BinaryNode *t) const;
    void printPostfixExpression(BinaryNode *n) const;

public:
    BET();
    BET(const std::string &postfix);
    BET(const BET &);
    ~BET();

    bool buildFromPostfix(const std::string &postfix);
    void printInfixExpression() const;
    void printPostfixExpression() const; // If you decide to implement
    size_t size() const;
    size_t leaf_nodes() const;
    bool empty() const;

    const BET &operator=(const BET &);
};

#endif
