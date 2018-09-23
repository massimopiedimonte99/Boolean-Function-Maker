#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <ctime>

class BooleanExpression
{
public:
    /**
     * This constructor initialize the "bits" vector
     * with pseudo-random N values [0, 1]
     * 
     * @name <BooleanExpression> BooleanExpression::BooleanExpression() 
     * @param <int> N
     */
    BooleanExpression(int N)
    {
        for (int i = 0; i < N; i++)
            this->bits.push_back(rand()%2);

        this->vectorSize = this->bits.size();
    };

    /**
     * This method takes a lambda function as
     * parameter in order to cut the string
     * BooleanExpression::booleanExpression.
     * 
     * I do this because when i'll build this
     * string in the BooleanExpression::makeBooleanExpression
     * method, i will basically leave an extra "OR "
     * at the end of the string.
     * 
     * @param <T> cutStr - The lambda function.
     * @return <std::string> - The formatted boolean expression.
     */
    template <typename T>
    std::string get_booleanExpression(T cutStr)
    {
        return cutStr(this->booleanExpression);
    }

    /**
     * Simple getter for the "bits" vector.
     * I won't use it, tho.
     * 
     * @return <std::vector> - The "bits" vector.
     * @see BooleanExpression::makeBooleanExpression
     */
    std::vector<int> get_bits()
    {
        return this->bits;
    }

    /**
     * What this method does is simply print all
     * the bits of the "bits" vector.
     * 
     * The output will look like:
     * x  y  f
     * 0  0  0
     * 1  1  1
     * 1  0  1
     * 0  0  0
     * 
     * @return <void> 
     */
    void printBits()
    {
        /*
         * I used "printf()" 'cause IMHO is much more cleaner
         * in case you want to nicely format the console
         * output. 
         */
        printf("%s  %s  %s\n", "x", "y", "f");
        for (int i = 0; i < this->vectorSize; i++) {
            printf("%d  ", this->bits[i]);
            if(i!=0 && (i+1)%3==0) printf("\n");
        }
    }

    /**
     * This method prepares the 
     * BooleanExpression::booleanExpression string.
     * 
     * @return <void>
     */
    void makeBooleanExpression()
    {
        /*
         * This two values are going to store
         * the value of the "x" and the "y" bit.
         */
        int x = 0, y = 0;

        for (int i = 0; i < this->vectorSize; i++) {
            // If the "f" bit is equal to 1...
            if((i+1)%3==0 && bits[i] == 1) {
                x = bits[i-2];  // x bit
                y = bits[i-1];  // y bit

                // Build the expression
                if(x == 0 && y == 0) 
                    this->booleanExpression.append("NOT X and NOT Y OR ");
                else if(x == 0 && y == 1)
                    this->booleanExpression.append("NOT X and Y OR ");
                else if(x == 1 && y == 0)
                    this->booleanExpression.append("X and NOT Y OR ");
                else if(x == 1 && y == 1)
                    this->booleanExpression.append("X and Y OR ");
            }
        }
    }

private:
    std::string booleanExpression = "";
    std::vector<int> bits = {};
    int vectorSize = this->bits.size();

    // For debugging purposes only
    void _debugPrintBits()
    {
        if(this->vectorSize > 0) 
        {
            std::cout << "[ ";
            std::for_each(this->bits.begin(), this->bits.end(), [](int el) -> void {
                std::cout << el << " ";
            });
            std::cout << "]" << std::endl;
        } 
        
        else 
        {
            std::cout << "[ empty ]";
        }
    }
};

int main(void)
{
    srand(time(0));

    /**
     * Make a std::unique_ptr to BooleanExpression.
     * 
     * There's no particular reason to use a pointer,
     * i just wanted to practice with the STL library.
     */
    std::unique_ptr<BooleanExpression> bool_exp{new BooleanExpression(12)};
    
    bool_exp->printBits();
    bool_exp->makeBooleanExpression();
    
    /**
     * Print the result of the getter 
     * BooleanExpression::get_booleanExpression.
     * 
     * What the lambda does is basically to cut 
     * the last three characters from the string passed
     * as an argument.
     * 
     * This way i can delete the extra "OR "
     * i used when i built this string.
     */
    std::cout << bool_exp->get_booleanExpression([](std::string s) -> std::string {
        return std::string("\nf(x, y) = " + s.substr(0, s.length()-3));
    });

    return 0;
}
