//===========================================================================
//                      EXTENDED TICTACTOE
//                      Developed By: Leron Julian
//               PROGRAM COMPLETED PER PROGRAM SPECIFICATION
//===========================================================================

#include <iostream>
#include <string>
using namespace std;

struct playerInfo
{
    string firstName;
    string lastName;
    
    int wins = 0, losses = 0, draws = 0;
    int gamesPlayed = 0;
};

void welcomeMessage ();
int getPlayerNames (playerInfo *player_Information3);
void formatName (playerInfo *player_Information4, int num_Of_Players);
void printBoard (char **gameBoard, int boardWidth, int boardLength);
int getBoardLength();
int getBoardWidth();
void initalizeBoard (char **gameBoard, int length, int width);
void playGame (playerInfo *player_Information, int players);
void boardPosition (char **gameBoard, int length, int width, char playerPiece, string boardPlacement);
int checkWinner (char **gameBoard, int length, int width);
void displayStats (playerInfo *player_Information2, int players);

int main ()
{
    playerInfo *player_information = new playerInfo[5];
    
    welcomeMessage();
    
    int num_Of_Players = getPlayerNames(player_information);
    
    formatName(player_information, num_Of_Players);
    
    playGame(player_information, num_Of_Players);
    
    return 0;
}

void welcomeMessage ()
{
    cout << endl;
    cout << "===============================" << endl;
    cout << "  Welcome to The Board Game!   " << endl;
    cout << "===============================" << endl;
    cout << endl;
}

//===========================================================================
//  This function prints out a welcome message to the screen
//===========================================================================

int getPlayerNames (playerInfo *player_Information3)
{
    char charArray[13] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm'};
    
    bool fail;
    int numberOfPlayers;
    
    string firstName, lastName;
    
    do
    {
        cout << "Enter the amount of players (2-5 Players) -> ";
        cin >> numberOfPlayers;
        
        fail = cin.fail();
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        if (fail || (numberOfPlayers < 2 || numberOfPlayers > 5))
            cout << "Invalid Input! " << endl << endl;
        
    } while (fail == true || (numberOfPlayers < 2 || numberOfPlayers > 5));
    
    for (int i = 0; i < numberOfPlayers; i++)
    {
        cout << endl;
        cout << "Player " << (i + 1) << " will be <" << charArray[i] << ">." << endl;
        
        cout << "Enter Player " << (i + 1) << "'s first name -> ";
        cin >> firstName;
        
        player_Information3[i].firstName = firstName;
        
        cout << "Enter Player " << (i + 1) << "'s last name -> ";
        cin >>  lastName;
        
        player_Information3[i].lastName = lastName;
    }
    
    cout << endl;
    return numberOfPlayers;
}
//===========================================================================
//  This function gets the names of the players
//===========================================================================

void formatName (playerInfo *player_Information4, int num_Of_Players)
{
    string firstName, lastName;
    
    for (int i = 0; i < num_Of_Players; i++)
    {
        firstName = player_Information4[i].firstName;
        lastName = player_Information4[i].lastName;
        
        for (int j = 0; j < firstName.size(); j++)
        {
            if (firstName[j] >= 'A' && firstName[j] <= 'Z')
                firstName[j] = firstName[j] - 'A' + 'a';
            
            if (firstName[0] >= 'a' && firstName[0]<='z')
                firstName[0] = firstName[0] - 'a'+'A';
        }
        
        for (int k = 0; k < lastName.size(); k++){
            if (lastName[k] >= 'A' && lastName[k] <= 'Z')
                lastName[k] = lastName[k] - 'A' + 'a';
            
            if (lastName[0] >= 'a' && lastName[0] <= 'z')
                lastName[0] = lastName[0] - 'a'+'A';
        }
        
        player_Information4[i].firstName = firstName;
        player_Information4[i].lastName = lastName;
    }
}

//===========================================================================
//  This function formats the players first and last
//  names into desired format
//===========================================================================

void printBoard (char **gameBoard, int boardWidth, int boardLength)
{
    char charArray[13] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M'};
    int numArray[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    
    for (int i = 0; i < boardWidth ; i++)
        cout  << "\t " << numArray[i] ;
    
    cout << "\n   ";
    
    for (int j = 0; j < boardWidth; j++)
        cout << " ---";
    
    cout << endl;
    
    for (int i = 0; i < boardLength; i++)
    {
        cout << " " << charArray[i] << " ";
        
        for (int j = 0; j < boardWidth; j++)
            cout << "| " << gameBoard[i][j] << " ";
        
        cout << "| " << charArray[i] << endl << "   ";
        
        for (int j = 0; j < boardWidth; j++)
            cout << " ---";
        
        cout << endl;
    }
    
    cout << "   ";
    
    for (int i = 0; i < boardWidth; i++)
    {
        cout  << "\t " << numArray[i] ;
    }
    
    cout << endl;
}
//===========================================================================
//  This function prints the board with its current state
//===========================================================================

int getBoardWidth ()
{
    int width;
    bool fail;
    
    do{
        cout << "Enter the width of the board (From 3 - 16) -> ";
        cin >> width;
        
        fail = cin.fail();
        cin.clear();
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        if (fail || (width < 3 || width > 16))
            cout << endl << "Invalid Input! " << endl;
        
        else
            fail = true;
        
        cout << endl;
        
    } while (fail == false || width < 3 || width > 16);
    
    return width;
}

//===========================================================================
//  This function geits the width of the board
//===========================================================================

int getBoardLength ()
{
    bool fail;
    int length;
    
    do{
        cout << "Enter the length of the board (From 3 - 13) -> ";
        cin >> length;
        
        fail = cin.fail();
        cin.clear();
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        if (fail || (length < 3 || length > 13))
            cout << endl << "Invalid Input! " << endl;
        
        else
            fail = true;
        
        cout << endl;
        
    } while (fail == false || length < 3 || length > 13);
    
    return length;
}

//===========================================================================
//  This function gets the length of the board
//===========================================================================

void initalizeBoard (char **gameBoard, int length, int width)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < width; j++)
            gameBoard[i][j] = ' ';
    }
}

