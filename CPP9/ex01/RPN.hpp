#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <sstream>

class RPN
{
    private:
        std::string         _operation;
        std::stack<int>     _stack;
        RPN();
        RPN operator=(const RPN &other);
    
    public:
        RPN(std::string operation);
        RPN(const RPN &other);
        ~RPN();

        std::string getOperation() const;

        void    calculation();
        void    pushNumber();
};

#endif