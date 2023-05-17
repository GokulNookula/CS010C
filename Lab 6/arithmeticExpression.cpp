#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <stack>
#include "arithmeticExpression.h"

using namespace std;

/* Initializes an empty tree and sets the infixExpression
to the value of parameter passed in. */
arithmeticExpression::arithmeticExpression(const string & userString)
{
    // Set the root of the expression to nullptr.
    root = nullptr;

    // Set the infix expression to the user-provided string.
    infixExpression = userString;
}

/* Calls the recursive infix function. */
void arithmeticExpression::infix()
{
    infix(root);
}

/* Helper function that outputs the infix notation of the arithmetic expression tree
    by performing the inorder traversal of the tree.
    An opening and closing parenthesis must be added at the 
    beginning and ending of each expression. */
void arithmeticExpression::infix(TreeNode* currentNode)
{
    // Check if the current node is null.
    if (currentNode != nullptr)
    {
        // If the current node is an operator, print a left parenthesis.
        if (currentNode->data == '+' || currentNode->data == '-' || currentNode->data == '/' || currentNode->data == '*')
        {
            cout << '(';
        }

        // Recursively print the infix expression of the left subtree.
        infix(currentNode->left);

        // Print the data of the current node.
        cout << currentNode->data;

        // Recursively print the infix expression of the right subtree.
        infix(currentNode->right);

        // If the current node is an operator, print a right parenthesis.
        if (currentNode->data == '+' || currentNode->data == '-' || currentNode->data == '/' || currentNode->data == '*')
        {
            cout << ')';
        }
    }
}

/* Calls the recursive prefix function. */
void arithmeticExpression::prefix()
{
    prefix(root);
}

/* Helper function that outputs the prefix notation of the arithmetic expression tree
    by performing the preorder traversal of the tree. */
void arithmeticExpression::prefix(TreeNode* currentNode)
{
    // Check if the current node is null.
    if (currentNode != nullptr)
    {
        // Print the data of the current node.
        cout << currentNode->data;

        // Recursively print the prefix expression of the left subtree.
        prefix(currentNode->left);

        // Recursively print the prefix expression of the right subtree.
        prefix(currentNode->right);
    }
}

/* Calls the recursive postfix function. */
void arithmeticExpression::postfix()
{
    postfix(root);
}

/* Helper function that outputs the postfix notation of the arithmetic expression tree
    by performing the postorder traversal of the tree. */
void arithmeticExpression::postfix(TreeNode* currentNode)
{
    // Check if the current node is null.
    if (currentNode != nullptr)
    {
        // Recursively print the postfix expression of the left subtree.
        postfix(currentNode->left);

        // Recursively print the postfix expression of the right subtree.
        postfix(currentNode->right);

        // Print the data of the current node.
        cout << currentNode->data;
    }
}

/* Converts the infixExpression to its equivalent postfix string
    and then generates the tree and assigns the root node to the 
    root data field. The key for the first node is 'a', 'b' for the second node and so on. */
void arithmeticExpression::buildTree()
{
    // Convert the infix expression to postfix expression.
    infixExpression = infix_to_postfix();

    // Create a stack to store the nodes of the tree.
    stack<TreeNode*> s;

    // Iterate over the postfix expression.
    for (unsigned i = 0; i < infixExpression.length(); i++)
    {
        // Create a new node for the current character.
        TreeNode* currentNode = new TreeNode(infixExpression.at(i), 'a' + i);

        // Check if the current character is an operator.
        if (priority(infixExpression.at(i)) == 0)
        {
            // Push the node onto the stack.
            s.push(currentNode);
        }
        else
        {
            // The current character is an operand.
            // Pop the two operands from the stack.
            TreeNode* rightOperand = s.top();
            s.pop();
            TreeNode* leftOperand = s.top();
            s.pop();

            // Set the left and right children of the current node.
            currentNode->left = leftOperand;
            currentNode->right = rightOperand;

            // Push the current node onto the stack.
            s.push(currentNode);
        }
    }

    // The root of the tree is the top element of the stack.
    root = s.top();
}