//===========================================================================
//  This function initalizes the board to an empty space at every positon
//===========================================================================

void playGame (playerInfo *player_Information, int players)
{
    cout << endl;
    
    int boardLength = getBoardLength();
    int boardWidth = getBoardWidth();
    
    char **gameBoard = new char*[boardLength];
    
    for(int i = 0; i < boardLength; ++i)
        gameBoard[i] = new char[boardWidth];
    
    player_Information[1].gamesPlayed += 1;
    
    initalizeBoard(gameBoard, boardLength, boardWidth);
    
    char charArray[13] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm'};
    
    string playerPosition;
    
    bool run = true;
    char playAgain;
    
    int i = player_Information[1].gamesPlayed - 1;
    int moves = 0;
    
    while (run)
    {
        char tempChar = ' ';
        
        cout << endl;
        printBoard(gameBoard, boardWidth, boardLength);
        cout << player_Information[i].firstName << " <" << charArray[i] << ">, where would you like to play (Ex. b5) -> ";
        cin >> playerPosition;
        
        int size = boardWidth;
        
        if (size > 9)
            size = 3;
        else
            size = 2;
        
        char firstValidation = charArray[boardLength - 1];
        char lastValidation = charArray[0];
        
        
        while (playerPosition.size() > size || playerPosition.size() < 2 || playerPosition[0] > firstValidation || playerPosition[0] < lastValidation)
        {
            cout << "Enter a valid position (Ex. a5) -> ";
            cin >> playerPosition;
            
            if (playerPosition.size() < size && playerPosition.size() > 1 && playerPosition[0] < firstValidation && playerPosition[0] > lastValidation)
                break;
        }
        
        tempChar = playerPosition[0];
        
        if (tempChar >= 'a' && tempChar <= 'z')
            tempChar = tempChar - 'a'+'A';
        
        playerPosition[0] = tempChar;
        
        char playerPiece = charArray[i];

        boardPosition(gameBoard, boardLength, boardWidth, playerPiece, playerPosition);
        
        int check = checkWinner(gameBoard, boardLength, boardWidth);
        
        i++;
        moves++;
        
        if(i == players)
            i = 0;
        
        if (moves == (boardLength * boardWidth))
        {
            cout << endl;
            printBoard(gameBoard, boardWidth, boardLength);
            
            cout << "It is a DRAW!!" << endl;
            
            cout << endl;
            
            for (int count = 0; count <= players; count++)
                player_Information[count].draws += 1;
            
            displayStats(player_Information, players);
            
            cout << endl;
            
            cout << "Would you like to play again (Enter: y/n) -> ";
            cin >> playAgain;
            
            if (playAgain == 'y' || playAgain == 'Y')
            {
                run = true;
                playGame(player_Information, players);
                
            }
            
            else
                exit(1);
        }
        
        if(check >= 0 && check < 13)
        {
            cout << endl << player_Information[check].firstName << " won!!" << endl;
            
            for (int count = 0; count < players; count++)
            {
                if (count == check)
                    player_Information[check].wins += 1;
                else
                    player_Information[count].losses += 1;
            }
            
            printBoard(gameBoard, boardWidth, boardLength);
            
            cout << endl;
            
            displayStats(player_Information, players);
            cout << endl;
            
            cout << "Would you like to play again (Enter: y/n) -> ";
            cin >> playAgain;
            
            if (playAgain == 'y' || playAgain == 'Y')
            {
                run = true;
                playGame(player_Information, players);
                
            }
            
            else
                exit(1);
        }
    }
}

//===========================================================================
//  This function plays the whole game and uses other functions
//===========================================================================

