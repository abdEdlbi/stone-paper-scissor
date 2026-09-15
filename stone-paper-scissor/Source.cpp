#include <iostream>
#include<cmath>
#include<cstdlib>
#include<cctype>
using namespace std;
enum engame { stone = 1, paper = 2, scissor = 3 };
int ReadNumberOfGame() {
    int n;
    do {
        cout << "\n Enter number of Round Bettwen 1 to 10 ?" << endl;
        cin >> n;
    } while (n < 1 || n > 10);
    return n;
}
engame RandomCoputer(int from, int to) {
    int random = rand() % (to - from + 1) + from;

    engame comp = (engame)random;
    return comp;
}
engame CoichePlayer() {
    int n;
    cout << "\nYour choice [1]:stone [2]:paper [3]:scissor ?" << endl;
    cin >> n;
    return (engame)n;

}
int checkWinner(engame computer, engame user) {
    if (computer == engame::stone && user == engame::paper)
        return 1;
    else if (computer == engame::stone && user == engame::scissor)
        return -1;
    else if (computer == engame::stone && user == engame::stone)
        return 0;
    else if (computer == engame::paper && user == engame::paper)
        return 0;
    if (computer == engame::paper && user == engame::scissor)
        return 1;
    else if (computer == engame::paper && user == engame::stone)
        return -1;
    else if (computer == engame::scissor && user == engame::paper)
        return -1;
    else if (computer == engame::scissor && user == engame::stone)
        return 1;
    else if (computer == engame::scissor && user == engame::scissor)
        return 0;

}
int roundInGame(engame user, engame computer) {
    if (checkWinner(computer, user) == 1)
    {

        return 1;
    }
    else if (checkWinner(computer, user) == -1)
    {
        return -1;
    }
    else
        return 0;
}
void PrintRound(int index, engame user, engame computer, int& playercount, int& computerCount) {
    int stateGame = roundInGame(user, computer);
    cout << "\n Round [" << index << "] begins :" << endl;
    cout << "\n______________[ " << index << " ]_______________" << endl << endl;
    cout << "Player choice :";
    if (user == engame::paper)
        cout << "paper" << endl;
    else if (user == engame::stone)
        cout << "stone" << endl;
    else if (user == engame::scissor)
        cout << "scissor" << endl;
    cout << "computer choice :";
    if (computer == engame::paper)
        cout << " paper" << endl;
    else if (computer == engame::stone)
        cout << "stone" << endl;
    else if (computer == engame::scissor)
        cout << "scissor" << endl;
    cout << "ROUND WINNER IS  :";
    if (stateGame == 1) {

        cout << "[ " << "Player ]" << endl;
        system("color 2f");
        playercount++;
    }
    else if (stateGame == -1) {
        cout << "[ " << "Computer ]" << endl;
        system("color 4f");
        computerCount++;
    }
    else
    {
        cout << "[ " << "No Winner ]" << endl;
        system("color 6f");
    }
    cout << "_________________________________" << endl;
}
void RecursionGame() {
    int counterGame = ReadNumberOfGame();
    int counter = 1;
    int PlayerCount = 0;
    int ComputerCount = 0;
    while (counter <= counterGame) {
        engame computer = RandomCoputer(1, 3);
        engame user = CoichePlayer();
        PrintRound(counter, user, computer, PlayerCount, ComputerCount);
        counter++;
    }
    cout << "\n\n";
    cout << "\t\t__________________________________________________\n\n";
    cout << "\t\t\t\t*** GAME OVER ***" << endl;
    cout << "\t\t__________________________________________________";
    cout << "\n\n\t\t___________[GAME RESULT]_____________\n\n";
    cout << "\t\tGAME ROND : " << counterGame << endl;
    cout << "\t\tPLAYER WIN : " << PlayerCount << endl;
    cout << "\t\tCOMPUTER WIN : " << ComputerCount << endl;
    cout << "\t\tDRAW : " << counterGame - PlayerCount - ComputerCount << endl;
    cout << "\t\tFINAL WINNER : ";
    if (PlayerCount > ComputerCount)
        cout << "PLAYER";
    else if (PlayerCount < ComputerCount)
        cout << "COMPUTER";
    else
        cout << "NO WINNER";
    cout << "\n\n__________________________________" << endl;

}
void startGamePlay()
{
    char res;
    do {
        system("cls");
        system("color 0f");
        RecursionGame();
        cout << "Do You want  to play again ?Y/N" << endl;
        cin >> res;
    } while (toupper(res)== 'Y');

}
int main() {
    srand((signed)time(NULL));
    startGamePlay();
    return 0;
}