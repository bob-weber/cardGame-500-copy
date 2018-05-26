#ifndef CARD_H
#define CARD_H

#include <QObject>
#include <string>
#include <iostream>
#include <vector>
//#include <QIcon>

using namespace std;

class Card : public QObject
{
		Q_OBJECT

	public:
		/**
		 * Cards have a suit, and a pip. Technically, a pip refers to the dots on numeric cards, but for
		 * this class, we use pip to indicate face cards and jokers.
		 * All pips can be one of 4 suits: heart, diamond, spade or club
		 * Jokers can be one of 2 suits: read or black.
		 */

		/* Provide properties reads for suit and PIP
		 */
		enum Suit { SUIT_SPADE = 0, SUIT_CLUB, SUIT_DIAMOND, SUIT_HEART, SUIT_NUMBER_OF_SUITS };
		Q_ENUM(Suit)
		Q_PROPERTY(Suit suit READ getSuit)
		Suit getSuit() const;

		enum Pip { PIP_2 = 0, PIP_3, PIP_4, PIP_5, PIP_6, PIP_7, PIP_8, PIP_9, PIP_10,
			         PIP_JACK, PIP_QUEEN, PIP_KING, PIP_ACE, PIP_JOKER };
		Q_ENUM(Pip)
		Q_PROPERTY(Pip pip READ getPip)
		Pip getPip() const;

		/* Orientation properties. Can be read and written.
		 */
		enum Orientation { FACE_UP, FACE_DOWN };
		Q_ENUM(Orientation)
		Q_PROPERTY(Orientation orientation
		           READ getOrientation
		           WRITE setOrientation
		           NOTIFY orientationChanged)
		Orientation getOrientation() const;
		void setOrientation(Orientation orientation);

		// Rotation varies from 0 to 359 (degrees)
		const unsigned int MIN_ROTATION = 0;
		const unsigned int MAX_ROTATION = 359;
		Q_PROPERTY(unsigned int rotation
		           READ getRotation
		           WRITE setRotation
		           NOTIFY rotationChanged)
		unsigned int getRotation() const;
		void setRotation(unsigned int rotation);

		/** Construcors/destrucors
		 * If no suit or PIP is specified, a 2 of spades will be created.
		 */
		explicit Card(QObject *parent = nullptr,
		              Pip pip = PIP_2, Suit suit = SUIT_SPADE,
		              Orientation orientation = FACE_DOWN, unsigned int rotation = 0);
		virtual ~Card();

		/* Paint the specified area with the image for this card, either the PIP/foreground side
		 * or the backside of the card.
		 * Inputs:
		 *	paintArea = the area to paint
		 *	orientation = the card orientation, face up or face down.
		 *	rotation = card rotation, from 0 to 359 degrees. 0 is the default.
		 *		  0 has the card image vertically, with the image top at the top.
		 *		 90 has the card rotated horizontally, with the image top to the right.
		 *		180 has the card upside down.
		 *		270 has the image horizontal, with the image top to the left.
		 * Any
		 */
		void Paint(QRect paintArea, Orientation orientation);



		// Convencience operators
		bool operator==(Card &card) {
			return ((this->m_suit == card.m_suit) && (this->m_pip == card.m_pip)) ? true : false;
		}

		Card& operator=(Card& card) {
			this->m_suit = card.m_suit;
			this->m_pip = card.m_pip;
			return *this;
		}

	signals:
		void orientationChanged(Card::Orientation orientation);
		void rotationChanged(unsigned int);

	public slots:

	private:
		Pip m_pip;
		Suit m_suit;

		/* Beyond the specifics of each card, there are useful fields that can be used different games, such
		 * as whether the card is face up/down, or rotated.
		 */
		Orientation m_orientation;		// Is the card face-up or down.
		unsigned int m_rotation;
};

Q_DECLARE_METATYPE(Card::Orientation);

#endif // CARD_H