void boardPosition(char **gameBoard, int length, int width, char playerPiece, string boardPlacement)
{
    string position;
    char charToInt, charToInt2;
    
    char test = 'A';
    char charHolder;
    char tempChar;
    char tempChar2;
    
    int temp1, temp2;
    
    int total;
    
    int positionLength = test - boardPlacement[0];
    
    positionLength = abs(positionLength);
    
    if (boardPlacement.size() == 3)
    {
        tempChar = boardPlacement[1];
        charToInt = tempChar - '0';
        temp1 = charToInt;
        
        tempChar2 = boardPlacement[2];
        charToInt2 = tempChar2 - '0';
        temp2 = charToInt2;
        
        total = temp1 + temp2 + 9;
        
        gameBoard[positionLength][total - 1] = playerPiece;
    }
    
    else
    {
        charHolder = boardPlacement[1];
        char charToInt = charHolder - '0';
        int positionWidth = charToInt - 1;
        
        gameBoard[positionLength][positionWidth] = playerPiece;
    }
}

//===========================================================================
//  This function takes the users input and puts the associated players
//  piece on their board position
//===========================================================================

int checkWinner (char **gameBoard, int length, int width)
{
    char charArray[13] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm'};
    
    char winningPiece = ' ';
    char temp;
    int position = 22;
    
    for (int i = 0; i < length; i++)
        for (int j = 0; j < width; j++)
            if (gameBoard[i][j] == gameBoard[i][j + 1] && gameBoard[i][j] == gameBoard[i][j + 2] && gameBoard[i][j] != ' ')
            {
                temp = gameBoard[i][j];
                gameBoard[i][j] = gameBoard[i][j] - 'a'+'A';
                gameBoard[i][j + 1] = gameBoard[i][j + 1] - 'a'+'A';
                gameBoard[i][j + 2] = gameBoard[i][j + 2] - 'a'+'A';
                winningPiece = temp;
            }
    
    for (int i = 0; i < length - 2; i++)
        for (int j = 0; j < width; j++)
            if (gameBoard[i][j] == gameBoard[i + 1][j] && gameBoard[i][j] == gameBoard[i + 2][j] && gameBoard[i][j] != ' ')
            {
                temp = gameBoard[i][j];
                gameBoard[i][j] = gameBoard[i][j] - 'a'+'A';
                gameBoard[i + 1][j] = gameBoard[i + 1][j] - 'a'+'A';
                gameBoard[i + 2][j] = gameBoard[i + 2][j] - 'a'+'A';
                winningPiece = temp;
            }
    
    for (int i = 0; i < length - 2; i++)
        for (int j = 0; j < width - 2; j++)
            if (gameBoard[i][j] == gameBoard[i + 1][j + 1] && gameBoard[i][j] == gameBoard[i + 2][j + 2] && gameBoard[i][j] != ' ')
            {
                temp = gameBoard[i][j];
                gameBoard[i][j] = gameBoard[i][j] - 'a'+'A';
                gameBoard[i + 1][j + 1] = gameBoard[i + 1][j + 1] - 'a'+'A';
                gameBoard[i + 2][j + 2] = gameBoard[i + 2][j + 2] - 'a'+'A';
                winningPiece = temp;
            }
   
    for (int i = 0; i < length - 2; i++)
        for( int j = 0; j < width; j++)
            if (gameBoard[i][j] == gameBoard[i + 1][j - 1] && gameBoard[i][j] == gameBoard[i + 2][j - 2] && gameBoard[i][j] != ' ')
            {
                temp = gameBoard[i][j];
                gameBoard[i][j] = gameBoard[i][j] - 'a'+'A';
                gameBoard[i + 1][j - 1] = gameBoard[i + 1][j - 1] - 'a'+'A';
                gameBoard[i + 2][j - 2] = gameBoard[i + 2][j - 2] - 'a'+'A';
                winningPiece = temp;
            }
    
    for (int i = 0; i < 13; i++)
    {
        if (charArray[i] == winningPiece)
            position = i;
    }
    
    return position;
}

//===========================================================================
//  This function checks for a winning combination either horizontally
//  vertically or diagonally
//===========================================================================

void displayStats(playerInfo *player_Information2, int players)
{
    cout << "Total games played = " << player_Information2[1].gamesPlayed<< endl << endl;
    
    cout.width (44 - (player_Information2[players - 1].firstName.size() + player_Information2[players - 1].lastName.size())); cout << right  <<  " WIN " << " " << " LOSS " << " " << " DRAW ";
    
    cout << endl;
    
    for (int i = 0; i < players; i++)
    {
        cout.width (44 - (player_Information2[players - 1].firstName.size() + player_Information2[players - 1].lastName.size())); cout << right  <<  "------" << " " << "------" << " " << "------";
        cout << endl;
        
        cout << player_Information2[i].firstName << " " << player_Information2[i].lastName;
        
        cout.width (30 - (player_Information2[i].firstName.size() + player_Information2[i].lastName.size()));
        cout  <<  right << " |   " << player_Information2[i].wins << "  "  << "|   " << player_Information2[i].losses << "  " << "|   " << player_Information2[i].draws << "  " << "| ";
        
        cout << endl;
    }
    
    cout.width (44 - (player_Information2[players - 1].firstName.size() + player_Information2[players - 1].lastName.size())); cout << right  <<  "------" << " " << "------" << " " << "------";
    cout << endl;
}

//===========================================================================
//  This function displays the players wins, losses, and draws
//===========================================================================
