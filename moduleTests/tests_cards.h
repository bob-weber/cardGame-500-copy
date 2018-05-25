#ifndef TESTS_CARDS_H
#define TESTS_CARDS_H

#include <QObject>
#include "../gameSrc/data/card.h"

class tests_Cards : public QObject
{
		Q_OBJECT
	public:
		explicit tests_Cards(QObject *parent = nullptr);
		void executeAll();

	signals:

	public slots:

	private Q_SLOTS:
		void Creation();
		void Orientation();
		void Rotation();

		/* Pointers to card objects, so we can use them in different tests
		 */
	private:
		Card *card_2_Spades;
		Card *card_King_Hearts;

};

#endif // TESTS_CARDS_H
