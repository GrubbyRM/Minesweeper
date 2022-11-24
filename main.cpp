#include <iostream>

class board
{
    private:
        int array[8][8];
        int x=8;
        int y=8;
        std::string newline = "\n";
        std::string newlinex2 = "\n\n";
        std::string divide = "    –––––––––––––––––––––––––––––––––––––––––––––––––";
        std::string doublespace = "  ";

    public:

    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }

   /* void drawBoard()
    {
        int board[8][8];
        for(int x=0; x<getX(); x++)
        {
            for(int y = 0; y<getY(); y++)
            {
                std::cout << "□";
            }
            newlinex2;
        }
    }*/

    void printBoard()
    {
        std::cout << newline;
        std::cout << "   ";
        for(int i=0; i<getX(); i++)
        {
                std::cout<< "   " << "|" << i << "|";
        }
        for(int i=0; i<getX(); i++)
        {
            std::cout << newline;

            for(int j=0; j<=getX();j++)
            {
                if(j==0)
                {
                    std::cout<<"|" << i << "|";
                }
                std::cout << " | " << "   ";
            }
            std::cout << newline;
            std::cout << divide;
        }
    }
};



int main()
{
    board b1;
    //b1.drawBoard();

    b1.printBoard();
}