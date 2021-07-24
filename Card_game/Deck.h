#pragma once
#include <vector>
#include <utility>
#include "Card.h"

class Deck {
private:
	std::vector <Card> m_deck;
	int m_cardIndex = 0;
public:
	Deck() {
		for (int card = 0; card < 52; ) 
		for (int suit = 0; suit < Card::MAX_SUITS; suit++) 
		for (int value = 0; value < Card::MAX_VALUES; value++) {
			m_deck.push_back(Card(static_cast<Card::Value>(value), static_cast<Card::Suit>(suit)));
			card++;			
		}
	}
	void printDeck() const {
		for (int i = 0; i < 52; i++) {
			m_deck[i].printCard();
			std::cout << std::endl;
		}
	}
	void shuffleDeck() {
		m_cardIndex = 0;
		for (int i = 0; i < 52; i++) {
			swapCard(m_deck[getRandom(0, 51)], m_deck[getRandom(0, 51)]);
		}
	}
	const Card& dealCard() {
		++m_cardIndex;
		return m_deck[m_cardIndex];
	}
private:
	static void swapCard(Card& card1, Card& card2) {
		std::swap(card1, card2);
	}
	short getRandom(int min, int max) {
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
		return static_cast<int>(rand() * fraction * (max - min + 1) + min);
	}	
};