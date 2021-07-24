#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Card.h"
#include "Deck.h"
struct Inventory {
	unsigned short value = 0;
	std::vector<Card> cards;
};
enum Outcome {
	PLAYER_WINS,
	DEALER_WINS,
	NOONE_WINS
};
Outcome playBlackjack() {
	Deck deck;
	deck.shuffleDeck();
	Inventory player;
	Inventory dealer;
	std::cout << "Dealer takes one card... It is ";
	dealer.cards.push_back(deck.dealCard());
	dealer.cards[dealer.cards.size() - 1].printCard();
	std::cout << std::endl << std::endl;
	for (int i = 0; i < 2; ++i) {
		player.cards.push_back(deck.dealCard());
		std::cout << "Player takes card ";
		player.cards[i].printCard();
		player.value += player.cards[i].getCardValue();
		std::cout << " and gets overall score: " << player.value << std::endl;
	}
	std::string choice;
	do {
		std::cout << "You can HIT or STAND, what will you choose?\n";
		std::cin >> choice;
		if (choice == "HIT") {
			player.cards.push_back(deck.dealCard());
			std::cout << "You took ";
			player.cards[player.cards.size() - 1].printCard();
			player.value += player.cards[player.cards.size() - 1].getCardValue();
			std::cout << " and your overall score became: " << player.value << std::endl;
			if (player.value > 21) return DEALER_WINS;
		}
	}while (choice != "STAND");
	while (dealer.value < 17) {
		std::cout << "Dealer takes card... It is ";
		dealer.cards.push_back(deck.dealCard());
		dealer.cards[dealer.cards.size() - 1].printCard();
		std::cout << std::endl;
		dealer.value += dealer.cards[dealer.cards.size() - 1].getCardValue();
		std::cout << "Dealer`s overall score is " << dealer.value << std::endl;
	}
	if (dealer.value > 21) {
		return PLAYER_WINS;
	}
	if (player.value > dealer.value) return PLAYER_WINS;
	else if (dealer.value > player.value) return DEALER_WINS;
	else return NOONE_WINS;
}
int main() {
	srand(static_cast<unsigned int>(time(0))); 
	rand(); 
	std::string choice;
	do {
		system("CLS");
		std::cout << "Do you want to play a game? Type YES or NO\n";
		std::cin >> choice;
		if (choice == "YES")
		switch (playBlackjack()) {
		case PLAYER_WINS: std::cout << "Congrats! You have won!\n\n"; system("Pause");  break;
		case DEALER_WINS: std::cout << "You have lost! Dealer has won!\n\n"; system("Pause"); break;
		case NOONE_WINS: std::cout << "Ooops! We have a draw!\n\n"; system("Pause"); break;
		}
		if (choice == "NO") exit(0);
	} while (choice != "NO");
	return 0;
}



