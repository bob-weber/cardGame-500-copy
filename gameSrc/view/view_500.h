#ifndef VIEW_500_H
#define VIEW_500_H

#include <QWidget>
#include <QLabel>
#include <QFrame>

class view_500 : public QWidget
{
		Q_OBJECT
	public:
		explicit view_500(QWidget *parent = nullptr);
		QWidget *setupCardTable();

	signals:

	public slots:

	private:
		// Local fields we populate the card table with.
		QLabel *lbl_Player1_Name;
		QLabel *lbl_Player1_Action;
		QLabel *lbl_Player2_Name;
		QLabel *lbl_Player2_Action;
		QLabel *lbl_Player3_Name;
		QLabel *lbl_Player3_Action;
		QLabel *lbl_Player4_Name;
		QLabel *lbl_Player4_Action;
		QLabel *lbl_Team1_Score;
		QLabel *lbl_Team2_Score;
		QLabel *lbl_test;

		QFrame *frm_Player1_HandArea;
		QFrame *frm_Player2_HandArea;
		QFrame *frm_Player3_HandArea;
		QFrame *frm_Player4_HandArea;

};

#endif // VIEW_500_H
