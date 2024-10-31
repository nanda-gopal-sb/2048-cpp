#include <iostream>
#include <random>
#include <vector>
using namespace std;
random_device rd; // seeding the random number generator
mt19937 gen(rd());

enum dir // enum to select the direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT,
};
class Matrix
{
private:
    int **matrix;
    dir currentDirection;
    void moveArray(int pos, dir direction)
    {
        if (direction == LEFT)
        {
            for (int j = 0; j < 2; j++)
            {
                for (int i = 3; i > 0; i--)
                {
                    if (matrix[pos][i] == matrix[pos][i - 1])
                    {
                        matrix[pos][i - 1] = 2 * matrix[pos][i];
                        matrix[pos][i] = 0;
                        continue;
                    }
                    else if (matrix[pos][i - 1] == 0)
                    {
                        matrix[pos][i - 1] = matrix[pos][i];
                        matrix[pos][i] = 0;
                        continue;
                    }
                    else if (matrix[pos][i] != matrix[pos][i - 1])
                    {
                        continue;
                    }
                }
            }
        }
        if (direction == RIGHT)
        {
            for (int j = 0; j < 2; j++)
            {
                for (int i = 0; i < 3; i++)
                {
                    if (matrix[pos][i] == matrix[pos][i + 1])
                    {
                        matrix[pos][i + 1] = 2 * matrix[pos][i];
                        matrix[pos][i] = 0;
                        continue;
                    }
                    else if (matrix[pos][i + 1] == 0)
                    {
                        matrix[pos][i + 1] = matrix[pos][i];
                        matrix[pos][i] = 0;
                        continue;
                    }
                    else if (matrix[pos][i] != matrix[pos][i + 1])
                    {
                        continue;
                    }
                }
            }
        }
        if (direction == UP)
        {
            for (int j = 0; j < 2; j++)
            {
                for (int i = 3; i > 0; i--)
                {
                    if (matrix[i][pos] == matrix[i - 1][pos])
                    {
                        matrix[i - 1][pos] = 2 * matrix[i][pos];
                        matrix[i][pos] = 0;
                        continue;
                    }
                    else if (matrix[i - 1][pos] == 0)
                    {
                        matrix[i - 1][pos] = matrix[i][pos];
                        matrix[i][pos] = 0;
                        continue;
                    }
                    else if (matrix[i][pos] != matrix[i - 1][pos])
                    {
                        continue;
                    }
                }
            }
        }
        if (direction == DOWN)
        {
            for (int j = 0; j < 2; j++)
            {
                for (int i = 0; i < 3; i++)
                {
                    if (matrix[i][pos] == matrix[i + 1][pos])
                    {
                        matrix[i + 1][pos] = 2 * matrix[i][pos];
                        matrix[i][pos] = 0;
                        continue;
                    }
                    else if (matrix[i + 1][pos] == 0)
                    {
                        matrix[i + 1][pos] = matrix[i][pos];
                        matrix[i][pos] = 0;
                        continue;
                    }
                    else if (matrix[i][pos] != matrix[i + 1][pos])
                    {
                        continue;
                    }
                }
            }
        }
    }
    void insertRandomTwo()
    {
        vector<pair<int, int>> emptyPositions;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (matrix[i][j] == 0)
                {
                    emptyPositions.push_back(make_pair(i, j));
                }
            }
        }
        if (!emptyPositions.empty())
        {
            uniform_int_distribution<> dist(0, emptyPositions.size() - 1);
            pair<int, int> pos = emptyPositions[dist(gen)];
            matrix[pos.first][pos.second] = 2;
        }
    }

public:
    Matrix()
    {
        matrix = new int *[4];
        for (int i = 0; i < 4; i++)
        {
            matrix[i] = new int[4];
        }
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                matrix[i][j] = 0;
            }
        }
        insertRandomTwo();
        insertRandomTwo();
    }

    void move(dir direction)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                moveArray(i, direction);
            }
        }
        insertRandomTwo();
    }
    void printArray()
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                cout << matrix[i][j] << "\t";
            }
            cout << "\n";
        }
    }
    void welcomeMessage()
    {
        cout << "Welcome to alpha version of 2048" << "\n";
        cout << "This game follows the w a s d format" << "\n";
        cout << "0 indicates the absence of something" << "\n";
    }
    ~Matrix()
    {
        for (int i = 0; i < 4; i++)
            delete[] matrix[i];
        delete[] matrix;
    }
};

int main(int argc, char const *argv[])
{
    Matrix mat;
    mat.welcomeMessage();
    char ch = '0';
    int i = 9;
    while (1)
    {
        mat.printArray();
        cout << "Enter the movement" << "\n";
        ch = getchar();
        if (ch == 'w')
            mat.move(UP);
        else if (ch == 'a')
            mat.move(LEFT);
        else if (ch == 's')
            mat.move(DOWN);
        else if (ch == 'd')
            mat.move(RIGHT);
        system("clear");
    }
}
