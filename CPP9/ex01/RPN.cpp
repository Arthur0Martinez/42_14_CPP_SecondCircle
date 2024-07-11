#include "RPN.hpp"

RPN::RPN() : _operation("8 9 * 9 - 9 - 9 - 4 - 1 +") {}

RPN::RPN(std::string operation) : _operation(operation) {}

RPN::RPN(const RPN &other) : _operation(other.getOperation()) {}

RPN RPN::operator=(const RPN &other)
{
    this->_operation = other.getOperation();
    return (*this);
}

RPN::~RPN() {}

std::string RPN::getOperation() const
{
    return (this->_operation);
}

bool verify(std::string operation) 
{
    std::istringstream iss(operation);
    std::string token;
    int count = 0;
    while (iss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") 
        {
            if (count < 2)
                return false;
            count--;
        } 
        else
        {
            if (token == " " || token == "\t" || token == "\n" || token == "\r")
                continue;
            if(!std::isdigit(token[0]))
                return false;
            count++;
        }
    }
    return count == 1;
}

void    RPN::calculation()
{
    char token;
    int a;
    int b;
    if(!verify(this->_operation))
        throw std::invalid_argument("Expression is unvalid");
    std::istringstream iss(this->_operation);
    while(iss >> token)
    {
        switch(token)
        {
            case '+':
                a = this->_stack.top();
                this->_stack.pop();
                b = this->_stack.top();
                this->_stack.pop();
                this->_stack.push(a + b);
                break;
            case '-':
                a = this->_stack.top();
                this->_stack.pop();
                b = this->_stack.top();
                this->_stack.pop();
                this->_stack.push(b - a);
                break;
            case '*':
                a = this->_stack.top();
                this->_stack.pop();
                b = this->_stack.top();
                this->_stack.pop();
                this->_stack.push(a * b);
                break;
            case '/':
                a = this->_stack.top();
                this->_stack.pop();
                b = this->_stack.top();
                this->_stack.pop();
                this->_stack.push(b / a);
                break;
            default:
                std::string str(1, token);
                std::istringstream iss(str);
                iss >> a;
                this->_stack.push(a);
        }
    }
    std::cout << this->_stack.top() << std::endl;
    this->_stack.pop();
}