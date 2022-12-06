#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

class board
{
    private:
        std::string newline = "\n";
        std::string newlinex2 = "\n\n";
        std::string doublespace = "  ";
        int bombCount_;
        int arraySizeX_;
        int arraySizeY_;

    public:
    board()
    {
        std::cout << "Set X value: ";
        std::cin >> arraySizeX_;
        std::cout << "Set Y value: ";
        std::cin >> arraySizeY_;
        std::cout << "Set number of bombs: ";
        std::cin >> bombCount_;
    }
    void setArraySizeX(int arraySizeX)
    {
        arraySizeX_ = arraySizeX;
    }
    int getArraySizeX()
    {
        return arraySizeX_;
    }

    void setArraySizeY(int arraySizeY)
    {
        arraySizeY_ = arraySizeY;
    }
    int getArraySizeY()
    {
        return arraySizeY_;
    }

    void setBombCount(int bombCount)
    {
        bombCount_ = bombCount;
    }

    int getBombCount()
    {
        return bombCount_;
    }

    int** createArray(int arraySizeX, int arraySizeY)
    {
            int** array = new int*[getArraySizeX()];
            for(int i = 0; i < getArraySizeX(); i++)
            {
                array[i] = new int[getArraySizeY()];
            }
            return array;
    }

    void deleteArray(int arraySizeX, int arraySizeY, int** array)
    {
        for(int i = 0; i < getArraySizeX(); i++)
            {
                delete[] array[i];
            }
        delete[] array;
        array = NULL;

        std::cout << "Array destroyed! [it should be at ~DTOR" << std::endl;
    }

    /*void printBoard(int *arraySize)
    {
        std::cout << newline;
        std::cout << "   ";
        for(int i=0; i<*arraySize; i++)
        {
                std::cout<< "   " << "|" << i << "|";
        }
        for(int i=0; i<*arraySize; i++)
        {
            std::cout << newline;

            for(int j=0; j<=*arraySize;j++)
            {
                if(j==0)
                {
                    std::cout<<"|" << i << "|";
                }
                std::cout << " | " << "   ";
            }
            std::cout << newline;
        }
    }*/

        /*void putBombs(int arraySizeX, int arraySizeY, int** array)
    {
        srand(time(0));
        int i = 0;
        int j = 0;
        int currentMines = 0;

    do {
        do {
            i = rand() % bombCount;
            j = rand() % bombCount;
        }while(array[i][j] != 0);

        array[i][j] = 9;
        currentMines++;

    }while(currentMines < bombCount);
    }

    void putBombs(int arraySizeX, int arraySizeY, int** array)
    {
        for(int i = 0; i < arraySizeX; i++)
        {
            for(int j = 0; j < arraySizeY; j++)
            {
                std::cout << "Put the value on position " << i << " " << j << ":";
                std::cin>>array[i][j];
                std::cout << endl;
            }
        }
    }*/

    void putBombs1(int arraySizeX, int arraySizeY, int** array)
    {
    srand(time(0));
    int i=0;
    int j=0;   
    int currentMines = 0;
    do{ 
        do{   
            i = rand() % getArraySizeX();
            j = rand() % getArraySizeY();
        }while(array[i][j] != 0);

    array[i][j] = 9;
    currentMines++;

    }while (currentMines < getBombCount());
    }

   void showBoms(int arraySizeX, int arraySizeY, int** array)
    {
    for(int i=0; i<getArraySizeX(); i++)
    {
        for(int j=0; j<getArraySizeY(); j++)
        {
            std::cout << array[i][j] << " ";
        }
        std::cout << endl;
    }
    }

    void checkNeighbour(int arraySizeX, int arraySizeY, int** array)
    {
        for(int i=0; i<getArraySizeX(); i++)
        {
            for(int j = 0; j<getArraySizeY(); j++)
            {
                if(array[i][j] == 9) {continue;}

                const int left = i-1;
                const int right = i+1;
                const int top = j-1;
                const int bottom = j+1;
                int neighbourCount = 0;

                if(left>=0 && top >= 0 && array[left][top] == 9) {neighbourCount++;}
                if(top >= 0 && array[i][top] == 9) {neighbourCount++;}
                if(right < getArraySizeX() && array[right][top] == 9) {neighbourCount++;}
                if(left >= 0 && array[left][j] == 9) {neighbourCount++;}
                if(right < getArraySizeX() && array[right][j] == 9) {neighbourCount++;}
                if(left >= 0 && bottom < getArraySizeX() && array[left][bottom] == 9) {neighbourCount++;}
                if(bottom < getArraySizeX() && array[i][bottom] == 9) {neighbourCount++;}
                if(right < getArraySizeX() && bottom < getArraySizeX() && array[right][bottom] == 9) {neighbourCount++;}

                array[i][j] = neighbourCount;


            }
        }
    }
};




int main()
{
    board b1;
    auto newArray = b1.createArray(b1.getArraySizeX(), b1.getArraySizeY());   
    b1.putBombs1(b1.getArraySizeX(), b1.getArraySizeY(), newArray);
    b1.checkNeighbour(b1.getArraySizeX(), b1.getArraySizeY(), newArray);
    b1.showBoms(b1.getArraySizeX(), b1.getArraySizeY(), newArray);
    b1.deleteArray(b1.getArraySizeX(), b1.getArraySizeY(), newArray);

    //b1.printBoard(&b);
}