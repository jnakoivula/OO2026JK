#include <iostream>
#include <cstdlib>
#include <ctime>

//Osa 1:
/*
int main() {
    std::srand(std::time(0));

    int number = std::rand() % 20+1;
    int answer = 0;

    std::cout << "Arvaa numero 1 ja 20 väliltä." << std::endl;

    while (answer != number) {
        std::cout << "Anna numero: ";
        std::cin >> answer;

        if (answer < number) {
            std::cout << "Liian pieni" << std::endl;
        }
        else if (answer > number) {
            std::cout << "Liian iso" << std::endl;
        }
        else {
            std::cout << "Arvasit oikein!" << std::endl;
        }
    }
    return 0;
}
*/

//Osa 2:
/*
int game(); //funktion prototyyppi

int main() {
    std::srand(std::time(0));

    int answers = game();
    std::cout << "Arvasit oikein " << answers << " arvauksella" << std::endl;
    return 0;
}

int game() {
    int number = std::rand() % 20+1;
    int answer = 0;
    int count = 0;

    std::cout << "Arvaa numero 1 ja 20 väliltä." << std::endl;

    while (answer != number) {
        std::cout << "Anna numero: ";
        std::cin >> answer;
        count++; //lisää arvausten määrää

        if (answer < number) {
            std::cout << "Liian pieni" << std::endl;
        }
        else if (answer > number) {
            std::cout << "Liian iso" << std::endl;
        }
        else {
            std::cout << "Arvasin oikein!" << std::endl;
        }
    }
    return count; //palauttaa arvausten määrän
}
*/

//Osa 3:

int game(int maxnum); //funktion prototyyppi

int main() {
    std::srand(std::time(0));

    int answers = game(40);
    std::cout << "Arvasit oikein " << answers << " arvauksella" << std::endl;
    return 0;
}

int game(int maxnum) {
    int number = std::rand() % maxnum+1;
    int answer = 0;
    int count = 0;

    std::cout << "Arvaa numero 1 ja " << maxnum << " väliltä" << std::endl;

    while (answer != number) {
        std::cout << "Anna numero: ";
        std::cin >> answer;
        count++; //lisää arvausten määrää

        if (answer < number) {
            std::cout << "Liian pieni" << std::endl;
        }
        else if (answer > number) {
            std::cout << "Liian iso" << std::endl;
        }
        else {
            std::cout << "Arvasin oikein!" << std::endl;
        }
    }
    return count; //palauttaa arvausten määrän
}

