#pragma once
#include <iostream>
class Card {
public:
	enum Value {
		TWO,
		THREE,
		FOUR,
		FIVE,
		SIX,
		SEVEN,
		EIGHT,
		NINE,
		TEN,
		VALET,
		QUEEN,
		KING,
		ACE,
		MAX_VALUES
	};
	enum Suit {
		CLUBS,
		HEARTS,
		DIAMONDS,
		SPADES,
		MAX_SUITS
	};
private:
	Value m_value;
	Suit m_suit;
public:
	Card(Value value, Suit suit) : m_value(value), m_suit(suit)
	{

	}
	void printCard() const {
		switch (m_value) {
		case Value::TWO:		std::cout << "Two of ";	    break;
		case Value::THREE:		std::cout << "Three of ";	break;
		case Value::FOUR:    	std::cout << "Four of ";	break;
		case Value::FIVE:   	std::cout << "Five of ";	break;
		case Value::SIX:		std::cout << "Six of ";	    break;
		case Value::SEVEN:		std::cout << "Seven of ";	break;
		case Value::EIGHT:		std::cout << "Eight of ";	break;
		case Value::NINE:		std::cout << "Nine of ";	break;
		case Value::TEN:		std::cout << "Ten of ";	break;
		case Value::VALET:		std::cout << "Valet of ";	break;
		case Value::QUEEN:		std::cout << "Queen of ";	break;
		case Value::KING:		std::cout << "King of ";	break;
		case Value::ACE:		std::cout << "Ace of ";	break;
		}
		switch (m_suit) {
		case Suit::CLUBS:    std::cout << "Clubs"; break;
		case Suit::DIAMONDS: std::cout << "Diamonds"; break;
		case Suit::HEARTS:   std::cout << "Hearts"; break;
		case Suit::SPADES:   std::cout << "Spades"; break;
		}
	}
	short getCardValue() const {
		switch (m_value) {
		case Value::TWO: return 2;
		case Value::THREE: return 3;
		case Value::FOUR: return 4;
		case Value::FIVE: return 5;
		case Value::SIX: return 6;
		case Value::SEVEN: return 7;
		case Value::EIGHT: return 8;
		case Value::NINE: return 9;
		case Value::TEN:
		case Value::VALET:
		case Value::QUEEN:
		case Value::KING: return 10;
		case Value::ACE: return 11;
		}
	}
};