/* Helper function for generating the dotty file. This is a recursive function. */
void arithmeticExpression::visualizeTree(ofstream &out, TreeNode *currentNode)
{
    // Check if the current node is null.
    if (currentNode != nullptr)
    {
        // Print the data of the current node.
        out << "\t" << currentNode->key << endl;

        // Print the data of the left child.
        if (currentNode->left != nullptr)
        {
            out << "\t" << currentNode->key << " -> " << currentNode->left->key << endl;
        }

        // Print the data of the right child.
        if (currentNode->right != nullptr)
        {
            out << "\t" << currentNode->key << " -> " << currentNode->right->key << endl;
        }

        // Recursively visualize the left and right subtrees.
        visualizeTree(out, currentNode->left);
        visualizeTree(out, currentNode->right);
    }
}

/* Helper function that returns the postfix notation equivalent
    to the given infix expression */
string arithmeticExpression::infix_to_postfix()
{
    // Create a stack to store the operators.
    stack<char> s;

    // Create a string stream to store the postfix expression.
    ostringstream oss;

    // Iterate over the infix expression.
    for (unsigned i = 0; i < infixExpression.size(); ++i)
    {
        // Get the current character.
        char c = infixExpression.at(i);

        // If the current character is a space, skip it.
        if (c == ' ')
        {
            continue;
        }

        // If the current character is an operator, push it onto the stack.
        if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')')
        {
            if (c == '(')
            {
                s.push(c);
            }
            else if (c == ')')
            {
                // While the top of the stack is not an opening parenthesis, pop the top of the stack and add it to the postfix expression.
                while (s.top() != '(')
                {
                    oss << s.top();
                    s.pop();
                }

                // Pop the opening parenthesis from the stack.
                s.pop();
            }
            else
            {
                // While the stack is not empty and the precedence of the top of the stack is greater than or equal to the precedence of the current operator, pop the top of the stack and add it to the postfix expression.
                while (!s.empty() && priority(c) <= priority(s.top()))
                {
                    if (s.top() == '(')
                    {
                        break;
                    }

                    oss << s.top();
                    s.pop();
                }

                // Push the current operator onto the stack.
                s.push(c);
            }
        }
        else
        {
            // The current character is an operand, add it to the postfix expression.
            oss << c;
        }
    }

    // While the stack is not empty, pop the top of the stack and add it to the postfix expression.
    while (!s.empty())
    {
        oss << s.top();
        s.pop();
    }

    // Return the postfix expression.
    return oss.str();
}

// This function visualizes the binary expression tree in a graph.
void arithmeticExpression::visualizeTree(const string &outputFilename)
{
    // Open the output file.
    ofstream outFS(outputFilename.c_str());

    // Check if the file opened successfully.
    if (!outFS.is_open())
    {
        // Print an error message and return.
        cout << "Error opening " << outputFilename << endl;
        return;
    }

    // Write the header of the graph.
    outFS << "digraph G {" << endl;

    // Recursively visualize the tree.
    visualizeTree(outFS, root);

    // Write the footer of the graph.
    outFS << "}" << endl;

    // Close the file.
    outFS.close();

    // Generate the image file.
    string jpgFilename = outputFilename.substr(0, outputFilename.size() - 4) + ".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}

// This function returns the precedence of the operator.
int arithmeticExpression::priority(char op)
{
    // Initialize the priority to 0.
    int priority = 0;

    // Check if the operator is an opening parenthesis.
    if (op == '(')
    {
        // The precedence of an opening parenthesis is 3.
        priority = 3;
    }
    // Check if the operator is a multiplication or division operator.
    else if (op == '*' || op == '/')
    {
        // The precedence of a multiplication or division operator is 2.
        priority = 2;
    }
    // Check if the operator is an addition or subtraction operator.
    else if (op == '+' || op == '-')
    {
        // The precedence of an addition or subtraction operator is 1.
        priority = 1;
    }

    // Return the priority.
    return priority;
}
