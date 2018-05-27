#include <QLabel>
#include <QGridLayout>

#include "view_500.h"

view_500::view_500(QWidget *parent) : QWidget(parent)
{

}

QWidget *view_500::setupCardTable()
{
	// Local fields we populate the card table with.
	/**************************************************************************
	 * The layout will be on a 12x13 grid, and laid out as follows.
	 *
	 *   | 0  | 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  | 10 | 11 | 12 |
	 *---
	 * 0                 Player3Name    Action: Status
	 *---                -----------------------------
	 * 1                |          Hand Area          |
	 *---                -----------------------------
	 * 2 Player2Name                                  Player4Name
	 *---     ---                                           ---
	 * 3     |   |                                         |   |
	 *---    |   |                                         |   |
	 * 4     |   |                                         |   |
	 *---    |   |                                         |   |
	 * 5     |   |                                         |   |
	 *---    |   |                                         |   |
	 * 6     |   |                                         |   |
	 *---    |   |                                         |   |
	 * 7     |   |                                         |   |
	 *---    |   |                                         |   |
	 * 8     |   |                                         |   |
	 *---     ---                                           ---
	 * 9 Action: Status                               Action: Status
	 *---                -----------------------------
	 * 10               |          Hand Area          |
	 *---                -----------------------------
	 * 11                Player1Name    Action: Status
	 *---
	 * 12			 Team1Score: xxx                    Team2Score: xxx
	 **************************************************************************/
	                                                      // row, col, row span, col span, align
	lbl_Player1_Name = new QLabel("Player1");			// (11,  3,   1,        3,       TBD)
	lbl_Player1_Action = new QLabel("P1 Action");	// (11,  6,   1,        3,       TBD)
	lbl_Player2_Name = new QLabel("Player2");			// ( 2,  0,   1,        3,       TBD)
	lbl_Player2_Action = new QLabel("P2 Action");	// ( 9,  0,   1,        3,       TBD)
	lbl_Player3_Name = new QLabel("Player3");			// ( 0,  3,   1,        3,       TBD)
	lbl_Player3_Action = new QLabel("P3 Action");	// ( 0,  6,   1,        3,       TBD)
	lbl_Player4_Name = new QLabel("Player4");			// ( 2,  9,   1,        3,       TBD)
	lbl_Player4_Action = new QLabel("P3 Action");	// ( 9,  9,   1,        3,       TBD)
	lbl_Team1_Score = new QLabel("Team 1 Score");	// (12,  1,   1,        3,       TBD)
	lbl_Team2_Score = new QLabel("Team 2 Score");	// (12,  8,   1,        3,       TBD)
	lbl_test = new QLabel("X");

	frm_Player1_HandArea = new QFrame;	// (10,  3,   1,        6,       TBD)
	frm_Player2_HandArea = new QFrame;	// ( 1,  1,   6,        1,       TBD)
	frm_Player3_HandArea = new QFrame;	// ( 1,  3,   1,        6,       TBD)
	frm_Player4_HandArea = new QFrame;	// ( 3, 10,   6,        1,       TBD)

	QGridLayout *tableLayout = new QGridLayout;
	tableLayout->addWidget(lbl_Player1_Name, 11, 3, 1, 3);
	tableLayout->addWidget(lbl_Player1_Action, 11, 6, 1, 3);
	tableLayout->addWidget(lbl_Player2_Name, 2, 0, 1, 3);
	tableLayout->addWidget(lbl_Player2_Action, 9, 0, 1, 3);
	tableLayout->addWidget(lbl_Player3_Name, 0, 3, 1, 3);
	tableLayout->addWidget(lbl_Player3_Action, 0, 6, 1, 3);
	tableLayout->addWidget(lbl_Player4_Name, 2, 9, 1, 3);
	tableLayout->addWidget(lbl_Player4_Action, 9, 9, 1, 3);
	tableLayout->addWidget(lbl_Team1_Score, 12, 1, 1, 3);
	tableLayout->addWidget(lbl_Team2_Score, 12, 8, 1, 3);
	tableLayout->addWidget(frm_Player1_HandArea, 10, 3, 1, 6);
	tableLayout->addWidget(frm_Player2_HandArea, 1, 1, 6, 1);
	tableLayout->addWidget(frm_Player3_HandArea, 1, 3, 1, 6);
	tableLayout->addWidget(frm_Player4_HandArea, 3, 10, 6, 1);

	QWidget *tableWidget = new QWidget();
	tableWidget->setLayout(tableLayout);
	return tableWidget;
}

